#include <stdio.h>
#include <stdlib.h>
#include "dataManage.h"
#include "matrix.h"
#include "../operator/operator.h"

int dataSave(struct _network *n){

	FILE *oFile;
	char *formatted_matrix;
	char *formatted_queries;
	char data_dir[] = {"../data/"}
	char filename_matrix[MAX_FILE_NAME];
		memset(filename_matrix, 0, MAX_FILE_NAME);
	char filename_queries[MAX_FILE_NAME];
		memset(filename_queries, 0, MAX_FILE_NAME);
	char *data_path_matrix;
	char *data_path_queries;
	
	// Grab matrix file
	printf("\nPlease input name of file to save matrix: ");
	scanf("%s\n", filename);
	data_path_matrix = strcat(filename_matrix, data_dir);
	
	// Format output
	formatted_matrix = formatMatrixForSave(n->weights);
	formatted_queries = formatQueriesForSave(n->queries);

	// Print matrix file
	oFile = fopen(data_path_matrix, "w");
	fprintf(oFile, formatted_matrix);
	fclose(oFile);
	free(formatted_matrix);
	
	// Grab query file
	printf("\nPlease input name of file to save queries: ");
	scanf("%s\n", filename_queries);
	data_path_queries = strcat(filename_queries, data_dir);
	
	// Print query file
	oFile = fopen(data_path_queries, "w");
	fprintf(oFile, formatted_queries);
	fclose(oFile);
	free(formatted_queries);
	
	return 1;

}

char *formatMatrixForSave(struct _matrix *m) {

	int i;
	char delim[] = {"!*@#$"};
	char *s;
		s = malloc(MAX_SIZE_OF_MATRIX_ENCRYPTION);
		memset(s, 0, MAX_SIZE_OF_MATRIX_ENCRYPTION);
	
	sprintf(s, "%c%s", m->rows, delim);
	s = strcat(s, n->cols);
	
	for(i = 0; i < (m->rows * m->cols); i++) {
		s = strcat(s, delim);
		s = strcat(s, m->values[i]);
	
	}
	
	return s;

}

char *formatQueriesForSave(char *qs[]) {

	int i;
	char *out;
		out = malloc(MAX_SIZE_OF_QUERY_ENCRYPTION);
		memset(s, 0, MAX_SIZE_OF_QUERY_ENCRYPTION);
	char delim[] = "\n";

	sprintf(out, "%s", query);
	
	for (i = 1; qs[i]; i++) {
		out = strcat(out, delim);
		out = strcat(out, qs[i]);
		
	}
	
	return out;

}

