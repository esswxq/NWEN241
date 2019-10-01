/**
* vdb.hh
*/
#ifndef __VDB_HH__
#define __VDB_HH__

#include <vector>
#include "dbms2.hh"

using namespace std;
using namespace dbms2;


namespace dbms2{
// This class inherits from Base and implements fun()
class VectorDbTable: public AbstractDbTable
{
  public:
    //function to return rows
    int rows();
    //function to nDisplay
    bool show(const int rowIndex);
    //functin to add record
    bool add(movie &m);
    bool remove(unsigned long id);

    //function to return a pointer to a movie struct
    movie * get(const int rowIndex);

    //constructor
    VectorDbTable();
    ~VectorDbTable();

  private:
    int rowTotal;

    vector<movie> movies;
};

}

#endif
