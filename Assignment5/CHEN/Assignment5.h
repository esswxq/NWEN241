#ifndef __ASSIGNMENT5_H__
#define __ASSIGNMENT5_H__

#define DEFAULT_STRLEN	100
#define NUM_RECORDS 25
#define DEFAULT_PORT 12345


//structure for movie
struct movie {
  char title[DEFAULT_STRLEN];
  char director[DEFAULT_STRLEN];
  short year;
  short oscars_won;
  char origin_country[DEFAULT_STRLEN];
};

typedef struct movie movie_t;

int loadFile(movie_t *movies);

#endif
