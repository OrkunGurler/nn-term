#include "mxlib.h"

typedef struct LAYER_S *layer;
typedef struct LAYER_S
{
    mx nodes;
    mx weights;
    float bias;
    layer next;
} LAYER_T[1];
layer create_layers(int input_size, int hidden_layer_node_size, int hidden_layer_size, int output_node_size);