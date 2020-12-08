#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "sortlib.h"

typedef struct mxlib
{
    int rows, cols;
    float **data;
} mx;
mx create_matrix(int rows, int cols);

void randomize(mx m, int init, int fin);

void addtom(mx m, float n);
void addm(mx m1, mx m2);
void subm(mx m1, mx m2);

void mulwm(mx m, float n);
void hadamard(mx m1, mx m2);
mx dot(mx m1, mx m2);

float r_sum(mx m, int rn);
float c_sum(mx m, int cn);

float r_maxmin(mx m, int rn, int flag);
float c_maxmin(mx m, int cn, int flag);

mx transpose(mx m);

void map(mx m, float (*func)(float));
void map_v(mx m, void (*func)(float));
mx map_r(mx m, float (*func)(float));

mx copym(mx m);

float *matrix_to_array(mx m);
mx array_to_matrix(float *arr, int rows, int cols);

void free_matrix(mx m);

void print_arr(float *arr, int size);
void print_matrix(mx m);