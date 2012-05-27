#include <stdlib.h>
#include <stdio.h>
#include "operator.h"
#include "../util/matrix.h"
#include "../util/perceptron.h"


int main(int argc, char *argv[]){

/*
	char input[MAX_INPUT_LENGTH];

	system("clear");
	printf("Welcome to the Genre Calculator: Science Fiction edition!\n\n\n");
	printf("Menu:");
	printf("\t[L]oad Calculator\n");
	printf("\t[C]reate New\n");
	
	printf("\t[E]xit\n\n");
	printf("Selection: ");

	scanf(input);
*/
	MATRIX a;
	MATRIX b;
	//MATRIX *result;
	MATRIX t;
	int val1[] = {1,4,2,4,1,4};
	int val2[] = {5,8,7,4,6,8};
	int val3[] = {0};
	
	t.rows = 1;
	t.cols = 1;
	t.values = val3;
	
	a.rows = 6;
	a.cols = 1;
	b.rows = 1;
	b.cols = 6;
	a.values = val1;
	b.values = val2;

	
	printf("\n\nMatrix a:");
	printMatrix(a);
	printf("\n\nMatrix b:");
	printMatrix(b);
	
	perceptronLearn(1, a, t, &b);
	printMatrix(b);


}
