#include "../include/Admin.h"
#include "../include/Datahandler.h"
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
Admin::Admin(string username, string pass, int i) : Person(username, pass, i) {}
Admin::~Admin(){}

void Admin:: openMenu( map<string, Product>&products){
       int choice;
       cout<<"Welcome "<<this->getUsername()<<"!"<<endl;
       cout<<"---Admin Menu---"<<endl<<"How would you like to proceed?"<<endl;
       cout<<"1. Add Product"<<endl<<"2. Edit Product"<<endl<<"3. Remove Product"<<endl<<"4. Search Product"<<endl;
       cout<<"5. Show Unavailable Products"<<endl<<"6. Show Top5 Products"<<endl<<"7. EXIT"<<endl;
       cout<<"Enter your choice: ";

       cin>>choice;
       cout<<endl;

       switch (choice)
       {
       case 1:
              addProduct(products);
              break;
       case 2:
              editProduct(products);
              break;
       case 3:
              removeProduct(products);
              break;
       case 4:
              searchProducts(products);
              break;
       case 5:
              showNotAvailable(products);
              break;
       case 6:
              showTop5(products);
              break;
       case 7:
              return;       
       default:
              break;
       }
       updatefile(products);
       openMenu(products);
}

void Admin:: addProduct( map<string, Product>&products){
       cin.ignore();
       Product p1;
       cout<<"Give product title:";
       getline(cin,p1.title);

       //έλεγχος αν υπάρχει ήδη το product
       if (products.find(p1.title)!= products.end()){
              cout<<"Product already exists"<<endl;
              return;
       }
       
       //παίρνουμε τα στοιχεία του product
       cout<<endl<<"Give product description: ";
       getline(cin,p1.description);
       
       cout<<endl<<"Give one of the following categories: Tech Book Clothing Drink Food"<<endl;
       cin>>p1.category;

       if(p1.category=="Tech"){
              cout<<endl<<"Give one of the following subcategories: Computer Laptop Phone Tablet"<<endl;
              cin>>p1.subcategory;
       }
       else if(p1.category=="Book"){
              cout<<endl<<"Give one of the following subcategories: Mystery Sci-fi Romance Comedy Academic Comic"<<endl;
              cin>>p1.subcategory;
       }
       else if(p1.category=="Clothing"){
              cout<<endl<<"Give one of the following subcategories: Shirt Pant Hat Shoe"<<endl;
              cin>>p1.subcategory;
       }
       else if(p1.category=="Food"){
              cout<<endl<<"Give one of the following subcategories: Fruit Vegetable Meat Seafood Dairy Sweet Baked"<<endl;
              cin>>p1.subcategory;
       }
       else if(p1.category=="Drink"){
              cout<<endl<<"Give one of the following subcategories: Juice -Soft Drink- Coffee Tea Dairy Alcohol"<<endl;
              cin>>p1.subcategory;
       }

       cout<<endl<<"Give product price: $";
       cin>>p1.price;

       cout<<endl<<"Give measurement type[Kg/Unit]: ";
       cin>>p1.unitOrKg;
       if(p1.unitOrKg== "Unit"){
              cout<<endl<<"Give units: ";
              cin>>p1.quantity;
       }
       else if(p1.unitOrKg== "Kg"){
              cout<<endl<<"Give Kg: ";
              cin>>p1.quantity;
       }

       //προσθέτουμε το νέο product στο map
       auto res= products.insert({p1.title, p1});
       if (res.second){
              cout<<"Product added succesfully"<<endl;
       }     
}

void Admin:: removeProduct( map<string, Product>&products){
       string p;
       cout<<"Enter the product you want to remove: ";
       cin>>p;
       cout<<endl;

       if(products.find(p)== products.end()){
              cout<<"No product with the name: "<<p<<"exists."<<endl;
              return;
       }

       products.erase(p);
       cout<<"Product Removed Successfuly!"<<endl;
}

void Admin:: editProduct( map<string, Product>&products){
       string p;
       cout<<"Enter the product you want to edit: ";
       cin.ignore();
       getline(cin,p);
       cout<<endl;
       
       if(products.find(p)== products.end()){
              cout<<"No product with the name: "<<p<<" exists."<<endl;
              return;
       }

       int choice;
       cout<<"Enter the # of the field you want to change: 1.Title 2.Description 3.Category and Subcategory 4.Price 5.Availability 6.Nothing ";
       cin>>choice;

       switch (choice)
       {
       case 1:
              cout<<endl<<"Enter new title: ";
              cin.ignore();
              getline(cin,products[p].title);
              cout<<endl<<"Product title changed successfully!"<<endl;
              break;

       case 2:
              cout<<endl<<"Enter new description: ";
              cin.ignore();
              getline(cin,products[p].description);
              cout<<endl<<"Product description changed successfully!"<<endl;
              break;              

       case 3:
              cout<<endl<<"Enter new category: Tech Book Clothing Drink Food";
              cin>>products[p].category;
              if(products[p].category=="Tech"){
                     cout<<endl<<"Give one of the following subcategories: Computer Laptop Phone Tablet";
                     cin>>products[p].subcategory;
              }
              else if(products[p].category=="Book"){
                     cout<<endl<<"Give one of the following subcategories: Mystery Sci-fi Romance Comedy Academic Comic";
                     cin>>products[p].subcategory;
              }
              else if(products[p].category=="Clothing"){
                     cout<<endl<<"Give one of the following subcategories: Shirt Pant Hat Shoe";
                     cin>>products[p].subcategory;
              }
              else if(products[p].category=="Food"){
                     cout<<endl<<"Give one of the following subcategories: Fruit Vegetable Meat Seafood Dairy Sweet Baked";
                     cin>>products[p].subcategory;
              }
              else if(products[p].category=="Drink"){
                     cout<<endl<<"Give one of the following subcategories: Juice -Soft Drink- Coffee Tea Dairy Alcohol";
                     cin>>products[p].subcategory;
              }
              cout<<endl<<"Product category and subcategory changed successfully!"<<endl;
              break;
       case 4:
              cout<<endl<<"Enter new price: ";
              cin>>products[p].price;
              cout<<endl<<"Product price changed successfully!"<<endl;
              break;              
       case 5:
              if(products[p].unitOrKg=="Unit"){
                     cout<<endl<<"Enter number of available Units ";
                     cin>>products[p].quantity;
                     cout<<endl<<"Availability changed successfully!"<<endl;
              }
              if(products[p].unitOrKg=="Kg"){
                     cout<<endl<<"Enter number of available Kg ";
                     cin>>products[p].quantity;
                     cout<<endl<<"Availability changed successfully!"<<endl;
              }              
       case 6:
              return;
              break;                     
       default:
              break;
       }       

}

void Admin:: showNotAvailable(map<string, Product>products){
       cout<<"Unavailable Products: "<<endl;
       int i=0;
       for(map<string, Product>::iterator iter= products.begin(); iter!=products.end();++iter){
              if(iter->second.quantity==0){
                     i++;
                     cout<<i<<". "<<iter->second.title<<endl;
              }
       }
       if(i==0){
              cout<<"All products are available!"<<endl;
       }
}

void Admin::showTop5(map<string, Product>&products){
       checkTop5FromHistory(products);

       //Δημιουργούμε vector με τα products ώστε να μπορέσουμε να το κάνουμε sort με βάση το timesOrdered
       vector<pair<string, Product>> productVector(products.begin(), products.end());

       
       sort(productVector.begin(), productVector.end(), [](const auto &a, const auto &b) 
              {return a.second.timesOrdered > b.second.timesOrdered;}
       );

       cout<<"TOP 5 ΠΡΟΙΟΝΤΑ: "<<endl;

       int counter=0;
       for (const auto &p : productVector) {
              if (counter++ == 5) break;
              cout << "Product: " << p.second.title << ", Times Ordered: " << p.second.timesOrdered <<endl;
       }
}
