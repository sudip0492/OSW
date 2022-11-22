#include <stdio.h>
#include <string.h>

//Union function in C:

/*A union is a special data type available in C that allows to store different data types in the same memory location. You can define a union with many members, but only one member can contain a value at any given time. Unions provide an efficient way of using the same memory location for multiple-purpose.*/

/*The size occupied in the memory=size of the largest variable declared in the definiton of union declaration. For eg. in q1() the size occupied will be 20 bytes.*/
void q1()
{
//Printing the data one by one.
	union Data {
   		int i;
   		float f;
  		char str[20];
	};

    union Data data;        
	
    data.i = 10;
    printf( "data.i : %d\n", data.i);
   
    data.f = 220.5;
    printf( "data.f : %f\n", data.f);
   
    strcpy( data.str, "C Programming");
    printf( "data.str : %s\n", data.str);

}
void q2()
{
//Printing the data all at once in the end.
	union Data {
   		int i;
   		float f;
  		char str[20];
	}; 
	

   union Data data;        
   
   data.i = 10;
   data.f = 220.5;
   strcpy( data.str, "C Programming");
   
   
   printf( "data.i : %d\n", data.i);
   printf( "data.f : %f\n", data.f);
   printf( "data.str : %s\n", data.str);

}
int main()
{
	printf("Question 1:\n");
	q1();
	printf("Question 1:\n");
	q2();
}
