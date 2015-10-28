
#ifndef HASH_H
#define HASH_H


#include "LinkedList.h"


class Hash{
    
private:
    static const int table_size = 4;
    LinkedList* HashTable;
    // utility hash functon
    int Hash_Function(std::string) const;
    
public:
    // constructor and copy constructor/operator
    Hash();
    Hash(const Hash&);
    Hash& operator=(const Hash&);
        
    // add/remove
    void add_item(std::string, double);
    void rem_item(std::string);
    void update(std::string, double);
    
    // retrieve information
    void print_item(std::string) const;
    int  bucket_size(int) const;
    void print_bucket(int) const;
    void print_table() const;
    
    // destructor
    ~Hash();
    
};


#endif


