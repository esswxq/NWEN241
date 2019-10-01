/**
* editor.hh
*/

#ifndef __EDITOR2_HH__
#define __EDITOR2_HH__

#include <iostream>
#include <cstring>

namespace editor2
{
  class EditorUtilities
  {
  public:
    //function for test 10
    static int countWords(const char *editing_buffer,int size);
    //function for test 11
    static int searchMultipleNoCase(char *editing_buffer, int size, std::string str, int *positions, int occurrences);
  };
}


#endif
