#pragma once
#include<string>
#include<map>
using namespace std;

//κλάση Product για τα προιόντα
class Product{
public:
    string title;
    string description;
    string category;
    string subcategory;
    double price;
    string unitOrKg;
    int quantity;

    int timesOrdered=0;

    public:

    //constructor / destructor
    Product();
    Product(string t, string d, string c, string sc, double p, string u, int q);
    ~Product();
    
    //print product
    void printProduct();

    //φίλες κλάσεις για να έχουν access private του Product
    friend class Person;
    friend class Admin;
    friend class Customer;
    friend class CartItem;
    friend class Cart;
};
