
#include "Hash.h"

// constructor
Hash::Hash():HashTable(new LinkedList[table_size]) {}

// copy constructor
Hash::Hash(const Hash& rhs):HashTable(new LinkedList[table_size]) {
    std::copy(rhs.HashTable, rhs.HashTable + Hash::table_size, HashTable);
}

// assignment operator (copy - move)
Hash& Hash::operator=(Hash rhs) {
    return this->swap(rhs);
}

// move constructor
Hash::Hash(Hash&& rhs):Hash() {
    this->swap(rhs);
}

// destructor
Hash::~Hash() {delete[] HashTable;}

// update an existing item
Hash& Hash::update_item(std::string name, long number) {
    int index = Hash_Function(name);
    HashTable[index].update_node(name, number);
    return *this;
}

// add a new item
Hash& Hash::add_item(std::string name, long number) {
    int index = Hash_Function(name);
    HashTable[index].add_node(name, number);
    return *this;
}

// remove an existing item
Hash& Hash::rem_item(std::string name) {
    int index = Hash_Function(name);
    HashTable[index].rem_node(name);
    return *this;
}

// print an item
void Hash::print_item(std::string name) const {
    int index = Hash_Function(name);
    HashTable[index].print_node(name);
}

// output the size of bucket at index 
int Hash::bucket_size(int index) const {
    return HashTable[index].get_length();
}

// print the content of the bucket at index
void Hash::print_bucket(int index, std::ostream& os) const {
    HashTable[index].print_list(os);
}

// print a summary about each bucket of the hash_table
void Hash::print_table() const {
    for (int i=0; i<table_size; ++i) {
        std::cout << "# of items in bucket " << i << ":  ";
        std::cout << bucket_size(i) << std::endl;
        
        std::cout << "Information at bucket's head: ";
        if (HashTable[i].head){
            std::string head_name = HashTable[i].head->name;
            HashTable[i].print_node(head_name);
        }else{
            std::cout << "this bucket is empty!" << std::endl;
        }
    }
    std::cout << "* * * * * * * * * * * * * * *\n\n";
}

// utility hash function
int Hash::Hash_Function(std::string name) const {
    int sum = 0;
    for (int i=0; i<name.size(); ++i) {sum += (int)name[i];}
    return sum % table_size;
}

