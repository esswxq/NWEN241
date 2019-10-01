/**
* editor2.h
*/

#ifndef __EDITOR2_H__
#define __EDITOR2_H__

#define EDITING_BUFLEN 2000


//function for test 7
int editor_count_lines(const char *editing_buffer, int size);
//function for test 8
int editor_search_multiple(const char *editing_buffer,int size,const char *word,int *positions,int occurrences);






#endif /* __EDITOR2_H__ */
