typedef struct Matrix
{
    int rows, cols;
    float **data;
} Matrix;
Matrix matrix(int rows, int cols);

void m_rand(Matrix m, int a, int b);

void m_s_add(Matrix m, float n);
Matrix m_add(Matrix m1, Matrix m2);

void m_s_mult(Matrix m, float n);
Matrix m_scalar(Matrix m1, Matrix m2);

Matrix m_tra(Matrix m);

void m_map(Matrix m, float (*func)(float));

Matrix m_copy(Matrix m);

float *to_arr(Matrix m);
Matrix from_arr(float *arr, int size);

void PrintArray(float *arr, int size);
void PrintMatrix(Matrix m);