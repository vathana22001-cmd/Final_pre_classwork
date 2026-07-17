#pragma once
#include <vector>
#include <string>
#include "product.hpp"

// Manager System to handle data logic
class ProductManager {
private:
    std::vector<Product> products;

public:
    void create_product(Product product);
    void display_products();
    bool is_exist(int id);
    void update_product(int id, Product updatedData);
    void delete_product(int id);
    void search_by_title(std::string target_title);
};