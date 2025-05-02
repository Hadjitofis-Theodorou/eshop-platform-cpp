#include "../include/Product.h"
#include<iostream>

using namespace std;

Product:: Product():title(""), description(""),category(""), subcategory(""), price(0), unitOrKg(""), quantity(0){}
                    
Product::Product(string t, string d, string c, string sc, double p, string u, int q):title(t), description(d),
                    category(c), subcategory(sc), price(p), unitOrKg(u), quantity(q){}
Product::~Product(){}

void Product::printProduct(){
    cout<<"-----"<<this->title<<"-----"<<endl;
    cout<<"Description: "<<this->description<<endl;
    cout<<"Category: "<<this->category<<endl;
    cout<<"Subcategory: "<<this->subcategory<<endl;
    cout<<"Price per "<<this->unitOrKg<<": "<<this->price<<endl;
    cout<<"Total "<<this->unitOrKg<< " available: "<<this->quantity<<endl;
    cout<<endl;
} 
