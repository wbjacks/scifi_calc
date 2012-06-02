#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"

// Multiplies matrices. Returns a pointer to the resultant matrix if the inputs
// are compatible or NULL if they aren't.
MATRIX *matrixMultiply(MATRIX a, MATRIX b){

	MATRIX *m;
	int i, j, k, l;
	float val = 0.0;

	// Check matrix compatibility
	if (a.cols != b.rows) {
		fprintf(stderr, "Matrices not of proper size for multiplcation.\n");
		return NULL;

	}

	// Allocate space for new matrix
	m = malloc(sizeof(MATRIX));
		memset(m, 0, sizeof(MATRIX));
		m->rows = a.rows;
		m->cols = b.cols;
		m->values = malloc(a.rows * b.cols);

	// Compute matrix
	for (j = 0; j < a.rows; j++) {
		for (k = 0; k < b.cols; k++) {
			for (i = 0, l = 0; i < a.cols; i++, l++) {
				val += (a.values[i + j*a.cols] * b.values[k + l*b.cols]);

			}
		
			m->values[k + j*m->cols] = val;
			val = 0.0;

		}
	}

	return m;

}

// Given two input matrices, returns a pointer to their sum
MATRIX *matrixAdd(MATRIX a, MATRIX b) {

	int i, j;
	MATRIX *m;

	// Check size
	if (a.cols != b.cols || a.rows != b.rows){
		fprintf(stderr, "Mismatched size for matrix addition.\n");
		return NULL;
	
	}
	
	// Allocate memory for matrix
	m = malloc(sizeof(MATRIX));
		memset(m, 0, sizeof(MATRIX));
		m->rows = a.rows;
		m->cols = a.cols;
		m->values = malloc(m->rows * m->cols);
			memset(m->values, 0, (m->rows * m->cols));
	
	// Calculate matrix
	for (i = 0; i < m->rows; i++){
		for (j = 0; j < m->cols; ++j){
			m->values[j + i * m->cols] =
				a.values[j + i * m->cols] + b.values[j + i * m->cols];
		
		}
	}
	
	return m;
	
}

MATRIX *matrixInvert(MATRIX a){
	
	int i, j, k, l;
	MATRIX *m;
	
	// Allocate memory for matrix
	m = malloc(sizeof(MATRIX));
		memset(m, 0, sizeof(MATRIX));
		m->rows = a.cols;
		m->cols = a.rows;
		m->values = malloc(m->rows * m->cols);
			memset(m->values, 0, (m->rows * m->cols));
			
	for (i = 0, k = 0; i < a.rows; i++, k++) {
		for (j = 0, l = 0; j < a.cols; j++, l++) {
			m->values[k + l * m->cols] = a.values[j + i * a.cols];
			
		}
	}
	
	printf("\nMatrix Invert:");
	printMatrix(*m);
	
	return m;
	
}



// Prints an input matrix in human-readable format
void printMatrix(MATRIX m) {

	int i, j;

	printf("\n");

	for (i = 0; i < m.rows; i++){
		printf("| ");

		for (j = 0; j < m.cols; j++){
			printf("%1.2f ", m.values[j + (i * m.cols)]);

		}

		printf("|\n");

	}
}
