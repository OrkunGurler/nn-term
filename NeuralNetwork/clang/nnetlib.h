#include "activlib.h"
#include "trainlib.h"

typedef struct neuron
{
    int input;
    int hidden;
    int output;
} neuron;
neuron setneurons(int input, int hidden, int output);

typedef struct weight
{
    mx i2h;
    mx i2hb;
    mx *h2h;
    mx *h2hb;
    mx h2o;
    mx h2ob;
} weight;
weight setweights(neuron neurons, int hcount, int flag);

typedef struct neuralnetwork
{
    neuron neurons;
    weight weights;
    activ activation;
    float learningrate;
} nnet;
nnet createnetwork(neuron neurons, weight weights, activ activation, float learningrate);