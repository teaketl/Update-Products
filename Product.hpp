#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>

class Product {
    private:
        std::string id;
        std::string name;
        float price; //perhaps change to string but float might be easier to update
        std::string category;
    public:
        Product(std::string id, std::string name, float price, std::string category); //constructor
        
        //getters
        std::string getID() const; //just getting not changing
        std::string getName() const;
        float getPrice() const;
        std::string getCategory() const;
        
        //setters
        void setID(std::string &newID);
        void setName(std::string &newName);
        void setPrice(float newPrice); //this what we need!! update price
        void setCategory(std::string &newCategory); 
        
};
#endif
