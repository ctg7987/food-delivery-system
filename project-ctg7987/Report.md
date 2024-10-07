# Report

## Introduction
Despite the global surge in internet connectivity, millions remain disconnected due to infrastructure gaps, high costs, or geographic isolation. This digital divide leaves entire communities cut off from conveniences many take for granted—like the ease of ordering meals through platforms like Uber Eats, Deliveroo, or Talabat. With this project, the aim is to bring those same modern conveniences to underserved regions by introducing an innovative food delivery system that operates without the internet, relying solely on USSD technology. This solution offers a lifeline to regions long left behind by digital advancements.

This project introduces a **USSD-based food delivery system** that allows users to place food orders without needing internet access. Through a simple USSD code, users can access a list of restaurants, view menus, select items, and choose payment options. The order is then processed and delivered to the customer's doorstep without the need for internet connectivity.

The project showcases how object-oriented programming (OOP) principles and optimization techniques can be applied to build a real-world system addressing this engineering challenge.


## Approach

Using **object-oriented programming**, this project transforms the food delivery experience in regions with unreliable internet. By tapping into USSD technology and mobile banking platforms like EcoCash, a trusted service across Zimbabwe, we empower users to easily browse menus, place orders, and make payments—all without the need for the internet. This approach not only extends the reach of food delivery to previously disconnected communities but also fosters financial inclusion by integrating familiar, local payment options like EcoCash and Visa. It's a step toward leveling the playing field, offering the convenience of food delivery services to all, regardless of connectivity barriers.

### The following OOP techniques were used:

- **Classes and Objects**: Designed to represent restaurants, menu items, and the orders placed, encapsulating the system's core entities.
  
- **Inheritance**: Allowed for the creation of base and derived classes, optimizing code reuse, and ensuring flexibility for future expansions or modifications.
  
- **Function Overloading**: Enabled multiple variations of order placement, providing flexibility in how orders could be processed and enhancing user experience.

- **Function Overriding**: Allowed derived classes to modify inherited methods, enabling specific behavior for different restaurant types while maintaining common functionality.

### The following Optimization Techniques were used:

- **Inline Functions**: To enhance performance, **inline functions** are used in the `MenuItem` class for frequently accessed methods such as `getName()` and `getPrice()`. This approach reduces the overhead of function calls by embedding the function code directly at the call site, thus improving the efficiency of the system when these methods are called repeatedly. This optimization ensures that commonly used functions have minimal impact on the overall performance, especially in scenarios where menu item details are accessed frequently during order processing.
  
- **Function Templates**: The **isLessThan()** function template is used to dynamically compare prices when adding items to an order. This ensures that menu items are inserted in sorted order by price, improving the organization and usability of the system. By using a function template, the system can handle comparisons between different types of data efficiently, allowing for flexibility and reusability of the code across different operations.

- **STL Vectors**: Used for dynamic memory management, allowing the system to handle varying amounts of data (e.g., menus and orders) flexibly and efficiently. This ensures that the system can adapt to changes in data size without the need for manual memory management.

- **Friend Functions**: Implemented to allow specific non-member functions to access private members of the `MenuItem` class, facilitating formatted output and comparisons. This enhances the readability and usability of the output, ensuring proper formatting when displaying item details.


## System Architecture

At the heart of this system lie four core classes that manage all key entities and processes, each playing a vital role in enabling a smooth user experience. These classes work together to bridge the gap between customers, restaurants, and payment systems, ensuring that each interaction—from browsing menus to tracking orders—runs seamlessly, even without internet access.

- **MenuItem**: Encapsulates the properties of a menu item, such as its name and price. This class provides getter methods to access these attributes and ensures encapsulation of menu data.

- **Restaurant**: Contains a list of `MenuItem` objects and implements the logic for displaying and managing a restaurant's offerings. This class allows the addition of new menu items and ensures that the restaurant's menu is correctly managed and displayed.

- **Order**: Handles the placement, processing, and tracking of user orders. This class manages the addition of items to the order, calculates the total price, and processes the order's status updates, from placement to delivery.

- **USSDSystem**: Acts as the main controller of the system, interfacing with restaurants and processing orders through the USSD interface. This class manages user interaction, displaying available restaurants, and passing order information between the user and the restaurant.

This architecture ensures that each part of the system works independently, making it easier to update or fix specific sections without affecting the rest. Also, the code is organized for long-term upkeep, allowing future developers to modify or expand the system without causing major disruptions. By following object-oriented programming principles, the design also promotes clean and structured code, making the system more efficient and easier to understand.

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

- **Inheritance:** The Restaurant class inherits from the BaseRestaurant class, which defines the core structure that all restaurant types should follow. This setup demonstrates inheritance, where the Restaurant class automatically gains the common behavior defined in the BaseRestaurant class, such as the ability to display menus and retrieve restaurant names. By inheriting from a base class, the Restaurant class reuses shared functionality and ensures consistency across all restaurant types.

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
        void displayMenu() const override;
        string getName() const override;
};
```
This code demonstrates how inheritance allows the Restaurant class to automatically adopt the structure and functionality defined in the BaseRestaurant class, ensuring that all restaurants follow a consistent framework while allowing for specialized features.

- **Function Overloading**:
The `Order` class demonstrates **function overloading** by providing multiple versions of the `addItem()` method. This allows the system to process orders in different ways—either by a single `MenuItem`, multiple `MenuItem` objects, or by directly specifying the name and price of an item.

### Code Snippet:
```cpp
void Order::addItem(const MenuItem& item);
void Order::addItem(const vector<MenuItem>& itemsToAdd);
void Order::addItem(const string& name, double price);
```
This code highlights function overloading, a key OOP concept that enables the Order class to handle multiple forms of input for adding items, providing flexibility in how orders are processed.

- **Function Overriding:** The system utilizes function overriding to allow derived classes to provide specific implementations for inherited methods. In the `Restaurant` class, the `displayMenu()` and `getName()` methods are overridden to customize how each restaurant's menu and name are displayed. This ensures that the system maintains a consistent structure while enabling flexibility for each restaurant's specific behavior.

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
This snippet demonstrates how function overriding is applied to allow different restaurants to provide their own implementations of `displayMenu()` and `getName()`, ensuring flexibility while adhering to a general system structure.

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

### System Output

When a user interacts with the USSD-based food delivery system, they are presented with a series of prompts to select restaurants, choose menu items, and confirm their order. Below are sample outputs from various stages of the ordering process, including three payment method cases: Visa Card, EcoCash, and Payment on Delivery.

---

#### Restaurant Selection

After entering the USSD code, the user is presented with a list of available restaurants based on their default location.

<img width="704" alt="Screenshot 2024-10-06 at 16 10 23" src="https://github.com/user-attachments/assets/5e609377-579d-4fcf-ba0d-e746c17b6295">


---

#### Menu Selection

Once the user selects a restaurant, they are prompted to choose items from the menu. Multiple items can be selected until the user finalizes the order.

<img width="437" alt="Screenshot 2024-10-06 at 13 13 37" src="https://github.com/user-attachments/assets/a495ec01-c052-43b6-9c37-d82124d9a2db">


---
### Payment method Selection

After selecting items from the restaurant's menu, the user is presented with a summary of their selected items and the total price. The order is in a pending state, and the user is asked to choose a payment method.

<img width="330" alt="Screenshot 2024-10-06 at 13 14 04" src="https://github.com/user-attachments/assets/95a24d49-85f6-4b5e-b701-394cbb03a44e">

#### Payment Method (Case 1: Visa Card)

Here, the user selects Visa Card as their payment option.

<img width="457" alt="Screenshot 2024-10-06 at 13 14 32" src="https://github.com/user-attachments/assets/fa4a009e-61e3-4249-a523-05881519c67a">


---

#### Payment Method (Case 2: EcoCash)

Alternatively, the user can choose EcoCash as the payment method, where they would enter their EcoCash PIN to complete the transaction.

<img width="294" alt="Screenshot 2024-10-06 at 13 15 45" src="https://github.com/user-attachments/assets/433c373f-e934-4f10-bb92-8d1177e264d7">

---

#### Payment Method (Case 3: Payment on Delivery)

In this case, the user selects Payment on Delivery, where the payment is collected when the order is delivered.

<img width="271" alt="Screenshot 2024-10-06 at 13 16 43" src="https://github.com/user-attachments/assets/f12b428a-b266-45f1-a5bc-0c4cf0ef7d70">


---

#### Order Confirmation

After selecting items and choosing a payment method, the user receives confirmation of their order status. The system updates the user on the progress of their order: from order placement, dispatch, on the way, and finally delivered.

<img width="482" alt="Screenshot 2024-10-06 at 13 17 39" src="https://github.com/user-attachments/assets/2db8a746-d082-4070-a6d9-fc2a6ba1d4dc">


## Flowchart

A UML diagram is shown below to demonstrate the structure and interaction between the core classes of the system, such as `MenuItem`, `Restaurant`, `Order`, and `USSDSystem`. This diagram helps visualize how the classes interact with one another and the flow of data through the system, including user input, restaurant selection, order placement, and payment methods (EcoCash, Visa Card, Payment on Delivery).


![FDS_Visualization (8)](https://github.com/user-attachments/assets/ab6c10c4-ab3f-4fdb-be47-11953e4cdbde)

*(Diagram created using Draw.io)*

The above flowchart visually illustrates the seamless interaction between the system's core components, from user input to restaurant selection and payment, ensuring that the process flows as smoothly as it would in an internet-based platform.

## Conclusion

This project demonstrates the application of object-oriented principles such as classes and objects, inheritance, function overloading, and function overriding in addressing the real-world challenge of providing food delivery services in areas with limited internet access. The use of optimizations such as function templates, inline functions, friend functions, and STL vectors enhances the efficiency of the system. I have tested the code on Replit IDE, and it compiles successfully without any errors.

Built to address real-world challenges, this system collaborates with local restaurants in Harare, Zimbabwe’s vibrant capital, and integrates with EcoCash, the nation's leading mobile banking service. By leveraging the power of USSD technology, it overcomes the internet access barrier and offers users a smooth, reliable way to order and receive meals. From the initial order placement to live updates on delivery status, the system demonstrates a practical, scalable solution for regions struggling with connectivity. Its feasibility and impact lie not only in technological innovation but in its potential to transform how communities access essential services.

To prioritize both security and user experience, the system limits repeated input attempts after critical errors—such as entering the wrong restaurant number, payment method, pin, or card details. This intentional design choice safeguards sensitive user data, preventing brute-force attacks and misuse. By requiring users to restart the process upon such errors, the system not only enhances security but also simplifies the process, ensuring a smooth and protected experience for all users.

However, to fully implement this system, further integration with a local digital bank for secure payments and a user database for managing passwords and pins would be necessary. Additionally, expanding the restaurant database and adding an order tracking system for real-time status updates would enhance the user experience.

This project offers a flexible and easy-to-maintain solution that can be used in different regions. This system can be integrated with local digital banking systems, making it adaptable to various regions with different banking needs.

## References
1. [Mobile Money Research Paper](https://repository.up.ac.za/bitstream/handle/2263/86221/Muzanechita_MobileMoney_2022.pdf?isAllowed=y&sequence=3)
2. [Mobile Money Services Development in Zimbabwe](https://www.igi-global.com/article/drivers-of-mobile-money-services-development-in-zimbabwe/267945)
3. [Geography of Digital Access to Food in the US](https://www.brookings.edu/articles/delivering-to-deserts-new-data-reveals-the-geography-of-digital-access-to-food-in-the-us/)
4. [Recommendations for the Security of Mobile Payments](https://www.ecb.europa.eu/press/intro/cons/pdf/131120/recommendationsforthesecurityofmobilepaymentsdraftpc201311en.pdf)


