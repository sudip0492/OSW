#include<stdio.h>
#include<stdlib.h>
void q1()
{
      FILE* fp;
     fp=fopen("file1.txt","r");
     char x;
     printf("The numbers are: \n");
     int count=0;
    while(fscanf(fp,"%c",&x)!=EOF)
    {
        int n=atoi(&x);
        if(n>=1&&n<=9){
        printf("%c \n",x);
        count++;
        }
        if(count==3)
        break;
    }
}
int main()
{
    q1();
}
