#pragma once
#include <string>

// Product Entity
struct Product {
    int id;
    std::string title;
    std::string description;
    double price;
    int stock;
};