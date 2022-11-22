//DATE: 22 Nov 2022
#include<stdio.h>
#include<unistd.h>
void q1()
{
//The array is being initialized. Hence memory will be allocated and the size of output file will be large.
	int myarray[50000] = {1, 2, 3, 4};
	myarray[0] = 3;
}
void q2()
{
//The array is just being declared. Hence no memory allocation is done.Further only one place value of array is initialized.The size of output file will be small.	
	int myarray[50000];
	myarray[0] = 3;
}
#include<fcntl.h>//included to use O_RDONLY
#include<sys/stat.h>
#include<errno.h>//included to print the error no.
void q3()
{
//errorno stores the location of recent error(last error that occured).
	int fd=open("nov21_22.c",O_RDONLY);//file exists
	int fd1=10;//No such file exists
	close(fd);
		printf("Error no after closing fd:%d \n",errno);
		perror("Message after closing fd:");
	close(fd1);
		printf("Error no after closing fd:%d \n",errno);
		perror("Message after closing fd1:");
}
#include<string.h>
void q4()
{
//errono stores the location of recent error(Last error that occured).Hence to store the previous error we use strerror(errno).
	int fd=open("nofile.c",O_RDONLY);
	printf("\n %s:  ",strerror(errno));
	int fd1=10;
	close(fd);
		printf("errno = %d\n", errno);
		perror("After closing fd");
		printf("\n %s:  ",strerror(errno));
	close(fd1);
		printf("errno = %d\n", errno);
		perror("After closing fd1");
		printf("\n %s:  ",strerror(errno));
}
void q5()
{
//To print all the errors.
	int error;
	for(error=0;error<133;error++)
		printf("\n%d: %s:  ",error, strerror(error));
}
void q6()
{
//The while loop of Example 2.8 has an empty statement clause. It simply calls close until it either executes successfully or encounters a real error.
	
	int error;
	int fildes;
	while (((error = close(fildes)) == -1) && (errno == EINTR));
	if (error == -1)
		perror("Failed to close the file"); /* a real close error occurred */
}
/*
/*The problem of restarting library calls is so common that we provide a library of restarted calls with prototypes defined in restart.h.
The functions are designated by a leading r_ prepended to the regular library name.
For example, the restart library designates a restarted version of close by the name r_close.
	#include "restart.h" //user-defined library, not a part of standard
	int fildes;
	if (r_close(fildes) == -1)
		perror("Failed to close the file"); /* a true close error occurred */
*/
int main()
{
/*******Comparison of size of executable module*******/

	q1();//The output file will be of large size.
	q2();//The output file will be of small size.
	
	
/*Reason: The executable module for Version 1 should be about 200,000 bytes larger than that of Version 2 because the myarray of Version 1 is initialized static data and is therefore part of the executable module. The myarray of Version 2 is not allocated until the program is loaded in memory, and the array elements are initialized to 0 at that time.*/


/*Direction: Create two output files.Comment q2() function call and compile the code and save the output file as test1.out.Similarly,comment q1() and uncomment q2() ,recompile the code and save the output file as test2.out.Now give command ls -l to check the size of the output file.


The Command are mentioned below:
	gcc nov22_22.c -o test1.out
	gcc nov22_22.c -o test2.out
	ls -al
*/


/***********ErrorNo************/

//Open two files, one which exists and other which doesn't.Now check the error description using appropriate functions.
	q3();
/*Output on terminal when executed: 
Error no after closing fd:0 
Message after closing fd:: Success
Error no after closing fd:9 
Message after closing fd1:: Bad file descriptor
*/
//Track the errors with strerr function.
	q4();
//Print all the errors.
	q5();
	q6();
	
}
