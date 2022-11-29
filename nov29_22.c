//Date: 29.11.22
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
void 	q1()
{
//Print x=10 for parent process and x=20 for child process.
	int x;
	x = 0;
	pid_t pid;
	pid=fork();
	x=pid==0?20:10;
	printf("I am process %ld and my x is %d at %p\n", (long)getpid(), x, &x);
}
void q2()
{
//Print statement of parent process should be printed after print statement of child statement.--> The parent process should wait until the child process is completed.
	int x;
	x = 0;
	pid_t pid,pidw;
	pid=fork();
	x=pid==0?20:10;
	pidw=wait(NULL);
	/*Returns: 0 or -1 if process has no more child 
		     A value which is the pid of the child process.
      Wait function will suspend the parent process until child process is terminated and on successful termination it returns the pid of the child process.*/
	printf("I am process %ld and my x is %d at %p\n", (long)getpid(), x, &x);
	printf("pid_w value is %ld\n",(long)pid);
	/*pid_w =0 or -1 for process with no child, pid_w =process id of the child process.*/
}
void q3(int n)
{
	pid_t pid,cpid;
	int i;
	for(i=0;i<n;i++)
	{
		pid=fork();
		if(pid)
			break;
	}
	fprintf(stderr,"\n process id %ld,parent process id %ld \n",(long)getpid(),(long)getppid());
	cpid=wait(NULL);
	printf("\nI am %ld wait returned %ld\n",(long)getpid(),(long)cpid);
}
int main(int argc,char* argv[])
{
	//q1();
	//q2();
	if(argc<2)
	{
		printf("Usage : process input");
		return 0;
	}
	int n=atoi(argv[1]);
	q3(n);
}
