#include "layer.h"

layer create_layers(int input_node_size, int hidden_layer_node_size, int hidden_layer_size, int output_node_size)
{
    layer input_layer = (layer)malloc(sizeof(LAYER_T));
    input_layer->nodes = create_matrix(input_node_size, 1);
    input_layer->weights = create_matrix(hidden_layer_node_size, input_node_size);
    randomize(input_layer->weights, 0, 1);
    input_layer->bias = (float)rand() / (float)(RAND_MAX);
    input_layer->prev = NULL;

    layer next_hidden_layer = (layer)malloc(sizeof(LAYER_T));
    input_layer->next = next_hidden_layer;
    next_hidden_layer->prev = input_layer;

    int i;
    layer prev;
    for (i = 0; i < hidden_layer_size; i++)
    {
        next_hidden_layer->nodes = create_matrix(hidden_layer_node_size, 1);
        if (i != hidden_layer_size - 1)
        {
            next_hidden_layer->weights = create_matrix(hidden_layer_node_size, hidden_layer_node_size);
        }
        else
        {
            next_hidden_layer->weights = create_matrix(output_node_size, hidden_layer_node_size);
        }
        randomize(next_hidden_layer->weights, 0, 1);
        next_hidden_layer->bias = (float)rand() / (float)(RAND_MAX);
        next_hidden_layer->next = (layer)malloc(sizeof(LAYER_T));
        prev = next_hidden_layer;
        next_hidden_layer = next_hidden_layer->next;
        next_hidden_layer->prev = prev;
    }

    layer output_layer = next_hidden_layer;

    output_layer->nodes = create_matrix(output_node_size, 1);
    output_layer->next = NULL;

    return input_layer;
}