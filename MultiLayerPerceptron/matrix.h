typedef struct matrix
{
    int rows, cols;
    float **data;
} matrix;

matrix Matrix(int rows, int cols);

void m_rand(matrix m, int a, int b);

void m_s_add(matrix m, float n);
void m_s_mult(matrix m, float n);

matrix m_add(matrix m1, matrix m2);
matrix m_dot(matrix m1, matrix m2);
matrix m_tra(matrix m);

void PrintMatrix(matrix m);