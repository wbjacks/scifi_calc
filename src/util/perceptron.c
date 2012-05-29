#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "perceptron.h"
#include "matrix.h"

struct _matrix *perceptronLearn(int k, struct _matrix in, struct _matrix t, struct _matrix *w) {

	// Declare appropriate matrices
	int i, j;
	MATRIX *net_j;
	MATRIX *delta_w;
		delta_w = malloc(sizeof(MATRIX));
		memset(delta_w, 0, sizeof(MATRIX));
		delta_w->rows = w->rows;
		delta_w->cols = w->cols;
		delta_w->values = malloc(delta_w->rows * delta_w->cols);
	MATRIX *y;
	MATRIX *temp;
	
	// Calculate output
	y = matrixMultiply(in, *w);
	net_j = fNetJ(*y, 0);
	
	// Print output and training matrix
	printf("\n\nLearn Output:\n");
	printMatrix(*net_j);
	printf("\n\nTraining Matrix:\n");
	printMatrix(t);
	
	// Caclulate error matrix
	for (i = 0; i < w->rows; i++){
		for (j = 0; j < w->cols; j++){
			delta_w->values[j + i * w->cols] = k * (t.values[i] - net_j->values[i]) * in.values[i]; // This might go wrong
		
		}
	}
	
	// Output error matrix
	printf("\n\nDelta_W Matrix:\n");
	printMatrix(*delta_w);
	
	// Add to weight matrix, free and return
	temp = matrixAdd(*w, *delta_w);
	//free(w->values);
	//free(w);
	w = temp;
	printMatrix(*w);
	free(y->values);
	free(y);
	return;
	
}

struct _matrix *fNetJ(struct _matrix y, int theta){

	int i, j; 
	MATRIX *m;
		m = malloc(sizeof(MATRIX));
		memset(m, 0, sizeof(MATRIX));
		m->rows = y.rows;
		m->cols = y.cols;
		m->values = malloc(m->rows * m->cols);
		
	// Make binaries happen
	for (i = 0; i < m->rows; i++){
		for (j = 0; j < m->cols; j++){
			if (y.values[j + i * m->cols] >= theta) {
				m->values[j + i * m->cols] = 1;
				
			} else {
				m->values[j + i * m->cols] = 0;
			}
		}
	}
	
	return m;

}
