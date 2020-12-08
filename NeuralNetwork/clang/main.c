#include "nnetlib.h"

int main(int argc, char const *argv[])
{
    // i.e. 8 * 8 - 2D Canvas
    int size = 8 * 8;
    mx input_data = create_matrix(size, 1);
    randomize(input_data, 0, 1);
    int hidden_layer_node_size = pow(2, size);
    int hidden_layer_size = size;
    int output_node_size = sqrt(size);

    nnet nnet = create_network(input_data, hidden_layer_node_size, hidden_layer_size, output_node_size);

    mx input_for_prediction = create_matrix(pow(size, 2), 1);
    randomize(input_for_prediction, 0, 1);

    predict(nnet, input_for_prediction); // TODO: fix predicted values (all values are same)

    return 0;
}