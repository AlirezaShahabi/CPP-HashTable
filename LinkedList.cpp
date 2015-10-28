

#include "LinkedList.h"
#include <iostream>


// constructor
LinkedList::LinkedList():head(nullptr),length(0) {}



// copy constructor
LinkedList::LinkedList(const LinkedList& rhs){
    copier(rhs);
}



// copy assignment operator
LinkedList& LinkedList::operator=(const LinkedList& rhs){
    terminator();
    copier(rhs);
    return *this;
}



// add a new Node to *this
void LinkedList::add_Node(std::string name, double number){
    Node* newNode = new Node;
    newNode->name = name;
    newNode->number = number;
    newNode->next = nullptr;
    
    if (head == nullptr) {
        head = newNode;
    }else{
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    ++length;
}



// remove the Node keyed by name from *this
void LinkedList::rem_Node(std::string name){
    if (head == nullptr) {
        std::cout << "list is empty!" << std::endl;
    }else{
        
        Node* delPtr = nullptr;
        Node* p1 = head;
        Node* p2 = head->next;
        
        if (head->name == name) {
            
            delPtr = head;
            head = head->next;
            delete delPtr;
            --length;
            
        }else{
            
            bool exist = false;
            while (p2 != nullptr) {
                if (p2->name == name) {
                    exist = true;
                    break;
                }
                p1 = p2;
                p2 = p2->next;
            }
            if (exist) {
                delPtr = p2;
                p2 = p2->next;
                p1->next = p2;
                delete delPtr;
                --length;
            }else{
                std::cout << name << " does NOT exist!" << std::endl;
            }
        
        }
    }
}



// updata the value of the node keyed by name
void LinkedList::update(std::string name, double number){
    if (head == nullptr) {
        std::cout << "list is empty!" << std::endl;
    }else{
        
        Node* curr = head;
        while (curr->name != name && curr->next != nullptr) {
            curr = curr->next;
        }
        if (curr->name == name){
            curr->number = number;
        }else{
            std::cout << name << " does NOT exist!" << std::endl;
        }
    }
}



// print the data in the node keyed by name
void LinkedList::print_Node(std::string name) const {
    if (head == nullptr){
        std::cout << "list is empty!" << std::endl;
    }else{
        
        Node* curr = head;
        while (curr->name != name && curr->next != nullptr) {
            curr = curr->next;
        }
        if (curr->name == name) {
            std::cout << curr->name << ": " << curr->number;
            std::cout << std::endl;
        }else{
            std::cout << name << " does NOT exist!" << std::endl;
        }
    }
}



// print all the data in the nodes of *this
void LinkedList::print_List() const {
    if (head == nullptr){
        std::cout << "list is empty!" << std::endl;
    }else{
        
        Node* curr = head;
        while (curr->next != nullptr) {
            std::cout << curr->name << ": " << curr->number << " - ";
            curr = curr->next;
        }
        std::cout << curr->name << ": " << curr->number << std::endl;
    }
}



// return the number of nodes in *this
int LinkedList::get_Length() const {return length;}



// destructor
LinkedList::~LinkedList() {
    terminator();
}


// utility functions:


// utility function used by copy constructor and copy assignment
// operator. copies all the Nodes and length from obj into *this
void LinkedList::copier(const LinkedList& obj){
    if (obj.head == nullptr) {
        length = 0;
        head = nullptr;
    }else{
        length = obj.length;
        
        Node* p1 = nullptr;    // points to current Node in *this
        Node* p2 = nullptr;    // points to next Node in *this
        
        head = new Node;
        head->name   = obj.head->name;
        head->number = obj.head->number;
        p1 = head;
        p2 = obj.head->next;
        
        while (p2 != nullptr) {
            p1->next = new Node;
            p1 = p1->next;
            p1->name   = p2->name;
            p1->number = p2->number;
            p2 = p2->next;
        }
        p1->next = nullptr;
    }
}



// utility function used by destructor and copy assinment operator
// destryos all the nodes in *this and frees up resources
void LinkedList::terminator(){
    if (head != nullptr){
        Node* curr = head;
        while (curr->next != nullptr) {
            Node* delPtr = curr;
            curr = curr->next;
            delete delPtr;
        }
        delete curr;
    }
}






