typedef struct matrix
{
    int rows, cols;
    float **data;
} matrix;

matrix Matrix(int rows, int cols);

void m_rand(matrix m, int a, int b);

void m_s_add(matrix m, float n);
matrix m_add(matrix m1, matrix m2);

void m_s_mult(matrix m, float n);
matrix m_scalar(matrix m1, matrix m2);

matrix m_tra(matrix m);

matrix m_copy(matrix m);

float **to_arr(matrix m);
matrix from_arr(float *arr, int size);

void PrintMatrix(matrix m);