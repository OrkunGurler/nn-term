#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "matrix.h"

typedef struct nodes
{
    int input, hidden, output;
} nodes;
nodes Nodes(int input, int hidden, int output);

float Sigmoid(float x);
float Sigmoid_d(float x);

int main(int argc, char const *argv[])
{
    nodes n = Nodes(3, 3, 1);
    matrix m = Matrix(3, 2);

    return 0;
}

float Sigmoid(float x)
{
    float r = 1 / (1 + exp(x));
    return r;
}

float Sigmoid_d(float x)
{
    float r = Sigmoid(x) * (1 - Sigmoid(x));
    return r;
}

nodes Nodes(int input, int hidden, int output)
{
    nodes n;
    n.input = input;
    n.hidden = hidden;
    n.output = output;
    return n;
}