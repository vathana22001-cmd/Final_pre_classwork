#include "productManager.hpp"
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

void ProductManager::create_product(Product product) {
    products.push_back(product);
    cout << "Product added successfully" << endl;
}

void ProductManager::display_products() {
    if (products.empty()) {
        cout << "[!] Inventory is empty." << endl;
        return;
    }
    cout << left << setw(5) << "ID"
         << setw(25) << "Title"
         << setw(35) << "Description"
         << setw(10) << "Price"
         << setw(8)  << "Stock" << endl;
    cout << string(83, '-') << endl;

    for (size_t i = 0; i < products.size(); i++) {
        cout << left << setw(5) << products.at(i).id
             << setw(25) << products.at(i).title
             << setw(35) << products.at(i).description
             << "$" << fixed << setprecision(2) << setw(9) << products.at(i).price
             << setw(8)  << products.at(i).stock << endl;
    }
}

bool ProductManager::is_exist(int id) {
    for (size_t i = 0; i < products.size(); i++) {
        if (products.at(i).id == id) {
            return true;
        }
    }
    return false;
}

void ProductManager::update_product(int id, Product updatedData) {
    for (size_t i = 0; i < products.size(); i++) {
        if (products.at(i).id == id) {
            products.at(i).title = updatedData.title;
            products.at(i).description = updatedData.description;
            products.at(i).price = updatedData.price;
            products.at(i).stock = updatedData.stock;
            cout << "Product updated successfully" << endl;
            break;
        }
    }
}

void ProductManager::delete_product(int id) {
    for (size_t i = 0; i < products.size(); i++) {
        if (products.at(i).id == id) {
            products.erase(products.begin() + i);
            cout << "Product deleted successfully" << endl;
            break;
        }
    }
}

void ProductManager::search_by_title(string target_title) {
    cout << left << setw(5) << "ID"
         << setw(25) << "Title"
         << setw(35) << "Description"
         << setw(10) << "Price"
         << setw(8)  << "Stock" << endl;
    cout << string(83, '-') << endl;
    
    bool found = false;
    for (size_t i = 0; i < products.size(); i++) {
        string current_title = products.at(i).title;

        auto it = search(
            current_title.begin(), current_title.end(),
            target_title.begin(), target_title.end(),
            [](unsigned char ch1, unsigned char ch2) {
                return tolower(ch1) == tolower(ch2);
            }
        );

        if (it != current_title.end()) {
            found = true;
            cout << left << setw(5) << products.at(i).id
                 << setw(25) << products.at(i).title
                 << setw(35) << products.at(i).description
                 << "$" << fixed << setprecision(2) << setw(9) << products.at(i).price
                 << setw(8)  << products.at(i).stock << endl; 
        }
    }

    if (!found) {
        cout << "[!] No products matched your query." << endl;
    }
}