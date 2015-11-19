
#ifndef HASH_H
#define HASH_H


#include "LinkedList.h"


class Hash {
private:
    static const int table_size = 4;
    LinkedList* HashTable;
    Hash& swap(Hash& rhs) {
        LinkedList* temp = rhs.HashTable;
        rhs.HashTable = this->HashTable;
        this->HashTable = temp;
        return *this;
    }
    // utility hash functon
    int Hash_Function(std::string) const;
public:
    // constructor - assignment - destructor
    Hash();
    Hash(const Hash&);
    Hash& operator=(Hash);
    Hash(Hash&&);
    ~Hash();
    // update - add - remove
    Hash& update_item(std::string, long);
    Hash& add_item(std::string, long);
    Hash& rem_item(std::string);
    // retrieve information
    void print_item(std::string) const;
    int  bucket_size(int) const;
    void print_bucket(int, std::ostream&) const;
    void print_table() const;    
};

#endif

