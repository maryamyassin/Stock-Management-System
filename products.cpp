/*
     main.cpp
     CST2550 Coursework 1
     Created by M00696748 on 22/12/2020.
     Updated: 6/02/2021
*/


#include <iostream>
#include <fstream>
#include <string>
#include "Products.hpp"

std::fstream file1;
std::fstream file2;
std::fstream file3;
std::fstream file4;

/*
 Function for selling items. The employee enters the number of items they are selling. The system
 checks if the item is in stock. Once the sale is made, the stock quantity decreases and the number
 of sales increases.
 */

void Products::sellItems() {
  int number_of_products;
  std::cout << "Enter the number of products of this item you want to sell: ";
  std::cin >> number_of_products;
  if (stock > number_of_products) {
    stock = stock - number_of_products;
    number_of_sales = number_of_sales + number_of_products;

    std::cout << "Item Sold! Please update stock quantity before taking any other actions." <<
      std::endl;
  }
  
  else {
    std::cout << "Transaction not possible. There are " << stock << " items in stock." << std::endl;
  }
}

/*
 Function for restocking items. Based on the ID number entered by the employee,
 the stock quantity is returned to the original quantity of 100.
 */
void Products::restockItems() {
  stock = stock + number_of_sales;
  std::cout << "Item(s) has been restocked." <<
    "Please update stock quantity before taking any other actions." << std::endl;
}

/*
 Function for adding new items to the music shop. Employee enters the name of the new
 item. The item is then added to the list of items in the store.
 */
void Products::addnewItems() {
  std::string name;
  std::cout << "Enter product name: ";
  std::cin >> name;
  items_list.push_back(name);
  std::cout << "Item added.\nThe updated list of products: \n";

  for (int i = 0; i < items_list.size(); i++) {
      std::cout << items_list.at(i) << std::endl;
  }
}

/*
 Function to update the stock quantity. Writes the new values of the stock and number of sales
 to a file after the employee Sells and/or Restocks an item.
 */
void Products::updateStock(int ptype) {
  if (ptype == 1) {
    file1.open("BooksStockData.txt", std::ios::out);
    if (file1.is_open()) {
      file1 << "\nBooks Stock Quantity: \t" << stock << "\nBook Sales: " << number_of_sales;
      file1.close();
      std::cout << "Stock quantity has been updated." << std::endl;
    } else {
      std::cout << "File is not open!";
    }
  }
  if (ptype == 2) {
    file2.open("MagazineStockData.txt", std::ios::out);
    if (file2.is_open()) {
      file2 << "\nMagazines Stock Quantity: \t" << stock << "\nMagazine Sales: " << number_of_sales;
      file2.close();
      std::cout << "Stock quantity has been updated." << std::endl;
    } else {
      std::cout << "File is not open!";
    }
  }
  if (ptype == 3) {
    file3.open("DVDsStockData.txt", std::ios::out);
    if (file3.is_open()) {
      file3 << "\nDVDs Stock Quantity: \t" << stock << "\nDVD Sales: " << number_of_sales;
      file3.close();
      std::cout << "Stock quantity has been updated." << std::endl;
    } else {
      std::cout << "File is not open!";
    }
  }
  if (ptype == 4) {
    file3.open("CDsStockData.txt", std::ios::out);
    if (file4.is_open()) {
      file4 << "\nCDs Stock Quantity: \t" << stock << "\nCD Sales: " << number_of_sales;
      file4.close();
      std::cout << "Stock quantity has been updated." << std::endl;
    } else {
      std::cout << "File is not open!";
    }
  }
}

/*
 Function that allows the employee to read the stock quantity and sales from a file.
 */
void Products::stockReport(int ptype) {
  if (ptype == 1) {
    file1.open("BooksStockData.txt", std::ios:: in );
    if (file1.is_open()) {
      std::string line;
      while (getline(file1, line)) {
        std::cout << line << '\n' << std::endl;
        if (file1.eof()) //check if end of file is reached
          break;

      }
    } else {
      std::cout << "file not open!" << std::endl;
    }
    file1.close();
  }
  if (ptype == 2) {
    file2.open("MagazineStockData.txt", std::ios:: in );
    if (file2.is_open()) {
      {
        std::string line;
        while (getline(file2, line)) {
          std::cout << line << '\n' << std::endl;
          if (file2.eof()) //check if end of file is reached
            break;

        }
      }
    } else {
      std::cout << "file not open!" << std::endl;
    }
    file2.close();
  }
  if (ptype == 3) {
    file3.open("DVDsStockData.txt", std::ios:: in );
    if (file3.is_open()) {
      {
        std::string line;
        while (getline(file3, line)) {
          std::cout << line << '\n' << std::endl;
          if (file3.eof()) //check if end of file is reached
            break;

        }
      }
    } else {
      std::cout << "file not open!" << std::endl;
    }
    file3.close();
  }
  if (ptype == 4) {
    file4.open("CDsStockData.txt", std::ios:: in );
    if (file4.is_open()) {
      std::string line;
      while (getline(file4, line)) {
        std::cout << line << '\n' << std::endl;
        if (file4.eof()) //check if end of file is reached
          break;

      }
    } else {
      std::cout << "file not open!" << std::endl;
    }
    file4.close();
  }
}

/*
 Function for employee to enter their name and 4 Digit ID number. Checks wether ID is valid.
*/
void Employee::enterName() {
  std::string emp_name;
  std::cout << "Employee name: ";
  std::cin >> emp_name;
  std::cout << "\nEmployee ID: ";
  std::cin >> id;
    
  while (id < 999 || id > 10000) {
      std::cout << "Invalid ID number. Try again.\nEmployee ID: ";
      std::cin >> id;
    }
    
      std::cout << "Hi, " << emp_name << std::endl;
}

/*
 Constructors for Employee, Book, Magazine, DVD, and CD classes.
*/
Employee::Employee() {}

Book::Book() {}

Magazine::Magazine() {}

DVD::DVD() {}

CD::CD() {}

/*
 Function to check if the book has a valid ISBN number before it is managed.
*/
void Book::checkISBN() {
    int user_isbn;
    std::cout << "Please enter the 10 digit ISBN number: ";
    std::cin >> user_isbn;
    
    while (std::to_string(user_isbn).length() != 10) {
        std::cout << "ISBN number should be 10 digits long. Try again.\nISBN number: ";
        std::cin >> user_isbn;
      }
    
    isbn = user_isbn;
}

/*
 Function to check if the magazine has a valid ISSN number before it is managed.
 */
void Magazine::checkISSN() {
    
    int user_issn;
    std::cout << "Please enter the 8 digit ISSN number: ";
    std::cin >> user_issn;
    
    while (std::to_string(user_issn).length() != 8) {
        std::cout << "ISSN number should be 8 digits long. Try again.\nISSN number: ";
        std::cin >> user_issn;
      }
    
    issn = user_issn;
}


/*
 Function to check if DVD is a valid size before it is managed.
*/
void DVD::checkSize() {
    
    int user_size;
    std::cout << "Please enter the size of the DVD (maximum 5 GBs): ";
    std::cin >> user_size;

    while (user_size > 5 || user_size < 0) {
        std::cout << "DVD size should be maximum 5 GBs. Try again.\n DVD size: " << std::endl;
        std::cin >> user_size;
      }
    
    size = user_size;
    
}


/*
 Function to check if CD is a valid length before it is managed.
 */
void CD::checkLength() {
    int user_length;
    std::cout << "Please enter the CD length (in minutes): ";
    std::cin >> user_length;
    int i = 0;
    while (i<3) {
        if (isdigit(user_length)){
        length = user_length;
    }
        else{
        std::cout << "CD length should be in minutes. Try again\nCD Length: ";
        std::cin >> user_length;
        i++;
    }
        
  }
}

