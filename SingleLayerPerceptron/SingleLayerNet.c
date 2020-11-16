#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Structure to hold the information about a location
typedef struct location
{
    float position[2]; // Catesian coordinates of the location
    int label;         // Label for the region of the location
} location;

// Function to calculate the label of a location
void Label(int dim, location location);

// Function to calculate the weighted sum of the input neuron
float WeightedSum(int dim, location location, float *weights, float bias);

// Activation function of the neural network
int BinaryStep(int wSum);

// Function that implements the Perceptron Model
int Perceptron(int dim, location location, float *weights, float bias);

// Function to train the network with given dataset
void Train(int dim, int size, location *location, float *weights, float bias);

// Auxiliary function to print arrays
void PrintArray(int size, float *arr);

int main(int argc, char const *argv[])
{
    int i, j;
    int dim = 2;     // Dimension
    int size = 1000; // Train Data Size

    /* ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### */

    srand(time(NULL));
    float bias = 1;
    // Generating Initial Weights
    float weights[dim];
    for (i = 0; i < dim; i++)
    {
        weights[i] = 0;
    }
    printf("Initialized Weights..: ");
    PrintArray(dim, weights);

    /* ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### */

    location train[size];
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < dim; j++)
        {
            train[i].position[j] = (((float)rand() / (float)(RAND_MAX)) * 200) - 100;
        }

        Label(dim, train[i]);
    }

    Train(dim, size, train, weights, bias);

    printf("Trained Weights..: ");
    PrintArray(dim, weights);

    /* ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### */

    location userInput;
    while (1)
    {
        char p[3] = {'x', 'y', 'z'};
        printf("Enter position to find the place\n");
        for (i = 0; i < dim; i++)
        {
            printf("%c..: ", p[i]);
            scanf("%f", &userInput.position[i]);
        }
        userInput.label = Perceptron(dim, userInput, weights, bias);
        printf("%d\n", userInput.label);
    }

    return 0;
}

void Label(int dim, location location)
{
    if (location.position[0] >= location.position[1])
    {
        location.label = 1;
    }
    else
    {
        location.label = -1;
    }
}

float WeightedSum(int dim, location location, float *weights, float bias)
{
    int i;
    float wSum = 0;

    for (i = 0; i < dim; i++)
    {
        wSum = wSum + (location.position[i] * weights[i]);
    }

    return wSum + bias;
}

int BinaryStep(int wSum)
{
    int output;

    if (wSum >= 0)
    {
        output = 1;
    }
    else
    {
        output = -1;
    }

    return output;
}

int Perceptron(int dim, location location, float *weights, float bias)
{
    float wSum = WeightedSum(dim, location, weights, bias);

    int output = BinaryStep(wSum);

    return output;
}

void Train(int dim, int size, location *location, float *weights, float bias)
{
    int i, j;

    int output;
    int target;
    //int error;
    float lRate = 0.001; // Learning Rate
    for (i = 0; i < size; i++)
    {
        output = Perceptron(dim, location[i], weights, bias);
        target = location[i].label;
        //error = target - output;
        /*
        for (j = 0; j < dim; j++)
        {
            weights[j] += (location[i].position[j] * error) * lRate;
            //bias += target;
        }
        */
        if (output == target)
        {
            for (j = 0; j < dim; j++)
            {
                weights[j] += (location[i].position[j] * output) * lRate;
                bias += target;
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