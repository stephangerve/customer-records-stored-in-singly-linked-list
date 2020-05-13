#include <iostream>
#include "SinglyLL.h"
#include "Node.h"


SinglyLL::SinglyLL(){
	head = NULL;
}
SinglyLL::~SinglyLL(){
	Node* temp = head;
	for(int i = 0; i < count; i++){
		temp = head->getNext();
		delete head;
		head = temp;
	}
}
Node* SinglyLL::get(int k){
	k--;
	Node* temp = head;
	if(k > this->size() || k < 0 || this->isEmpty() == true){
		std::cout << "Invalid index." << std::endl;
	}
	else{
		for(int i = 0; i < k; i++){
			temp = temp->getNext();		
		}
	}
	return temp;
}
bool SinglyLL::remove(int k){
	k--;
	if(k > this->size() || k < 0 || this->isEmpty() == true){
		std::cout << "Invalid index." << std::endl;
		return false;
	}
	else{
		Node* prevNode;
		Node* nextNode;
		Node* temp = head;
		for(int i = 0; i < k; i++){
			prevNode = temp;
			temp = temp->getNext();
		}
		nextNode = temp->getNext();
		temp->setNext(NULL);
		delete temp;
		if(k == 0){
			head = nextNode;	
		}
		else{	
			prevNode->setNext(nextNode);
		}
		return true;
	}
}
bool SinglyLL::insert(Node* N){
	N->setNext(head);
	head = N;
	count++;
	return true;
}
bool SinglyLL::isEmpty(){
	if(count == 0){
		return true;
	}
	else if(count > 0){
		return false;
	}
}
int SinglyLL::size(){
	return count;
}
void SinglyLL::printList(){
	Node* temp = head;
	for(int i = 0; i < count; i++){
		temp->printData();
		temp = temp->getNext();
	}

}
