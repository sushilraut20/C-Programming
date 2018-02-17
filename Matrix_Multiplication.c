/* 
 * Description: 1)Matrix-Matrix Multiplication
 *		2)Matrix-Vector Multiplication
 * Key-Features of the program:
 * 1) Dynamic allocation of memory to metrices and vectors using malloc
 * 2) Generation of 2 metrices of size 1000*1000 and a vector of size 1000*1 with the random numbers between 0 and 1 using rand and srand from <stdlib.h> API.
 * 3) Usage of optimization flags while compiling the code with following command:
 *    gcc -O1/O2/O3 matrix_Multiplication.c -o matrix_Multiplication
 * 4)Handling memory leakage using free() function and checking for the same using command:
 *    valgrind --tool==memcheck --leak-check-yes ./matrix_Multiplication
 * 5) Calculating time for particular multiplication process using gettimeofday() function from <sys/time.h> API
 * 6) Calculating time for entire program execution using below command:
 *     time ./matrix_Multiplication   
 */


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>

int ra,i,j;

float ** insert_Data_Into_The_Matrix(float **matrix,int r,int c){
 for(i=0;i<r;i++){
  for(j=0;j<c;j++){
    ra=rand()%9;
    matrix[i][j]=(float)ra/10;
  }
 }
 return matrix; 
 }

float * insert_Data_Into_The_Vector(float * vector, int r){
 for(i=0;i<r;i++){
  ra=rand()%9;
  vector[i]=(float)ra/10;
 }
 return vector;
}
 

float ** matrix_Matrix_Multiplication(float **matrix1, float **matrix2, float **result,int r,int c){
  for(i=0;i<r;i++){
   for(j=0;j<c;j++){
    result[i][j]=0;
    for(int k=0;k<c;k++){
      result[i][j]+=matrix1[i][k]*matrix2[k][j];
    }
   }
  }
 return result;
}

float * matrix_Vector_Multiplication(float **matrix1, float *vector, float *result,int r,int c){
 for(int i=0;i<r;i++){
  result[i]=0;
  for(int j=0;j<c;j++){
   result[i]+=matrix1[i][j]*vector[j];
  }
 }
 return result;
}


int main()
{

 float **array1=NULL;
 float **array2=NULL;
 float **matrix_Matrix_Multiplication_Result=NULL;
 float *vector=NULL;
 float *matrix_Vector_Multiplication_Result=NULL;
 
 struct timeval start,end;

 srand(time(0));

 int r=1000, c=1000,i,j;

 /* Initialization of memory for Matrices Calculation
  *  First Initialize the memory for rows in the metrices, then using for loop, initialize the memory for columns
  */
 
 array1=(float **)malloc(r*sizeof(float *));
 array2=(float **)malloc(r*sizeof(float *));
 matrix_Matrix_Multiplication_Result=(float **)malloc(r*sizeof(float *));

 for(i=0;i<r;i++)
 {
 array1[i]=(float *)malloc(c*sizeof(float));
 array2[i]=(float *)malloc(c*sizeof(float));
 matrix_Matrix_Multiplication_Result[i]=(float *)malloc(c*sizeof(float));
 }

 /*Initialization of memory for Vector Calculation */

 vector=(float *)malloc(r*sizeof(float));
 matrix_Vector_Multiplication_Result=(float *)malloc(r*sizeof(float));

 /* Checking whether memory allocation using malloc is successful */ 

 if(array1==NULL || array2==NULL || matrix_Matrix_Multiplication_Result==NULL || vector==NULL || matrix_Vector_Multiplication_Result==NULL )
 {
 printf(stderr,"malloc failed \n");
 exit(1);
 }
 
 
 array1=insert_Data_Into_The_Matrix(array1,r,c);
 array2=insert_Data_Into_The_Matrix(array2,r,c);
 vector=insert_Data_Into_The_Vector(vector,r);

 gettimeofday(&start, NULL);
// matrix_Matrix_Multiplication_Result=matrix_Matrix_Multiplication(array1,array2,matrix_Matrix_Multiplication_Result,r,c);
 matrix_Vector_Multiplication_Result=matrix_Vector_Multiplication(array1,vector,matrix_Vector_Multiplication_Result,r,c);
 gettimeofday(&end, NULL);


 printf("Elapsed: %fs \n",((end.tv_sec-start.tv_sec)*1000000 + end.tv_usec - start.tv_usec)/1000000.0);


 /* Deallocating the allocated memory.
  * Memory should be deallocated in the reverse sequence of allocation. i.e. Memory last allocated should be deallocated first.
  * In this case, memory allocated to columns in the metrices should be deallocated first.
  */

 for(i=0;i<r;i++){
  free(array1[i]);
  free(array2[i]);
  free(matrix_Matrix_Multiplication_Result[i]);
 }

 /* Memory deallocation for rows in metrices and vectors */

 free(array1);
 free(array2);
 free(matrix_Matrix_Multiplication_Result);
 free(vector);
 free(matrix_Vector_Multiplication_Result);
 
 array1=NULL;
 array2=NULL;
 matrix_Matrix_Multiplication_Result=NULL;
 vector=NULL;
 matrix_Vector_Multiplication_Result=NULL;
 
return 0;

}




