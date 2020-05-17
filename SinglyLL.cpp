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
		count--;
		head = temp;
	}
}
Node* SinglyLL::get(int k){
	Node* temp = head;
	if(this->exists(k) == false){
		std::cout << "Invalid index." << std::endl;
	}
	else{
		for(int i = 0; i < k; i++){
			temp = temp->getNext();		
		}
	}
	return temp;
}
void SinglyLL::remove(int k){
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
	count--;
}
void SinglyLL::insert(Node* N){
	N->setNext(head);
	head = N;
	count++;
}
bool SinglyLL::isEmpty(){
	if(count == 0){
		return true;
	}
	else if(count > 0){
		return false;
	}
}
bool SinglyLL::exists(int k){
	if(k > this->size() || k < 0 || count == 0){
		std::cout << "Invalid index." << std::endl;
		return false;
	}
	else{
		return true;
	}
}
int SinglyLL::size(){
	return count;
}
void SinglyLL::printList(){
	Node* temp = head;
	for(int i = 0; i < count; i++){
		std::cout << i + 1 << ". ";
		temp->printID();
		temp = temp->getNext();
	}
	std::cout << std::endl;

}

