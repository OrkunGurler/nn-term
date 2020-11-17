#include "neuralnet.h"

Nodes nodes(int input, int hidden, int output)
{
    Nodes n;
    n.input = input;
    n.hidden = hidden;
    n.output = output;
    return n;
}

NeuralNet neuralnet(int input, int hidden, int output, float learning_rate, float (*activation)(float))
{
    NeuralNet net;
    net.nodes = nodes(input, hidden, output);

    net.weights_ih = matrix(hidden, input);
    m_rand(net.weights_ih, -1, 1);
    net.bias_ih = matrix(hidden, 1);
    m_rand(net.bias_ih, -1, 1);

    net.weights_ho = matrix(output, hidden);
    m_rand(net.weights_ho, -1, 1);
    net.bias_ho = matrix(output, 1);
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