#include "ab.h"
main() 
    { 
       int fd;
       char str[100];   
       unlink("aPipe");  /* Remove named pipe if it already exists */ 
       mknod("aPipe", S_IFIFO, 0);  /* Create name pipe */ 
       chmod("aPipe", 0660);  /* Change its permissions */ 
       fd = open("aPipe", O_RDONLY);  /* Open it for reading */ 
        while(readLine(fd, str) );  /* Display received messages */ 
          printf("%s\n", str "neha"); 
       close(fd);   /* Close pipe */ 
     }

    int readLine( fd, str ) 
     int fd; 
     char* str; 
     /* Read s single NULL-terminated line into str from fd */ 
     /* Return 0 when the end of input is reached and 1 otherwise */
     { 
        int n; 
          do /* Read characters until NULL or end of input */ 
           { 
              n = read( fd, str, 1);  /* Read one character */ 
           } 
          while ( n>0 && *str++ != NULL ); 

        return ( n> 0 );  /* Return false if end of input */ 
      } 


