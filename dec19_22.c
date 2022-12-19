#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#define BLKSIZE 1024
#define MAX 50


//   system() function
void q1()
{
	system("ls -l");	
}


//	Reading and writing to buffer using stdin/stdout.
void q2()
{
	int bytesread,byteswrite;
	char buffer[BLKSIZE];
	
	bytesread=read(STDIN_FILENO,buffer,MAX);
	byteswrite=write(STDOUT_FILENO,buffer,bytesread);
}


//	File Descriptor.
void q3()
{
	int fd=open("dec19_22.c",O_RDONLY);
	printf("File Descriptor : %d",fd);
	
	//fie desciptor: 0-->stdout,1-->stdin,2-->stderr , so 3--> fd.
	//if we open another file now... its fd will be 4 and so on.
	//Note : smallest available fd is 3.
	
	
}



//	copy a file content to another file.The destination file should be already created.
void q4(char* argv[])
{
	int src,des,bytesread,byteswrite;
	char buffer[BLKSIZE];
	src=open(argv[1],O_RDONLY);
	des=open(argv[2],O_WRONLY);
	do
	{	
		bytesread=read(src,buffer,MAX);
		byteswrite=write(des,buffer,bytesread);
	}while(bytesread!=0);
}



//	copy a file content to another file, if file destination file doesnt exists.. it will create one and then copy.
void q5(char* argv[])
{

	int src,des,bytesread,byteswrite;
	char buffer[BLKSIZE];
	mode_t fdmode = (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	src=open(argv[1],O_RDONLY);
	des=open(argv[2],O_WRONLY|O_CREAT,fdmode);
	do{
		bytesread=read(src,buffer,50);
		byteswrite=write(des,buffer,bytesread);
	}while(bytesread!=0);
}


/*NOTE: 1. cat function is used to see a file.
	   2. to copy a content of stdout command in cli, use '>' .
	   For eg, ls > myfile
	   	     cat myfile
	   This will copy the content of output of the command 'ls' into myfile, further we use cat myfile to print the content.
*/



//dup() function
void q6()
{
	int fd,nfd;
	fd=open("dec19_22.c",O_RDONLY);
	printf("file open success\n");
	//sleep(1);
	
	nfd=dup(fd);
	printf("Duplicate fd=%d \n",nfd);
	
	close(0);//closes std input and empties the slots, this will be occupied the process created below.
	nfd=dup(fd);
	printf("Duplicate fd=%d \n",nfd);
	
	close(2);//closes std error and empties the slot , this will be occupied the process created below.
	nfd=dup(fd);
	printf("Duplicate fd=%d \n",nfd);
	
	//Note: do not close std output, orelse no further printing will take place.
	
	close(fd);
	close(nfd);
}

//dup2() function
void q7()
{
	int fd,nfd;
	fd=open("dec19_22.c",O_RDONLY);
	printf("file open success\n");
	//sleep(1);
	
	nfd=dup(fd);
	printf("Duplicate fd=%d \n",nfd);
	
	nfd=dup2(fd,0);//it closes the file 0 i.e. std input file, and copies the file fd into the slot.
	/*Important exam question: 
	
	dup2(fd1,fd2); 
	
	    is equivalent to   
	 
	  
	close(fd2);
	dup(fd1);
	  
	  
	  */	 					
	printf("Duplicate fd=%d \n",nfd);
}

int main(int argc,char* argv[])
{
	//q1();
	//q2();
	//q3();
	//q4(argv);
	//q5(argv);
	//q6();
	//q7();
}
