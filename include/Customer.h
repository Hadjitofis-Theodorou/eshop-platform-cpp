#include<string>
#include "Person.h"
#include "Product.h"
#include "Cart.h"
//subclass της Person

class Customer:public Person{
    Cart cart;
public:

    //Constructor / destructor
    Customer(const string u, const string p, const int i);
    ~ Customer();

    //συνάρτηση για το μενού του πελάτη
    void openMenu(map<string, Product>&products);

    //προσθήκη στο καλάθι
    void addToCart(map<string, Product>&products);

    //update product στο καλάθι
    void updateProductInCart(map<string, Product>&products);

    //αφαίρεση προιόντος
    void removeProductFromCart(map<string, Product>&products);

    //προβολή του καλαθιού
    void viewCustomerCart();

    //ολοκλήρωση παραγγελίας
    void finishOrder();

    //ιστορικό παραγγελιών
    void viewOrderHistory();
};