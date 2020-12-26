#include "layer.h"
#include "activlib.h"

typedef struct nnetlib
{
    layer input;
    layer output;
    layer layers;
    activ activation;
    float learning_rate;
} nnet;

void add_input(nnet nnet, mx input_data);

mx feed_forward(nnet nnet, mx input_for_prediction);

void linear_regression();
void gradient_descent();
void logistic_regression();
void back_propagation(nnet nnet, mx input_for_train, mx input_for_test);