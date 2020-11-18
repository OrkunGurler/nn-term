#include "neuralnet.h"

int main(int argc, char const *argv[])
{
    int input_nodes = 3;
    int hidden_nodes = 3;
    int output_nodes = 1;
    Nodes n = set_nodes(input_nodes, hidden_nodes, output_nodes);

    Activation af = set_activation(&Leaky_ReLU, &Leaky_ReLU_d);

    NeuralNetwork network = create_neuralnetwork(n, af, 0.01);

    Matrix input = create_matrix(input_nodes, 1);
    m_randomize(input, -100, 100);

    Matrix p = predict(network, input);
    print_matrix(p);

    return 0;
}