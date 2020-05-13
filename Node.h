#ifndef NODE_H_EXISTS
#define NODE_H_EXISTS

#include "Customer.h"

class Node{
	private:
		
		Customer *C;	
		Node *next;
	
	public:
		Node();
		Node(std::string, std::string, std::string);
		~Node();
		Customer *getCustomer();
		void setCustomer(Customer*);
		Node *getNext();
		void setNext(Node*);
		void printData();
};




#endif
