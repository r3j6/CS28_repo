#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>

using namespace std;

// Base class representing a general product
class Product {
protected:
    string name;        
    string brand;       
    double price;       
    int quantity;       
    string description; 
    string category;    

public:
    // Constructor to initialize all the attributes
    Product(const string& name, const string& brand, double price, int quantity, const string& description, const string& category)
        : name(name), brand(brand), price(price), quantity(quantity), description(description), category(category) {}

    // Function to print the details of the product
    virtual void printDetails() const {
        cout << "Name: " << name << "\n"
             << "Brand: " << brand << "\n"
             << "Price: " << price << "\n"
             << "Quantity: " << quantity << "\n"
             << "Description: " << description << "\n"
             << "Category: " << category << "\n";
    }
};

// Derived class representing a clothing item
class Clothing : public Product {
private:
    string size;       
    string color;      
    string material;   

public:
    // Constructor to initialize all the attributes, including base class attributes
    Clothing(const string& name, const string& brand, double price, int quantity, const string& description, const string& category, const string& size, const string& color, const string& material)
        : Product(name, brand, price, quantity, description, category), size(size), color(color), material(material) {}

    // Override the printDetails function to include clothing-specific details
    void printDetails() const override {
        Product::printDetails(); // Call the base class printDetails() function
        cout << "Size: " << size << "\n"
             << "Color: " << color << "\n"
             << "Material: " << material << "\n";
    }
};

// Derived class representing an electronic item
class Electronics : public Product {
private:
    string model;       // Model of the electronic item
    int warranty;       // Warranty period of the electronic item (in months)
    string techSpec;    // Technical specifications of the electronic item

public:
    // Constructor to initialize all the attributes, including base class attributes
    Electronics(const string& name, const string& brand, double price, int quantity, const string& description, const string& category, const string& model, int warranty, const string& techSpec)
        : Product(name, brand, price, quantity, description, category), model(model), warranty(warranty), techSpec(techSpec) {}

    // Override the printDetails function to include electronics-specific details
    void printDetails() const override {
        Product::printDetails(); // Call the base class printDetails() function
        cout << "Model: " << model << "\n"
             << "Warranty: " << warranty << " months\n"
             << "Technical Specifications: " << techSpec << "\n";
    }
};

#endif // PRODUCT_H

