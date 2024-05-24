#ifndef FILEHANDLER_HPP
#define FILEHANDLER_HPP

#include <fstream> //for reading and writing
#include <sstream> //string stream
#include <string>
#include <vector>
#include "Product.hpp"


class FileHandler {
    private:
        std::string fileName; //takes file name ie product.csv
        std::ifstream inputFile;
        std::ofstream outputFile;
        
    public:
        FileHandler(const std::string &fileName); //constructor
        ~FileHandler(); //destructor (gets rid of whatevers in file)
        
        //getters
        std::string getFileName() const;
        std::ifstream &getInputFile(); //pull whats in address
        std::ofstream &getOutputFile();
        
        //setters
        void setFileName(std::string &newFileName); 
        void setInputFile(std::string &fileName);
        void setOutputFile(std::string &fileName);
        
        //extra methods
        bool isFileOpen(); //check if file is open if not open file (done in openFIle)
        void openInputFile(); //open file but only if not open already
        void readInputFile(std::vector<Product> &products); //read file return all contents as string
        void writeFile(std::vector<Product> &products); //needs to take contents of og file and write and update to new file
        
    
};
#endif
