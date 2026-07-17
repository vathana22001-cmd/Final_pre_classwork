#include <iostream>
#include <string>
#include "productManager.hpp"

using namespace std;

int main() {

    system("cls"); 
    ProductManager manager;
    int next_id = 1;

    while (true) {
        cout << "\n======== [[ Product Management System ]] ========" << endl;
        cout << "1. Add product" << endl;
        cout << "2. Update product by ID" << endl;
        cout << "3. Delete product by ID" << endl;
        cout << "4. Display all products" << endl;
        cout << "5. Search product by title" << endl;
        cout << "0. Exit program" << endl;

        int option;
        cout << "[-] Choose an option: ";
        cin >> option;
        
        if (option == 0) {
            cout << "Exiting....\n";
            return 0;
        }

        switch (option) {
            case 1: {
                int id = next_id++;
                string title, description;
                double price;
                int stock;

                cin.ignore();
                cout << "[+] Input product title: ";
                getline(cin, title);

                cout << "[+] Input product description: ";
                getline(cin, description);

                cout << "[+] Input product price ($): ";
                cin >> price;

                cout << "[+] Input product stock count: ";
                cin >> stock;

                manager.create_product({id, title, description, price, stock});
                break;
            }
            case 2: {
                int id;
                cout << "Enter product ID to update: ";
                cin >> id;

                if (manager.is_exist(id)) {
                    string new_title, new_description;
                    double new_price;
                    int new_stock;

                    cin.ignore();
                    cout << "Enter new title: ";
                    getline(cin, new_title);
                    cout << "Enter new description: ";
                    getline(cin, new_description);
                    cout << "Enter new price ($): ";
                    cin >> new_price;
                    cout << "Enter new stock count: ";
                    cin >> new_stock;

                    Product updatedProduct = {id, new_title, new_description, new_price, new_stock};
                    manager.update_product(id, updatedProduct);
                } else {
                    cout << "[!] Product ID not found." << endl;
                }
                break;
            }   
            case 3: {
                int id;
                cout << "Enter product ID to delete: ";
                cin >> id;

                if (manager.is_exist(id)) {
                    manager.delete_product(id);
                } else {
                    cout << "[!] Product ID not found." << endl;
                }
                break;
            }
            case 4: {
                manager.display_products();
                break;
            }
            case 5: {
                string title;
                cin.ignore(); 
                cout << "Enter search title : ";
                getline(cin, title);
                manager.search_by_title(title);
                break;
            } 
            default: {
                cout << "Invalid option!" << endl;
                cout << "Try again!" << endl;
            }       
        }
    }
}