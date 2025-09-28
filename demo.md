# 🎬 USSD Food Delivery System - Interactive Demo

This demo showcases the complete user journey through the USSD-based food delivery system.

## 🚀 Quick Demo Setup

```bash
# Build the project
make

# Run the interactive demo
./food_delivery
```

## 📱 Demo Walkthrough

### 1. USSD Code Entry
When you run the program, you'll see:
```
Enter USSD code to start (*0101#): 
```

Enter the USSD code:
```
Enter USSD code to start (*0101#): *0101#

USSD code validated. Proceeding...
```

### 2. Restaurant Selection
You'll then see the available restaurants:
```
Available Restaurants:
1. Victoria 22
2. Organikks Ndizvo  
3. Amanzi Restaurant
4. Paula's Place
5. Mozambik Honeybear Greystone Park
6. Coimbra
7. China Garden Zw
8. Queen of Hearts Cafe
9. Gava's
10. Sabai Thai

Enter restaurant number: 
```

Let's select Victoria 22 (option 1):
```
Enter restaurant number: 1
```

### 3. Menu Browsing
You'll see Victoria 22's menu:
```
Menu for Victoria 22:
1. Prawn and hake madras curry with turmeric rice - $20
2. Seafood linguine with roasted tomato and basil sauce - $17.5
3. Red wine braised oxtail with parmesan mash - $17.5
4. De-boned stuffed quails with a bone marrow jus - $20
5. Sweet chili pork fillet wrapped in bacon - $17.5
6. Eggplant tower, tomato passata, and lentil ragù - $12.5
7. 4 Cheese Penne - $17.5

Enter menu item number (0 to finish): 
```

### 4. Order Building
Let's select a few items:
```
Enter menu item number (0 to finish): 1
Added to order. Choose another item or 0 to finish: 3
Added to order. Choose another item or 0 to finish: 0
```

### 5. Order Summary
```
Order contains:
- Prawn and hake madras curry with turmeric rice ($20)
- Red wine braised oxtail with parmesan mash ($17.5)

Total price: $37.50

Select payment method:
1. Visa Card
2. EcoCash
3. Payment on Delivery

Enter your choice: 
```

### 6. Payment Processing
Let's choose EcoCash (option 2):
```
Enter choice (1-3): 2
```

### 7. EcoCash Payment Flow
```
=== Payment Processing ===
Please enter your EcoCash PIN: 1234

✅ Payment successful!
```

### 8. Order Tracking
```
✅ Order confirmed and being prepared
🚚 Order dispatched and on the way
🏠 Order delivered successfully!

Thank you for using USSD Food Delivery!
```

## 🔄 Alternative Payment Methods

### Visa Card Payment
```
Enter choice (1-3): 1

=== Payment Processing ===
Please enter your card number: 1234567890123456
Please enter your CVV: 123
Please enter expiry date (MM/YY): 12/25

✅ Payment successful!
```

### Payment on Delivery
```
Enter choice (1-3): 3

=== Payment on Delivery Selected ===
✅ Order confirmed and being prepared
🚚 Order dispatched and on the way
💰 Please prepare $37.50 in cash
🏠 Order delivered successfully!
```

## 🎯 Demo Scenarios to Try

1. **Single Item Order**: Select one item and complete the order
2. **Multi-Item Order**: Select multiple items from the same restaurant
3. **Different Payment Methods**: Try all three payment options
4. **Different Restaurants**: Explore menus from various restaurants
5. **Error Handling**: Try entering invalid inputs to see error handling

## 📊 Expected Outputs

The system will demonstrate:
- ✅ Clean restaurant menu display
- ✅ Item selection and order building
- ✅ Price calculation and totals
- ✅ Multiple payment method support
- ✅ Order status tracking
- ✅ Professional user interface
- ✅ Error handling and validation

## 🛠️ Technical Features Demonstrated

- **Object-Oriented Design**: Clean class interactions
- **STL Vectors**: Dynamic menu management
- **Exception Handling**: Robust error management
- **Function Overloading**: Flexible order processing
- **Template Functions**: Efficient price comparisons
- **Inline Functions**: Optimized performance

## 💡 Tips for Demo

1. **Start Simple**: Begin with a single item order
2. **Explore Menus**: Try different restaurants to see variety
3. **Test Payments**: Experience all three payment methods
4. **Read Output**: Notice the professional formatting and user experience
5. **Error Testing**: Try invalid inputs to see error handling

---

*This demo showcases how modern C++ OOP principles can create practical solutions for real-world problems in underserved communities.*
