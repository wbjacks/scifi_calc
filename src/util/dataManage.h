//dataManage.h

#define MAX_FILENAME 20
#define MAX_SIZE_OF_MATRIX_ENCRYPTION 100000
#define MAX_SIZE_OF_QUERY_ENCRYPTION 3000000

int dataSave(struct _network *n)
char *formatQueriesForSave(char *qs[]);
char *formatMatrixForSave(struct _matrix *m);

