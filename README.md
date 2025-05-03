# 🛒 C++ E-Shop Platform

This project implements a fully functional **object-oriented e-commerce system** written in C++.  
It simulates an online shop where administrators manage products and customers browse, shop, and track their order history — all stored persistently in local files.

---

## 🚀 Features

👤 **User Roles**  
- Admins can:
  - Add, edit, and manage products
  - View stock levels and product statistics
- Customers can:
  - Browse products by category or search
  - Add items to their cart, adjust quantities, and complete orders
  - View their personal order history

📦 **Product Management**  
- Products categorized with subcategories  
- Stock tracked by units or weight (kg)  
- Persistent updates across sessions (file-based)

💳 **Shopping Cart System**  
- Add, remove, and adjust products in the cart  
- Calculate total cost  
- Complete orders, updating inventory

📝 **Order History**  
- Each user has an order history file (`<username>_history.txt`)  
- Follows a clear, structured format  
- Used to analyze past purchases

🎁 **(Bonus) Discount System**  
- Recognizes loyal customers  
- Applies discounts for repeated purchases or bulk buys  
- Randomly selects the best discount if multiple apply

---

## ⚙️ Build & Run

Compile the program:
```bash
make
```
Run the e-shop:
```bash
./oop24 files/categories.txt files/products.txt files/users.txt
```
Unit tests:
```bash
./unit_tests
```
## 📊 Code Highlights
🛠 Object-Oriented Design

  -  Admin, Customer, Product, Cart, DataHandler classes

  -  Clean use of inheritance, encapsulation, and polymorphism

  -  Easily extendable for new features (like more product types or payment systems)

## 💾 File-Based Persistence

  -  ser accounts and roles

  -  Product inventory

  -  Order histories

  -  Discount rules (via discounts.txt)

🧪 Testing & Quality

  -  Automated unit tests included

  -  Modular codebase for easier debugging and upgrades

## 🌱 What I Gained as a Programmer
  -  ✅ Hands-on experience with C++ object-oriented programming
  -  ✅ Designing systems with multiple interacting components
  -  ✅ Managing dynamic memory and ensuring program stability
  -  ✅ Writing maintainable, extendable code
  -  ✅ Using Git/GitHub for version control and collaboration
  -  ✅ Connecting technical code to real-world problem-solving (like shopping systems)

## 💡 Future Improvements
  -  🌐 Add a GUI or web frontend for a more interactive experience

  -  📱 Make it mobile-friendly

  -  💳 Integrate mock payment systems

  -  📊 Add analytics dashboards for admins
# 🛠 Authors
Andreas Hadjitofis & Giorgos Theodorou

Computer Science Students @ National and Kapodistrian University of Athens 

