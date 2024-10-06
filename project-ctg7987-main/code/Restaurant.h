//==========================================================================================================
// Name         : Food Delivery System 
// Author       : Calvin Gutsa
// Version      : 1.0
// Date Created : 05-10-2022 
// Description  : Vector-based implementation of Food Delivery system in areas with limited internet access
//==========================================================================================================

#ifndef RESTAURANT_H // include guard
#define RESTAURANT_H

#include <vector> // vector
#include <string> // string
#include "MenuItem.h" // MenuItem

using namespace std; // namespace

class BaseRestaurant { // BaseRestaurant class
public:
    virtual void displayMenu() const = 0; // virtual function to display menu 
    virtual string getName() const = 0;   // virtual function to get restaurant name
    virtual ~BaseRestaurant() {}          // virtual destructor     
};

class Restaurant : public BaseRestaurant { // Restaurant class
private:
    string name; // restaurant name
    vector<MenuItem> menu; // vector of menu items
public:
    Restaurant(string resName); // constructor
    void addMenuItem(const MenuItem& item); // function to add menu item

    void displayMenu() const override;  // override function to display menu
    string getName() const override; // override function to get restaurant name
    const vector<MenuItem>& getMenu() const; // function to get menu items
    const MenuItem& getMenuItem(int index) const; // function to get menu item by index
};
#endif
