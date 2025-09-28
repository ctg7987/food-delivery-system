//==========================================================================================================
// Name         : Food Delivery System 
// Author       : Calvin Gutsa
// Version      : 1.0
// Date Created : 05-10-2022 
// Description  : Vector-based implementation of Food Delivery system in areas with limited internet access
//==========================================================================================================

#include "MenuItem.h" // include the header file for MenuItem class

MenuItem::MenuItem(string itemName, double itemPrice) : name(itemName), price(itemPrice) {} // constructor for MenuItem class

ostream& operator<<(ostream& os, const MenuItem& item) { // overload the << operator for MenuItem class
    os << item.getName() << " ($" << item.getPrice() << ")"; // print the name and price of the item
    return os; // return the output stream
}
