# Report

## Introduction
Despite the rapid spread of internet access across the globe, many regions still face barriers to constant, reliable connectivity. These barriers can stem from the lack of infrastructure, prohibitive internet costs, or geographic challenges. As a result, food delivery systems like Uber Eats, Deliveroo, and Talabat struggle to provide services in areas with limited internet access. The challenge this project seeks to solve is how to offer a food delivery service to customers in such areas, using an innovative, internet-free approach.

This project introduces a **USSD-based food delivery system** that allows users to place food orders without needing internet access. Through a simple USSD code, users can access a list of restaurants, view menus, select items, and choose payment options. The order is then processed and delivered to the customer's doorstep without the need for internet connectivity.

The project showcases how object-oriented programming (OOP) principles and optimization techniques can be applied to build a real-world system addressing this engineering challenge.


## Approach

The development of the **USSD-based food delivery system** leverages several core **OOP concepts**, including **classes, inheritance**, and **function overloading**. The goal was to create a system where a user interacts with the system via USSD, selects a restaurant, places an order, and pays using Visa or Ecocash, a popular digital banking service in Zimbabwe.

### The following OOP techniques were used:

- **Classes**: Designed to represent restaurants, menu items, and the orders placed, encapsulating the system's core entities.
  
- **Inheritance**: Allowed for the creation of base and derived classes, optimizing code reuse and ensuring flexibility for future expansions or modifications.
  
- **Function Overloading**: Enabled multiple variations of order placement, providing flexibility in how orders could be processed and enhancing user experience.

- **Error Handling**: Incorporated to ensure that the system gracefully handles edge cases, such as menu size limits or invalid inputs, ensuring robustness.

### The following Optimization Techniques were used:

- **Inline Functions**: To enhance performance, **inline functions** are used in the `MenuItem` class for frequently accessed methods such as `getName()` and `getPrice()`. This approach reduces the overhead of function calls by embedding the function code directly at the call site, thus improving the efficiency of the system when these methods are called repeatedly. This optimization ensures that commonly used functions have minimal impact on the overall performance, especially in scenarios where menu item details are accessed frequently during order processing.
  
- **Function Templates**: The **isLessThan()** function template is used to dynamically compare prices when adding items to an order. This ensures that menu items are inserted in sorted order by price, improving the organization and usability of the system. By using a function template, the system can handle comparisons between different types of data efficiently, allowing for flexibility and reusability of the code across different operations.

- **STL Vectors**: Utilized for dynamic memory management, allowing the system to handle varying amounts of data (e.g., menus and orders) flexibly and efficiently.

- **Friend Functions**: Implemented to enable specific non-member functions to access private members of the `MenuItem` class, facilitating formatted output and comparisons.

## System Architecture

The system is built around four core classes that encapsulate the main entities and processes involved in the **USSD-based food delivery system**:

- **MenuItem**: Encapsulates the properties of a menu item, such as its name and price. This class provides getter methods to access these attributes and ensures encapsulation of menu data.

- **Restaurant**: Contains a list of `MenuItem` objects and implements the logic for displaying and managing a restaurant's offerings. This class allows the addition of new menu items and ensures that the restaurant's menu is correctly managed and displayed.

- **Order**: Handles the placement, processing, and tracking of user orders. This class manages the addition of items to the order, calculates the total price, and processes the order's status updates, from placement to delivery.

- **USSDSystem**: Acts as the main controller of the system, interfacing with restaurants and processing orders through the USSD interface. This class manages user interaction, displaying available restaurants, and passing order information between the user and the restaurant.

This architecture ensures that each component of the system is modular, maintainable, and adheres to **object-oriented programming principles**.

## Solution

### OOP Concepts Implemented

- **Classes and Objects**: The `Restaurant`, `MenuItem`, and `Order` classes form the backbone of the system. Each `Restaurant` contains a menu represented as a list of `MenuItem` objects. Users interact with `Order` objects to place and track their food orders. This object-oriented structure promotes modularity and clear separation of concerns, ensuring that each class is responsible for a specific part of the system.

#### Code Snippet:
```cpp
class Restaurant {
    private:
        string name;
        vector<MenuItem> menu; // Menu stored as STL vector of MenuItem objects
    public:
        Restaurant(string resName);
        void addMenuItem(const MenuItem& item);
        void displayMenu() const;
        string getName() const;
};
```
This code demonstrates how the Restaurant class manages its menu of items using an STL vector and encapsulates the relevant methods to add items, display the menu, and retrieve the restaurant's name. The implementation of classes and objects ensures scalability and the possibility of adding more complex interactions without disrupting the existing code structure.

- **Inheritance and Function Overriding**:
The `Restaurant` class inherits from the `BaseRestaurant` class, which defines the pure virtual functions `displayMenu()` and `getName()`. This setup demonstrates **inheritance**, where the `Restaurant` class inherits common behavior from a base class, while also showcasing **function overriding**, as `Restaurant` provides its own custom implementation for these virtual functions.

### Code Snippet:
```cpp
class BaseRestaurant { 
    public:
        virtual void displayMenu() const = 0; // Pure virtual function
        virtual string getName() const = 0;   // Pure virtual function
        virtual ~BaseRestaurant() {}          // Virtual destructor
};

class Restaurant : public BaseRestaurant { 
    private:
        string name;
        vector<MenuItem> menu;
    public:
        Restaurant(string resName);
        void displayMenu() const override;  // Override displayMenu()
        string getName() const override;    // Override getName()
};
```
This code demonstrates inheritance through the BaseRestaurant class, which lays out a general structure for all restaurants, and function overriding, where each restaurant provides its specific behavior for displaying menus and retrieving names.

- **Function Overloading**:
The `Order` class demonstrates **function overloading** by providing multiple versions of the `addItem()` method. This allows the system to process orders in different ways—either by a single `MenuItem`, multiple `MenuItem` objects, or by directly specifying the name and price of an item.

### Code Snippet:
```cpp
void Order::addItem(const MenuItem& item);
void Order::addItem(const vector<MenuItem>& itemsToAdd);
void Order::addItem(const string& name, double price);
```
This code highlights function overloading, a key OOP concept that enables the Order class to handle multiple forms of input for adding items, providing flexibility in how orders are processed.

- **Error Handling**:
The system incorporates **robust error handling** to manage edge cases and ensure smooth execution. For instance, in the `addMenuItem()` method of the `Restaurant` class, a `std::length_error` is thrown when the menu exceeds its maximum allowed size. This ensures that the system gracefully handles situations where the number of menu items exceeds predefined limits, rather than crashing unexpectedly.

### Code Snippet:
```cpp
if (menu.size() >= menu.max_size()) {  
    throw length_error("Menu has exceeded its maximum allowed size.");
}
```
This snippet demonstrates how error handling is used to catch and respond to potential issues, helping maintain system stability and reliability.

### Optimization Concepts Implemented

- **Inline Functions**: Getter methods in the `MenuItem` class are defined as **inline** to minimize function call overhead.

#### Code Snippet:
```cpp
inline string getName() const { return name; }
inline double getPrice() const { return price; }
```
This optimization ensures that commonly used functions have minimal impact on the overall performance, especially in scenarios where menu item details are accessed frequently during order processing.

- **Function Templates**: The `isLessThan()` template is used to dynamically compare prices during item insertion into the order.

#### Code Snippet:
```cpp
template <typename T>
bool isLessThan(const T& a, const T& b) {
    return a < b;
}
```
- **STL Vectors**: The system uses STL Vectors to store restaurant menus and orders. Vectors provide dynamic memory management, allowing the system to efficiently manage varying amounts of data. This ensures that the system can scale with the number of restaurants and menu items without manual memory management.

### Code Snippet:
```cpp
vector<MenuItem> menu;
vector<MenuItem> items; // Used in the Order class to store the list of MenuItems
```
Using STL Vectors allows the program to handle collections of data dynamically, automatically resizing when items are added or removed, which enhances flexibility and efficiency.

- **Friend Functions**: Friend functions allow non-member functions to access private members of `MenuItem` and `Order`, facilitating formatted output.

#### Code Snippet:

```cpp
friend ostream& operator<<(ostream& os, const MenuItem& item) {
    os << item.getName() << " ($" << fixed << setprecision(2) << item.getPrice() << ")";
    return os;
}
```
Friend functions allow external non-member functions to access the private members of a class, in this case, `MenuItem` and `Order`. By declaring the `operator<<` function as a friend of the `MenuItem` class, it can access private attributes like `name` and `price` directly. This is particularly useful for providing formatted output, such as displaying a menu item with its name and price in a user-friendly way.

### System Output:

When a user interacts with the USSD-based food delivery system, they are presented with a series of prompts to select restaurants, choose menu items, and confirm their order. Below are sample outputs from various stages of the ordering process, including three payment method cases: Visa Card, EcoCash, and Payment on Delivery.

---

#### Restaurant Selection:

After entering the USSD code, the user is presented with a list of available restaurants based on their default location.

<img width="704" alt="Screenshot 2024-10-06 at 16 10 23" src="https://github.com/user-attachments/assets/5e609377-579d-4fcf-ba0d-e746c17b6295">


---

#### Menu Selection:

Once the user selects a restaurant, they are prompted to choose items from the menu. Multiple items can be selected until the user finalizes the order.

<img width="437" alt="Screenshot 2024-10-06 at 13 13 37" src="https://github.com/user-attachments/assets/a495ec01-c052-43b6-9c37-d82124d9a2db">


---
### Payment method Selection:

After selecting items from the restaurant's menu, the user is presented with a summary of their selected items and the total price. The order is in a pending state, and the user is asked to choose a payment method.

<img width="330" alt="Screenshot 2024-10-06 at 13 14 04" src="https://github.com/user-attachments/assets/95a24d49-85f6-4b5e-b701-394cbb03a44e">

#### Payment Method (Case 1: Visa Card):

Here, the user selects Visa Card as their payment option.

<img width="457" alt="Screenshot 2024-10-06 at 13 14 32" src="https://github.com/user-attachments/assets/fa4a009e-61e3-4249-a523-05881519c67a">


---

#### Payment Method (Case 2: EcoCash):

Alternatively, the user can choose EcoCash as the payment method, where they would enter their EcoCash PIN to complete the transaction.

<img width="294" alt="Screenshot 2024-10-06 at 13 15 45" src="https://github.com/user-attachments/assets/433c373f-e934-4f10-bb92-8d1177e264d7">

---

#### Payment Method (Case 3: Payment on Delivery):

In this case, the user selects "Payment on Delivery," where the payment is collected when the order is delivered.

<img width="271" alt="Screenshot 2024-10-06 at 13 16 43" src="https://github.com/user-attachments/assets/f12b428a-b266-45f1-a5bc-0c4cf0ef7d70">


---

#### Order Confirmation:

After selecting items and choosing a payment method, the user receives confirmation of their order status. The system updates the user on the progress of their order: from order placement, dispatch, "on the way," and finally delivered.

<img width="482" alt="Screenshot 2024-10-06 at 13 17 39" src="https://github.com/user-attachments/assets/2db8a746-d082-4070-a6d9-fc2a6ba1d4dc">


## Flowchart:

A UML diagram is below to demonstrate the structure and interaction between the core classes of the system, such as `MenuItem`, `Restaurant`, `Order`, and `USSDSystem`. This diagram helps visualize how the classes interact with one another and the flow of data through the system.

![FDS_Visualization (8)](https://github.com/user-attachments/assets/ab6c10c4-ab3f-4fdb-be47-11953e4cdbde)

*(Diagram created using Draw.io)*

## Conclusion

This project demonstrates the application of object-oriented principles such as inheritance, function overloading, and function overriding in addressing a real-world challenge of providing food delivery services in areas with limited internet access. The use of optimizations such as function templates, inline functions, and STL vectors enhances the efficiency of the system.

In my implementation, I used actual restaurants around Zimbabwe’s capital city, Harare, and integrated the local digital banking service, EcoCash, to showcase the system's feasibility. The solution also simulates real-time order processing with intervals between steps such as order placement, dispatch, and delivery to create a more interactive and realistic user experience.

However, to fully implement this system, further integration with a local digital bank for secure payments and a user database for managing passwords and pins would be necessary. Additionally, expanding the restaurant database and adding an order tracking system for real-time status updates would enhance the user experience.

This project provides a scalable and maintainable solution, adaptable to various geographic regions, especially through integration with local digital banking systems.

## References
1. [Reddit discussion on food delivery services in Zimbabwe](https://www.reddit.com/r/Zimbabwe/comments/1cr3j5f/food_delivery_service/)
2. [YouTube Video: Local Zimbabwe Food Delivery Overview](https://www.youtube.com/watch?v=fmriMi2Cjv8)
3. [TripAdvisor: Restaurants in Harare, Zimbabwe](https://www.tripadvisor.com/Restaurants-g293760-Harare_Harare_Province.html)
4. [Victoria 22 Restaurant Official Website](https://www.victoria22.com/)
5. [China Garden Zimbabwe Facebook Page](https://www.facebook.com/chinagardenzw/)



