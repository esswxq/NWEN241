
/**
 * editor.c
 *
 * You must implement the functions in editor.h in this file.
 * Consult the assignment handout for the detailed specifications of each of the functions.
 *
 * Student ID:300403758
 * Name: Xianqiong Wu
 */
 #include "stdio.h"
 #include "editor.h"
 #include "string.h"
 #include "stdbool.h"

//task1 - to insert
 int editor_insert_char(char *editing_buffer, char to_insert, int pos) {
     char toMove[EDITING_BUFLEN - (pos + 1)];          //creats a new char to store characters after pos
     for (int i = 0; i < EDITING_BUFLEN - pos - 1; i++) {
         toMove[i] = editing_buffer[i + pos];
     }
     editing_buffer[pos] = to_insert;                  //set pos char to insert char
     for (int i = 0; i < EDITING_BUFLEN - pos - 1; i++) {
         editing_buffer[i + pos + 1] = toMove[i];      //move characters in toMove to buffer
     }

     return 1;
 }

 //task2 - to delete
 int editor_delete_char(char *editing_buffer, char to_delete, int offset) {
     int position;																	//
     for (int i = offset; i < EDITING_BUFLEN; i++) {			  //goes through whole char from index of offset
         if (editing_buffer[i] == to_delete) {				//finds the char eauqls delete char
            position = i;
             break;																		//stop when find
         }
     }
     if (editing_buffer[position] == to_delete){
         for (int i = position; i < EDITING_BUFLEN - 1; i++) {		//from pos of deletedChar
             editing_buffer[i] = editing_buffer[i + 1];		//shift pos by increase one
         }
         editing_buffer[EDITING_BUFLEN] = '\0';						//set the final pos to null
         return position;
     }
 }

//task3 - to replace
 int editor_replace_str(char *editing_buffer, const char *str, const char *replacement, int offset) {
   int position = -1;                           //position where I delete first char

   for(int i = offset; i<strlen(str);i++){
    position = editor_delete_char(editing_buffer,str[i],offset);   //delete str in buffer
   }
   for(int i = 0;i<strlen(replacement);i++){
      int insert = editor_insert_char(editing_buffer,replacement[i],position+i);  //insert replacement from where I delete
   }
   return position+strlen(replacement)+1;   //return last position of char
	 }


//task 4 - to view


//main
/*
 int main() {
	 	 char editing_buffer[EDITING_BUFLEN] = "The quick brown fox";			//the char we need to edit
		 //char[][] viewing_bufer[VIEWING_COLS][VIEWING_ROWS];

		 //for testing
     int r = editor_insert_char(editing_buffer,'s', 9);									//invoke insert function
		 int r = editor_delete_char(editing_buffer,'f',10);									//invoke delete function
		 int r = editor_replace_str(editing_buffer, "brown", "blue", 0);		//invoke
     printf("\n%s", editing_buffer);
     //int r = editor_view(viewing_bufer, editing_buffer, 1);
     return 0;
 }
 */
