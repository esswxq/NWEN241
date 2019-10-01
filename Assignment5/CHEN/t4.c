#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <ctype.h>

#include "Assignment5.h"

int loadFile(movie_t *movies){
//input file stream to read CSV
  FILE *csv;
  csv = fopen("scifi.csv","r");
  if(!csv){
    printf("Failed to open scifi.csv\n");
    return -1;
  }

  int  index = 0;
  //read all the data in the file
  while(!feof(csv) && index < NUM_RECORDS){
    fscanf(csv, "%[^,],%[^,],%d,%d,%[^\n]%*c",
           movies[index].title,movies[index].director,&movies[index].year,&movies[index].oscars_won,movies[index].origin_country);
    index++;
  }
  //close the file
  fclose(csv);
  return 0;
}


int main(void) {
   int sockfd, bindret, fd, clientfd;
   socklen_t clilen;
   char buffer[DEFAULT_STRLEN];
   struct sockaddr_in serv_addr, cli_addr; //address structs
   int r, s;
   movie_t movies[NUM_RECORDS];

   //load csv file
   if(loadFile(movies) < 0) printf("Failed to read file\n");

   printf("Starting server...\n");

   /* Step 1 : create a socket with the socket() system call */
   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   if (sockfd < 0) {
      printf("Error: Unable to open socket\n");
      exit(1);
   }

   serv_addr.sin_family = AF_INET;
   serv_addr.sin_addr.s_addr = INADDR_ANY;
   serv_addr.sin_port = htons(12345);

   /* Step 2 : Bind the socket to an address using the bind() system call */
   bindret = bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
   if (bindret < 0) {
      printf("Error: Unable to bind\n");
      exit(1);
   }

   for(;;){
      /* Step 3 : Listen for connections with the listen() system call */
      if (listen(sockfd,SOMAXCONN) < 0){
        printf("Error: Unable to bind\n");
        exit(1);
      }

      clilen = sizeof(cli_addr);
      /* Step 4 : Accept a connection with the accept() system call */
      clientfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
      int pid;
      int new;
      if (clientfd < 0) {
         printf("Error: Unable to accept\n");
         exit(1);
      }

      //fork
      else{
        char m[] = "HELLO\n";
        send(clientfd,m,strlen(m), 0);

        pid = fork();
        if(pid == 0){
          int rnumber, row;

          while(1){
            /*reset the buffer*/
            memset(buffer, 0, DEFAULT_STRLEN);

            /* Step 5 : Send and receive data */
            r = recv(clientfd,buffer,DEFAULT_STRLEN, 0);
            if (r < 0) {
               printf("Error: Unable to read from socket");
               exit(1);
            }

            printf("Message received: %s\n",buffer);
            char temp[DEFAULT_STRLEN];
            rnumber = sscanf(buffer, "%s %d", temp, &row);

            if(rnumber == 1){
              //BYE
              if ((strcasecmp(temp, "BYE") == 0) || (strcasecmp(buffer, "BYE\n") == 0) ){
                printf("Closing connection with client.\n");
                close(clientfd);
                exit(1);
              }

              //GET
              if(strcasecmp(temp, "GET") == 0){
                printf("Sent entire database\n");
                for(int i = 0; i < NUM_RECORDS; i++){
                  snprintf(buffer, 5*DEFAULT_STRLEN, "%d: %s, %s, %d, %d, %s\r\n", i ,
                           movies[i].title,movies[i].director,movies[i].year,movies[i].oscars_won,movies[i].origin_country);
                  s = send(clientfd, buffer, strlen(buffer),0);
                }
              }
            }
            //get particular row
            else if(rnumber == 2){
              if(strcasecmp(temp, "GET") == 0){
                if(row < 0 || row > NUM_RECORDS){
                  printf("Out of bound\n");
                  exit(1);
                }
                else{
                  snprintf(buffer, 5*DEFAULT_STRLEN, "%d: %s, %s, %d, %d, %s\r\n", row,
                           movies[row].title, movies[row].director, movies[row].year, movies[row].oscars_won, movies[row].origin_country);
                   s = send(clientfd, buffer, strlen(buffer), 0);
                }
              }
            }
              /* Step 5 : Send and receive data */
              if (s < 0) {
                 printf("Error: Unable to write to socket\n");
                 exit(1);
               }
             }
           }
             //failed creating fork
           else{
             continue;
           }
         }
       }
     return 0;
   }
