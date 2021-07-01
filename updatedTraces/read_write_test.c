#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define MAXBUFFERSIZE 542 //a constant for the maximum size of the buffer
// for ease of changing for the test packet values

int main()
{
  
  char buff[MAXBUFFERSIZE];	// buffer for readss and writes
  int z = 1;	// int for read return  value
  int y = 1;	// int for write return value
  int fp1 = open("source.txt", O_RDONLY);		//uses the system command for open read only for the source
  int fp2 = open("destination.txt", O_WRONLY);		//uses the system command for open and write only for the destination
  double exe_time = 0.0; 				//double for the write execution time 

  if(fp1 == -1)		//checks if the open threw a error
  {
    printf("source file ope Open Error");
    exit(1);
  }
  if(fp2 == -1)	       //checks of the open threw a error
  {
    printf("fp2 Open Error");
    exit(1);
  }

  clock_t begin = clock(); 	//start timing the read and writes
  while(z!=0||z!=-1||y!=-1)
  {
	z = read(fp1,buff,MAXBUFFERSIZE);	// read from the file using the size set in MAXBUFFERSIZE
  	y = write(fp2,buff, MAXBUFFERSIZE);	//write using amount set in MAXBUFFERSIZE
	if(z==0)	// breaks the while loop if the read file finishes
		break;	
  }
  clock_t end = clock(); 	// end the timer for the reads and writes
  exe_time = (double)(end-begin)/CLOCKS_PER_SEC;	// calculate elapsed time
  if(z==0)		// print a message confiming success and execution time
  {
	  printf("source file finished\n"); 
  	  printf("Execution time: %f\n",exe_time);
  }  
  else if(z==-1)	// print a message if there is a read error
  {
	  printf("source error\n");
  }
	
  if(y==-1)		// print a message if there is a write error
  {
	  printf("destination error\n");
  }
  close(fp2);	// close the destination file
  close(fp1);	// close the source file

  return 0;
	
}
