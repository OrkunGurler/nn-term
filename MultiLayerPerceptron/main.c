#include "neuralnet.h"

int main(int argc, char const *argv[])
{
    int input_nodes = 3;
    int hidden_nodes = 3;
    int output_nodes = 1;
    Nodes n = nodes(input_nodes, hidden_nodes, output_nodes);

    Activation af = activation(&Sigmoid, &Sigmoid_d);

    NeuralNet net = neuralnet(n, af, 0.01);

    Matrix input = matrix(input_nodes, 1);
    m_rand(input, -100, 100);

    Matrix p = predict(net, input);
    PrintMatrix(p);

    return 0;
}