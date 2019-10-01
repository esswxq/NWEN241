#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#include "load.h"

#define DEFAULT_STRLEN 100
#define NUM_RECORDS 25

typedef struct movie movie_t;

int loadCSV(){
  //declare a pointer to movie_t
  movie_t *movies;

  //allocate memory for 25 records
  movies = (movie_t*) calloc(NUM_RECORDS,sizeof(movie_t));

  //input file stream to read CSV
  FILE *csv;
  csv = fopen("scifi.csv","r");
  if(csv == NULL){
    printf("Failed to open scifi.csv\n");
    return -1;
  }

  int  i = 0;
  //read all the data in the file
  while(!feof(csv) && i < NUM_RECORDS){
    fscanf(csv, "%[^,],%[^,],%d,%d,%[^\n]%*c",
           movies[i].title,
           movies[i].director,
           movies[i].year,
           movies[i].oscars_won,
           movies[i].origin_country);
    i++;
  }
  fclose(csv);
  return 0;
}
