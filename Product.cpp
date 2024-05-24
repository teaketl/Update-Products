#include "Product.hpp"

Product::Product(std::string id, std::string name, float price, std::string category) : 
    id(id), name(name), price(price), category(category) {} //constructor


//getters
std::string Product::getID() const{ //just getting not changing
    return id;
}
std::string Product::getName() const{
    return name;
}
float Product::getPrice() const{
    return price;
}
std::string Product::getCategory() const{
    return category;
}
        
//setters
void Product::setID(std::string &newID){ //passes newID into id
    id = newID;
}
void Product::setName(std::string &newName){ //same thing w id repeated here and then in category
    name= newName;
}
void Product::setPrice(float newPrice){ //this what we need!! to help update price
    price = newPrice;
}
void Product::setCategory(std::string &newCategory){
    category = newCategory;
}
