/* Data structures */

	typedef struct _matrix {
		int rows;
		int cols;
		int *values;
	
	} __matrix;
	
	typedef struct _matrix MATRIX;
	
	
/* Functional Prototypes */
	
	MATRIX *matrixMultiply(MATRIX a, MATRIX b);
