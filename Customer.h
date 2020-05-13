#ifndef CUSTOMER_H_EXISTS
#define CUSTOMER_H_EXISTS

#include <iostream>

class Customer{
	private:
		std::string name;
		std::string gender;
		std::string DOB;
		
	public:
		Customer(std::string, std::string, std::string);
		void setName(std::string);
		std::string getName();
		void setGender(std::string);
		std::string getGender();
		void setDOB(std::string);
		std::string getDOB();
		


};


#endif
