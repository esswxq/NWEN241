/**
* dbms2.hh
*/
#ifndef __DBMS2_HH__
#define __DBMS2_HH__
#include <vector>

using namespace std;

namespace dbms2{
    struct movie {
        unsigned long id;
        char title[50];
        unsigned short year;
        char director[50];
    };


class AbstractDbTable{
public:

//function to return integer
virtual int rows() = 0;

//function to show
virtual bool show(const int rowIndex) = 0;

//function to adding
virtual bool add(movie &t) = 0;

//function to remove
virtual bool remove(unsigned long id) = 0;

//function to get - return pointer
virtual movie * get(const int rowIndex) = 0;

//task5 - load
bool loadCSV(const char *infn);

//task6 - save
bool saveCSV(const char *outfn);


};
}




















#endif
