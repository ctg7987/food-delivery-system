///==========================================================================================================
// Name         : Food Delivery System 
// Author       : Calvin Gutsa
// Version      : 1.0
// Date Created : 05-10-2022 
// Description  : Vector-based implementation of Food Delivery system in areas with limited internet access
//==========================================================================================================

#ifndef ORDER_H // include guard
#define ORDER_H

#include <vector> // vector
#include <string> // string
#include "MenuItem.h" // MenuItem

using namespace std; // standard namespace

class Order { // Order class
private:
    vector<MenuItem> items; // vector of MenuItem objects
    string status; // status of the order
    double totalPrice; // total price of the order

public:
    Order();

    void addItem(const MenuItem& item); // add an item to the order

    void addItem(const vector<MenuItem>& itemsToAdd); // add multiple items to the order

    void addItem(const string& name, double price); // add an item to the order

    void updateStatus(const string& newStatus); // update the status of the order
    void displayOrder() const; // display the order details
    string getStatus() const; // get the status of the order
};

#endif


