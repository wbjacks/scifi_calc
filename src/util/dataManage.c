int dataSaveMatrix(char *mat_file, MATRIX *save_matrix){

	FILE *oFile;
	char *formatted_matrix;
	char data_dir[] = {"../data/"}
	char *data_path;
	
	data_path = strcat(mat_file, data_dir);
	formatted_matrix = formatMatrixForSave(save_matrix);

	oFile = fopen(data_path, "w");
	fprintf(oFile, formatted_matrix);
	fclose(oFile);
	free(formatted_matrix);
	
	return 1;

}
