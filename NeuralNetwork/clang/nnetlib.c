#include "nnetlib.h"

neuron setneurons(int input, int hidden, int output)
{
    neuron n;
    n.input = input;
    n.hidden = hidden;
    n.output = output;
    return n;
}

weight setweights(neuron neurons, int hcount, int flag)
{
    weight w;
    w.i2h = createm(neurons.input, hcount);
    w.i2hb = createm(neurons.input, 1);
    w.h2h = (mx *)malloc(hcount * sizeof(mx));
    w.h2hb = (mx *)malloc(hcount * sizeof(mx));
    int i;
    for (i = 0; i < hcount; i++)
    {
        w.h2h[i] = createm(hcount, hcount);
        w.h2hb[i] = createm(hcount, 1);
        if (flag)
        {
            matrandom(w.h2h[i], 0, 1);
            matrandom(w.h2hb[i], 0, 1);
        }
    }
    w.h2o = createm(hcount, neurons.output);
    w.h2ob = createm(hcount, 1);
    return w;
}

nnet createnetwork(neuron neurons, weight weights, activ activation, float learningrate)
{
    nnet n;
    n.neurons = neurons;
    n.weights = weights;
    n.activation = activation;
    n.learningrate = learningrate;
}