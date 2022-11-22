#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//Implementation of file operations : read a file and write on a file, std input and output printing.
void q1()
{
FILE  *fp,*fw;
	fp=fopen("sale.txt","r");
	fw=fopen("write.txt","w");
	if(fp==NULL){
		printf("file is empty");
		return;
		}
 	char area[10];
	char rep[10];
	char item_name[10];
	int item_q;
	double price;
	fprintf(fw,"area rep item_name  item_q  	price	 total\n");
	while(fscanf(fp,"%s %s %s %d %lf",area,rep,item_name,&item_q,&price)!=EOF)
	{
		fprintf(stdout,"%s %s %s %d %lf \n ",area,rep,item_name,item_q,price);
		double total=item_q*price;
		 fprintf(fw,"%s %s %s %d %lf %lf \n ",area,rep,item_name,item_q,price,total);
		}
		fclose(fp);
}







//Structure in C. Using struct to create user define struct and do file operations on it.
//Use of pointers in structure.
#define row 50
struct sale
{
	char area[10];
	char rep[10];
	char item_name[10];
	int item_q;
	double price,total;
};
void display(struct sale s[])
{
for(int i=0;i<row;i++){
printf("%s %s %s %d %lf %lf\n",s[i].area,s[i].rep,s[i].item_name,s[i].item_q,s[i].price,s[i].total);
}
}
void q2()
{
	struct sale s1[row+1],*p;
	FILE *fp=fopen("sale.txt","r");
	int i=0;
	while(fscanf(fp,"%s %s %s %d %lf",s1[i].area,s1[i].rep,s1[i].item_name,&s1[i].item_q,&s1[i].price)!=EOF)
	{
	s1[i].total=s1[i].item_q*s1[i].price;
	i++;
	}
	//Display row 1 using pointer.
	display(s1);
	p=&s1[1];
	printf("Printing the data using pointer: %s %s %s %d %lf",p->area,p->rep,p->item_name,p->item_q,p->price);
	//Take input from user and updating the row 1.
	printf("Input a custom data:\n");
	scanf("%s %s %s %d %lf",p->area,p->rep,p->item_name,&p->item_q,&p->price);
	display(s1);
}

int main()
	{
	q1();
	q2();
	}

