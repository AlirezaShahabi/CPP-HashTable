

#include "Hash.h"
#include <iostream>


// constructor
Hash::Hash() : HashTable(new LinkedList[table_size]) {}



// copy constructor
Hash::Hash(const Hash& rhs){
    HashTable = new LinkedList[rhs.table_size];
    
    for (int i=0; i<table_size; ++i) {
        HashTable[i] = rhs.HashTable[i];
    }
}



// copy assignment operator
Hash& Hash::operator=(const Hash& rhs){
    delete[] HashTable;
    HashTable = new LinkedList[rhs.table_size];
    for (int i=0; i<table_size; ++i){
        HashTable[i] = rhs.HashTable[i];
    }
    return *this; 
}



// add a new item to *this hash_table
void Hash::add_item(std::string name, double number){
    int index = Hash_Function(name);
    // call the corresponding member function of linked list
    HashTable[index].add_Node(name, number);
}



// remove the object keyed by name from *this hash_table
void Hash::rem_item(std::string name){
    int index = Hash_Function(name);
    // call the corresponding member function of linked list
    HashTable[index].rem_Node(name);
}



// update the value of item keyed by name
void Hash::update(std::string name, double number){
    int index = Hash_Function(name);
    // call the corresponding member function of linked list
    HashTable[index].update(name, number);
}



// print the data in the item keyed by name
void Hash::print_item(std::string name) const {
    int index = Hash_Function(name);
    // call the corresponding member function of linked list
    HashTable[index].print_Node(name);
}



// return the number of items in the bucket indexed by n
int Hash::bucket_size(int n) const {
    // call the corresponding member function of linked list
    return HashTable[n].get_Length();
}



// print all the item in the bucket indexed by n
void Hash::print_bucket(int n) const {
    // call the corresponding member function of linked list
    HashTable[n].print_List();
}



// output the first Item of the list in each bucket
// and the total number of Items in there.
void Hash::print_table() const {
    for (int i=0; i<table_size; ++i) {
        std::cout << "# of items in bucket " << i << ":  ";
        std::cout << bucket_size(i) << std::endl;
        
        std::cout << "Bucket's head point to: ";
        if (HashTable[i].head != nullptr){
            std::string head_name = HashTable[i].head->name;
            HashTable[i].print_Node(head_name);
        }else{
            std::cout << "this bucket is empty!" << std::endl;
        }
    }
    std::cout << "* * * * * * * * * * * * * * *\n\n";
}




// destructor
// the main job will done by destructor of every LinkeLise item
Hash::~Hash(){
    delete[] HashTable;
}


// utility function

// hash function recieves a string (key) as argument and returns an
// integer which is index to one of the buckets
int Hash::Hash_Function(std::string key) const {
    int hash_index = 0;
    for (int i=0; i<key.size(); ++i) {
        hash_index += (int)key[i];
    }
    return hash_index % table_size;
}




