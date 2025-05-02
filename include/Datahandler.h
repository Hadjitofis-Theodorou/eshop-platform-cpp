#include <string>
#include <map>
#include "../include/Person.h"
void fileworking(char* args);
void handledata(char* arg1,char* arg2,char* arg3,map<string, Person>&users);
void storenewcustomer(const std::string& username, const std::string& password, int isAdmin);
void updatefile(map<string, Product>products);
string removeExtraSpaces(const string& str);
void checkTop5FromHistory(map<string, Product>&products);