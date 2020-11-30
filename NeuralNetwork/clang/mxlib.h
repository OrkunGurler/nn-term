#include "sortlib.h"

typedef struct matrix
{
    int rows, cols;
    float **data;
} mx;
mx createm(int rows, int cols);

void matrandom(mx m, int init, int fin);

void addtom(mx m, float n);
void addm(mx m1, mx m2);
void subm(mx m1, mx m2);

void mulwm(mx m, float n);
void hadamard(mx m1, mx m2);
mx dot(mx m1, mx m2);

float r_sum(mx m, int rn);
float c_sum(mx m, int cn);

float r_max(mx m, int rn);
float r_min(mx m, int rn);
float c_max(mx m, int cn);
float c_min(mx m, int cn);

mx transpose(mx m);

void map(mx m, float (*func)(float));
void map_v(mx m, void (*func)(float));
mx map_r(mx m, float (*func)(float));

mx copym(mx m);

float *mtoarr(mx m);
mx arrtom(float *arr, int rows, int cols);

void printarr(float *arr, int size);
void printm(mx m);