#define SIZE 100
struct set {
	int array[SIZE];
	int howmany;
};
typedef struct set SET, *SETP;

SETP create(void);
void add(int, SETP);
void print(SETP);
SETP setunion(SETP, SETP);
