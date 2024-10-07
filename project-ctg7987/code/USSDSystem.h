//=========================================================================================================
// Name         : Food Delivery System 
// Author       : Calvin Gutsa
// Version      : 1.0
// Date Created : 05-09-2022 
// Description  : Vector-based implementation of Food Delivery system in areas with limited internet access
//=========================================================================================================


#ifndef USSDSYSTEM_H // Header Guard
#define USSDSYSTEM_H

#include <vector> // Include Vector Library
#include "Restaurant.h" // Include Restaurant Class
#include "Order.h" // Include Order Class

using namespace std;  // Namespace Declaration

class USSDSystem { // Class Declaration
private:
    vector<Restaurant> restaurants; // Vector of Restaurant Objects
    Order currentOrder;  // Order Object

public:
    void addRestaurant(const Restaurant& restaurant); // Function to add Restaurant to the vector
    void displayRestaurants() const;  // Function to display Restaurants
     void placeOrder(); // Function to place Order
};

#endif 