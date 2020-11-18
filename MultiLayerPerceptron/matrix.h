typedef struct Matrix
{
    int rows, cols;
    float **data;
} Matrix;
Matrix create_matrix(int rows, int cols);

void m_randomize(Matrix m, int a, int b);

void m_s_add(Matrix m, float n);
Matrix m_add(Matrix m1, Matrix m2);

void m_multiply(Matrix m, float n);
Matrix m_scalar(Matrix m1, Matrix m2);

Matrix m_transpose(Matrix m);

void m_map(Matrix m, float (*func)(float));

Matrix m_copy(Matrix m);

float *to_array(Matrix m);
Matrix from_array(float *arr, int size);

void print_array(float *arr, int size);
void print_matrix(Matrix m);