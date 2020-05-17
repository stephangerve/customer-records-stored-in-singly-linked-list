#include "Node.h"
#include "Customer.h"


Node::Node(){
	next = NULL;

}
Node::Node(std::string name, std::string gender, std::string DOB){
	C = new Customer(name, gender, DOB);
	next = NULL;
}
Customer* Node::getCustomer(){
	return C;
}
void Node::setCustomer(Customer* C){
	delete this->C;
	this->C = C;
}
Node* Node::getNext(){
	return next;
}
void Node::setNext(Node* next){
	this->next = next;
}
Node::~Node(){
	delete C;

}
void Node::printID(){
	std::cout << C->getName() << std::endl;
}
void Node::printData(){
	C->printCustomerInfo();
}

