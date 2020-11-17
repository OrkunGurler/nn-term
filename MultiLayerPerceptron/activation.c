#include <math.h>
#include "activation.h"

/* ##### ##### ##### ##### ##### ##### ##### ##### */
/*     Activation Functions for Neural Network     */
/* ##### ##### ##### ##### ##### ##### ##### ##### */

Activation activation(float (*func)(float), float (*func_d)(float))
{
    Activation act;
    act.func = func;
    act.func_d = func_d;
    return act;
}

// Identity
float Identity(float x)
{
    float r = x;

    return r;
}

// Identity Derivative
float Identity_d(float x)
{
    float r = 1;

    return r;
}

/* ##### ##### ##### ##### ##### ##### ##### ##### */

// Binary Step
float BinaryStep(float x)
{
    float r;

    if (x >= 0)
    {
        r = 1;
    }
    else
    {
        r = 0;
    }

    return r;
}

// Binary Step Derivative
float BinaryStep_d(float x)
{
    float r;

    if (x == 0)
    {
        r = x;
    }
    else
    {
        r = 0;
    }

    return r;
}

/* ##### ##### ##### ##### ##### ##### ##### ##### */

// Sigmoid
float Sigmoid(float x)
{
    float r = 1 / (1 + exp(-x));

    return r;
}

// Sigmoid Derivative
float Sigmoid_d(float x)
{
    float r = Sigmoid(x) * (1 - Sigmoid(x));

    return r;
}

/* ##### ##### ##### ##### ##### ##### ##### ##### */

// TanH
float TanH(float x)
{
    float r = (exp(x) - exp(-x)) / (exp(x) + exp(-x));

    return r;
}

// TanH Derivative
float TanH_d(float x)
{
    float r = 1 - (TanH(x) * TanH(x));

    return r;
}

/* ##### ##### ##### ##### ##### ##### ##### ##### */

// Rectified Linear Unit
float ReLU(float x)
{
    float r;

    if (x > 0)
    {
        r = x;
    }
    else
    {
        r = 0;
    }

    return r;
}

// Rectified Linear Unit Derivative
float ReLU_d(float x)
{
    float r;

    if (x > 0)
    {
        r = 1;
    }
    else
    {
        r = 0;
    }

    return r;
}

/* ##### ##### ##### ##### ##### ##### ##### ##### */

// Gaussian Error Linear Unit
// float GELU(float x) {}

// Gaussian Error Linear Unit Derivative
// float GELU_d(float x) {}

/* ##### ##### ##### ##### ##### ##### ##### ##### */

// SoftPlus
// float SoftPlus(float x) {}

// SoftPlus Derivative
// float SoftPlus_d(float x) {}

/* ##### ##### ##### ##### ##### ##### ##### ##### */

// Exponential Linear Unit
float ELU(float x, float alpha)
{
    float r;

    if (x >= 0)
    {
        r = x;
    }
    else
    {
        r = alpha * (exp(x) - 1);
    }

    return r;
}

// Exponential Linear Unit Derivative
float ELU_d(float x, float alpha)
{
    float r;

    if (x > 0)
    {
        r = 1;
    }
    else
    {
        r = alpha * exp(x);
    }

    return r;
}

/* ##### ##### ##### ##### ##### ##### ##### ##### */

// Scaled Exponential Linear Unit
// float SELU(float x, float alpha) {}

// Scaled Exponential Linear Unit Derivative
// float SELU_d(float x, float alpha) {}

/* ##### ##### ##### ##### ##### ##### ##### ##### */

// Leaky Rectified Linear Unit
float Leaky_ReLU(float x, float alpha)
{
    float r;

    if (x > 0)
    {
        r = x;
    }
    else
    {
        r = alpha * x;
    }

    return r;
}

// Leaky Rectified Linear Unit Derivative
float Leaky_ReLU_d(float x, float alpha)
{
    float r;

    if (x > 0)
    {
        r = 1;
    }
    else
    {
        r = alpha;
    }

    return r;
}

/* ##### ##### ##### ##### ##### ##### ##### ##### */

// Parameteric Rectified Linear Unit
// float PReLU(float x, float alpha) {}

// Parameteric Rectified Linear Unit Derivative
// float PReLU_d(float x, float alpha) {}

/* ##### ##### ##### ##### ##### ##### ##### ##### */

// ArcTan
// ArcTan Derivative

/* ##### ##### ##### ##### ##### ##### ##### ##### */

// Square Nonlinearity
// Square Nonlinearity Derivative

/* ##### ##### ##### ##### ##### ##### ##### ##### */

// S-Shaped Rectified Linear Activation Unit
// S-Shaped Rectified Linear Activation Unit Derivative

/* ##### ##### ##### ##### ##### ##### ##### ##### */

// Bent identity
// Bent identity Derivative

/* ##### ##### ##### ##### ##### ##### ##### ##### */

// Sigmoid Linear Unit
// Sigmoid Linear Unit Derivative

/* ##### ##### ##### ##### ##### ##### ##### ##### */

// Sinusoid
// Sinusoid Derivative

/* ##### ##### ##### ##### ##### ##### ##### ##### */

// Sinc
// Sinc Derivative

/* ##### ##### ##### ##### ##### ##### ##### ##### */

// Gaussian
// Gaussian Derivative

/* ##### ##### ##### ##### ##### ##### ##### ##### */

// SQ-RBF
// SQ-RBF Derivative

/* ##### ##### ##### ##### ##### ##### ##### ##### */

// Softmax
// Softmax Derivative

/* ##### ##### ##### ##### ##### ##### ##### ##### */

// Maxout
// Maxout Derivative