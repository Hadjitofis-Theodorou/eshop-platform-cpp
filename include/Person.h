#include <string>
#include "Product.h"
#pragma once

using namespace std;

//Κλαση για άτομα (admin/users)
class Person{

    string username;
    string password;
    int isAdmin;

public :
    //Constructor/destructor
    Person();
    Person(const string user, const string pass, const int i);
    ~ Person();

    // Getters
    string getUsername();
    string getPassword();
    int getIsAdmin();

    //κοινές συναρτήσεις Admin και Customer για τα Products
    //αναζήτηση προιόντος
    void searchProducts(map<string, Product>products);
};
