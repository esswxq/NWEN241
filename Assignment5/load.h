/**
* load.h
*/
#ifndef __LOAD_H__
#define __LOAD_H__

#define DEFAULT_STRLEN	100
#define NUM_RECORDS 25

typedef struct movie {
  char title[DEFAULT_STRLEN];
  char director[DEFAULT_STRLEN];
  short year;
  short oscars_won;
  char origin_country[DEFAULT_STRLEN];
}movie_t;

int loadCSV();


#endif
