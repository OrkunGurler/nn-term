#include "matrix.h"
#include "activation.h"

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

    Activation activation;

    float learning_rate;
} NeuralNet;
NeuralNet neuralnet(Nodes n, Activation func, float learning_rate);

Matrix predict(NeuralNet net, Matrix input);
void train(NeuralNet net, float input_arr, float target_arr);