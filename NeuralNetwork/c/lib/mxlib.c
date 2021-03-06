#include "mxlib.h"

mx create_matrix(int rows, int cols)
{
    mx m;
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

void randomize(mx m, int init, int fin)
{
    srand(time(NULL));
    if (init > fin)
    {
        printf("\n[ERR: randomize] Initial value must be lower than Final value!\n");
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

void addtom(mx m, float n)
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

void addm(mx m1, mx m2)
{
    int i, j;
    if ((m1.rows != m2.rows) || (m1.cols != m2.cols))
    {
        printf("\n[ERR: addm] Columns and Rows must match!\n");
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

void subm(mx m1, mx m2)
{
    int i, j;
    if ((m1.rows != m2.rows) || (m1.cols != m2.cols))
    {
        printf("\n[ERR: subm] Columns and Rows must match!\n");
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

void mulwm(mx m, float n)
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

void hadamard(mx m1, mx m2)
{
    int i, j;
    if ((m1.rows != m2.rows) || (m1.cols != m2.cols))
    {
        printf("\n[ERR: hadamard] Columns and Rows must match!\n");
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

mx dot(mx m1, mx m2)
{
    mx m;
    int i, j, k;
    if (m1.cols != m2.rows)
    {
        printf("\n[ERR: dot] First matrix's Column Size and Second matrix's Row Size must match!\n");
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

float r_sum(mx m, int n)
{
    float sum = 0;
    int i;
    for (i = 0; i < m.cols; i++)
    {
        sum += m.data[n][i];
    }
    return sum;
}

float c_sum(mx m, int n)
{
    float sum = 0;
    int i;
    for (i = 0; i < m.rows; i++)
    {
        sum += m.data[i][n];
    }
    return sum;
}

float r_maxmin(mx m, int n, int flag)
{
    float max = 0;
    float *arr = (float *)malloc(m.cols * sizeof(float));
    int i;
    for (i = 0; i < m.cols; i++)
    {
        arr[i] = m.data[n][i];
    }
    insertion_sort(arr, m.cols, flag);
    max = arr[m.cols - 1];
    free(arr);
    return max;
}

float c_maxmin(mx m, int n, int flag)
{
    float max = 0;
    float *arr = (float *)malloc(m.rows * sizeof(float));
    int i;
    for (i = 0; i < m.rows; i++)
    {
        arr[i] = m.data[n][i];
    }
    insertion_sort(arr, m.rows, flag);
    max = arr[m.rows - 1];
    free(arr);
    return max;
}

mx transpose(mx m)
{
    mx m_t = create_matrix(m.cols, m.rows);
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

void map(mx m, float (*func)(float))
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

void map_v(mx m, void (*func)(float))
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

mx map_r(mx m, float (*func)(float))
{
    float f;
    mx nm = create_matrix(m.rows, m.cols);
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

mx copym(mx m)
{
    mx m_c = create_matrix(m.cols, m.rows);
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

float *matrix_to_array(mx m)
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

mx array_to_matrix(float *arr, int rows, int cols)
{
    mx m = create_matrix(rows, cols);
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

void free_matrix(mx m)
{
    int i;
    for (i = 0; i < m.rows; i++)
    {
        free(m.data[i]);
    }
    free(m.data);
}

void print_arr(float *arr, int size)
{
    int i;
    for (i = 0; i < size - 1; i++)
    {
        printf("%.6f, ", arr[i]);
    }
    printf("%.6f\n", arr[size - 1]);
}

void print_matrix(mx m)
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