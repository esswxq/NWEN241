#include "dbms2.hh"
#include "vdb.hh"
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>
#define NUM_RECORDS 25

using namespace dbms2;
using namespace std;
//typedef struct movie movie_t;

//constractor - Allocate memory for 25 records
VectorDbTable::VectorDbTable(){
  // use calloc to allocate dynamic memory
  // table = (movie_t *)calloc(NUM_RECORDS,sizeof(movie_t));
}

//destructor
VectorDbTable::~VectorDbTable(){
  // destructor for the table
  // delete(table);
}

// function to return rows
int VectorDbTable::rows(){
  return movies.size();
}
//display records
bool VectorDbTable::show(const int rowIndex){
  // declare vector to contain records
  printf("\n\nDisplaying the %d row record:\n",rowIndex);
  // display records
  if(0 <= rowIndex && rowIndex < movies.size()){
    cout << "Row " << rowIndex << endl;
    cout << "ID             : " << movies[rowIndex].id << endl;
    cout << "Title          : " << movies[rowIndex].title << endl;
    cout << "Year           : " << movies[rowIndex].year << endl;
    cout << "director       : " << movies[rowIndex].director << endl;
    // return true if successful
    return true;
    }
    // return false if failed
    return false;
}

// function to add
bool VectorDbTable::add(movie &t){
  movies.push_back(t) ;
  return true;

}

// function to remove
bool VectorDbTable::remove(unsigned long id){
  //go through the movies and find movie id which match the input number
  for(int i = 0; i<movies.size();i++){
    if(movies[i].id == id){
      movies.erase(movies.begin()+i);  //remove
      return true;
    }
  }
  return false;
}

movie * VectorDbTable::get(const int rowIndex){
  //get index must less than movies size
  if(rowIndex < movies.size()){
    return  &movies[rowIndex];
  }
  return 0x0;  //retur null pointer
}
