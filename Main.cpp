

#include "Hash.h"
#include <iostream>


int main(){
    
    
    ////////////////////////////////////////////////////////////
    
    
    std::cout << "\nFIRST SECTION: test the LinkedList class\n\n\n";
    
    LinkedList list1;               // constructor
    
    list1.add_Node("Sara",45.9);
    list1.add_Node("Susan",100.1);  // adding nodes
    list1.add_Node("Michael",7);
    list1.add_Node("Lily",20.5);
    list1.add_Node("Steve",77);
    list1.add_Node("Tina",59);
    
    list1.print_List();             // member function test
    std::cout << list1.get_Length() << std::endl;

    
    list1.rem_Node("Sara");     // remove node from begining
    list1.rem_Node("Lily");     // remove node from middle
    list1.rem_Node("Tina");     // remove node from end
    list1.rem_Node("Jordan");   // remove node that does not exist
    list1.update("Steve",1000); // member function test
    
    list1.print_List();
    std::cout << list1.get_Length() << std::endl;
    
    
    
    LinkedList list2(list1);    // copy constructor
    
    list2.print_List();
    std::cout << list2.get_Length() << std::endl;
    
    LinkedList list3;
    list3 = list1;              // copy assignment operator
    
    list3.print_List();
    std::cout << list3.get_Length() << std::endl;
    
    list3.print_Node("Susan");  // member function test
    list3.print_Node("Lily");
    
    LinkedList list4;
    list4.print_Node("Zack");   // operation on empty list
    list4.rem_Node("Sara");
    std::cout << list4.get_Length() << std::endl;
    
    
    ////////////////////////////////////////////////////////////


    std::cout << "\n\nSECOND SECTION: test the hash class\n\n\n";
    
    Hash ht1;                       // constructor
    
    ht1.add_item("John",34);
    ht1.add_item("Sherri",4.09);
    ht1.add_item("Mike",87.78);
    ht1.add_item("Rayan",11);       // add items
    ht1.add_item("Alex",37.8);
    ht1.add_item("Cathy",70);
    ht1.add_item("James",295.31);
    ht1.add_item("Stephan",1.56);
    ht1.add_item("Marty",5);
    
    ht1.print_table();              // member function test
    
    ht1.print_bucket(0);
    ht1.print_bucket(1);            // items in each row
    ht1.print_bucket(2);
    ht1.print_bucket(3);
    std::cout << "- - - - - - - -\n\n";

    ht1.rem_item("James");          // remove item from begining
    ht1.rem_item("Cathy");          // remove item from middle
    ht1.rem_item("Stephan");        // remove item from end
    ht1.update("Mike",10000);       // member function test
    
    
    ht1.print_bucket(0);
    ht1.print_bucket(1);            // items in each row after removing
    ht1.print_bucket(2);
    ht1.print_bucket(3);
    std::cout << "- - - - - - - -\n\n";

    Hash ht2(ht1);                  // copy constructor
    
    ht2.print_table();

    Hash ht3;
    ht3 = ht1;                      // copy assignment operator
    
    ht2.print_table();

    return 0;
}




