#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

// Multiplies matrices. Returns a pointer to the resultant matrix if the inputs
// are compatible or NULL if they aren't.
MATRIX *matrixMultiply(MATRIX a, MATRIX b){

	MATRIX *m;
	int i, j, k, l;
	int val = 0;

	// Check matrix compatibility
	if (a.cols != b.rows) {
		printf("Input matrix not");
		return NULL;

	}

	// Allocate space for new matrix
	m = malloc(sizeof(MATRIX));
		m->rows = a.rows;
		m->cols = b.cols;
		m->values = malloc(a.rows * b.cols);

	// Compute matrix
	for (j = 0; j < a.rows; j++) {
		for (k = 0; k < b.cols; k++) {
			for (i = 0, l = 0; i < a.cols, l < b.rows; i++, l++) {
				val += (a.values[i + j*a.cols] * b.values[k + l*b.cols]);

			}
		
			m->values[k + j*m->cols] = val;
			val = 0;

		}
	}

	return m;

}

// Prints an input matrix in human-readable format
void printMatrix(MATRIX m) {

	int i, j;

	printf("\n");

	for (i = 0; i < m.rows; i++){
		printf("| ");

		for (j = 0; j < m.cols; j++){
			printf("%d ", m.values[j + (i * m.cols)]);

		}

		printf("|\n");

	}
}
