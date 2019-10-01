#include <stdio.h>
#include <string.h>       //allow to use string functions
#include "editor2.h"


//task 7
int editor_count_lines(const char *editing_buffer, int size){
  int count = 0;  //number to count how many lines we got
  for(int i = 0; i < size; i++){
    if(*(editing_buffer+i) == '\n'){        //if we meet \n that means we get one line
      count++;
    }
  }
  return count;  //return number of lines in the buffer
}


//task 8
int editor_search_multiple(const char *editing_buffer,int size,const char *str,int *positions,int occurrences){
  int same = 0;     //to count how many charactors of string same with the buffer
  int count = 0;    //to count how many same words we got

  for(int i = 0; i < size ; i ++){
    if(*(editing_buffer + i) == str[same]) {      //if pointer points a same charactor with the charactor of string
      same++ ;       //gets one more same char
    }else{
      same = 0;       //if different, count became to 0
    }
    if(same == strlen(str)){            //if every char is same
      positions[count] = i - strlen(str) + 1;       //get first cahr of string position
      count++;                          //we got one more multiple word
      if(count == occurrences){         //if we got words up to max number
        break;                          //stop searching
      }
    }
  }
  return count;       //return how many multiple words we found
}
