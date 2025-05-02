#pragma once
#include<string>
#include "Person.h"
#include "Product.h"


//subclass της Person
class Admin:public Person{

public:

    //Constructor/ destructor
    Admin(const string u, const string pass, const int i);
    ~ Admin();

    //συνάρτηση για το μενού διαχειριστή
    void openMenu( map<string, Product>&products);

    //συναρτήσεις για διαχείρηση προίόντων
    //προσθήκη προιόντος
    void addProduct(map<string, Product>&products);

    //διαγραφή προιόντος
    void removeProduct( map<string, Product>&products);

    //επεξεργασία προιόντος
    void editProduct( map<string, Product>&products);

    //μη-διαθέσιμα προιόντα
    void showNotAvailable(map<string, Product>products);

    //top 5 προιόντα
    void showTop5(map<string, Product>&products);
};