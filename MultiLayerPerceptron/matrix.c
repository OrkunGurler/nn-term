#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

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

matrix m_scalar(matrix m1, matrix m2)
{
    matrix m;
    int i, j, k;
    if (m1.cols != m2.rows)
    {
        printf("\n[ERR: m_scalar] First matrix's column and second matrix's row sizes are not equal!\n");
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

matrix m_copy(matrix m)
{
    matrix m_c = Matrix(m.cols, m.rows);
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

float **to_arr(matrix m)
{
    float **arr = (float **)malloc(m.rows * sizeof(float *));
    int i, j;
    for (i = 0; i < m.rows; i++)
    {
        arr[i] = (float *)malloc(m.cols * sizeof(float));
        for (j = 0; j < m.cols; j++)
        {
            arr[i][j] = m.data[i][j];
        }
    }
    return arr;
}

matrix from_arr(float *arr, int size)
{
    matrix m = Matrix(size, 1);
    int i;
    for (i = 0; i < size; i++)
    {
        m.data[i][1] = arr[i];
    }
    return m;
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