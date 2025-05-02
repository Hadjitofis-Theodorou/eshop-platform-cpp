#include<string>
#include<map>
#include "Person.h"
using namespace std;

bool registerUser(map<string,Person>&users);
bool loginUser(map<string, Person>&users);
void welcome(map<string, Person>&users);
void userswitch(Person p);