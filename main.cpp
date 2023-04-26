#include "Employee.h"													// Defines class Employee
#include "Library.h"
#include "Map.h"														// Defines template Map<Key, Value>
#include <iostream>

typedef unsigned int ID; 												// Identification number of employee
typedef Map<ID, Employee> Database; 									// Database of employees

typedef string title;
typedef Map<title, Library> DatabaseLib;

using namespace std;

void addEmployees(Database& database);
void modifyEmployees(Database& database);
void testEmployees();

void addBooks(DatabaseLib& database);
void modifyBooks(DatabaseLib& database);
void testLibrary();

int main()
{
    testEmployees();
    testLibrary();

    return 0;
}

void testEmployees()
{
    cout << endl << endl << "-------- EMPLOYEES CLASS TEST --------" << endl << endl;

    Database database;
    addEmployees(database);

    Database newDatabase = database;									// Make a copy of database
    newDatabase.add(830505432, Employee("Ewa Nowak", "charwoman", 43));	// Add fourth employee
    modifyEmployees(newDatabase);

    cout << "Original database:" << endl << database << endl;
    cout << "Modified database:" << endl << newDatabase << endl;

    database = newDatabase;												// Update original database

    cout << "Database after the assignment:" << endl << database << endl;
}

void addEmployees(Database& database)
{
    database.add(761028073, Employee("Jan Kowalski", "salesman", 28)); 	// Add first employee: name: Jan Kowalski, position: salseman, age: 28,
    database.add(510212881, Employee("Adam Nowak", "storekeeper", 54));	// Add second employee
    database.add(730505129, Employee("Anna Zaradna", "secretary", 32));	// Add third employee
}

void modifyEmployees(Database& database)
{
    Employee* employeePtr;

    employeePtr = database.find(510212881);								// Find employee using its ID
    employeePtr->position = "salesman";									// Modify the position of employee

    employeePtr = database.find(761028073);								// Find employee using its ID
    employeePtr->age = 29;												// Modify the age of employee
}



void testLibrary()
{
    cout << endl << endl << "-------- LIBRARY CLASS TEST --------" << endl << endl;
    DatabaseLib database;
    addBooks(database);

    DatabaseLib newDatabase = database;

    newDatabase.add("Kanadyjskie kartele", Library("Adrian Nowak", "Kryminal", 175, 1));
    modifyBooks(newDatabase);

    cout << "Original database:" << endl << database << endl;
    cout << "Modified database:" << endl << newDatabase << endl;

    database = newDatabase;
    cout << "Database after the assignment:" << endl << database << endl;
}

void addBooks(DatabaseLib& database)
{
    Library book_1("Mateusz Jurek", "Nauka", 100, 1);
    Library book_2("Daniel Zwierzynski", "Science-fiction", 500, 0);
    Library book_3("Dawid Wojcik", "Przygoda", 200, 0);

    database.add("C++", book_1);
    database.add("Podroz na Marsa", book_2);
    database.add("Piesek Leszek", book_3);
}

void modifyBooks(DatabaseLib& database)
{
    Library* ptr;

    ptr = database.find("C++");
    ptr->author = "Steve Jobs";
    ptr->pages = 155;

    ptr = database.find("Piesek Leszek");
    ptr->author = "Bartosz Walaszek";
    ptr->category = "Bajka";
    ptr->pages = 404;
    ptr->available = 1;
}