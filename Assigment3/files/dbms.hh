/**
* editor.hh
*/

#ifndef __DBMS_HH__
#define __DBMS_HH__
#define DEFAULT_STRLEN 100

#include <iostream>
#include <cstring>

namespace dbms
{
  struct album {
    unsigned long id;
    char title[DEFAULT_STRLEN];
    unsigned short year;
    char artist[DEFAULT_STRLEN];
  };


  class DbTable
  {
  public:
    //function to return rowsUsed
    unsigned int rows(){
      return rowsUsed;
    }
    //function to return rowsTotal
    unsigned int allocated(){
      return rowsTotal;
    }
    // allocate table and free
    DbTable();
    ~DbTable();

    //function to show records
    int show(unsigned int rowNumber);
    void reallocateMemory(album *a);
    int add(album t);

  private:
    album *table;
    unsigned int rowsTotal;
    unsigned int rowsUsed;
  };
}


#endif
