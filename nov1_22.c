#include<stdio.h>
#include<string.h>
void q1()
{
	char str1[]="A Rose is a Rose";
	char str2[]="Rose";
	char* pos=strstr(str1,str2);
	if(strlen(pos))
		printf("exists \n");
	else
		printf("DNE\n");
}
//taking arguments input from main
//int main(int argc,char* argv[])
//{
//	char* str1,*str2;
//	str1=argv[1];
//	str2=argv[2];
//	strcat(str1,str2);
//	for(int i=0;i<strlen(str1);i++)
//		printf("%c",str1[i]);
//q1();
//}
void q3()
{
	//files
	FILE *fp=fopen("read.txt","r");
	char str[50];
	fgets(str,50,fp);
	puts(str);
	fclose(fp);
}

int main()
{
	q3();
}
