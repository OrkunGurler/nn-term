#include "nnetlib.h"

nnet create_network(mx input_data, int hidden_layer_node_size, int hidden_layer_size, int output_node_size)
{
    nnet nnet;
    int data_size = input_data.rows;
    nnet.layers = create_layers(data_size, hidden_layer_node_size, hidden_layer_size, output_node_size);
    add_input(nnet, input_data);
    return nnet;
}

void add_input(nnet nnet, mx input_data)
{
    int i, j;
    for (i = 0; i < nnet.layers->nodes.rows; i++)
    {
        for (j = 0; j < nnet.layers->nodes.cols; j++)
        {
            nnet.layers->nodes.data[i][j] = input_data.data[i][j];
        }
    }
}

void predict(nnet nnet, mx input_for_prediction)
{
    layer layer = nnet.layers;
    while (layer->next != NULL)
    {
        layer->next->nodes = dot(layer->weights, layer->nodes);
        addtom(layer->next->nodes, layer->bias);
        map(layer->next->nodes, &sigmoid);
        layer = layer->next;
    }
    printf("\nrows..: %d", layer->nodes.rows);
    printf("\ncols..: %d\n", layer->nodes.cols);
    print_matrix(layer->nodes);
}

void linear_regression() {}
void gradient_descent() {}
void logistic_regression() {}