#include "matrix.h"
#include "activation.h"

typedef struct Nodes
{
    int input, hidden, output;
} Nodes;
Nodes set_nodes(int input, int hidden, int output);

typedef struct NeuralNetwork
{
    Nodes nodes;

    Matrix weights_ih;
    Matrix bias_ih;

    Matrix weights_ho;
    Matrix bias_ho;

    Activation activation;

    float learning_rate;
} NeuralNetwork;
NeuralNetwork create_neuralnetwork(Nodes node, Activation func, float learning_rate);

Matrix predict(NeuralNetwork network, Matrix input);
void train(NeuralNetwork network, Matrix inputs, Matrix targets);