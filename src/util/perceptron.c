void perceptronLearn(int k, MATRIX in, MATRIX t, MATRIX *w) {

	// Declare appropriate matrices
	int i, j;
	MATRIX net_j;
		net_j.rows = l.rows;
		net_j.cols = l.cols;
		net_j.values = malloc(net_j.rows * net_j.cols);
			memset(net_j.values, 0, net_j.rows * net_j.cols);
	MATRIX delta_w;
		delta_w.rows = w->rows;
		delta_w.cols = w->cols;
		delta_w.values = malloc(delta_w.rows * delta_w.cols);
			memset(delta_w.values, 0, delta_w.rows * delta_w.cols);
	MATRIX *y;
	
	// Calculate output
	y = matrixMultiply(in, *w);
	net_j = fNetJ(*y, 0);
	
	// Print output and training matrix
	printf("\n\nLearn Output:\n");
	printMatrix(*net_j);
	printf("\n\nTraining Matrix:\n");
	printMatrix(t);
	
	// Caclulate error matrix
	for (i = 0; i < m->rows; i++){
		for (j = 0; j < m->cols; ++j, ind = j + i * m->cols){
			delta_w.values[ind] = k * (t[i] - y[i]) * in[i]; // This might go wrong
		
		}
	}
	
	// Output error matrix
	printf("\n\nDelta_W Matrix:\n");
	printMatrix(delta_w);
	
	// Add to weight matrix, free and return
	w = matrixAdd(*w, delta_w);
	free(y);
	return;
	
}

MATRIX *fNetJ(MATRIX y, int theta){

	int i, j, ind; 
	MATRIX *m;
		m = malloc(sizeof(MATRIX));
		memset(m, 0, sizeof MATRIX);
		m->rows = y.rows;
		m->cols = y.cols;
		m->values = malloc(m->rows * m->cols);
		
	for (i = 0; i < m->rows; i++){
		for (j = 0; j < m->cols; ++j, ind = j + i * m->cols){
			if (y.values[ind] >= theta) {
				m->values[ind] = 1;
				
			} else {
				m->values[ind] = 0;
			}
		
		}
	}
	
	return m;

}
