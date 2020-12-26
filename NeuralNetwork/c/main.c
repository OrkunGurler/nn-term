#include "nnetlib.h"

int main(int argc, char const *argv[])
{
    // i.e. 8 * 8 - 2D Canvas
    mx input_data = create_matrix(8, 8);
    randomize(input_data, 0, 1);
    int input_size = input_data.rows * input_data.cols;
    int hidden_layer_node_size = pow(2, input_size);
    int hidden_layer_size = input_size;
    int output_node_size = sqrt(input_size);

    nnet nnet;
    nnet.layers = create_layers(input_size, hidden_layer_node_size, hidden_layer_size, output_node_size);
    nnet.activation = set_activfunc(&sigmoid, &sigmoid_d);
    nnet.learning_rate = 0.01;

    // mx input_for_train = create_matrix(pow(input_size, 2), 1);
    // backpropagation(nnet, input_for_train);

    mx input_for_prediction = create_matrix(pow(input_size, 2), 1);
    randomize(input_for_prediction, 0, 1);

    mx predicted = feed_forward(nnet, input_for_prediction); // TODO: fix predicted values (all values are same)
    print_matrix(predicted);

    return 0;
}