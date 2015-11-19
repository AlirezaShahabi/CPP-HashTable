

#include "LinkedList.h"
#include <iostream>


// constructor
LinkedList::LinkedList():head(nullptr),length(0) {}

// copy constructor
LinkedList::LinkedList(const LinkedList& rhs):head(new Node),
length(rhs.length) {
    if (rhs.head) {copy_helper(head,rhs.head);}
}

// assignment operator (copy-move)
LinkedList& LinkedList::operator=(LinkedList rhs) {
    swap(*this, rhs);
    return *this;
}

// move constructor
LinkedList::LinkedList(LinkedList&& rhs):LinkedList() {
    swap(*this, rhs);
}

// destructor
LinkedList::~LinkedList() {if (head) {delete_helper(head);}}

// updata the value of the node keyed by name
LinkedList& LinkedList::update_node(std::string name, long new_number) {
    if (!head) {
        std::cout << "list is empty" << std::endl;
    } else {
        Node* ans = find_helper(head, name);
        if (ans) {
            ans->phone_number = new_number;
        } else {
            std::cout << name << " is not in the list" << std::endl;
        }
    }
    return *this;
}

// add a new Node to the front of *this
LinkedList& LinkedList::add_node(std::string new_name, long new_number) {
    Node* new_node = new Node(new_name, new_number);
    if (!head) {
        head = new_node;
    } else {
        Node* old_head = head;
        new_node->next = old_head;
        head = new_node;
    }
    ++length;
    return *this;
}

// remove the Node keyed by name from *this
LinkedList& LinkedList::rem_node(std::string name) {
    if (!head) {
        std::cout << "list is empty" << std::endl;
    } else if (head->name == name) {
        Node* old_head = head;
        Node* delptr = old_head;
        head = old_head->next;
        delptr->next = nullptr;
        delete delptr;
        --length;
    } else {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr && curr->name != name) {
            prev = curr;
            curr = curr->next;
        }
        if (!curr) {
            std::cout << name << " is not in the list" << std::endl;
        } else {
            Node* delptr = curr;
            prev->next = curr->next;
            delptr->next = nullptr;
            delete delptr;
            --length;
        }
    }
    return *this;
}

// print the phone number in the node keyed by name
void LinkedList::print_node(std::string name) const {
    if (!head) {
        std::cout << "list is empty" << std::endl;
    } else {
        Node* ans = find_helper(head, name);
        if (ans) {
            std::cout << name << "'s phone number is: ";
            std::cout << ans->phone_number << std::endl;
        } else {
            std::cout << name << " is not in the list" << std::endl;
        }
    }
}

// print all the names and phone numbers in the nodes of *this
void LinkedList::print_list(std::ostream& os) const {
    Node* curr = head;
    while (curr) {
        os << curr->name << "'s phone number is: ";
        os << curr->phone_number << std::endl;
        curr = curr->next;
    }
    os << std::endl;
}



// return the number of nodes in *this
int LinkedList::get_length() const {return length;}



// private utility functions:


// used by update_node, print_node
// start searching at temp, return a pinter to the node with name
LinkedList::Node* LinkedList::find_helper(Node* temp, std::string name) const {
    while (temp && temp->name != name) {
        temp = temp->next;
    }
    return (temp ? temp:nullptr);
}


// used by copy constructor
// makes a deep copy of all the Nodes starting at source into target
void LinkedList::copy_helper(Node*& target, Node* source) {
    Node* creator = new Node(source->name, source->phone_number);
    target = creator;
    Node* iterator = source->next;
    while (iterator) {
        creator->next = new Node;
        creator = creator->next;
        creator->name = iterator->name;
        creator->phone_number = iterator->phone_number;
        iterator = iterator->next;
    }
    creator->next = nullptr;
}



// used by destructor
// destryos all the nodes starting at curr to the end and frees up resources
void LinkedList::delete_helper(Node* curr) {
    while (curr) {
        Node* delptr = curr;
        curr = curr->next;
        delptr->next = nullptr;
        delete delptr;
    }
}






