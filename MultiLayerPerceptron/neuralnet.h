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

NeuralNet neuralnet(int *node_arr, float learning_rate, float (*activation)(float));
Matrix predict(NeuralNet net, float *input_arr, int size);
void train(NeuralNet net, float input_arr, float target_arr);