//dataManage.h

#define MAX_FILENAME 20
#define MAX_SIZE_OF_MATRIX_ENCRYPTION 10000
#define MAX_SIZE_OF_QUERY_ENCRYPTION 300000

int dataSave(struct _network *n);
struct _network *dataLoad(char *matrix_file, char *query_file);
char *formatQueriesForSave(char *qs[]);
char *formatMatrixForSave(struct _matrix *m);

