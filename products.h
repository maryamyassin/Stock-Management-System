/*
    products.h
    Author: M00696748
    Created: 22/12/2020
    Updated: 22/01/2021
*/

#ifndef Products_h
#define Products_h
#include <fstream>
#include <stdio.h>
#include <vector>
#include <string>


class Products {
private:
    int stock = 100;
    int number_of_sales = 0;
    std::vector<std::string> items_list; //a vector storing products
    
public:
    void sellItems(); //increase number of sales & decrease stock quantity
    void restockItems(); //stock number updated to desired amount
    void addnewItems(); // updates the list of items
    void updateStock(int ptype); //correct stock levels after selling and restocking
    void stockReport(int ptype); //read from file w list of stock quantity
};

class Employee{
private:
    std::string name;
    int id;
public:
    Employee();
    void enterName();
};

class Book : public Products {
private:
    int isbn;
public:
    Book();
    void checkISBN();
};

class Magazine : public Products {
private:
    int issn;
public:
    Magazine();
    void checkISSN();
};

class DVD : public Products {
private:
    int size;
public:
    DVD();
    void checkSize();
};

class CD : public Products {
private:
    int length;
public:
    CD();
    void checkLength();
};



#endif /* Products_h */

