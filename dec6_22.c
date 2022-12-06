// Date: 6.12.22

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
int q1()
{
	pid_t childpid,childpidR;
	char *arg[]={"/bin/ls","ls","-l", NULL};
	childpid = fork();
	if (childpid == -1) 
	{
		perror("Failed to fork");
		return 1;
	}
	if (childpid == 0) 
	{
	//All these commands below gives the same output.
		//child code //
		//execl("/bin/ls", "ls", "-l", NULL);
		//execv("/bin/ls",&arg[1]);
		execv(arg[0],&arg[1]);
		printf("hi");
		return 1;
	}
	else
	{
	childpidR = wait(NULL);
	// parent code //
		printf("Original child id : %d    ,Returned child : %d \n",childpid,childpidR);
		return 1;
	}
return 0;
}


int q2()
{
	pid_t childpid;
	childpid = fork();
	if (childpid == -1) 
	{
		perror("Failed to fork");
		return 1;
	}
	if (childpid == 0) 
	{
		//Placing the address of the fibonacci code output in the first argument of execl. The second argument is signifying how to run the located file. 
		execl("/home/student/Documents/2041013030/fibo.o", "./fibo.o", NULL);
		return 1;
	}
	else
	{
	childpid = wait(NULL);
	// parent code //
		printf("Original child id : %d ",childpid);
		return 1;
	}
return 0;
}

int q3(char **argv)
{
	int i;
	char *cmdarg[20];
	for(i=1;argv[i]!=NULL;i++)
		cmdarg[i-1]=argv[i];	
	
	cmdarg[i-1]=NULL;
	execv("/bin/ls",cmdarg);
	return 0;
}

int main(int argc,char *argv[])
{
	//************exec() function************* 
	/*
	The execl (execl, execlp and execle) functions pass the command-
line arguments in an explicit list and are useful if the number of command-
line arguments are known at compile time.

	The execv (execv, execvp and execve) functions pass the command-
line arguments in an argument array.
*/
	//Use the exec() function to run the "ls -l" command through the child process.
	q1();
	//Run the fibonacci code whose output file is  " fibo.o " .
	q2();
	// write the command in CLI and run it through child process . For eg.  ./a.out ls    or    ./a.out ls -l
	q3(argv);
	return 0;
}
