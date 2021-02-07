
#include <iostream>
#include <fstream>
#include <string>
#include "Products.hpp"
#include "catch.hpp"

/*
main.cpp
Author: M00696748
Created: 22/12/2020
Updated: 11/01/2021
*/

/*
A music shop sells CDs, DVDs, magazines and books. It is in need of a stock management system
to maintain stock records with a text (command line) menu with options to allow the user to
perform the following functionality:
• sell items
• restock items (increase stock quantity)
• add new items
• update stock quantity (correct stock levels)
• view a report of sales
It should also be possible to load and save the stock data to/from a file.
*/

int main()
{
    /*
     Creating objects of each class to implement the program
     */
    Employee employee;
    Book book;
    Magazine mag;
    CD cd;
    DVD dvd;
    
    std::cout << "Hi! Welcome to the Stock Management System.\n" << std::endl;
    employee.enterName();
    int item_type;
    

    std::cout << "\nWhich items would you like to manage?\n1.Books\t2.Magazines\t3.DVDs\t4.CDs\n" << std::endl;
    std::cin >> item_type;
    
        
    for (int i = 0; i < 10; i++){
               
                int selection;
                std::cout << "\nSelect an Option from the menu below\tEnter 'q' to log out of system\n"
                        << "\tMENU\n1.Sell Items\n2.Restock Items\n3.Add new Item\n4.Update Stock Quantity\n5.View a report of sales and stock\n" << std::endl;
                std::cin >> selection;
                
                if (item_type == 1){
                    
                            if (selection == 1){
                                book.sellItems();
                            }
                            else if(selection == 2){
                                book.restockItems();
                            }
                            else if (selection == 3){
                                book.addnewItems();
                            }
                            else if (selection == 4){
                                
                                book.checkISBN();
                                book.updateStock(item_type);
                            }
                            else if (selection == 5){
                                book.stockReport(item_type);
                            }
                            else {
                                std::cout << "Please enter a number from 1 to 5.";
                            }
                    }
                
                    
                         
                else if (item_type == 2){
                    
                            if (selection == 1){
                                mag.sellItems();
                            }
                            else if(selection == 2){
                                mag.restockItems();
                            }
                            else if (selection == 3){
                                mag.addnewItems();
                            }
                            else if (selection == 4){
                                mag.checkISSN();
                                mag.updateStock(item_type);
                            }
                            else if (selection == 5){
                                mag.stockReport(item_type);
                            }
                            else {
                                std::cout << "Please enter a number from 1 to 5.";
                            }
                        }
                            
                else if (item_type == 3){
                            if (selection == 1){
                                dvd.sellItems();
                            }
                            else if(selection == 2){
                                dvd.restockItems();
                            }
                            else if (selection == 3){
                                dvd.addnewItems();
                            }
                            else if (selection == 4){
                                dvd.checkSize();
                                dvd.updateStock(item_type);
                            }
                            else if (selection == 5){
                                dvd.stockReport(item_type);
                            }
                            else {
                                std::cout << "Please enter a number from 1 to 5.";
                            }
                        }
                            
                else if (item_type == 4){
                    
                            if (selection == 1){
                                cd.sellItems();
                            }
                            else if(selection == 2){
                                cd.restockItems();
                            }
                            else if (selection == 3){
                                cd.addnewItems();
                            }
                            else if (selection == 4){
                                
                                
                                cd.checkLength();
                                cd.updateStock(item_type);
                            }
                            else if (selection == 5){
                                cd.stockReport(item_type);
                            }
                            else {
                                std::cout << "Please enter a number from 1 to 5.";
                            }
                        }
                
                
                else {
                    std::cout << "Enter a value from 1 to 4 please.";
                    }
                
                char option;
                std::cout << "Would you like to manage a different item? [y/n]" << std::endl;
                std::cin >> option;
                
                if (option == 'y'){
                    std::cout << "\n1.Books\t2.Magazines\t3.DVDs\t4.CDs\n" << std::endl;
                    std::cin >> item_type;
                }
                else {
                    continue;
                }
            }
}




