typedef struct Matrix
{
    int rows, cols;
    float **data;
} Matrix;
Matrix create_matrix(int rows, int cols);

void m_randomize(Matrix m, int a, int b);

void m_add_n(Matrix m, float n);
void m_addition(Matrix m1, Matrix m2);
void m_subtraction(Matrix m1, Matrix m2);

void m_multiply(Matrix m, float n);
void m_hadamard(Matrix m1, Matrix m2);
Matrix m_scalar(Matrix m1, Matrix m2);

Matrix m_transpose(Matrix m);

void m_map(Matrix m, float (*func)(float));
void m_map_v(Matrix m, void (*func)(float));
Matrix m_map_r(Matrix m, float (*func)(float));

Matrix m_copy(Matrix m);

float *to_array(Matrix m);
Matrix from_array(float *arr, int rows, int cols);

void print_array(float *arr, int size);
void print_matrix(Matrix m);