#include "dbms2.hh"
#include "vdb.hh"
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <cstring>


using namespace dbms2;
using namespace std;
//typedef struct movie movie_t;

//function to read and load data to data structure
//Input file stream to read csv
bool AbstractDbTable::loadCSV(const char *infn){
  // return false if infn file is null
  if(infn == NULL) return false;
  // Input file stream to read csv
  ifstream csv;

  csv.open(infn);

  //return false if file open falied
  if(!csv.is_open()) {
      printf("Failed to open %s\n",infn);
      return false;
  }

  // declare a movie vector
  //vector<movie> movies;

  movie m;

  // Parse CSV file and load records
  while(!csv.eof()) {
      string t;
      if(!getline(csv, t, ',')) break; //retur if no more
      m.id = strtoul(t.c_str(),NULL,10);
      if(!getline(csv, t, ',')) break; //retur if no more
      strncpy(m.title, t.c_str(), t.length()+1);
      if(!getline(csv, t, ',')) break; //retur if no more
      m.year = (unsigned short)strtoul(t.c_str(),NULL,10);
      if(!getline(csv, t, '\n')) break;      //retur if no more
      strncpy(m.director, t.c_str(), t.length()+1);
      //movies.push_back(m);
      add(m);
  }

  // Close
  csv.close();
  return true;
}


bool AbstractDbTable::saveCSV(const char *outfn){
  FILE *csv;
  //open file
  csv = fopen(outfn, "w");
  //return false if file is not empty
  if(csv == NULL) return false;

  //declare a movie vector
  //vector<movie> movies;

  //return false if cannot open file
  // if(!csv.is_open()) {
  //     printf("Failed to open %s\n",outfn);
  //     return false;
  // }

  //write records into file
  for(int i = 0;i < rows();i++){
    struct movie *movie = get(i);
    //if movie is null, stop
    if(movie == NULL) break;
    //get each variable of the record
    unsigned long id = (*movie).id;
    string title =  (*movie).title;
    unsigned short year = (*movie).year;
    string director = (*movie).director;
    //display the records
    cout << id << "," << title << "," << year << "," <<director << endl;
    // csv << (*movie).id;
    // csv << ",";
    // csv << (*movie).title;
    // csv << ",";
    // csv << (*movie).year;
    // csv << ",";
    // csv << (*movie).director;
    // csv << endl;
  }
  //close file
  fclose(csv);
  return true;
}
