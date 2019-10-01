#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for close

#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>

#include "dbserver.h"

int loadCSV(movie_t *movies){
 //input file stream to read CSV
  FILE *csv;
  csv = fopen("scifi.csv","r");
  //failed to open file
  if(!csv){
    printf("Error: Unable to open scifi.csv\n");
    return -1;
  }

  int  i = 0;
  //read all the data in the file
  while(!feof(csv) && i < NUM_RECORDS){
    fscanf(csv, "%[^,],%[^,],%d,%d,%[^\n]%*c",
           movies[i].title,
           movies[i].director,
           &movies[i].year,
           &movies[i].oscars_won,
           movies[i].origin_country);
    i++;
  }
  //close the file
  fclose(csv);
  //read successful
  return 0;
}


int main(void) {
   int sockfd, bindret, fd, clientfd; //socket file descriptors
   socklen_t clilen;
   char buffer[DEFAULT_STRLEN];
   struct sockaddr_in serv_addr, cli_addr; //address structs
   int r, s;
   int read;
   int rn, row;
   movie_t movies[NUM_RECORDS];

   clilen = sizeof(cli_addr);

   //load csv file
   read = loadCSV(movies);
   if(read < 0) printf("Error: Unable to read file\n");

   printf("Starting server...\n");

   /* Step 1 : create a socket with the socket() system call */
   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   if (sockfd < 0) {
      printf("Error: Unable to open socket\n");
      exit(0);
   }

   serv_addr.sin_family = AF_INET;
   serv_addr.sin_addr.s_addr = INADDR_ANY;
   serv_addr.sin_port = htons(12345);

   /* Step 2 : Bind the socket to an address using the bind() system call */
   bindret = bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
   if (bindret < 0) {
      printf("Error: Unable to bind\n");
      exit(0);
   }

  /* Step 3 : Listen for connections with the listen() system call */
  if (listen(sockfd,SOMAXCONN) < 0){
    printf("Error: Unable to bind\n");
    exit(0);
  }

  /* Step 4 : Accept a connection with the accept() system call */
  clientfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
  if (clientfd < 0) {
     printf("Error: Unable to accept\n");
     exit(0);
  }
  else{
    //set buffer to "HELLO"
    strncpy(buffer, "HELLO\n", 7);
    send(clientfd,buffer,strlen(buffer), 0);
  }

  while(1){
    /*reset the buffer*/
    memset(buffer, 0, DEFAULT_STRLEN);

    /* Step 5 : Send and receive data */
    r = recv(clientfd,buffer,DEFAULT_STRLEN, 0);
    if (r < 0) {
       printf("Error: Unable to read from socket");
       exit(0);
    }

    printf("Message received: %s\n",buffer);
    char temp[DEFAULT_STRLEN];
    rn = sscanf(buffer, "%s %d", temp, &row);

    //just command
    if(rn == 1){
      //BYE
      if ((strcasecmp(temp, "BYE") == 0) || (strcasecmp(buffer, "BYE\n") == 0) ){
        printf("Closing connection with client.\n");
        close(clientfd);
        close(sockfd);
        exit(0);
      }

      //GET
      if(strcasecmp(temp, "GET") == 0){
        printf("Sent entire data of movies\n");
        for(int i = 0; i < NUM_RECORDS; i++){
          snprintf(buffer, 5*DEFAULT_STRLEN, "%d: %s, %s, %d, %d, %s\r\n", i ,
                   movies[i].title,
                   movies[i].director,
                   movies[i].year,
                   movies[i].oscars_won,
                   movies[i].origin_country);
          s = send(clientfd, buffer, strlen(buffer),0);
        }
      }
    }
    //command with index of row
    else if(rn == 2){
      if(strcasecmp(temp, "GET") == 0){
        if(row < 0 || row > NUM_RECORDS){
          printf("Error: index out of bound\n");
          exit(0);
        }
      else{
        snprintf(buffer, 5*DEFAULT_STRLEN, "%d: %s, %s, %d, %d, %s\r\n", row,
                 movies[row].title,
                 movies[row].director,
                 movies[row].year,
                 movies[row].oscars_won,
                 movies[row].origin_country);
         s = send(clientfd, buffer, strlen(buffer), 0);
      }
    }
  }
      /* Step 5 : Send and receive data */
      //s = send(clientfd,buffer,strlen(buffer), 0);

      if (s < 0) {
         printf("Error: Unable to write to socket\n");
         exit(0);
    }
  }
     return 0;
  }
