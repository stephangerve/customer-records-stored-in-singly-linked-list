#ifndef SINGLYLL_H_EXISTS
#define SINGLYLL_H_EXISTS

#include <iostream>
#include "Node.h"

class SinglyLL{
	private:
		Node* head;
		int count;

	public:
		SinglyLL();
		~SinglyLL();
		Node* get(int);
		void remove(int);
		void insert(Node*);
		bool exists(int);
		bool isEmpty();
		int size();
		void printList();
		
		



};



#endif
