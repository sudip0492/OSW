#include<stdio.h>
void q1(int i,int n)
{
	if(i>n)
		return;
	printf("%d ",i);
	q1(i+1,n);
}
int q2(int n)
{
	if(n==0)
		return 0;
	return n+q2(n-1);
}
void q3(int a,int b,int n)
{
	if(n==0)
		return;
	printf("%d ",a);
	q3(b,a+b,n-1);
}
void q4(int* a,int n,int i)
{
	if(i==n)
		return;
	printf("%d ",a[i]);
	q4(a,n,i+1);
}
int q5(int n)
{
	if(n==0)
		return 0;
	return 1+q5(n/10);
}
int q6(int n)
{
	if(n==0)
		return 0;
	return n%10+q6(n/10);
}
int q7(int a,int b)
{
	if(b==0)
		return a;
	return q7(b,a%b);
}
int q8(int n)
{
	if(n==1)
		return 1;
	return n*q8(n-1);
}
void q9(int n)
{
	if(n==0)
		return;
	q9(n/2);
	printf("%d",n%2);
}
int q10(int i,int n)
{
	if(i>=n)
		return 1;
	if(n%i==0)
		return i;
	return q10(i+1,n);
}
int main()
{
	int n;
	printf("Enter the value of n , to print the first n natural numbers ,their sum  and the fibo. series upto n terms :");
	scanf("%d",&n);
	printf("\nEnter a number to count the digits and print its sum :"); 
	int a;
	scanf("%d",&a);
	printf("\nEnter two numbers to find their GCD :");
	int x,y;
	scanf("%d%d",&x,&y);
	printf("\nEnter a number to find its factorial, binary equivalent and check it for prime : ");
	int b;
	scanf("%d",&b); 
	printf("\n\n1.The first %d natural numbers are: ",n);
	q1(1,n);
	printf("\n2.The sum of numbers from 1 to %d is : %d ",n,q2(n));
	printf("\n3.The fibonacci series for n terms is : ");
	q3(0,1,n);
	int arr[]={1,2,3,4,5};
	printf("\n4.The elements of the array are {1,2,3,4,5} are : ");
	q4(arr,5,0);
	printf("\n5.The number of digits in %d is : %d",a,q5(a));
	printf("\n6.The sum of the digits of %d is : %d",a,q6(a));
	printf("\n7.The GCD of %d and %d is : %d ",x,y,q7(x,y));
	printf("\n8.The factorial of %d is : %d.",b,q8(b));
	printf("\n9.The Binary equivalent of %d is : ",b);
	q9(b);
	if(q10(2,b)==1)
		printf("\n10.The number %d is a prime number.",b);
	else
		printf("\n10.The number %d is not a prime number because %d is a factor of it.\n",b,q10(2,b));
	}
