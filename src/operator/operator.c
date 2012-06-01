#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "operator.h"
#include "../util/matrix.h"
#include "../util/perceptron.h"
#include "../util/dataManage.h"


void createMatrixThenSubMenu();
void loadMatrixThenSubMenu();
void subMenu(NETWORK *n);
void operateInterface(NETWORK *n);
void trainInterface(NETWORK *n);

int main(int argc, char *argv[]) {


	char input[MAX_INPUT_LENGTH];
	// Output main menu
	system("clear");
	printf("Welcome to the Genre Calculator: Science Fiction edition!\n\n\n");
	printf("Menu:");
	printf("\t[L]oad Calculator\n");
	printf("\t[C]reate New\n");
	
	printf("\t[E]xit\n\n");
	printf("Selection: ");

	scanf("%s", input);
	
	// Operate menu
	switch (input[0]) {
		case 'c': createMatrixThenSubMenu(); return 0;
		case 'l': loadMatrixThenSubMenu(); return 0;
		case 'e': return 0;
		default:
			fprintf(stderr, "Error: Improper input\n");
			main(argc, argv);
			return 0;
	
	}
}

// Loads a saved matrix, then passes it to the sub-menu
void loadMatrixThenSubMenu() {
	
	char input_mat[MAX_FILENAME];
	char input_quer[MAX_FILENAME];
	NETWORK *n;
	
	system("clear");
	printf("Please input matrix filename to load or [ENTER] to exit: ");
	scanf("%s", input_mat);
	if (input_mat[0] == '\n')
		return;
	
	printf("\nPlease input queries filename to load: ");
	scanf("%s", input_quer);
	
	n = dataLoad(input_mat, input_quer);
	
	subMenu(n);
	return;

}

// Creates a new matrix, saves it, then passes it to the sub-menu
void createMatrixThenSubMenu() {

	int i;
	int val;
	char input[MAX_QUERY_LENGTH];
	NETWORK *n;
		n = malloc(sizeof(NETWORK));
			memset(n, 0, sizeof(NETWORK));
		n->weights = malloc(sizeof(MATRIX));
	
	system("clear");
	
	printf("NOTE: Maximum of 20 queries.\n\n");
	for(i = 0; i < 20; i++) {
		printf("Please input query ([q] to complete): ");
		memset(input, 0, MAX_QUERY_LENGTH);
		scanf("%s", input);
		
		if (input[0] == 'q')
			break;
		
		n->queries[i] = malloc(MAX_QUERY_LENGTH);
		strcpy(n->queries[i], input);
	
	}
	
	n->weights->rows = i;
	n->weights->cols = 1;
	n->weights->values = malloc(n->weights->rows);
	printf("Please input initial value of weight matrix: ");
	scanf("%d", &val);
	memset(n->weights->values, val, n->weights->rows);
	
	// Store data in files
	printf("\n\nSaving...");
	dataSave(n);
	
	subMenu(n);
	return;

}

// Gives the user options for manipulating a loaded network
void subMenu(NETWORK *n) {

	char input[MAX_INPUT_LENGTH];

	while(1) {
	
		memset(input, 0, MAX_INPUT_LENGTH);

		system("clear");
		printf("Network menu:\n");
		printf("\t[T]rain loaded matrix\n");
		printf("\t[O]perate loaded matrix\n");
		printf("\t[L]oad new matrix\n");
		printf("\t[E]xit\n");
		printf("Selection: ");
	
		scanf("%s", input);

		switch (input[0]) {
			case 't': trainInterface(n); break;
			case 'o': operateInterface(n); break;
			case 'l': loadMatrixThenSubMenu(); return;
			case 'e': return;
			default: return;
	
		}
	}

}

// Allows the user to use a network
void operateInterface(NETWORK *n) {
	
	int i;
	char input[MAX_INPUT_LENGTH];
	MATRIX *in;
		in = malloc(sizeof(MATRIX));
		memset(in, 0, sizeof(MATRIX));
	MATRIX *out;
		
	// Construct input
	in->rows = 1;
	in->cols = n->weights->rows;
	in->values = malloc(in->cols);
		memset(in->values, 0, in->cols);
		
	// Collect input values
	for (i = 0; i < in->cols; i++){
		printf("%s? Binary true / false: ", n->queries[i]);
		scanf("%s", input);
		in->values[i] = atoi(input);
	
	}
	
	// Operate network
	out = perceptronOperate(*in, n->weights);
	
	// Output
	if (out->values[0] == 1) {
		printf("The book is science fiction!");
	
	}
	else {
		printf("The book is not science fiction.");
	
	}
	
	// Make sure the user sees the result before the screen is refreshed
	fflush(stdout);
	sleep(3);
	
	// Clean and return
	free(in->values);
	free(in);
	return;

}

// Allows the user to train a network
void trainInterface(NETWORK *n) {

	int i;
	int k_val;
	char input[MAX_INPUT_LENGTH];
	MATRIX *in;
		in = malloc(sizeof(MATRIX));
		memset(in, 0, sizeof(MATRIX));
	MATRIX *train;
		train = malloc(sizeof(MATRIX));
		memset(train, 0, sizeof(MATRIX));
		
	// Construct input
	in->rows = 1;
	in->cols = n->weights->rows;
	in->values = malloc(in->cols);
		memset(in->values, 0, in->cols);
		
	// Construct training matrix
	train->rows = 1;
	train->cols = 1;
	train->values = malloc(1);
		memset(train->values, 0, 1);
		
	// Collect input values
	for (i = 0; i < in->cols; i++){
		printf("%s? Binary true / false: ", n->queries[i]);
		scanf("%s", input);
		in->values[i] = atoi(input);
	
	}
	
	// Collect training value and k value
	printf("Please enter training value: ");
	scanf("%s", input);
	train->values[0] = atoi(input);
	printf("Please enter a k value, which affects the severity of the training: ");
	scanf("%s", input);
	k_val = atoi(input);
	
	// Operate network
	n->weights = perceptronLearn(k_val, *in, *train, n->weights);
	
	// Output
	printf("New weight matrix:\n");
	fflush(stdout);
	printMatrix(*(n->weights));
	
	// Make sure the user sees the result before the screen is refreshed
	fflush(stdout);
	sleep(10);
	
	free(in->values);
	free(in);
	free(train->values);
	free(train);
	return;

}
