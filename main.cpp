#include <stdio.h>
#include <iostream>
#include <vector>
#include "FileHandler.hpp"
#include "Product.hpp"

int main()
{
    FileHandler starterFile("products.csv");
    std::vector<Product> products;
    starterFile.readInputFile(products);
    starterFile.writeFile(products);

    return 0;
}
