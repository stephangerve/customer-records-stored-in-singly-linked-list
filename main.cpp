#include <iostream>
#include <fstream>
#include <sstream>
#include "Customer.h"
#include "Node.h"
#include "SinglyLL.h"

int main(){

	SinglyLL *list;
	std::ifstream inFile;
	std::ofstream outFile;
        std::string fileName = "data.txt";
        std::string currentLine;
        std::string token;
	std::string name, gender, DOB;
        std::stringstream parser;

        inFile.open(fileName);
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
		int choice = -1;
		while(choice != 0){
			std::cout << std::endl;
			std::cout << "1) Print list" << std::endl;
			std::cout << "2) Add customer to list" << std::endl;
			std::cout << "3) Remove customer from list" << std::endl;	
			std::cout << "4) Get customer information" << std::endl;	
			std::cout << "5) Check size of list" << std::endl;
			std::cout << "0) Exit program" << std::endl;
			std::cout << ": ";
			std::cin >> choice;
			if(choice == 1){
				list->printList();
				choice = -1;
			}
			else if(choice == 2){
				std::cin.ignore();
				std::cout << "Name: ";
				getline(std::cin, name);
				std::cout << "Gender: ";
				getline(std::cin, gender);
				std::cout << "DOB (mm/dd/yy): ";
				getline(std::cin, DOB);	
				list->insert(new Node(name, gender, DOB));	
				std::cout << name << " added to list." << std::endl;		
				choice = -1;
			}
			else if(choice == 3){
				list->printList();
				std::cout << "Enter the customer number: ";
				std::cin >> choice;
				if(list->exists(choice - 1) == true){
					name = list->get(choice - 1)->getCustomer()->getName();
					list->remove(choice - 1);
					std::cout << name << " successfully removed." << std::endl;
				}
				else if(list->exists(choice - 1) == false){
					std::cout << "Error removing customer." << std::endl;
				}
				choice = -1;
			}
			else if(choice == 4){
				list->printList();
				std::cout << "Enter the customer number: ";
				std::cin >> choice;
				Node* temp = list->get(choice - 1);
				temp->printData();
				choice = -1;
			}
			else if(choice == 5){
				std::cout << "List size: " << list->size() << std::endl;
				choice = -1;
			}
			else if(choice == 0){
				outFile.open(fileName);
				Node* temp;
				for(int i = 0; i < list->size(); i++){
					temp = list->get(i);
					outFile << temp->getCustomer()->getName() << ",";
					outFile << temp->getCustomer()->getGender() << ",";
					outFile << temp->getCustomer()->getDOB() << std::endl;			
				}
				outFile.close();
				delete list;
			}	
			else{
				std::cout << "Invalid choice" << std::endl;
			}
		}
	

        }
       	inFile.close();


}
