#include "neuralnet.h"

Nodes nodes(int input, int hidden, int output)
{
    Nodes n;
    n.input = input;
    n.hidden = hidden;
    n.output = output;
    return n;
}

NeuralNet neuralnet(Nodes n, Activation func, float learning_rate)
{
    NeuralNet net;

    net.nodes = n;

    net.weights_ih = matrix(net.nodes.hidden, net.nodes.input);
    m_rand(net.weights_ih, -1, 1);
    net.bias_ih = matrix(net.nodes.hidden, 1);
    m_rand(net.bias_ih, -1, 1);

    net.weights_ho = matrix(net.nodes.output, net.nodes.hidden);
    m_rand(net.weights_ho, -1, 1);
    net.bias_ho = matrix(net.nodes.output, 1);
    m_rand(net.bias_ho, -1, 1);

    net.activation = func;

    net.learning_rate = learning_rate;

    return net;
}

Matrix predict(NeuralNet net, Matrix input)
{
    Matrix hidden = m_scalar(net.weights_ih, input);
    hidden = m_add(hidden, net.bias_ih);
    m_map(hidden, net.activation.func);

    Matrix output = m_scalar(net.weights_ho, hidden);
    output = m_add(output, net.bias_ho);
    m_map(output, net.activation.func_d);

    return output;
}

void train(NeuralNet net, float input_arr, float target_arr)
{
}