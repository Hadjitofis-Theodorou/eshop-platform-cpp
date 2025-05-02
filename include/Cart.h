#pragma once
#include "Product.h"
#include<vector>

using namespace std;

//κλάση για τα products που ειναι ΜΕΣΑ στο καλάθι
class CartItem{ 

    Product product;
    int quantityInCart;

    public :

    CartItem(const Product p, int q);
    ~ CartItem();

    //συνολικό ποσό κάθε item ανάλογα με την ποσότητα του στο καλάθι
    double getPrice();
    friend class Cart;
};

//κλάση για το καλάθι
class Cart{

    vector<CartItem>items;
    double totalPrice=0;
    int cartNum=0;
    public :

    //οι συναρτήσεις αυτές είναι για τον χειρισμο των Cart Items μέσα στο cart
    //για να είναι πιο καθαρός ο κώδικας στις συναρτήσεις του customer
    void addItem(CartItem item);
    void updateItem(string p,int q, map<string, Product>&products);
    void removeItem(string p, map<string, Product>&products);
    void viewCart();
    void writeCartInHistory(string name);
    friend class Customer;

};