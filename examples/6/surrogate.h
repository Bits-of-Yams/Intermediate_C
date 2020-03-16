#define NAMESIZE 20
				
struct records {					
    char name[NAMESIZE];			
    int age;						
};
								
typedef struct records R, *PR;
		
void print(PR *, int);				
void sort(PR *, int);				
int input_rec(PR);				
int get_the_data(PR *, int);

