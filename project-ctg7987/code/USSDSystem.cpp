//==========================================================================================================
// Name         : Food Delivery System 
// Author       : Calvin Gutsa
// Version      : 1.0
// Date Created : 05-10-2022 
// Description  : Vector-based implementation of Food Delivery system in areas with limited internet access
//==========================================================================================================

#include "USSDSystem.h" // USSDSystem class
#include <iostream> // for cout, cin
#include <string> // for string
#include <thread>  // for thread
#include <chrono>  // for chrono

using namespace std;  // using namespace std

bool validateUSSDCode(const string& code) { //    
    return code == "*0101#";  // USSD code to validate
}

void USSDSystem::addRestaurant(const Restaurant& restaurant) { // add restaurant to restaurants vector
    restaurants.push_back(restaurant); // add restaurant to restaurants vector
}

void USSDSystem::displayRestaurants() const { // display restaurants
    cout << "\nAvailable Restaurants:\n"; // display restaurants
    for (size_t i = 0; i < restaurants.size(); ++i) { // for loop to iterate through restaurants vector
        cout << i + 1 << ". " << restaurants[i].getName() << endl; // display restaurant name

    }
}

bool processPayment(bool &isPaymentOnDelivery) { // process payment
    int paymentMethod; // payment method
    cout << "\nSelect payment method:\n"; // select payment method
    cout << "1. Visa Card\n";  // select payment method
    cout << "2. EcoCash\n";// select payment method
    cout << "3. Payment on Delivery\n"; // select payment method
    cout << "Enter option: "; // enter option
    cin >> paymentMethod; // input payment method

    switch (paymentMethod) { // switch statement for payment method
        case 1: {  
            string cardNumber; // card number
            cout << "\nEnter Visa card number (use 123456789 as card number): "; // enter card number
            cin >> cardNumber; // input card number
            if (cardNumber == "123456789") { // if card number is valid
                cout << "\nPayment successful!\n"; // payment successful
                return true; // return true
            } else { // if card number is invalid
                cout << "Invalid card number. Try again.\n"; // invalid card number
                return false; // return false
            }
        }
        case 2: {  // case for ecocash
            string pin; //string to store pin
            cout << "\nEnter EcoCash PIN (use 4321 as pin): "; //prompting the user to enter pin
            cin >> pin; //input pin
            if (pin == "4321") { //if pin is valid
                cout << "\nPayment successful!\n"; //payment successful
                return true; //return true
            } else { //if pin is invalid
                cout << "Invalid PIN. Try again.\n"; //invalid pin
                return false; //return false

            }
        }
        case 3: {  // Payment on delivery
            isPaymentOnDelivery = true; // set isPaymentOnDelivery to true
            cout << "\nPayment will be processed on delivery!\n"; // display message
            return true;  // return true
        }
        default: // default case
            cout << "Invalid option. Try again.\n"; // invalid option
            return false; // return false
    }
}

void updateOrderStatus(Order& order) { // update order status
    this_thread::sleep_for(chrono::seconds(5)); // sleep for 5 seconds
    order.updateStatus("Dispatched"); // update order status to dispatched
    cout << "\nOrder status: Dispatched\n"; // display order status

    this_thread::sleep_for(chrono::seconds(5)); // sleep for 5 seconds
    order.updateStatus("On the Way"); // update order status to on the way
    cout << "\nOrder status: On the Way\n"; // display order status

    this_thread::sleep_for(chrono::seconds(5)); // sleep for 5 seconds
    order.updateStatus("Delivered"); // update order status to delivered
    cout << "\nOrder status: Delivered\n"; // display order status
}

void USSDSystem::placeOrder() { // place order
    string ussdCode; // string to store ussd code

    do { // do-while loop to validate ussd code
        cout << "\nEnter USSD code to start (*0101#): "; // prompt user to enter ussd code
        cin >> ussdCode; // input ussd code

        if (!validateUSSDCode(ussdCode)) { // if ussd code is invalid
            cout << "Invalid USSD code. Please try again.\n"; // display error message
        }

    } while (!validateUSSDCode(ussdCode)); // loop until ussd code is valid
 
    cout << "\nUSSD code validated. Proceeding...\n"; // display message

    displayRestaurants(); // display restaurants

    int restaurantChoice; // variable to store restaurant choice
    cout << "\nEnter restaurant number: "; // prompt user to enter restaurant number
    cin >> restaurantChoice; // input restaurant number

    if (restaurantChoice < 1 || restaurantChoice > restaurants.size()) { // if restaurant choice is invalid
        cout << "Invalid choice. Try again!"; // display error message
        return; // return from function
    }

    Restaurant& chosenRestaurant = restaurants[restaurantChoice - 1]; // get chosen restaurant
    chosenRestaurant.displayMenu(); // display menu

    int itemChoice; // variable to store item choice
    cout << "\nEnter menu item number (0 to finish): "; // prompt user to enter menu item number
    while (cin >> itemChoice && itemChoice != 0) { // loop until user enters 0
        if (itemChoice < 1 || itemChoice > chosenRestaurant.getMenu().size()) { // if item choice is invalid
            cout << "Invalid choice. Try again."; // display error message
            cout << "\nEnter menu item number (0 to finish): "; // prompt user to enter menu item number
            continue; // continue to next iteration of loop
        }
        currentOrder.addItem(chosenRestaurant.getMenuItem(itemChoice - 1)); // add item to current order
        cout << "Added to order. Choose another item or 0 to finish: "; // prompt user to choose another item or 0 to finish
    }

    // Display the order details
    currentOrder.displayOrder();

    // Update the order status to pending before payment
    currentOrder.updateStatus("\nOrder Pending");

    // Process payment
    bool isPaymentOnDelivery = false;
    bool paymentSuccessful = processPayment(isPaymentOnDelivery);

    // Confirm order placed after payment method selection
    if (paymentSuccessful || isPaymentOnDelivery) {
        currentOrder.updateStatus("Order Placed");
        cout << "\nOrder status: Order Placed\n";

        // Introduce intervals between status updates
        this_thread::sleep_for(chrono::seconds(5));  // Wait for 5 seconds
        currentOrder.updateStatus("Dispatched"); // Update status to Dispatched
        cout << "\nOrder status: Dispatched\n"; // Display status

        this_thread::sleep_for(chrono::seconds(5));  // Wait for 5 seconds
        currentOrder.updateStatus("On the Way"); // Update status to On the Way
        cout << "\nOrder status: On the Way\n"; // Display status

        this_thread::sleep_for(chrono::seconds(10));  // Wait for 10 seconds
        currentOrder.updateStatus("Delivered"); // Update status to Delivered
        cout << "\nOrder status: Delivered\n"; // Display status

        // Handle payment confirmation for Payment on Delivery
        if (isPaymentOnDelivery) {// if payment is on delivery
            cout << "Payment successful!\n"; // display message
        }

        cout << "\nThanks for ordering with us! We look forward to serving you again :)\n"; // display message
    } else {// if payment is not successful
        cout << "Payment failed. Please try again.\n"; // display message
    }
}