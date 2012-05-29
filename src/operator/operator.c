#include <stdlib.h>
#include <stdio.h>
#include "operator.h"
#include "../util/matrix.h"
#include "../util/perceptron.h"


int main(int argc, char *argv[]){


	char input[MAX_INPUT_LENGTH];

	system("clear");
	printf("Welcome to the Genre Calculator: Science Fiction edition!\n\n\n");
	printf("Menu:");
	printf("\t[L]oad Calculator\n");
	printf("\t[C]reate New\n");
	
	printf("\t[E]xit\n\n");
	printf("Selection: ");

	scanf(input);
	
	switch (input[0]) {
		case 'l': loadMatrixThenSubMenu();
		case 'c': createMatrixThenMainMenu();
		case 'e': return 0;
		default: fprintf(stderr, "Error: Improper input"); main();
	
	}
	
	
/* //TEST INPUT


	MATRIX a;
	MATRIX *wgt;
		wgt = malloc(sizeof(MATRIX));
		memset(wgt, 0, sizeof(MATRIX));
	MATRIX t;
	int val1[] = {1,0,0,0,1,0};
	int val2[] = {5,8,7,4,6,8};
	int val3[] = {0};
	
	t.rows = 1;
	t.cols = 1;
	t.values = val3;
	
	a.rows = 1;
	a.cols = 6;
	wgt->rows = 6;
	wgt->cols = 1;
	a.values = val1;
	wgt->values = val2;

	
	printf("\n\nMatrix a:");
	printMatrix(a);
	printf("\n\nWeight Matrix:");
	printMatrix(*wgt);
	
	perceptronLearn(1, a, t, wgt);
	printMatrix(*wgt);

*/

}
