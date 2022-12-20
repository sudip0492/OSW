#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void q1()
{
    char rbuff[20],wbuff[20];
    int fd[2],bytesread; 
    pid_t pid;
    pipe(fd);
    pid=fork();
    if(pid)
    {//close(fd[1]);
    printf(" in parent");
	bytesread=read(fd[0],rbuff,20);
	write(1,rbuff,bytesread);
    }
    else
    {
    write(fd[1],"SEC-A",5);
    
    }
}    

int main()
{
	q1();
}
    
    
    
