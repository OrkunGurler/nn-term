#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct dataSet
{
    float position[2];
    int label;
} dataSet;

int Threshold(dataSet data, float *weights, float bias);
void Train(float *weights, float bias, float learningRate, int size);

void PrintArray(int size, float *arr);

int main(int argc, char const *argv[])
{
    float bias = 0;
    float learningRate = 0.001;

    /* ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### */

    srand(time(NULL));
    float weights[2];
    int i;
    for (i = 0; i < 2; i++)
    {
        weights[i] = 0; // (float)rand() / (float)(RAND_MAX);
    }
    printf("Initialized Weights..: ");
    PrintArray(2, weights);

    /* ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### */

    Train(weights, bias, learningRate, 1000000000);
    printf("Trained Weights..: ");
    PrintArray(2, weights);

    /* ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### */

    dataSet data;
    int predicted;
    int err = 0;
    int j;
    for (i = 0; i < 1000000000; i++)
    {
        for (j = 0; j < 2; j++)
        {
            data.position[j] = (((float)rand() / (float)(RAND_MAX)) * 2000) - 1000;
        }

        if (data.position[0] >= data.position[1])
        {
            data.label = 1;
        }
        else
        {
            data.label = -1;
        }

        predicted = Threshold(data, weights, bias);
        if (predicted != data.label)
        {
            err++;
        }
    }
    float rate = err / 1000000000;
    printf("Error Rate..: %.6f\n", rate);

    if (rate <= 0.00001)
    {
        dataSet userInput;
        while (1)
        {
            char p[3] = {'x', 'y', 'z'};
            printf("\nEnter position to find the place\n");
            for (i = 0; i < 2; i++)
            {
                printf("%c..: ", p[i]);
                scanf("%f", &userInput.position[i]);
            }
            userInput.label = Threshold(userInput, weights, bias);
            printf("%d\n", userInput.label);
        }
    }

    return 0;
}

int Threshold(dataSet data, float *weights, float bias)
{
    float weightedSum = 0;
    int i;
    for (i = 0; i < 2; i++)
    {
        weightedSum = data.position[i] * weights[i];
    }
    weightedSum += bias;

    if (weightedSum > 0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void Train(float *weights, float bias, float learningRate, int size)
{
    dataSet data;
    int predict;
    int i, j, k;
    for (i = 0; i < 1000000; i++)
    {
        for (j = 0; j < 2; j++)
        {
            data.position[j] = (((float)rand() / (float)(RAND_MAX)) * 2000) - 1000;
        }

        if (data.position[0] >= data.position[1])
        {
            data.label = 1;
        }
        else
        {
            data.label = -1;
        }

        predict = Threshold(data, weights, bias);
        if (predict != data.label)
        {
            for (k = 0; k < 2; k++)
            {
                weights[k] += learningRate * (data.label - predict) * data.position[k];
                bias += learningRate * (data.label - predict);
            }
        }
    }
}

void PrintArray(int size, float *arr)
{
    int i;
    for (i = 0; i < size - 1; i++)
    {
        printf("%.6f, ", arr[i]);
    }
    printf("%.6f\n\n", arr[size - 1]);
}
