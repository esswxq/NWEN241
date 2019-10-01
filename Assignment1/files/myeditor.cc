/**
 * myeditor.cc
 *
 * You must implement the member functions, including constructors, of your class defined in myeditor.hh.
 * Consult the assignment handout for the detailed specifications of each of the member functions.
 *
 * Student ID: 300403758
 * Name: Xianqiong Wu
 */
#include "myeditor.hh"

//int main() {
//    MyEditingBuffer meb;
    //meb.setBuffer("The quick brown fox", 21);
    //meb.replace('b', 'B', 5);
//    meb.replace("brown", "violet", 8);
//}

//task1 - to replace the char
bool MyEditingBuffer::replace(char c, char replacement, int offset) {
    for (int i = 0; i + offset < sizeof(buffer); i++) {
        if (buffer[offset + i] == c) {
            buffer[offset + i] = replacement;
            return true;
        }
    }
    return false;
}

//task 2 - to  replace
// I tried but seems failed
int MyEditingBuffer::replace(std::string str, std::string replacement, int offset) {
  std::string line = line.replace(line.find(str), offset, replacement);
  //cout << line << endl;
  return 0;
}

//#endif
