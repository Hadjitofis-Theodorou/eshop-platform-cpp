#include<iostream>
#include<iomanip>
#include<map>
#include<sstream>
#include<string>
#include<fstream>
#include<filesystem>
#include"../include/Person.h"
#include"../include/globalfiles.h"
#include"../include/Product.h"

using namespace std;
void fileworking(string args){
        ifstream inputFile(args); // Open the file
        if (!inputFile) {
            cerr << "Error: Unable to open file " << args << endl;
        
        }}

void handledata(char* arg1,char* arg2,char* arg3,map<string, Person>&users){
    
    categoriesFile=arg1;
    productsFile=arg2;
    usersFile=arg3;
//fills the user map with the users data
    fileworking(usersFile);
        string line;
 ifstream inputFile(usersFile);
 while (getline(inputFile, line)) {
        string username, password;
        int isAdminInt;
        stringstream ss(line); 

        
        if (getline(ss, username, ',') && getline(ss, password, ',') && ss >> isAdminInt) {
            
            users[username] = Person(username, password, isAdminInt);
        }
    }
    
    inputFile.close();

//fills the products map
    fileworking(productsFile);
 ifstream inputFile2(productsFile);
while (getline(inputFile2, line)) {
string title, description, category, subcategory, unitOrKg, priceStr, quantityStr;
    double price = 0.0;
    int quantity = 0;

    stringstream ss(line);  
    
    if (getline(ss, title, '@') && getline(ss, description, '@') &&
        getline(ss, category, '@') && getline(ss, subcategory, '@') &&
        getline(ss, priceStr, '@') && getline(ss, unitOrKg, '@') &&
        getline(ss, quantityStr, '@')) {
            title=removeExtraSpaces(title);
            description=removeExtraSpaces(description);
            category=removeExtraSpaces(category);
            subcategory=removeExtraSpaces(subcategory);
            unitOrKg=removeExtraSpaces(unitOrKg);
        
        
            price = stod(priceStr);  
            quantity = stoi(quantityStr);  
      
        
        products[title] = Product(title, description, category, subcategory, price, unitOrKg, quantity);
    } else {
        cerr << "Warning: Skipping malformed line: " << line << endl;
    }
}

inputFile2.close(); 
}

void storenewcustomer(const string& username, const string& password, int isAdmin) {
    fstream fileStream(usersFile, ios::in | ios::out | ios::ate); 
    fileworking(usersFile);

    // Check if the file ends with a newline
    fileStream.seekg(-1, ios::end); // Move to the last character in the file
    char lastChar;
    fileStream.get(lastChar); // Read the last character

    if (lastChar != '\n') {
        // If the last character is not a newline, add one
        fileStream.clear(); // Clear EOF flag
        fileStream.seekp(0, ios::end); // Move to the end of the file for writing
        fileStream << '\n';
    }

    // Write the new customer's data
    fileStream << username << "," << password << "," << isAdmin << endl;
    cout << "Thanks for signing up! You are automatically logged-in as " << username << endl;

    fileStream.close();
}
void updatefile(map<string, Product>products){
    fileworking(productsFile);
    ofstream inputFile(productsFile);
     for (const auto& [key, product] : products) {
        inputFile << product.title << " @ " 
             << product.description << " @ " 
             << product.category << " @ " 
             << product.subcategory << " @ " 
             <<fixed<< setprecision(2)<< product.price<< " @ " 
             << product.unitOrKg << " @ " 
             << product.quantity << "\n";
    }

    inputFile.close(); // Close the file after writing
}
string removeExtraSpaces(const string& str) {
    string result;
    bool inWord = false;  

    for (size_t i = 0; i < str.length(); ++i) {
        if (!isspace(str[i])) {  
            result += str[i];    
            inWord = true;       
        } else if (inWord) {     
            result += ' ';       
            inWord = false;      
        }
    }


    if (!result.empty() && result.back() == ' ') {
        result.pop_back();
    }

    return result;
}

void checkTop5FromHistory(map<string, Product>&products){
    string folderPath = "files/order_history/";  

    //κάνουμε Include την filesystem για κάνουμε navigate μέσα στα directories μας
    for (const auto& entry : filesystem::directory_iterator(folderPath)) {
        ifstream historyFile(entry.path());
        if (!historyFile.is_open()) {
            cerr << "Failed to open file: " << entry.path() << endl;
            continue;
        }

        string line, productTitle;
        int quantity = 0;
        bool insideCart = false;

        while (getline(historyFile, line)) {
            if (line.find("---CART") != string::npos) {
                insideCart = (line.find("START") != string::npos);
                continue;
            }
            if (insideCart) {
                istringstream iss(line);
                iss >> quantity;
                getline(iss, productTitle);
                productTitle = removeExtraSpaces(productTitle);

                if (!productTitle.empty() && products.find(productTitle) != products.end()) {
                    products[productTitle].timesOrdered += quantity; // Update orders count
                }
            }
        }
        historyFile.close();
    }
}
