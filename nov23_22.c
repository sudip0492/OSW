//Date: 23 Nov 2022
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char **makeargv_version1(char *s)
{
	int ntokens,i;
	char *t,**argvp;
	argvp=NULL;
	t=(char *)malloc(sizeof(char)*(strlen(s)));
	strcpy(t,s);
	
	if(strtok(s," ")!=NULL)
	{ /* count the number of tokens in s */
		for(ntokens=1;strtok(NULL," ")!=NULL;ntokens++);
	}
	printf("Number of tokens=%d\n",ntokens);
	argvp=(char **)malloc((ntokens+1)*sizeof(char *));
	
	/* insert pointers to tokens into the argument array */
	*argvp=strtok(t," ");
	for(i=1;i<ntokens;i++){
		*(argvp+i)=strtok(NULL," ");
	}
	
	*(argvp+ntokens)=NULL; /* put in final NULL pointer */
	return argvp;
}
int main(int argc,char *argv[])
{
//****************Introduction to Argument Arrays******************
	char s[]="This is a string";
	char **myargv;
	if(argv[1]!=NULL)//If user enters any custom string.
	myargv=makeargv_version1(argv[1]);
	else //If user do not enter any custom string, use the predefined string.
	myargv=makeargv_version1(s);
	
	if(myargv==NULL)
		fprintf(stderr,"Failed to construct an argument array\n");
	else
	{
		for(int i=0;myargv[i]!=NULL;i++)
		printf("Myargv[%d]: %s\n",i,myargv[i]);
	}
	return 0;
}

