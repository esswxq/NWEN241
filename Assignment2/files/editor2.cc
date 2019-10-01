#include "editor2.hh"
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
using namespace editor2;

//task 10
int EditorUtilities::countWords(const char *editing_buffer,int size){
  int count = 0;
  for(int i = 0; i < size ; i++){
    //points first char is be a valid alphabet charactor, second char must be a symbol
    if((   (*(editing_buffer+i-1) != '\t') && (*(editing_buffer+i-1) != ' ')
        && (*(editing_buffer+i-1) != '\n') && (*(editing_buffer+i-1) != '\v') && (*(editing_buffer+i-1) != '\f')
        && (*(editing_buffer+i-1) != '\r' ))
        &&((*(editing_buffer+i) == '\t')   || (*(editing_buffer+i) == ' ' )   || (*(editing_buffer+i) == '\0')
        || (*(editing_buffer+i) == '\n')  || (*(editing_buffer+i) == '\v' )  || (*(editing_buffer+i) == '\f')
        || (*(editing_buffer+i) == '\r'))) {
          count++;   //if we get a word, count increased
      }
  }
  return count;
}

//task 11
int EditorUtilities::searchMultipleNoCase(char *editing_buffer,int size,std::string str,int *positions,int occurrences){

  string buffer(editing_buffer);    ///transfer editing_buffer to string
  std::transform(buffer.begin(), buffer.end(), buffer.begin(), ::tolower); //transfer all the char in buffer to lowercase

  // codes below are similar to test8, just compare char one by one by pointer moving
  int same = 0;
  int count = 0;

  for(int i = 0; i < size ; i ++){
    if(buffer[i] == str[same]) {
      same ++ ;
    }else{
      same = 0;
    }
    if(same == str.length()){
      positions[count] = i-str.length()+1;
      count++;
      if(count == occurrences){
        break;
      }
    }
  }
  return count;
}
