#include "neuralnet.h"

Nodes set_nodes(int input, int hidden, int output)
{
    Nodes n;
    n.input = input;
    n.hidden = hidden;
    n.output = output;
    return n;
}

NeuralNetwork create_neuralnetwork(Nodes n, Activation func, float learning_rate)
{
    NeuralNetwork network;

    network.nodes = n;

    network.weights_ih = create_matrix(network.nodes.hidden, network.nodes.input);
    m_randomize(network.weights_ih, -1, 1);
    network.bias_ih = create_matrix(network.nodes.hidden, 1);
    m_randomize(network.bias_ih, -1, 1);

    network.weights_ho = create_matrix(network.nodes.output, network.nodes.hidden);
    m_randomize(network.weights_ho, -1, 1);
    network.bias_ho = create_matrix(network.nodes.output, 1);
    m_randomize(network.bias_ho, -1, 1);

    network.activation = func;

    network.learning_rate = learning_rate;

    return network;
}

Matrix predict(NeuralNetwork network, Matrix input)
{
    Matrix hidden = m_scalar(network.weights_ih, input);
    hidden = m_add(hidden, network.bias_ih);
    m_map(hidden, network.activation.func);

    Matrix output = m_scalar(network.weights_ho, hidden);
    output = m_add(output, network.bias_ho);
    m_map(output, network.activation.func_d);

    return output;
}

void train(NeuralNetwork network, float input_arr, float target_arr)
{
}