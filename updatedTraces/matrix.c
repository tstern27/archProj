// C program to multiply two square matrices. 
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/time.h>

#define A1 31 
#define A2 41
#define B1 41
#define B2 16
#define loops 1


void enterData(double first[][A2], double second[][B2]);
void multiplyMatrices(double first[][A2], double second[][B2], double multResult[][B2]);
void display(double mult[][B2]);
double time_diff(struct timeval x , struct timeval y);


double time_diff(struct timeval x , struct timeval y);

double diff_t;

int main()
{
    struct timeval before , after;
    gettimeofday(&before , NULL);

    srand(time(0)); 


    for(int i=0; i < loops; i++)
    {
        double first[A1][A2], second[B1][B2], mult[A1][B2];

        // Function to take matrices data
        enterData(first, second);

        // Function to multiply two matrices.
        multiplyMatrices(first, second, mult);
    }
    gettimeofday(&after , NULL);

    double time_res = time_diff(before , after); 
    time_res = time_res/1000000;

    printf("Execution time = %f\n", time_res);
    return 0; 
}

void enterData(double first[][A2], double second[][B2]) {

    for (int i = 0; i < A1; ++i) {
        for (int j = 0; j < A2; ++j) {
            first[i][j] = (double)rand()/(double)(RAND_MAX);
        }
    }


    for (int i = 0; i < B1; ++i) {
        for (int j = 0; j < B2; ++j) {
            second[i][j] = (double)rand()/(double)(RAND_MAX);
        }
    }
}

void multiplyMatrices(double first[][A2], double second[][B2], double mult[][B2]) {

    // Initializing elements of matrix mult to 0.
    for (int i = 0; i < A1; ++i) {
        for (int j = 0; j < B2; ++j) {
            mult[i][j] = 0;
        }
    }

    // Multiplying first and second matrices and storing in mult.
    for (int i = 0; i < A1; ++i) {
        for (int j = 0; j < B2; ++j) {
            for (int k = 0; k < A2; ++k) {
                mult[i][j] += first[i][k] * second[k][j];
            }
        }
    }
}

void display(double mult[][B2]) {

    printf("\nOutput Matrix:\n");
    for (int i = 0; i < A1; ++i) {
        for (int j = 0; j < B2; ++j) {
            printf("%lf ", mult[i][j]);
            if (j == B2 - 1)
                printf("\n");
        }
    }
}

double time_diff(struct timeval x , struct timeval y)
{
	double x_ms , y_ms , diff;
	
	x_ms = (double)x.tv_sec*1000000 + (double)x.tv_usec;
	y_ms = (double)y.tv_sec*1000000 + (double)y.tv_usec;
	
	diff = (double)y_ms - (double)x_ms;
	
	return diff;
}
