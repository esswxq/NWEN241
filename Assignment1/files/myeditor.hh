/**
 * myeditor.hh
 *
 * You must define a class that extends the EditingBuffer class in this file.
 * Consult the assignment handout for more information.
 *
 * Student ID: 300403758
 * Name: Xianqiong WU
 */

#ifndef __MYEDITOR_HH__
#define __MYEDITOR_HH__


#include "editor.hh"
#include <iostream>
#include <cstring>

using namespace editor;

//extends
class MyEditingBuffer : public EditingBuffer{
  public:
    bool replace(char c,char replacement, int offset);
    int replace(std::string str, std::string replacement, int offset);

    void justify(char **viewingBuffer, int rows, int cols) {}

    int numberOfChars(){
      int chars = 0;
      for(int i = 0; i < sizeof(buffer); i++){
        if(buffer[i]!='\0'){
          chars++;
        }
      }
      return chars;
    }
};
#endif
