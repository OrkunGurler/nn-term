#include "activation.h"

typedef struct Nodes
{
    int input, hidden, output;
} Nodes;
Nodes set_nodes(int input, int hidden, int output);

typedef struct Network
{
    Nodes nodes;

    Matrix weights_ih;
    Matrix bias_ih;

    Matrix weights_ho;
    Matrix bias_ho;

    Activation activation;

    float learning_rate;
} Network;
Network create_network(Nodes node, Activation func, float learning_rate);

Matrix predict(Network network, Matrix input);
void train(Network network, Matrix inputs, Matrix targets);