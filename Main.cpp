

#include "Hash.h"
#include "LinkedList.h"


int main() {
    
    ////////////////////////////////////////////////////////////
    
    std::cout << "\nFIRST SECTION: test the LinkedList class\n\n\n";
    
    LinkedList list1;               
    list1.add_node("Sara",6179085437).add_node("Susan",7812094545);
    list1.add_node("Michael",4051769012).add_node("Lily",2058113958);
    list1.add_node("Robert",3409012371);
    list1.add_node("Steve",6453081221).add_node("Tina",5099940211);
    std::cout << list1.get_length() << std::endl;
    list1.print_list(std::cout);
    
    list1.rem_node("Sara");
    list1.rem_node("Lily");
    list1.rem_node("Tina");
    list1.rem_node("Jordan");
    list1.update_node("Steve",9999999999);
    std::cout << list1.get_length() << std::endl;
    list1.print_list(std::cout);
    
    std::cout << "test copy constructor\n\n";
    LinkedList list2(list1);
    std::cout << list2.get_length() << std::endl;
    list2.print_list(std::cout);
    
    std::cout << "test operation on empty list\n\n";
    LinkedList list3;
    std::cout << list3.get_length() << std::endl;
    list3.rem_node("John");
    list3.update_node("mike",3215679292);
    
    std::cout << "test copy assignment operator\n\n";
    list3 = list1;
    std::cout << list3.get_length() << std::endl;
    list3.print_list(std::cout);
    
    std::cout << "test move constructor\n\n";
    LinkedList list4 = std::move(list2);
    std::cout << list4.get_length() << std::endl;
    list4.print_list(std::cout);
    list4.print_node("Susan");
    list4.print_node("Lily");
    
    ////////////////////////////////////////////////////////////
    

    std::cout << "\n\nSECOND SECTION: test the hash class\n\n\n";
    
    Hash ht1;                       
    
    ht1.add_item("John",3479806576).add_item("Sherri",4091169833);
    ht1.add_item("Mike",7478980921).add_item("Rayan",4918095685);
    ht1.add_item("Alex",3788902276).add_item("Cathy",7082149876);
    ht1.add_item("James",2953102288).add_item("Stephan",5150606287);
    ht1.add_item("Marty",5398712640);
    
    ht1.print_table();              
    
    ht1.print_bucket(0, std::cout);
    ht1.print_bucket(1, std::cout);
    ht1.print_bucket(2, std::cout);
    ht1.print_bucket(3, std::cout);
    std::cout << "- - - - - - - -\n\n";

    ht1.rem_item("James").rem_item("Cathy").rem_item("Stephan");        
    ht1.update_item("Mike",1111111111);
    
    ht1.print_bucket(0, std::cout);
    ht1.print_bucket(1, std::cout);
    ht1.print_bucket(2, std::cout);
    ht1.print_bucket(3, std::cout);
    std::cout << "- - - - - - - -\n\n";

    std::cout << "test copy constructor\n\n";
    Hash ht2(ht1);
    ht2.print_table();

    std::cout << "test copy assignment operator\n\n";
    Hash ht3;
    ht3 = ht1;
    ht3.print_table();
    
    std::cout << "test move constructor\n\n";
    Hash ht4(std::move(ht3));
    ht4.print_table();
    ht3.print_table();
    ht1.print_table();
    
    std::cout << "test move assignment operator\n\n";
    Hash ht5;
    ht5 = std::move(ht2);
    ht5.print_table();
    ht2.print_table();
    
    return 0;
}

