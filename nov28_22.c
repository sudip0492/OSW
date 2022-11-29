//Date:28.11.22
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
void twofork()
{
	pid_t pid;
	fork();
	fork();
	
	printf(" Process id %ld Parent process id %ld \n",(long)getpid(),(long)getppid());
}
void threefork()
{
	pid_t pid;
	//We can also use a loop to call fork()  3 times.
	fork();
	fork();
	fork();
	printf(" Process id %ld Parent process id %ld \n",(long)getpid(),(long)getppid());
}

void q1()
{
	pid_t pid;
	for(int i=0;i<3;i++)
	{
		pid=fork();
		if(pid==0)
			break;
	}
	printf(" Process id %ld Parent process id %ld \n",(long)getpid(),(long)getppid());
}
void q2(int n)
{
	pid_t pid;
	int i;
	for(i=0;i<n;i++)
	{
		pid=fork();
		if(pid==0)
			break;
	}
	printf(" Process id %ld Parent process id %ld \n",(long)getpid(),(long)getppid());
}
	
int main(int argc,char* argv[])
{
	//Draw the process diagram for the following functions call.
	//twofork();
	//threefork();
	//write a function to call three forks. The following fork should only be called by the parent,and not the child created by the root parent.
	//q1();
	//write a function to generate an error. An error occurs when a parent gets terminated before the child.
	if(argc<2)
	{
		printf("Usage : process input");
		return 0;
	}
	int n=atoi(argv[1]);
	q2(n);
}
