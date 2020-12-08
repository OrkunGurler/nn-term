#include "layer.h"
#include "activlib.h"

typedef struct nnetlib
{
    layer layers;
} nnet;
nnet create_network(mx input_data, int hidden_layer_node_size, int hidden_layer_size, int output_node_size);

void add_input(nnet nnet, mx input_data);

void predict(nnet nnet, mx input_for_prediction);

void linear_regression();
void gradient_descent();
void logistic_regression();