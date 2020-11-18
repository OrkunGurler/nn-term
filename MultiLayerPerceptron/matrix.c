#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "matrix.h"

Matrix create_matrix(int rows, int cols)
{
    Matrix m;
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

void m_randomize(Matrix m, int a, int b)
{
    srand(time(NULL));
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

void m_s_add(Matrix m, float n)
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

Matrix m_add(Matrix m1, Matrix m2)
{
    Matrix m;
    int i, j;
    if ((m1.rows != m2.rows) || (m1.cols != m2.cols))
    {
        printf("\n[ERR: m_add] The column or row sizes are not equal!\n");
        exit(1);
    }
    m = create_matrix(m1.rows, m1.cols);
    for (i = 0; i < m.rows; i++)
    {
        for (j = 0; j < m.cols; j++)
        {
            m.data[i][j] = m1.data[i][j] + m2.data[i][j];
        }
    }
    return m;
}

void m_s_multiply(Matrix m, float n)
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

Matrix m_scalar(Matrix m1, Matrix m2)
{
    Matrix m;
    int i, j, k;
    if (m1.cols != m2.rows)
    {
        printf("\n[ERR: m_scalar] First matrix's column and second matrix's row sizes are not equal!\n");
        exit(1);
    }
    m = create_matrix(m1.rows, m2.cols);
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

Matrix m_transpose(Matrix m)
{
    Matrix m_t = create_matrix(m.cols, m.rows);
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

void m_map(Matrix m, float (*func)(float))
{
    float f;
    int i, j;
    for (i = 0; i < m.rows; i++)
    {
        for (j = 0; j < m.cols; j++)
        {
            f = m.data[i][j];
            m.data[i][j] = func(f);
        }
    }
}

Matrix m_copy(Matrix m)
{
    Matrix m_c = create_matrix(m.cols, m.rows);
    int i, j;
    for (i = 0; i < m.rows; i++)
    {
        for (j = 0; j < m.cols; j++)
        {
            m_c.data[i][j] = m.data[i][j];
        }
    }
    return m_c;
}

float *to_array(Matrix m)
{
    float *arr = (float *)malloc((m.rows * m.cols) * sizeof(float));
    int i, j;
    for (i = 0; i < m.rows; i++)
    {
        for (j = 0; j < m.cols; j++)
        {
            arr[i] = m.data[i][j];
        }
    }
    return arr;
}

Matrix from_array(float *arr, int size)
{
    Matrix m = create_matrix(size, 1);
    int i;
    for (i = 0; i < size; i++)
    {
        m.data[i][1] = arr[i];
    }
    return m;
}

void print_array(float *arr, int size)
{
    int i;
    for (i = 0; i < size - 1; i++)
    {
        printf("%.6f, ", arr[i]);
    }
    printf("%.6f\n", arr[size - 1]);
}

void print_matrix(Matrix m)
{
    int i, j;
    for (i = 0; i < m.rows; i++)
    {
        for (j = 0; j < m.cols; j++)
        {
            printf(" %.6f ", m.data[i][j]);
        }
        printf("\n");
    }
}