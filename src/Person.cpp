#include "../include/Person.h"
#include <iostream>
#include <map>

using namespace std;

Person::Person() : username(""), password(""), isAdmin(0) {}
Person::Person(const string user, const string pass, const int i):username(user), password(pass), isAdmin(i){}
Person::~Person(){}
string Person::getUsername(){
    return username;
}
string Person::getPassword(){
    return password;
}
int Person::getIsAdmin(){
    return isAdmin;
}

void Person::searchProducts(map<string, Product>products){
    int choice;
    string t;
    string cat;
    cout<<"Select search method: "<<endl;
    cout<<"1. Serch by Title"<<endl<<"2. View products of a Category"<<endl<<"3. Show all products"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    cout<<endl;

    switch (choice)
    {
    case 1:
        cout<<"Enter product Title: ";
        cin.ignore();
        getline(cin,t);
        if(products.find(t)== products.end()){
            cout<<"Sorry, we couldn't find a product with the title: "<<t<<endl;
            return;
        }
        else{
            products[t].printProduct();
        }
        break;

    case 2:
        int num;
        cout<<"Choose a category: Tech Book Clothing Drink Food"<<endl;
        cin>>cat;
        cout<<"Do you want to choose a sub-category aswell?(1(yes)/0(no)) ";
        cin>>num;
        cout<<endl;
        
        //μόνο με category
        if(num==0){
            cout<<"Results:"<<endl;
            for(map<string, Product>::iterator iter= products.begin(); iter!=products.end();++iter){
                if(iter->second.category==cat){
                    cout<<iter->second.title<<endl;
                }
            }
        }
        //και με subcategory
        else if(num==1){
            string sub;
            if(cat=="Tech"){
                cout<<endl<<"Give one of the following subcategories: Computer Laptop Phone Tablet"<<endl;
                cin>>sub;
            }
            else if(cat=="Book"){
                cout<<endl<<"Give one of the following subcategories: Mystery Sci-fi Romance Comedy Academic Comic"<<endl;
                cin>>sub;
            }
            else if(cat=="Clothing"){
                cout<<endl<<"Give one of the following subcategories: Shirt Pant Hat Shoe"<<endl;
                cin>>sub;
            }
            else if(cat=="Food"){
                cout<<endl<<"Give one of the following subcategories: Fruit Vegetable Meat Seafood Dairy Sweet Baked"<<endl;
                cin>>sub;
            }
            else if(cat=="Drink"){
                cout<<endl<<"Give one of the following subcategories: Juice -Soft Drink- Coffee Team Dairy Alcohol"<<endl;
                cin>>sub;
            }
            cout<<endl<<"Results:"<<endl;
            for(map<string, Product>::iterator iter= products.begin(); iter!=products.end();++iter){
                if(iter->second.category==cat && iter->second.subcategory==sub){
                    cout<<iter->second.title<<endl;
                }
            }

            //από τη λίστα των products θα διαλέξει ενα
            cout<<"Enter product Title:";
            cin.ignore();
            getline(cin,t);
            products[t].printProduct();
        }
        break;
    case 3:
        cout<<"Results: "<<endl;
        for(map<string, Product>::iterator iter= products.begin(); iter!=products.end();++iter) {
            cout<<iter->second.title<<endl;
        }   
        cout<<"Enter product Title:";
        cin.ignore();
        getline(cin,t);
        products[t].printProduct();  
        break;
    
    default:
        break;
    }
}