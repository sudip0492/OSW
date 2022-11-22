#include<stdio.h>
#include<string.h>

//DATE: 21.11.22

void q1()
{
//Introduction to strtok():
	char str[] ="ITER-IBCS-SHM-SUM-IDS";
	char *token;
	token=strtok(str,"-");
	while (token!=NULL)
	{
		printf("Token=%s\n",token);
		token=strtok(NULL,"-");
	}
}

void q2() 	
{
//Using strtok with delimeters:
	char str[]="ITER-IBCS-SHM-SUM-IDS";
	char *delimiters="-";
	int numtokens;
	/* count the number of tokens in str */
	if (strtok(str, delimiters) != NULL)
	for(numtokens = 1; strtok(NULL, delimiters) != NULL;numtokens++) ;
	printf("Number of tokens=%d\n",numtokens);
}

void q3()
{
//Problem with strtok when using multiple threads:
	char str[] ="ITER-IBCS-SOA-SUM-ids";
	char ptr[] ="iter-ibcs-soa-sum-ids-CSE";
	char *token,*ptoken;
	token=strtok(str,"-");
	ptoken=strtok(ptr,"-");
	while (token!=NULL)
	{
		printf("Token=%s\n",token);
		token=strtok(NULL,"-");
	}
}

void q4()
{
//Introduction to strtok_r():
	char str[] ="Lesson-plan-USP-DOS-FML-PLC";
	printf("Entered string : ");
	puts(str);
	char *token;
	char *last;
	token = strtok_r(str, "-", &last);
	while (token!=NULL) 
	{
		printf("Token:%s\n", token);
		printf("\t\tRemaining part of the string:%s\n",last);
		token = strtok_r(NULL, "-", &last);
	}
}

void q5()
{
//Resolving the problem when using Multiple threads with strtok_r():
	char str[] ="ITER-IBCS-SOA-SUM-ids";	
	char ptr[] ="iter-ibcs-soa-sum-ids-CSE";
	char *token,*ptoken,*sptr1,*sptr2;
	token=strtok_r(str,"-",&sptr1);
	ptoken=strtok_r(ptr,"-",&sptr2);
	while (token!=NULL)
	{
		printf("Token=%s\n",token);
		token=strtok_r(NULL,"-",&sptr1);
	}
}

void q6()
{
//Write a program to count the number of lines and number of words in each line.
	char str[]="ITER-IBCS-SOA*SUM-ids-iter-ibcs*soa-sum-ids-CSE";
	printf("The String is : %s.\n\n",str);
	char *lines,*endlines;
	lines=strtok_r(str,"*",&endlines);
	int lc=1;//linecounter
	while(lines!=NULL)
	{
		char *lasttemp;
		int numtokens;
		if (strtok_r(lines,"-",&lasttemp) != NULL)
	for(numtokens = 1; strtok_r(NULL, "-",&lasttemp) != NULL;numtokens++) ;
	printf("No. of words in Line %d is %d.\n",lc++,numtokens);
	lines=strtok_r(NULL,"*",&endlines);
	}
}	

int main()
{
 	//q1();
 	//q2();
 	//q3();
 	//q4();
 	//q5();
 	//q6();
}

