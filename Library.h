#ifndef MAP_LIBRARY_H
#define MAP_LIBRARY_H

#include <string>
#include <iostream>

using namespace std;

class Library
{
    public:
        string author;
        string category;
        unsigned int pages;
        unsigned short available;

        Library(string a = "---", string c = "---", uint32_t p = 0, uint8_t av = 0)
        {
            this->author = a;
            this->category = c;
            this->pages = p;
            this->available = av;
        }

        friend ostream& operator<<(ostream& out, const Library& lib)
        {
            out << "(" << lib.author << " " << lib.category << " " << lib.pages << " " << "'" << lib.available  << "'" << ")";
            return out;
        }
};

#endif
