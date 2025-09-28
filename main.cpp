//=========================================================================================================
// Name         : Food Delivery System 
// Author       : Calvin Gutsa
// Version      : 1.0
// Date Created : 05-10-2022 
// Description  : Vector-based implementation of Food Delivery system in areas with limited internet access
//=========================================================================================================


#include <iostream>      //incorporates the iostream library
#include "USSDSystem.h"   //including the USSDSystem header file
#include "Restaurant.h"   //including the Restaurant header file
#include "MenuItem.h"     //including the MenuItem header file
#include <stdexcept> 

using namespace std;

int main() {
    
    USSDSystem ussd;//creating an object of the USSDSystem class

    try {
        Restaurant restaurant1("Victoria 22"); //creating an object of the Restaurant class
        restaurant1.addMenuItem(MenuItem("Prawn and hake madras curry with turmeric rice", 20.00)); //adding a menu item to the restaurant
        restaurant1.addMenuItem(MenuItem("Seafood linguine with roasted tomato and basil sauce", 17.50)); //adding a menu item to the restaurant
        restaurant1.addMenuItem(MenuItem("Red wine braised oxtail with parmesan mash", 17.50)); //adding a menu item to the restaurant
        restaurant1.addMenuItem(MenuItem("De-boned stuffed quails with a bone marrow jus", 20.00)); //adding a menu item to the restaurant
        restaurant1.addMenuItem(MenuItem("Sweet chili pork fillet wrapped in bacon", 17.50));//adding a menu item to the restaurant
        restaurant1.addMenuItem(MenuItem("Eggplant tower, tomato passata, and lentil ragù",  12.50)); //adding a menu item to the restaurant
        restaurant1.addMenuItem(MenuItem("4 Cheese Penne", 17.50)); //adding a menu item to the restaurant

        
        Restaurant restaurant2("Organikks Ndizvo");//creating an object of the Restaurant class
        restaurant2.addMenuItem(MenuItem("Coconut Tilapia Curry (S)", 12.00));//adding a menu item to the restaurant
        restaurant2.addMenuItem(MenuItem("Thai Green Curry (prawn, chicken, or veg) (V)", 18.00));//adding a menu item to the restaurant
        restaurant2.addMenuItem(MenuItem("Braised Oxtail", 16.00));//adding a menu item to the restaurant
        restaurant2.addMenuItem(MenuItem("Chicken Schnitzel", 16.00));//adding a menu item to the restaurant
        restaurant2.addMenuItem(MenuItem("Lemon Butter Tilapia", 12.00));//adding a menu item to the restaurant
        restaurant2.addMenuItem(MenuItem("Beef Fillet Medallions", 12.00));//adding a menu item to the restaurant
        restaurant2.addMenuItem(MenuItem("Lasagne (beef or veg) (V) ", 12.00));//adding a menu item to the restaurant
        restaurant2.addMenuItem(MenuItem("Asian Stir Fry Noodles (prawn, chicken, or veg) (V)", 14.00));//adding a menu item to the restaurant
        restaurant2.addMenuItem(MenuItem("Carbonara Pasta", 16.00));//adding a menu item to the restaurant
        restaurant2.addMenuItem(MenuItem("Arrabiata or Napolitano Pasta (prawn, chicken, or mushroom) (V) ", 12.00));

      
        Restaurant restaurant3("Amanzi Restaurant");//creating an object of the Restaurant class
        restaurant3.addMenuItem(MenuItem("West African Chicken Groundnut Stew", 25.00));//adding a menu item to the restaurant
        restaurant3.addMenuItem(MenuItem("Confit Duck Leg with Beetroot, Red Onion Pickle & Cranberry Sauce ", 28.00));//adding a menu item to the restaurant
        restaurant3.addMenuItem(MenuItem("Miso Vegetables with Dashi Rice & Sesame Peanut Dressing", 20.00));//adding a menu item to the restaurant
        restaurant3.addMenuItem(MenuItem("Seared Sole with Lentil Rice & Ginger Browned Butter", 28.00));//adding a menu item to the restaurant
        restaurant3.addMenuItem(MenuItem("Chicken Kiev with Kimchi & Garlic Butter", 25.00));//adding a menu item to the restaurant
        restaurant3.addMenuItem(MenuItem("Sticky Pork Belly with Soy & Chilli Pak Choi", 25.00));//adding a menu item to the restaurant
        restaurant3.addMenuItem(MenuItem("Slow Cooked Lamb Shoulder with Harissa & Mint Yogurt", 28.00));//adding a menu item to the restaurant
        restaurant3.addMenuItem(MenuItem("Five Spice Oxtail with Creamed Spinach", 25.00));//adding a menu item to the restaurant
        restaurant3.addMenuItem(MenuItem("Maple & Fennel Cured Salmon with Pickled Cucumber", 30.00));//adding a menu item to the restaurant
        restaurant3.addMenuItem(MenuItem("rime Dry-Aged Beef with a Choice of Sauces", 28.00));//adding a menu item to the restaurant

       
        Restaurant restaurant4("Paula's Place");//creating an object of the Restaurant class
        restaurant4.addMenuItem(MenuItem("1/4 Chicken & Prawns", 15.00));//adding a menu item to the restaurant
        restaurant4.addMenuItem(MenuItem("1/4 Chicken & Calamari", 14.00));//adding a menu item to the restaurant
        restaurant4.addMenuItem(MenuItem("1/4 Chicken & Hake", 13.00));//adding a menu item to the restaurant
        restaurant4.addMenuItem(MenuItem("1/4 Chicken & Ribs", 16.00));//adding a menu item to the restaurant
        restaurant4.addMenuItem(MenuItem("1/4 Chicken & Pork Chops", 14.00));//adding a menu item to the restaurant
        restaurant4.addMenuItem(MenuItem("Hake & Pork Chops", 20.00));//adding a menu item to the restaurant
        restaurant4.addMenuItem(MenuItem("Prawn & Calamari", 22.00));//adding a menu item to the restaurant
        restaurant4.addMenuItem(MenuItem("Ribs & Hake", 18.00));//adding a menu item to the restaurant

        Restaurant restaurant5("Mozambik Honeybear Greystone Park");//creating an object of the Restaurant class
        restaurant5.addMenuItem(MenuItem("1/4 Plain or spicy Moz-BBQ basting", 9.00));//adding a menu item to the restaurant
        restaurant5.addMenuItem(MenuItem("1/4 Moz Peri-Peri Dry rub", 9.00));//adding a menu item to the restaurant
        restaurant5.addMenuItem(MenuItem("1/4 Garlic, Lemon & Herb or Peri-Peri ", 10.00));//adding a menu item to the restaurant
        restaurant5.addMenuItem(MenuItem("1/4 Zambeziana coconut or Meninas sauce (no chilli)", 11.00));//adding a menu item to the restaurant
        restaurant5.addMenuItem(MenuItem("1/2 Plain or spicy Moz-BBQ basting ", 14.00));//adding a menu item to the restaurant
        restaurant5.addMenuItem(MenuItem("1/2 mMoz Peri-Peri Dry rub ", 14.00));//adding a menu item to the restaurant
        restaurant5.addMenuItem(MenuItem("1/2 Garlic, Lemon & Herb or Peri-Peri ", 15.00));//adding a menu item to the restaurant
        restaurant5.addMenuItem(MenuItem("1/2 Zambeziana coconut or Meninas sauce (no chilli) ", 16.00));//adding a menu item to the restaurant

        Restaurant restaurant6("Coimbra");//creating an object of the Restaurant class
        restaurant6.addMenuItem(MenuItem("Coimbra Prawns", 10.00));//adding a menu item to the restaurant
        restaurant6.addMenuItem(MenuItem("Grilled Sole", 10.00));//adding a menu item to the restaurant
        restaurant6.addMenuItem(MenuItem("Calamari", 10.00));//adding a menu item to the restaurant
        restaurant6.addMenuItem(MenuItem("Coimbra Chicken (Half)", 6.00));//adding a menu item to the restaurant
        restaurant6.addMenuItem(MenuItem("Grilled Pork Chops", 8.00));//adding a menu item to the restaurant
        restaurant6.addMenuItem(MenuItem("Beef Espetada", 8.00));//adding a menu item to the restaurant
        restaurant6.addMenuItem(MenuItem("Full Flame-Grilled Chicken with Piri-Piri Sauce ", 6.00));//adding a menu item to the restaurant

        Restaurant restaurant7("China Garden Zw");//creating an object of the Restaurant class
        restaurant7.addMenuItem(MenuItem("Pork slices with green chilies ", 15.00));//adding a menu item to the restaurant
        restaurant7.addMenuItem(MenuItem("Cumin flavored Lamb", 18.00));//adding a menu item to the restaurant
        restaurant7.addMenuItem(MenuItem("Braised Fish", 20.00));//adding a menu item to the restaurant
        restaurant7.addMenuItem(MenuItem("Sweet'n'Sour Chicken", 14.00));//adding a menu item to the restaurant
        restaurant7.addMenuItem(MenuItem("Crispy Chicken ", 16.00));//adding a menu item to the restaurant
        restaurant7.addMenuItem(MenuItem("Sizzling Beef Short Ribs ", 19.00));//adding a menu item to the restaurant
        restaurant7.addMenuItem(MenuItem("Steamed Rice ", 3.00));//adding a menu item to the restaurant
        restaurant7.addMenuItem(MenuItem("Vegetable Fried Noodles", 5.00));//adding a menu item to the restaurant
        restaurant7.addMenuItem(MenuItem("Pork Boiled Dumplings", 6.00));//adding a menu item to the restaurant

        Restaurant restaurant8("Queen of Hearts Cafe");//creating an object of the Restaurant class
        restaurant8.addMenuItem(MenuItem("Butter Chicken Curry ", 10.00));//adding a menu item to the restaurant
        restaurant8.addMenuItem(MenuItem("Beef Dal Gosht Curry", 12.00));//adding a menu item to the restaurant
        restaurant8.addMenuItem(MenuItem("Half Chicken (Peri Peri or Lemon & Herb or BBQ, served with chips)", 10.00));//adding a menu item to the restaurant
        restaurant8.addMenuItem(MenuItem("Char-Grilled Pork Chop (served with chips and a garden salad)", 10.00));//adding a menu item to the restaurant
        restaurant8.addMenuItem(MenuItem("Crumbed Fish (served with chips, salad, and homemade tartar sauce)", 10.00));//adding a menu item to the restaurant
        restaurant8.addMenuItem(MenuItem("Char-Grilled 350g T-Bone Steak (served with chips, rice, or mash)", 14.00));//adding a menu item to the restaurant
        restaurant8.addMenuItem(MenuItem("Grilled BBQ Pork Riblets (served with chips and slaw)", 15.00));//adding a menu item to the restaurant
        restaurant8.addMenuItem(MenuItem("Peppered Rump Steak (served with garlic mash and a garden salad)", 16.00));//adding a menu item to the restaurant
        restaurant8.addMenuItem(MenuItem("Char-Grilled Bourbon Rib Eye (marinated with bourbon sauce and served with garlic mash and salad)", 18.00));//adding a menu item to the restaurant
        restaurant8.addMenuItem(MenuItem("Supreme Surf & Turf (chargrilled sirloin steak and prawns served with mash and vegetables)", 18.00));//adding a menu item to the restaurant

        Restaurant restaurant9("Gava's");//creating an object of the Restaurant class
        restaurant9.addMenuItem(MenuItem("Beef/Pork Bones", 5.00));//adding a menu item to the restaurant
        restaurant9.addMenuItem(MenuItem("Maguru (Tripe)", 5.00));//adding a menu item to the restaurant
        restaurant9.addMenuItem(MenuItem("Chicken Stew", 6.00));//adding a menu item to the restaurant
        restaurant9.addMenuItem(MenuItem("Beef Stew ", 6.00));//adding a menu item to the restaurant
        restaurant9.addMenuItem(MenuItem("Goat Meat", 6.00));//adding a menu item to the restaurant
        restaurant9.addMenuItem(MenuItem("Liver and Kidney", 6.00));//adding a menu item to the restaurant
        restaurant9.addMenuItem(MenuItem("Huku (Chicken)", 6.00));//adding a menu item to the restaurant
        restaurant9.addMenuItem(MenuItem("Oxtail", 12.00));//adding a menu item to the restaurant
        restaurant9.addMenuItem(MenuItem("Gava’s Sampler (3 meats)", 10.00));//adding a menu item to the restaurant
        restaurant9.addMenuItem(MenuItem("Vegetarian", 12.00));//adding a menu item to the restaurant

        Restaurant restaurant10("Sabai Thai");//creating an object of the Restaurant class
        restaurant10.addMenuItem(MenuItem("Vegetable & Tofu", 12.95));//adding a menu item to the restaurant
        restaurant10.addMenuItem(MenuItem("Chicken or Pork", 14.95));//adding a menu item to the restaurant
        restaurant10.addMenuItem(MenuItem("Shrimp ", 16.95));//adding a menu item to the restaurant
        restaurant10.addMenuItem(MenuItem("Papaya Salad Som Tum", 11.95));//adding a menu item to the restaurant
        restaurant10.addMenuItem(MenuItem("Larb Salad", 14.95));//adding a menu item to the restaurant
        restaurant10.addMenuItem(MenuItem("Egg Fried Rice", 5.50));//adding a menu item to the restaurant
        restaurant10.addMenuItem(MenuItem("Sticky Rice", 2.50));//adding a menu item to the restaurant
        restaurant10.addMenuItem(MenuItem("Brown Rice", 2.50));//adding a menu item to the restaurant
        restaurant10.addMenuItem(MenuItem("Side Salad", 6.00));//adding a menu item to the restaurant
        restaurant10.addMenuItem(MenuItem("Extra Jasmine Rice", 2.50));//adding a menu item to the restaurant
        restaurant10.addMenuItem(MenuItem("Extra Sticky Rice", 2.50));//adding a menu item to the restaurant
        restaurant10.addMenuItem(MenuItem("Extra Protein (Chicken, Pork, or Shrimp)", 3.00));//adding a menu item to the restaurant

        ussd.addRestaurant(restaurant1);//adding a restaurant to the ussd
        ussd.addRestaurant(restaurant2);//adding a restaurant to the ussd
        ussd.addRestaurant(restaurant3);//adding a restaurant to the ussd
        ussd.addRestaurant(restaurant4);//adding a restaurant to the ussd
        ussd.addRestaurant(restaurant5);//adding a restaurant to the ussd
        ussd.addRestaurant(restaurant6);//adding a restaurant to the ussd
        ussd.addRestaurant(restaurant7);//adding a restaurant to the ussd
        ussd.addRestaurant(restaurant8);//adding a restaurant to the ussd
        ussd.addRestaurant(restaurant9);//adding a restaurant to the ussd
        ussd.addRestaurant(restaurant10);//adding a restaurant to the ussd

        ussd.placeOrder();//placing an order

    } 
    catch (const length_error& e) {
        cerr << "Error: " << e.what() << std::endl;  // Handle length errors (e.g., vector size exceeded)
    } 
    catch (const out_of_range& e) {
        cerr << "Error: " << e.what() << endl;  // Handle out-of-range errors
    } 
    catch (const std::exception& e) {
        cerr << "An unexpected error occurred: " << e.what() << endl;  // Handle any other exceptions
    }

return 0;//returning 0
}
