#ifndef MAP_EMPLOYEE_H
#define MAP_EMPLOYEE_H

#include <string>
#include <iostream>

using namespace std;

class Employee
{
    public:
        string name;
        string position;
        unsigned int age;

        Employee(string n = "---", string p = "---", int a = 0)
        {
            this->name = n;
            this->position = p;
            this->age = a;
        }

     friend ostream& operator<<(ostream& out, const Employee& emp)
     {
            out << "(" << emp.name << " " << emp.position << " " << emp.age << ")";
            return out;
     }

};

#endif
