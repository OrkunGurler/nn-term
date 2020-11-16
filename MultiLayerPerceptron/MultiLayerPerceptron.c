#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct nodes
{
    int input_nodes, hidden_nodes, output_nodes;
} nodes;
nodes Nodes(int input_nodes, int hidden_nodes, int output_nodes);

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

float Sigmoid(float x);
float Sigmoid_d(float x);

void PrintMatrix(matrix m);

int main(int argc, char const *argv[])
{
    // srand(time(NULL));
    // nodes nodes = Nodes(3, 3, 1);
    // matrix m = Matrix(3, 2);

    return 0;
}

float Sigmoid(float x)
{
    float r = 1 / (1 + exp(x));
    return r;
}

float Sigmoid_d(float x)
{
    float r = Sigmoid(x) * (1 - Sigmoid(x));
    return r;
}

nodes Nodes(int input_nodes, int hidden_nodes, int output_nodes)
{
    nodes nodes;
    nodes.input_nodes = input_nodes;
    nodes.hidden_nodes = hidden_nodes;
    nodes.output_nodes = output_nodes;
    return nodes;
}

matrix Matrix(int rows, int cols)
{
    matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = (float **)malloc(rows * sizeof(float *));
    int i, j;
    for (i = 0; i < rows; i++)
    {
        m.data[i] = (float *)malloc(cols * sizeof(float));
        for (j = 0; j < cols; j++)
        {
            m.data[i][j] = 0;
        }
    }
    return m;
}

void m_rand(matrix m, int a, int b)
{
    int temp;
    if (b <= 0)
    {
        temp = a;
        a = b;
        b = temp;
    }
    int i, j;
    for (i = 0; i < m.rows; i++)
    {
        for (j = 0; j < m.cols; j++)
        {
            m.data[i][j] = (((float)rand() / (float)(RAND_MAX)) * (b - a)) + a;
        }
    }
}

void m_s_add(matrix m, float n)
{
    int i, j;
    for (i = 0; i < m.rows; i++)
    {
        for (j = 0; j < m.cols; j++)
        {
            m.data[i][j] += n;
        }
    }
}

void m_s_mult(matrix m, float n)
{
    int i, j;
    for (i = 0; i < m.rows; i++)
    {
        for (j = 0; j < m.cols; j++)
        {
            m.data[i][j] *= n;
        }
    }
}

matrix m_add(matrix m1, matrix m2)
{
    matrix m;
    int i, j;
    if ((m1.rows != m2.rows) || (m1.cols != m2.cols))
    {
        printf("\n[ERR: m_add] The column or row sizes are not equal!\n");
        exit(1);
    }
    m = Matrix(m1.rows, m1.cols);
    for (i = 0; i < m.rows; i++)
    {
        for (j = 0; j < m.cols; j++)
        {
            m.data[i][j] = m1.data[i][j] + m2.data[i][j];
        }
    }
    return m;
}

matrix m_dot(matrix m1, matrix m2)
{
    matrix m;
    int i, j, k;
    if (m1.cols != m2.rows)
    {
        printf("\n[ERR: m_dot] First matrix's column and second matrix's row sizes are not equal!\n");
        exit(1);
    }
    m = Matrix(m1.rows, m2.cols);
    for (i = 0; i < m.rows; i++)
    {
        for (j = 0; j < m.cols; j++)
        {
            for (k = 0; k < m1.cols; k++)
            {
                m.data[i][j] += m1.data[i][k] * m2.data[k][j];
            }
        }
    }
    return m;
}

matrix m_tra(matrix m)
{
    matrix m_t = Matrix(m.cols, m.rows);
    int i, j;
    for (i = 0; i < m.rows; i++)
    {
        for (j = 0; j < m.cols; j++)
        {
            m_t.data[j][i] = m.data[i][j];
        }
    }
    return m_t;
}

void PrintMatrix(matrix m)
{
    int i, j;
    printf("\n");
    for (i = 0; i < m.rows; i++)
    {
        for (j = 0; j < m.cols; j++)
        {
            printf(" %.6f ", m.data[i][j]);
        }
        printf("\n");
    }
}