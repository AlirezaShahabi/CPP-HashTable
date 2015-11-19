
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>

class LinkedList {
friend class Hash;
friend void swap (LinkedList& lhs, LinkedList& rhs) {
    using std::swap;
    swap(lhs.head, rhs.head);
    swap(lhs.length, rhs.length);
}
private:
    struct Node{
        std::string name;
        long phone_number;
        Node* next;
        // Node constructor
        Node(std::string s, long n):name(s),phone_number(n),
        next(nullptr) {}
        Node():name(),phone_number(0),next(nullptr) {}
    };
    Node* head;
    int length;
    // private utility functions
    Node* find_helper(Node*, std::string) const;
    void copy_helper(Node*&, Node*);
    void delete_helper(Node*);
public:
    // constructor - assignment - destructor
    LinkedList();
    LinkedList(const LinkedList&);
    LinkedList& operator=(LinkedList);
    LinkedList(LinkedList&&);
    ~LinkedList();
    // update - add - remove
    LinkedList& update_node(std::string, long);
    LinkedList& add_node(std::string, long);
    LinkedList& rem_node(std::string);
    // retrieve information
    void print_node(std::string) const;
    void print_list(std::ostream&) const;
    int  get_length() const;
};

#endif


