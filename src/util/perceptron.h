/* Function Prototypes */
	struct _matrix *fNetJ(struct _matrix y, int theta);
	struct _matrix *perceptronLearn(int k, struct _matrix in, struct _matrix t, struct _matrix *w);
	struct _matrix *perceptronOperate(struct _matrix in, struct _matrix *w);
