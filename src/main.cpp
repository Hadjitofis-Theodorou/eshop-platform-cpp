#include<iostream>
#include<string>
#include<map>
#include "../include/Admin.h"
#include "../include/Customer.h"
#include "../include/Datahandler.h"
#include "../include/User.h"
#include "../include/Product.h"
#include "../include/globalfiles.h"

using namespace std;

int main(int argc, char* argv[]){
if(argc!=4){
    cout<<"wrong input,run again!"<<endl;
    return 0;
}

handledata(argv[1], argv[2], argv[3], users);
welcome(users);
}

