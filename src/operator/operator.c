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

	scanf("%s\n", input);
	
	switch (input[0]) {
		case 'c': createMatrixThenMainMenu(); return 0;
		case 'l': loadMatrixThenSubMenu(); return 0;
		case 'e': return 0;
		default: fprintf(stderr, "Error: Improper input\n"); main();
	
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

void loadMatrixThenSubMenu() {
	
	char input[MAX_FILE_NAME_LENGTH];
	FILE *iFile;
	NETWORK *n;
	
	system("clear");
	printf("Please input filename to load or [ENTER] to exit: ");
	scanf("%s\n", input);
	
	if (!input){
		return;
	
	}
	
	n = dataLoad(input);
	
	subMenu(n);
	return;

}

void createMatrixThenSubMenu {

	int i;
	int val;
	char *input;
	FILE *oFile;
	NETWORK *n;
		n = malloc(sizeof(NETWORK));
			memset(n, 0, sizeof(NETWORK));
		n->weights = malloc(sizeof(MATRIX));
	
	system("clear");
	
	printf("NOTE: Maximum of 20 queries.\n");
	for(i = 0; i < 20; i++) {
		printf("\nPlease input query: ");
		memset(input, 0, MAX_QUERY_LENGTH);
		input = malloc(MAX_QUERY_LENGTH);
		scanf("%s\n", input);
		n->queries[i] = input;
	
	}
	
	n->weights->rows = i;
	n->weights->cols = 1;
	n->weights->values = malloc(n->weights->rows);
	printf("Please input initial value of weight matrix: ");
	scanf("%d\n", &val);
	memset(n->weights->values, val, n->weights->rows);
	
	subMenu(n);
	return;

}

void subMenu(NETWORK *n) {

	system("clear");
	printf("Shit!\n");

}
