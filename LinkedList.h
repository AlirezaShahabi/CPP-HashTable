
#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include <string>


class LinkedList {
    
friend class Hash;
    
private:
    struct Node{
        std::string name; // key (unique)
        double number;    // value
        Node* next;       // pointer to next node
    };
    Node* head;
    int length;
    // private utility functions
    void copier(const LinkedList&);
    void terminator();
    
public:
    // constructor and copy constructor/assignment operator
    LinkedList();
    LinkedList(const LinkedList&);
    LinkedList& operator=(const LinkedList&);
    // add/remove 
    void add_Node(std::string, double);
    void rem_Node(std::string);
    void update(std::string, double);
    // retrieve information
    void print_Node(std::string) const;
    void print_List() const;
    int  get_Length() const;
    // destructor
    ~LinkedList();
};


#endif

