#include "../include/User.h"
#include<iostream>
#include"../include/Datahandler.h"
#include<string>
#include"../include/Admin.h"
#include "../include/globalfiles.h"
#include "../include/Customer.h"
using namespace std;

//Συνάρτηση για registration και εισαγωγή των νέων users στο map
bool registerUser(map<string, Person>&users){
    string name, pass;
    char admin;
    int adminnum;

    cout<<"Enter your username:";
    cin>>name;
    if(users.find(name)!= users.end()){
        cout<<"name already exists"<<endl;
        return false;
    }

    cout<<"Enter your password: ";
    cin>>pass;

    cout<<endl<<"Are you an Admin?(y for YES/ n for NO)"<<endl;
    cin>>admin;
    if(admin=='y')
    adminnum=1;
    else
    adminnum=0;

    Person p1(name,pass,adminnum);
    users[name]= p1;
    storenewcustomer(name,pass,adminnum);
    userswitch(p1);
    return true;
}

//Συνάρτηση για login του user 
bool loginUser(map<string, Person>&users){
    string name, pass;
    cout<<"Enter your username: ";
    cin>>name;
    if(users.find(name)== users.end()){
        cout<<"Incorrect Username"<<endl;
        return false;
    }
    cout<<"Enter your password: ";
    cin>>pass;
    if(users[name].getPassword()!=pass){
        cout<<"Wrong Password"<<endl;
        return false;
    }
    cout<<"Login successful!"<<endl;

    Person p1;
    p1=users[name];
    userswitch(p1);
    return true;
    
}

void welcome(map<string, Person>&users){
    cout<<"Welcome to our cyprus tradional grocery e-shop,where you shop like a local!"<<endl;
    cout<<"Login or register?"<<endl;
    string ans;
    cin>>ans;
    if( ans == "login" )
        {   
            loginUser(users);
        }
    else
        {
            registerUser(users);
        }
    


    
}
void userswitch(Person p){
   
    if(p.getIsAdmin()==1)
    {Admin a(p.getUsername(),p.getPassword(),p.getIsAdmin()); 
    a.openMenu(products);
    }
    else if(p.getIsAdmin()==0)
    {Customer a(p.getUsername(),p.getPassword(),p.getIsAdmin()); 
    a.openMenu(products);}
    return;
}
