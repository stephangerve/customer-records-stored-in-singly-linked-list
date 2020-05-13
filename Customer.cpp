#include "Customer.h"


Customer::Customer(std::string name, std::string gender, std::string DOB){
	this->name = name;
	this->gender = gender;
	this->DOB = DOB;

}

void Customer::setName(std::string name){
	this->name = name;
}

std::string Customer::getName(){
	return name;
}

void Customer::setGender(std::string gender){
	this->gender = gender;
}

std::string Customer::getGender(){
	return gender;
}

void Customer::setDOB(std::string DOB){
	this->DOB = DOB;
}

std::string Customer::getDOB(){
	return DOB;
}
