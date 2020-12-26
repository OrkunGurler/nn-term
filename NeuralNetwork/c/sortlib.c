#include "sortlib.h"

void bubble_sort(float *arr, int size, int flag)
{
    float temp;
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = (size - 1); j > i; j--)
        {
            if (compare(arr[j], arr[j - 1], flag))
            {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}

void insertion_sort(float *arr, int size, int flag)
{
    float temp;
    int i, j;
    for (i = 1; i < size; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && compare(temp, arr[j], flag))
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void merge_sort(float *arr, int p, int r, int flag)
{
    if (p + 1 < r)
    {
        int q = (int)((p + r) / 2);
        merge_sort(arr, p, q, flag);
        merge_sort(arr, q, r, flag);
        merge(arr, p, q, r, flag);
    }
}

void merge(float *arr, int p, int q, int r, int flag)
{
    int n1 = q - p;
    int n2 = r - q;
    float left[n1 + 1];
    float right[n2 + 1];
    int i, j, k;
    for (i = 0; i < n1; i++)
    {
        left[i] = arr[p + i];
    }
    for (j = 0; j < n2; j++)
    {
        right[j] = arr[q + j];
    }
    if (flag)
    {
        left[n1] = INF;
        right[n2] = INF;
    }
    i = 0;
    j = 0;
    for (k = p; k < r; k++)
    {
        if (compare(left[i], right[j], flag))
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
    }
}

void selection_sort(float *arr, int size, int flag)
{
    int i, j, least;
    float temp;
    for (i = 0; i < size; i++)
    {
        least = i;
        for (j = i + 1; j < size; j++)
        {
            if (compare(arr[j], arr[least], flag))
            {
                least = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[least];
        arr[least] = temp;
    }
}

int compare(float num1, float num2, int flag) { return (flag == 1 ? num1 > num2 : num1 < num2); }