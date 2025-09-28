//==========================================================================================================
// Name         : Food Delivery System 
// Author       : Calvin Gutsa
// Version      : 1.0
// Date Created : 05-10-2022 
// Description  : Vector-based implementation of Food Delivery system in areas with limited internet access
//==========================================================================================================


#include "Restaurant.h" // Restaurant class
#include <iostream> // for cin, cout
#include <stdexcept> // for exception handling

using namespace std; // using standard namespace

Restaurant::Restaurant(string resName) : name(resName) {} // constructor

void Restaurant::addMenuItem(const MenuItem& item) { // add menu item to menu
    if (menu.size() >= menu.max_size()) {  // check if menu is full
        throw length_error("Menu has exceeded its maximum allowed size."); // throw exception
    }
    menu.push_back(item); // add item to menu
}

void Restaurant::displayMenu() const { // display menu
    if (menu.empty()) { // check if menu is empty
        cout << "No menu items available for this restaurant." << endl; // display message
        return; // exit function
    }
    cout << "\nMenu for " << name << ":\n"; // display menu title
    for (size_t i = 0; i < menu.size(); ++i) { // loop through menu items
        cout << i + 1 << ". " << menu[i].getName() << " - $" << menu[i].getPrice() << endl; // display menu item
    }
}

string Restaurant::getName() const { // get restaurant name
    return name; // return restaurant name
}

const vector<MenuItem>& Restaurant::getMenu() const { // get menu
    return menu; // return menu
}

const MenuItem& Restaurant::getMenuItem(int index) const { // get menu item
    if (index < 0 || index >= static_cast<int>(menu.size())) { // check if index is out of range
        throw out_of_range("Invalid menu index"); // throw exception
    } 
    return menu.at(index); // return menu item
}
