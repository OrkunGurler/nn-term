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

void m_randomize(Matrix m, int init, int fin)
{
    srand(time(NULL));
    if (init > fin)
    {
        printf("\n[ERR: m_randomize] Initial value must be lower than Final value!\n");
        exit(1);
    }
    int temp;
    if (fin <= 0)
    {
        temp = init;
        init = fin;
        fin = temp;
    }
    int i, j;
    for (i = 0; i < m.rows; i++)
    {
        for (j = 0; j < m.cols; j++)
        {
            m.data[i][j] = (((float)rand() / (float)(RAND_MAX)) * (fin - init)) + init;
        }
    }
}

void m_add_n(Matrix m, float n)
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

void m_addition(Matrix m1, Matrix m2)
{
    int i, j;
    if ((m1.rows != m2.rows) || (m1.cols != m2.cols))
    {
        printf("\n[ERR: m_addition] Columns and Rows must match!\n");
        exit(1);
    }
    for (i = 0; i < m1.rows; i++)
    {
        for (j = 0; j < m1.cols; j++)
        {
            m1.data[i][j] += m2.data[i][j];
        }
    }
}

void m_subtraction(Matrix m1, Matrix m2)
{
    int i, j;
    if ((m1.rows != m2.rows) || (m1.cols != m2.cols))
    {
        printf("\n[ERR: m_subtraction] Columns and Rows must match!\n");
        exit(1);
    }
    for (i = 0; i < m1.rows; i++)
    {
        for (j = 0; j < m1.cols; j++)
        {
            m1.data[i][j] -= m2.data[i][j];
        }
    }
}

void m_multiply(Matrix m, float n)
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

void m_hadamard(Matrix m1, Matrix m2)
{
    int i, j;
    if ((m1.rows != m2.rows) || (m1.cols != m2.cols))
    {
        printf("\n[ERR: m_hadamard] Columns and Rows must match!\n");
        exit(1);
    }
    for (i = 0; i < m1.rows; i++)
    {
        for (j = 0; j < m1.cols; j++)
        {
            m1.data[i][j] *= m2.data[i][j];
        }
    }
}

Matrix m_scalar(Matrix m1, Matrix m2)
{
    Matrix m;
    int i, j, k;
    if (m1.cols != m2.rows)
    {
        printf("\n[ERR: m_scalar] First matrix's Column Size and Second matrix's Row Size must match!\n");
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

float m_r_sum(Matrix m, int n)
{
    float sum = 0;
    int i;
    for (i = 0; i < m.cols; i++)
    {
        sum += m.data[n][i];
    }
    return sum;
}

float m_c_sum(Matrix m, int n)
{
    float sum = 0;
    int i;
    for (i = 0; i < m.rows; i++)
    {
        sum += m.data[i][n];
    }
    return sum;
}

float m_r_max(Matrix m, int n)
{
    float max = 0;
    float *arr = (float *)malloc(m.cols * sizeof(float));
    int i;
    for (i = 0; i < m.cols; i++)
    {
        arr[i] = m.data[n][i];
    }
    m_ins_sort(arr, m.cols, 1);
    max = arr[m.cols - 1];
    free(arr);
    return max;
}

float m_r_min(Matrix m, int n)
{
    float min = 0;
    float *arr = (float *)malloc(m.cols * sizeof(float));
    int i;
    for (i = 0; i < m.cols; i++)
    {
        arr[i] = m.data[n][i];
    }
    m_ins_sort(arr, m.cols, 1);
    min = arr[0];
    free(arr);
    return min;
}

float m_c_max(Matrix m, int n)
{
    float max = 0;
    float *arr = (float *)malloc(m.rows * sizeof(float));
    int i;
    for (i = 0; i < m.rows; i++)
    {
        arr[i] = m.data[n][i];
    }
    m_ins_sort(arr, m.rows, 1);
    max = arr[m.rows - 1];
    free(arr);
    return max;
}

float m_c_min(Matrix m, int n)
{
    float min = 0;
    float *arr = (float *)malloc(m.rows * sizeof(float));
    int i;
    for (i = 0; i < m.rows; i++)
    {
        arr[i] = m.data[n][i];
    }
    m_ins_sort(arr, m.rows, 1);
    min = arr[0];
    free(arr);
    return min;
}

// Insertion Sort
void m_ins_sort(float *arr, int size, int flag)
{
    int temp;
    int i, j;
    for (i = 1; i < size; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && compare(arr[j], temp, flag))
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

int compare(int num1, int num2, int flag) { return (flag == 1 ? num1 > num2 : num1 < num2); }

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

void m_map_v(Matrix m, void (*func)(float))
{
    int i, j;
    for (i = 0; i < m.rows; i++)
    {
        for (j = 0; j < m.cols; j++)
        {
            func(m.data[i][j]);
        }
    }
}

Matrix m_map_r(Matrix m, float (*func)(float))
{
    float f;
    Matrix nm = create_matrix(m.rows, m.cols);
    int i, j;
    for (i = 0; i < m.rows; i++)
    {
        for (j = 0; j < m.cols; j++)
        {
            f = m.data[i][j];
            nm.data[i][j] = func(f);
        }
    }
    return nm;
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
    int i, j, count = 0;
    for (i = 0; i < m.rows; i++)
    {
        for (j = 0; j < m.cols; j++)
        {
            arr[count] = m.data[i][j];
            count++;
        }
    }
    return arr;
}

Matrix from_array(float *arr, int rows, int cols)
{
    Matrix m = create_matrix(rows, cols);
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            m.data[i][j] = arr[i];
        }
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