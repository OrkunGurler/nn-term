#include "neuralnet.h"

Nodes nodes(int input, int hidden, int output)
{
    Nodes n;
    n.input = input;
    n.hidden = hidden;
    n.output = output;
    return n;
}

NeuralNet neuralnet(int *node_arr, float learning_rate, float (*activation)(float))
{
    NeuralNet net;
    net.nodes = nodes(node_arr[0], node_arr[1], node_arr[2]);

    net.weights_ih = matrix(net.nodes.hidden, net.nodes.input);
    m_rand(net.weights_ih, -1, 1);
    net.bias_ih = matrix(net.nodes.hidden, 1);
    m_rand(net.bias_ih, -1, 1);

    net.weights_ho = matrix(net.nodes.output, net.nodes.hidden);
    m_rand(net.weights_ho, -1, 1);
    net.bias_ho = matrix(net.nodes.output, 1);
    m_rand(net.bias_ho, -1, 1);

    net.learning_rate = learning_rate;
    net.activasion = activation;

    return net;
}

Matrix predict(NeuralNet net, float *input_arr, int size)
{
    Matrix inputs = from_arr(input_arr, size);

    Matrix hidden = m_scalar(net.weights_ih, inputs);
    hidden = m_add(hidden, net.bias_ih);
    m_map(hidden, net.activasion);

    Matrix output = m_scalar(net.weights_ho, hidden);
    output = m_add(output, net.bias_ho);
    m_map(output, net.activasion);

    return output;
}

void train(NeuralNet net, float input_arr, float target_arr) {}