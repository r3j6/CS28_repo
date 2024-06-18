#include <iostream>
#include "ProductInventory.h"

using namespace std;

int main() {
    string name, brand, description, category, size, color, material, model, techSpec;
    double price;
    int quantity, warranty;

	cout << "Products_Clothing/Electronics\n";
    cout << "Programmed by: Renz Jaepril Mongaya\n";
    cout << "K-1L\n";
    cout << "===============================================\n\n";
    
    string productType;
    cout << "Enter product type (Enter Clothing/Electronics): ";
    getline(cin, productType);

    if (productType == "Clothing" || productType == "clothing") {
        // Create instance for Clothing
        cout << "Enter details for Clothing item:\n";
        cout << "Name: ";
        getline(cin, name);
        cout << "Brand: ";
        getline(cin, brand);
        cout << "Price: ";
        cin >> price;
        cout << "Quantity: ";
        cin >> quantity;
        cin.ignore();
        cout << "Description: ";
        getline(cin, description);
        category = "Clothing";
        cout << "Size: ";
        getline(cin, size);
        cout << "Color: ";
        getline(cin, color);
        cout << "Material: ";
        getline(cin, material);

        Clothing clothingItem(name, brand, price, quantity, description, category, size, color, material);

        // Print details of the clothing item
        cout << "\nClothing Item Details:\n";
        clothingItem.printDetails();
    } 
    else if (productType == "Electronics" || productType == "electronics") {
        // Create instance for Electronics
        cout << "Enter details for Electronics item:\n";
        cout << "Name: ";
        getline(cin, name);
        cout << "Brand: ";
        getline(cin, brand);
        cout << "Price: ";
        cin >> price;
        cout << "Quantity: ";
        cin >> quantity;
        cin.ignore(); 
        cout << "Description: ";
        getline(cin, description);
        category = "Electronics";
        cout << "Model: ";
        getline(cin, model);
        cout << "Warranty (in months): ";
        cin >> warranty;
        cin.ignore(); 
        cout << "Technical Specifications: ";
        getline(cin, techSpec);

        Electronics electronicsItem(name, brand, price, quantity, description, category, model, warranty, techSpec);

        // Print details of the electronics item
        cout << "\nElectronics Item Details:\n";
        electronicsItem.printDetails();
    } 
    else {
        cout << "Invalid product type entered." << endl;
    }

    return 0;
}

