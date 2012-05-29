#define MAX_INPUT_LENGTH 15
#define MAX_NUMBER_OF_QUERIES 20
#define MAX_QUERY_LENGTH 30

struct _network {
	char *queries[MAX_NUMBER_OF_QUERIES];
	struct _matrix *weights;

};

typedef _network NETWORK;
