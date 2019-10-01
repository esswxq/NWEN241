
#include "dbms2.hh"

namespace dbms2{
  struct node{
    int data;
    struct node *next;
  };

  // This class inherits from Base and implements functions
  class LinkedListDbTable: public AbstractDbTable{
  public:
    //functions
    int rows() = 0;
    bool show(int index);
    bool add(movie &movie);
    bool remove(unsigned long id);
    movie *get(int index);
    struct node *head;
    virtual node getLastNode();

    int count;
    //constractor
    LinkedListDbTable();
    //destructor
    ~LinkedListDbTable();
  };
}
