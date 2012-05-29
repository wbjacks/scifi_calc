#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"
#include "../operator/operator.h"
#include "dataManage.h"

int dataSave(struct _network *n){

	FILE *oFile;
	char *formatted_matrix;
	char *formatted_queries;
	char data_dir[] = "../data/";
	char filename_matrix[MAX_FILENAME];
		memset(filename_matrix, 0, MAX_FILENAME);
	char filename_queries[MAX_FILENAME];
		memset(filename_queries, 0, MAX_FILENAME);
	char *data_path_matrix;
	char *data_path_queries;
	
	// Grab matrix file
	printf("\nPlease input name of file to save matrix: ");
	scanf("%s", filename_matrix);
	data_path_matrix = strcat(data_dir, filename_matrix);
	
	// Format output
	formatted_matrix = formatMatrixForSave((MATRIX *)(n->weights));
	formatted_queries = formatQueriesForSave(n->queries);

	// Print matrix file
	oFile = fopen(data_path_matrix, "w");
	fprintf(oFile, formatted_matrix);
	fclose(oFile);
	free(formatted_matrix);
	
	// Grab query file
	printf("Please input name of file to save queries: ");
	scanf("%s", filename_queries);
	data_dir[8] = 0; // For some reason, strcat removes this.
	data_path_queries = strcat(data_dir, filename_queries);
	
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
	char *num;
		num = malloc(MAX_WEIGHT_DIGITS);
		memset(num, 0, MAX_WEIGHT_DIGITS);
	
	sprintf(s, "%d%s\0", m->rows, delim);
	sprintf(num, "%d", m->cols);
	s = strcat(s, num);
	
	for(i = 0; i < (m->rows * m->cols); i++) {
		s = strcat(s, delim);
		memset(num, 0, MAX_WEIGHT_DIGITS);
		sprintf(num, "%d", m->values[i]);
		s = strcat(s, num);
	
	}
	
	return s;

}

char *formatQueriesForSave(char *qs[]) {

	int i;
	char *out;
		out = malloc(MAX_SIZE_OF_QUERY_ENCRYPTION);
		memset(out, 0, MAX_SIZE_OF_QUERY_ENCRYPTION);
	char delim[] = {"\n"};

	sprintf(out, "%s", qs[0]);
	
	for (i = 1; qs[i]; i++) {
		out = strcat(out, delim);
		out = strcat(out, qs[i]);
		
	}
	
	return out;

}

struct _network *dataLoad(char *matrix_file, char *query_file){
	
	int i;
	char mat_delim[] = {"!*@#$"};
	char quer_delim[] = {"\n"};
	char *token;
	char *enc_queries;
		enc_queries = malloc(MAX_SIZE_OF_QUERY_ENCRYPTION);
		memset(enc_queries, 0, MAX_SIZE_OF_QUERY_ENCRYPTION);
	char *enc_mat;
		enc_mat = malloc(MAX_SIZE_OF_MATRIX_ENCRYPTION);
		memset(enc_mat, 0, MAX_SIZE_OF_MATRIX_ENCRYPTION);
	FILE *iFile;
	NETWORK *n;
		n = malloc(sizeof(NETWORK));
		n->weights = malloc(sizeof(MATRIX));
	
	// Read matrix file
	iFile = fopen(matrix_file, "r");
	fread(enc_mat, MAX_SIZE_OF_MATRIX_ENCRYPTION, 1, iFile);
	fclose(iFile);
	
	// Decrypt matrix file into matrix structure
	token = strtok(enc_mat, mat_delim);
	((MATRIX *)(n->weights))->rows = atoi(token);
	token = strtok(NULL, mat_delim);
	((MATRIX *)(n->weights))->cols = atoi(token);
	((MATRIX *)(n->weights))->values = malloc(((MATRIX *)(n->weights))->rows * ((MATRIX *)(n->weights))->cols);
	token = strtok(NULL, mat_delim);
	for (i = 0; token; i++) {
		// Copy token to place in structure
		((MATRIX *)(n->weights))->values[i] = atoi(token);
		
		// Grab next token, which can be NULL
		token = strtok(NULL, mat_delim);
		
	}
	
	// Read query file
	iFile = fopen(query_file, "r");
	fread(enc_queries, MAX_SIZE_OF_QUERY_ENCRYPTION, 1, iFile);
	fclose(iFile);
	
	// Decrypt query file into network structure
	token = strtok(enc_queries, quer_delim);
	for (i = 0; token; i++) {
		// Copy token to place in structure
		n->queries[i] = malloc(MAX_QUERY_LENGTH);
		memset(n->queries, 0, MAX_QUERY_LENGTH);
		strcpy(n->queries[i], token);
	
		// Grab next token, which can be NULL
		token = strtok(NULL, quer_delim);
		
	}
	
	return n;

}
