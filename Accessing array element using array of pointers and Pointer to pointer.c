#include<stdio.h>
#include<stdlib.h>

int main(){

 int a[]={1,2,3,4,5};

 printf("Printing elements from array a[] \n");

 for(int i=0;i<5;i++){
  printf("%d \n",a[i]);
 } 

 printf("\n");
 
 /*
 Declaring an array of pointers, where each element represents an address of each element in array a[]
  e.g., a: address of a[0]
        a+1: address of a[1]
        a+2: address of a[2]
        Likewise......
 */

 int *p[]={a,a+1,a+2,a+3,a+4};
 
 //Declaring a pointer pp to a pointer p
 int **pp=p;

 printf("a:(It's an address of an element a[0]) %p \n",a);
 printf("p:(It's an address of an element p[0]) %p \n",p);
 printf("pp:(It should be same as value of p as above) :  %p \n",pp);

 printf("\n\n");
 
 printf("Accessing a[3]=4 using different ways \n");
 printf("Using a[3]: %d \n",a[3]);
 printf("Using *(a+3): %d \n",*(a+3));
 printf("Using *p[3]: %d \n",*p[3]);
 printf("Using *(*(p+3)): %d \n",*(*(p+3)));
 printf("Using *(*(pp+3)): %d \n",*(*(pp+3)));

return 0;
}
