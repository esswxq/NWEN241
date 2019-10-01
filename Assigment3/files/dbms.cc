#include "dbms.hh"
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace dbms;
using namespace std;
typedef struct album album_t;

//task 3
DbTable::DbTable(){
  unsigned int rowsTotal = 5;
  unsigned int rowsUsed = 0;
  // use calloc to allocate dynamic memory
  table = (album_t *)
           calloc(rowsTotal,sizeof(album_t));
}

//task 4
DbTable::~DbTable(){
  // destructor for the table
  free(table);
}

//task 5 - display records
int DbTable::show(unsigned int rowNumber){
  // declare vector to contain records
  std::vector<album_t> albums;
  printf("\n\nDisplaying the %d row record:\n",rowNumber);
  // display records
  if(rowNumber < rowsTotal){
    printf("ID             : %d\n", albums[rowNumber].id);
    printf("Title          : %s\n", albums[rowNumber].title);
    printf("Year           : %d\n", albums[rowNumber].year);
    printf("Artist         : %s\n", albums[rowNumber].artist);
    // return true if successful
    return 1;
    }
    // return false if failed
    return 0;
}

//task 6 - adding a record into the database DbTable
void DbTable::reallocateMemory(album *a){
  //reallocate 
  if(rowsUsed >= rowsTotal){
    a = (album *)realloc(table, (rowsTotal)*sizeof(album));
    if(a == NULL){
      rowsTotal -= 5;
    }
  }
}

int DbTable::add(album t){
  //printf("What reference would you like to add to the record?\n");
  table[rowsUsed] = t;
  album *a = (album *)realloc(table, (rowsTotal)*sizeof(a));
  if(rowsUsed >= rowsTotal){
    reallocateMemory(a);
    rowsTotal += 5;
  }
  if(a == NULL)
    return 0;
  table = a;
  // update number of rows
  rowsUsed++;
  rowsTotal++;
  // successful
  return 1;
}
