//==========================================================================================================
// Name         : Food Delivery System 
// Author       : Calvin Gutsa
// Version      : 1.0
// Date Created : 05-10-2022 
// Description  : Vector-based implementation of Food Delivery system in areas with limited internet access
//==========================================================================================================

#include "Order.h" //include header file
#include <iostream> //include iostream
#include <iomanip> //include iomanip
#include <stdexcept> //include stdexcept

using namespace std; //using namespace std

Order::Order() : items(), status("Order Pending"), totalPrice(0.0) {} //default constructor

template <typename T> //template function
bool isLessThan(const T& a, const T& b) { //isLessThan function
    return a < b; //return a < b
}

void Order::addItem(const MenuItem& item) { //addItem function

    if (items.size() >= items.max_size()) { //if statement
        throw length_error("Order has exceeded its maximum allowed size."); //throw error
    }
    
    if (items.empty()) { //if statement
        items.push_back(item);  //push back item
    } else { //else statement
        auto it = items.begin(); //initialize it to items.begin
        while (it != items.end() && isLessThan(it->getPrice(), item.getPrice())) { //while loop
            ++it; //increment it
        }
        items.insert(it, item); //insert item
    }

    totalPrice += item.getPrice(); //add item price to total price
}

void Order::addItem(const vector<MenuItem>& itemsToAdd) { //addItem function
    for (const auto& item : itemsToAdd) { //for loop
        addItem(item); //add item
    }
}

void Order::addItem(const string& name, double price) { //addItem function
    MenuItem item(name, price); //create item
    addItem(item);  //add item
}

void Order::updateStatus(const string& newStatus) { //updateStatus function
    status = newStatus; //update status
}

void Order::displayOrder() const { //displayOrder function
    cout << "\nOrder contains:\n"; //print message
    for (const auto& item : items) { //for loop
        cout << "- " << item << "\n";  //print item
    }
    cout << "Total price: $" << fixed << setprecision(2) << totalPrice << "\n\n"; //print total price
    cout << "Order status: " << status << "\n";  //print status
}
string Order::getStatus() const { //getStatus function
    return status; //return status
}
