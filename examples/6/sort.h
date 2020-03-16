#define NO_LINES 20
#define ERROR -1
#define LINE_LENGTH 100

int numcmp(const char *, const char *);
int revcmp(const char *, const char *);
int revnum(const char *, const char *);

void printlines(char **lines, int howmany);
void sort(char **, int, int (*)(const char *, const char *));
int readlines(char **lines, int maximum);
