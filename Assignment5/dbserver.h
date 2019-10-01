#ifndef __DBSERVER_H__
#define __DBSERVER_H__

#define DEFAULT_STRLEN	100
#define NUM_RECORDS 25
#define DEFAULT_PORT 12345


//struc for movie
typedef struct movie {
  char title[DEFAULT_STRLEN];
  char director[DEFAULT_STRLEN];
  short year;
  short oscars_won;
  char origin_country[DEFAULT_STRLEN];
}movie_t;

//load csv file
int loadCSV(movie_t *movies);

#endif /* __SERVER_H__ */
