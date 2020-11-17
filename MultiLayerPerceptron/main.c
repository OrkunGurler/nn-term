#include "neuralnet.h"
#include "activation.h"

int main(int argc, char const *argv[])
{
    NeuralNet n = neuralnet(3, 3, 1, 0.01, &Sigmoid);

    float input_arr[] = {1, 2, 3};
    int input_arr_size = (int)(sizeof(input_arr) / sizeof(float));

    Matrix p = predict(n, input_arr, input_arr_size);

    PrintMatrix(p);

    return 0;
}