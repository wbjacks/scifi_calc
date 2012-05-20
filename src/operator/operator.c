#include <stdlib.h>
#include <stdio.h>
#include "../util/matrix.h"


int main(int argc, char *argv[]){

	MATRIX a;
	MATRIX b;
	MATRIX *result;
	int val1[] = {1,4,2,5,2,4,1,4};
	int val2[] = {5,8,7,4,6,8};
	
	a.rows = 4;
	a.cols = 2;
	b.rows = 2;
	b.cols = 3;
	a.values = val1;
	b.values = val2;
	
	printf("\n\nMatrix a:");
	printMatrix(a);
	printf("\n\nMatrix b:");
	printMatrix(b);
	
	printf("\n\nMatrix result:");
	result = matrixMultiply(a, b);
	printMatrix(*result);


}
