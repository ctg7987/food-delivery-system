//==========================================================================================================
// Name         : Food Delivery System 
// Author       : Calvin Gutsa
// Version      : 1.0
// Date Created : 05-10-2022 
// Description  : Vector-based implementation of Food Delivery system in areas with limited internet access
//==========================================================================================================

#ifndef MENUITEM_H // include guard
#define MENUITEM_H

#include <string> // for string library
#include <iostream> // for input and output

using namespace std; // using standard namespace

class MenuItem { // class for menu item
private:
    string name; // name of menu item
    double price; // price of menu item

public:
    MenuItem(string itemName, double itemPrice); // constructor for menu item

    inline string getName() const { return name; } // inline function to get name of menu item
    inline double getPrice() const { return price; } // inline function to get price of menu item

    friend ostream& operator<<(ostream& os, const MenuItem& item); // overloaded operator for output stream
};

#endif // MENUITEM_H
