#include "FileHandler.hpp"
#include <iostream>
#include <vector>

//constructor and destructor
FileHandler::FileHandler(const std::string &fileName) : fileName(fileName) { //takes filename
}

FileHandler::~FileHandler() { //open?! close it!!
    if (inputFile.is_open()) {
        inputFile.close();
    }
    if (outputFile.is_open()) {
        outputFile.close();
    }
}

//setterss
void FileHandler::setFileName(std::string &newFileName) {
    fileName = newFileName; //new file name
}

void FileHandler::setInputFile(std::string &fileName){
    inputFile.open(fileName); //puts file and opens it setting input file
}

void FileHandler::setOutputFile(std::string &fileName) {
    outputFile.open(fileName);
}

//getters
std::string FileHandler::getFileName() const{
    return fileName;
}

bool FileHandler::isFileOpen(){ //check if open
    if (inputFile.is_open()){
        return true;
    } else {
        return false;
    }
}

void FileHandler::openInputFile(){
    if (!isFileOpen()){ //! == not true
        inputFile.open(fileName);//if not open open
    }
}

void FileHandler::readInputFile(std::vector<Product> &products){ //read input file
    openInputFile();
    
    std::stringstream str;
	std::stringstream number;
	std::string currentLine = "";

	std::string id= ""; //set default values 
	std::string name ="";
	float price =0.0;
	std::string category="";

	bool keepGoing = true;

	while(keepGoing){
	    
		str.clear(); //reads each line and adds a delimiter 
		str.str("");
		getline(inputFile, currentLine, ',');
		str << currentLine;
		str >> id; 
	
		str.clear(); //clear each time so it can b read
		str.str("");
		std::getline(inputFile, currentLine, ',');
		str << currentLine;
		str >> name;
		
		number.clear();
		number.str("");
		std::getline(inputFile, currentLine, ',');
		number << currentLine;
		number >> price; //could potentially change to a string

		str.clear();
		str.str("");
		std::getline(inputFile, currentLine); //so no , at the end
		str << currentLine;
		str >> category;
		
		std::cout << id << " " << name << " " << price << " " << category << std::endl; //output everything
		
		products.emplace_back(id,name,price,category); //put in products

		if(inputFile.eof()){
		    inputFile.close();
			keepGoing = false; //done reading
		}
	}
}

void FileHandler::writeFile(std::vector<Product> &products) { //pass in values
    outputFile.open("updated_" + fileName); // update file name to be clear
    
    //user input to update file
    std::string chosenCategory;
    float percentChange;
    
    std::cout << "Enter a category: "<< std::endl;
    std::cin >> chosenCategory;
    std::cout << "Enter a percentage: "<< std::endl;
    std::cin >> percentChange;
        
    for (Product &product: products) {
        if (product.getCategory() == chosenCategory) { 
            float finalPrice = product.getPrice() * (1 + (percentChange/100)); //-10 = negative change 10= pos change
            product.setPrice(finalPrice); //set final price then can be gotten w getter
        }
    }
    
    // write to new file w updated price getter 
    for (const Product &product : products) {
        outputFile << product.getID() << "," << product.getName() << "," << product.getPrice() << "," << product.getCategory() << std::endl;
    }

    outputFile.close();
}
