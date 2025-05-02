#include "../include/Customer.h"
#include "../include/Datahandler.h"
#include<iostream>
#include<fstream>

using namespace std;

Customer::Customer(string username, string pass, int i) : Person(username, pass, i) {}
Customer:: ~Customer(){}

void Customer::openMenu(map<string,Product>&products){
    int choice;
    cout<<"Welcome "<<this->getUsername()<<"!"<<endl;
    cout<<"---Customer Menu---"<<endl<<"How would you like to proceed?"<<endl;
    cout<<"1. Search product"<<endl<<"2. Add product to cart"<<endl<<"3. Update product from cart"<<endl<<"4. Remove product from cart"<<endl;
    cout<<"5. Complete order"<<endl<<"6. View order history"<<endl<<"7. View cart"<<endl<<"8.EXIT"<<endl;
    cout<<"Enter your choice: ";
    //cin.ignore();
    cin>>choice;
    switch (choice)
    {
    case 1:
        searchProducts(products);
        break;
    case 2:
        addToCart(products);
        break;
    case 3:
        updateProductInCart(products);
        break;
    case 4:
        removeProductFromCart(products);
        break;
    case 5:
        finishOrder();
        break;
    case 6:
        viewOrderHistory();
        break;
    case 7:
        viewCustomerCart();
        break;
    case 8:
        return;
    default:
        break;
    }
    updatefile(products);
    openMenu(products);
}

void Customer::addToCart(map<string, Product>&products){
    string p;
    int q;
    cout<<endl<<"Which product would you like to add? : ";
    cin.ignore();
    getline(cin,p);
 
    if (products.find(p) == products.end()) {
        cout << "Product not found! "<<endl;
        return;
    }
    cout<<"Enter quantity: ";
    cin>>q;

    if(products[p].quantity>=q){
        auto iter=products.find(p);
        CartItem newItem(iter->second,q);
        cart.addItem(newItem);
        products[p].quantity -= q;
        cout<<"Product added successfully!"<<endl;
    }
    else{
        cout<<"We only have "<<products[p].quantity<<" left!"<<endl;
        return;
    }
}


//not sure need to check again
void Customer:: updateProductInCart(map<string, Product>&products){
    int q;
    string p;
    cout<<"Which product do you want to update? : ";
    cin.ignore();
    getline(cin,p);

    if (products.find(p) == products.end()) {
        cout << "Product not found!"<<endl;
        return;
    }
    cout<<"Enter new quantity: ";
    cin>>q;

    if(products[p].quantity>=q){
        cart.updateItem(p,q,products);
    }
    else{
        cout<<"We only have "<<products[p].quantity<<" left!"<<endl;
        return;
    }
}

void Customer::removeProductFromCart(map<string, Product>&products){
    string p;
    cout<<"Which product would you like to remove? : ";
    cin>>p;

    if (products.find(p) == products.end()) {
        cout << "Product not found!"<<endl;
        return;
    }
    cart.removeItem(p, products);

}

void Customer::viewCustomerCart(){
    cart.viewCart();
}

void Customer::finishOrder(){
    cart.writeCartInHistory(this->getUsername());
}

void Customer::viewOrderHistory(){
    string filename="files/order_history/"+this->getUsername()+"_history.txt";
    ifstream historyFile(filename);

    if (!historyFile) {
        cerr << "No order history found for " <<this->getUsername()<< endl;
        return;
    }
    cout<<this->getUsername()<<" Your order history:"<<endl;
    string line;
    cin.ignore();
    while(getline(historyFile,line)){
        cout<<line<<endl;
    }
    historyFile.close();
}