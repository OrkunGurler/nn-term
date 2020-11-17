#include "matrix.h"

typedef struct Nodes
{
    int input, hidden, output;
} Nodes;

Nodes nodes(int input, int hidden, int output);

typedef struct NeuralNet
{
    Nodes nodes;

    Matrix weights_ih;
    Matrix bias_ih;

    Matrix weights_ho;
    Matrix bias_ho;

    float learning_rate;
    float (*activasion)(float);
} NeuralNet;

NeuralNet neuralnet(int input, int hidden, int output, float learning_rate, float (*activation)(float));
float *predict(NeuralNet net, float *input_arr, int size);