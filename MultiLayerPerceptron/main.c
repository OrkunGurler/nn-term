#include "neuralnet.h"
#include "activation.h"

int main(int argc, char const *argv[])
{
    int node_arr[] = {3, 3, 1}; // Input, Hidden, Output Node Respectively
    NeuralNet net = neuralnet(node_arr, 0.01, &TanH);

    float input_arr[] = {1, 2, 3};
    int input_arr_size = (int)(sizeof(input_arr) / sizeof(float));

    Matrix p = predict(net, input_arr, input_arr_size);
    PrintMatrix(p);

    return 0;
}