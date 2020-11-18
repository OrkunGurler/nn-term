#include "network.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int input_nodes = 5;
    int hidden_nodes = 10;
    int output_nodes = 2;
    Nodes node = set_nodes(input_nodes, hidden_nodes, output_nodes);
    Activation af = set_activation(&Sigmoid, &Sigmoid_d);
    float learning_rate = 0.01;
    NeuralNetwork network = create_neuralnetwork(node, af, learning_rate);

    // printf("\nNetwork's Initial Input to Hidden Weights..: \n");
    // print_matrix(network.weights_ih);
    // printf("\nNetwork's Initial Hidden to Output Weights..: \n");
    // print_matrix(network.weights_ho);

    // Matrix test_data = create_matrix(input_nodes, 1);
    // m_randomize(test_data, -100, 100);
    // Matrix train_data = create_matrix(input_nodes, 1);
    // int i, size = 1000;
    // for (i = 0; i < size; i++)
    // {
    //     m_randomize(train_data, -100, 100);
    //     train(network, train_data, test_data);
    // }

    // printf("\nNetwork's Trained Input to Hidden Weights..: \n");
    // print_matrix(network.weights_ih);
    // printf("\nNetwork's Trained Hidden to Output Weights..: \n");
    // print_matrix(network.weights_ho);

    Matrix input = create_matrix(input_nodes, 1);
    m_randomize(input, -100, 100);
    Matrix p = predict(network, input);

    printf("\nPredicted..: ");
    print_array(to_array(p), p.rows * p.cols);

    return 0;
}