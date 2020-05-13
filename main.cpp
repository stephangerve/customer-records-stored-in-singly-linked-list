#include <iostream>
#include <fstream>
#include <sstream>
#include "Customer.h"
#include "Node.h"
#include "SinglyLL.h"

int main(){

	SinglyLL *list;
	std::ifstream inFile;
        std::string textfileName = "data.txt";
        std::string currentLine;
        std::string token;
	std::string name, gender, DOB;
        std::stringstream parser;

        inFile.open(textfileName);
        if(inFile.is_open() == false){
                std::cout << "File doesn't exists";

        }
        else if(inFile.is_open() == true){
                std::cout << "data.txt has been opened." << std::endl;
                list = new SinglyLL();
		while(getline(inFile, currentLine)){
                        parser.clear();
                        parser.str("");
                        parser.str(currentLine);
                        getline(parser, token, ',');
                        name = token;
                        getline(parser, token, ',');
                        gender = token;
			getline(parser, token, ',');
                        DOB = token;
			list->insert(new Node(name, gender, DOB));

                }
		list->printList();
		delete list;
		inFile.close();


        }
       


}
