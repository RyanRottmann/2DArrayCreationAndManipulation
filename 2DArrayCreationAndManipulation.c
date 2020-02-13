#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX 20

int check_error(int size);
void initalize_2Darray(int array[MAX][MAX], int size);
void print_2Darray(int array[MAX][MAX], int size);
int findZeros(int array[MAX][MAX], int size);
int findEvenOdd(int array[MAX][MAX], int size);
void loadDiagnal(int array [MAX][MAX], int size, int array2[MAX]);
void print1DArray(int array2[MAX],int size);
void print1DArrayDiagnally(int array2[MAX],int size);
void printTranspose(int array[MAX][MAX], int size);
void findMaxNumber(int array[MAX][MAX], int size);


int main (void){// Main
	srand(time (NULL));
	int array1[MAX][MAX];
	int array2[MAX];
	int size;

	printf("\nEnter the size of the 2D array: ");
	scanf("%d", &size);
	check_error(size);// returns 0 on fail
	while(check_error(size)==0){
		printf("Please enter a value betweekn 1-20 only: ");
		scanf("%d", &size);
	}
	array1[MAX][MAX] = array1 [size][size];// Sets the selected size to array1
	
	initalize_2Darray(array1, size);// Initializes 2D array
	print_2Darray(array1, size);// Prints random 2D array of selected size
	
	int zeros = findZeros(array1, size);// Sets # of zeros to int zeros
	printf("The number of zeros in 2-D Array: %d\n", zeros);

	int even = findEvenOdd(array1, size);// Finds # of even numbers and sets it to even
	int odd = size * size - even;// Finds # of odd numbers and sets to odd
	printf("The number of Even numbers: %d\nThe number of Odd numbers: %d\n", even, odd);
	findMaxNumber(array1, size);
	loadDiagnal(array1, size, array2);// Sets diagonal values of 2-D array1 to 1-D array2
	print1DArray(array2, size);// Prints 1-D diagonal array2
	print1DArrayDiagnally(array2, size);// Prints 1-D array2 diagonally
	printf("\nThe array printed transpose or having the x an y axis flipped is\n\n");
	printTranspose(array1, size);
	printf("\n");
	return 0;
}// End of main

int check_error(int size){// Error Check
	if (size<1 || size>MAX){
		return 0;
	}
	return 1;
}// End of error check

void initalize_2Darray(int array[MAX][MAX], int size){// Initialize array
	int i, j;
	for (i=0; i<size; i++){
		for (j=0; j<size; j++){
			array [i][j] = (rand()%10);
		}
	}
}// End of initialize array

void print_2Darray(int array[MAX][MAX], int size){// Print array
	printf("\n");
	int i, j;
	for (i=0; i<size; i++){
		for (j=0; j<size; j++){
			printf("%d", array[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}// End of print array

int findZeros(int array[MAX][MAX], int size){// Find zeros
	int i, j, counter=0;
	for (i=0; i<size; i++){
		for (j=0; j<size; j++){
			if (array[i][j] == 0){
				counter++;
			}
		}
	}
	return counter;
}// End of find zeros

int findEvenOdd(int array[MAX][MAX], int size){// Find even
	int i, j, counter=0;
	for (i=0; i<size; i++){
		for (j=0; j<size; j++){
			if (array[i][j] %2 == 0){
				counter++;
			}
		}
	}
	return counter;
}// End of find even

void loadDiagnal(int array[MAX][MAX], int size, int array2[MAX]){// Load diagnal
	int i, j;

	for (i=0; i<size; i++){
		for (j=0; j<size; j++){
			if (i==j){
				array2[i] = array[i][j];
			}
		}
	}
}// End of load diagnal

void print1DArray(int array2[MAX], int size){// Print 1D array
	int i;
	printf("The primary diagonal elements in the 2-D array, loaded into a 1-D array are: ");
	for (i=0; i<size; i++){
		printf("%d", array2[i]);
	}
	printf("\n");
}// End of print 1D array

void print1DArrayDiagnally(int array2[MAX], int size){// Print 1D array
	int i, temp;
	printf("\n");
	for (i=0; i<size; i++){
		temp = i;
		while (temp>0){
			printf(" ");// prints space before diagonal 
			temp--;
		}
		printf("%d\n", array2[i]);
	}
}// End of print 1D array

void printTranspose(int array[MAX][MAX], int size){// Print transpose
	int i, j;
	for (i=0; i<size; i++){
		for (j=0; j<size; j++){
			printf("%d", array[j][i]);
		}
	printf("\n");
	}

}// End of print transpose

void findMaxNumber(int array[MAX][MAX], int size){//Find max number

	int i, j, maxNum = 0;
	for (i=0; i<size; i++){
		for (j=0; j<size; j++){
			//printf("arrayVal = %d\n", array[i][j]);
			if (array[i][j] > maxNum){
				maxNum = array[i][j];
				//printf("maxNum = %d\n", maxNum);
			}
			//printf("%d", array[i][j]);
		}
	}
	printf("The maximum value in the 2D array is: %d\n", maxNum);
}// End of Find max number
