#include "nnetlib.h"

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

mx feed_forward(nnet nnet, mx input_for_prediction)
{
    layer layer = nnet.layers;
    while (layer->next != NULL)
    {
        layer->next->nodes = dot(layer->weights, layer->nodes);
        addtom(layer->next->nodes, layer->bias);
        map(layer->next->nodes, &sigmoid);
        layer = layer->next;
    }
    return layer->nodes;
}

void linear_regression() {}
void gradient_descent() {}
void logistic_regression() {}
void back_propagation(nnet nnet, mx input_for_train) {}