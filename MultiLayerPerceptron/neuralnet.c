#include "neuralnet.h"

Nodes set_nodes(int input, int hidden, int output)
{
    Nodes node;
    node.input = input;
    node.hidden = hidden;
    node.output = output;
    return node;
}

NeuralNetwork create_neuralnetwork(Nodes node, Activation func, float learning_rate)
{
    NeuralNetwork network;

    network.nodes = node;

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
    m_addition(hidden, network.bias_ih);
    m_map(hidden, network.activation.func);

    Matrix outputs = m_scalar(network.weights_ho, hidden);
    m_addition(outputs, network.bias_ho);
    m_map(outputs, network.activation.func);

    return outputs;
}

void train(NeuralNetwork network, Matrix inputs, Matrix targets)
{
    Matrix hidden = m_scalar(network.weights_ih, inputs);
    m_addition(hidden, network.bias_ih);
    m_map(hidden, network.activation.func);

    Matrix outputs = m_scalar(network.weights_ho, hidden);
    m_addition(outputs, network.bias_ho);
    m_map(outputs, network.activation.func);

    Matrix output_errors = m_copy(targets);
    m_subtraction(output_errors, outputs);
    Matrix output_gradients = m_map_r(outputs, network.activation.func_d);
    m_hadamard(output_gradients, output_errors);
    m_multiply(output_gradients, network.learning_rate);

    Matrix hidden_t = m_transpose(hidden);
    Matrix weights_ho_d = m_scalar(output_gradients, hidden_t);
    m_addition(network.weights_ho, weights_ho_d);
    m_addition(network.bias_ho, output_gradients);

    Matrix weights_ho_t = m_transpose(network.weights_ho);
    Matrix hidden_errors = m_scalar(weights_ho_t, output_errors);
    Matrix hidden_gradients = m_copy(hidden);
    m_map(hidden_gradients, network.activation.func_d);
    m_hadamard(hidden_gradients, hidden_errors);
    m_multiply(hidden_gradients, network.learning_rate);

    Matrix inputs_t = m_transpose(inputs);

    Matrix weights_ih_d = m_scalar(hidden_gradients, inputs_t);
    m_addition(network.weights_ih, weights_ih_d);
    m_addition(network.bias_ih, hidden_gradients);
}