#include "../include/Cart.h"
#include<string>
#include<iostream>
#include<fstream>

using namespace std;

CartItem::CartItem(const Product p, int q): product(p), quantityInCart(q){}
CartItem::~CartItem(){}
double CartItem::getPrice(){
    return this->product.price * this->quantityInCart;
}


void Cart::addItem(CartItem item){

    //ελέγχουμε αν είναι ηδη μέσα στο καλάθι και αν είναι προσθέτουμε το quantity
    for(auto& i : items){
        if(i.product.title==item.product.title){
            i.quantityInCart+= item.quantityInCart;
            totalPrice+= item.getPrice();
            return;
        }
    }

    //αν δεν είναι το προσθέτουμε στο καλάθι
    items.push_back(item);
    totalPrice += item.getPrice();
}

void Cart::updateItem(string p, int q, map<string, Product>&products){
    for(auto iter= items.begin(); iter!= items.end(); ++iter){
        if(iter->product.title==p){
            //αν το νέο quantity είναι 0 απλα αφαιρούμε το product
            if(q==0){
                removeItem(p,products);
                return;
            }

            int currentQuantityInCart=iter->quantityInCart;
            int difference= q-currentQuantityInCart;

            //κάνουμε update το stock και το cart
            products[p].quantity-=difference;
            iter->quantityInCart=q;
            totalPrice+=difference* iter->product.price;

            cout<<"Updated "<<p<<" to "<<q<<" "<<products[p].unitOrKg<<endl;
            return;
        }
    }
    cout<<"Product not fount in cart"<<endl;
}

void Cart::removeItem(string p, map<string, Product>&products){
    for(auto iter = items.begin(); iter != items.end(); ++iter){
        if(iter->product.title==p){
            int qInCart=iter->quantityInCart;
            double itemPrice=iter->getPrice();

            //νέο ποσό καλαθιού
            totalPrice-= itemPrice;

            //νεα ποσότητα προιόντος σε stock αφου τα βγάλαμε από το καλάθι
            products[p].quantity+=qInCart;

            items.erase(iter);
            cout<<"Item removed from cart successfully!"<<endl;
            return;
        }
    }
    cout<<"Product not found in cart."<<endl;
}

void Cart::viewCart(){
    cout<<"---CART START---"<<endl;
    for(auto iter = items.begin(); iter != items.end(); ++iter){
        cout<<iter->quantityInCart<<" "<<iter->product.title<<endl;
    }
    cout<<"---CART END---"<<endl;
    cout<<"Total Cost: "<<totalPrice<<endl;
}

void Cart::writeCartInHistory(string name){
    string filename="files/order_history/"+name+"_history.txt";
    ofstream historyFile(filename, ios::app);

    if (!historyFile) {
        cerr << "Error: Unable to open file " << filename << " for writing."<<endl;
        return;
    }
    cartNum++;
    historyFile<<"---CART "<<cartNum<<" START---"<<endl;

    for(auto iter = items.begin(); iter != items.end(); ++iter){
        historyFile<<iter->quantityInCart<<" "<<iter->product.title<<endl;
    }
    historyFile<<"---CART "<<cartNum<<" END---"<<endl;
    historyFile<<"Total Cost: "<<totalPrice<<endl<<endl;

    historyFile.close();
    cout<<"Your order has been completed!"<<endl;

    //το καλάθι αδειάζει
    items.clear();
    totalPrice=0;
}




