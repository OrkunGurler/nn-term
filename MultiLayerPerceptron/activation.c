#include <math.h>
#include "activation.h"

Activation activation(float (*func)(float), float (*func_d)(float))
{
    Activation act;
    act.func = func;
    act.func_d = func_d;
    return act;
}

// Identity
float Identity(float x) { return x; }

// Identity Derivative
float Identity_d(float x) { return 1; }

// Binary Step
float BinaryStep(float x) { return (x >= 0 ? 1 : 0); }

// Binary Step Derivative
float BinaryStep_d(float x) { return (x == 0 ? x : 0); }

// Sigmoid
float Sigmoid(float x) { return (1 / (1 + exp(-x))); }

// Sigmoid Derivative
float Sigmoid_d(float x) { return (Sigmoid(x) * (1 - Sigmoid(x))); }

// TanH
float TanH(float x) { return ((exp(x) - exp(-x)) / (exp(x) + exp(-x))); }

// TanH Derivative
float TanH_d(float x) { return (1 - (TanH(x) * TanH(x))); }

// Rectified Linear Unit
float ReLU(float x) { return (x > 0 ? x : 0); }

// Rectified Linear Unit Derivative
float ReLU_d(float x) { return (x > 0 ? 1 : 0); }

// Gaussian Error Linear Unit
// float GELU(float x) {}

// Gaussian Error Linear Unit Derivative
// float GELU_d(float x) {}

// SoftPlus
// float SoftPlus(float x) {}

// SoftPlus Derivative
// float SoftPlus_d(float x) {}

// Exponential Linear Unit
float ELU(float x, float alpha) { return (x >= 0 ? x : (alpha * (exp(x) - 1))); }

// Exponential Linear Unit Derivative
float ELU_d(float x, float alpha) { return (x > 0 ? 1 : (alpha * exp(x))); }

// Scaled Exponential Linear Unit
// float SELU(float x, float alpha) {}

// Scaled Exponential Linear Unit Derivative
// float SELU_d(float x, float alpha) {}

// Leaky Rectified Linear Unit
float Leaky_ReLU(float x, float alpha) { return (x > 0 ? x : (alpha * x)); }

// Leaky Rectified Linear Unit Derivative
float Leaky_ReLU_d(float x, float alpha) { return (x > 0 ? 1 : alpha); }

// Parameteric Rectified Linear Unit
// float PReLU(float x, float alpha) {}

// Parameteric Rectified Linear Unit Derivative
// float PReLU_d(float x, float alpha) {}

// ArcTan
// ArcTan Derivative

// Square Nonlinearity
// Square Nonlinearity Derivative

// S-Shaped Rectified Linear Activation Unit
// S-Shaped Rectified Linear Activation Unit Derivative

// Bent identity
// Bent identity Derivative

// Sigmoid Linear Unit
// Sigmoid Linear Unit Derivative

// Sinusoid
// Sinusoid Derivative

// Sinc
// Sinc Derivative

// Gaussian
// Gaussian Derivative

// SQ-RBF
// SQ-RBF Derivative

// Softmax
// Softmax Derivative

// Maxout
// Maxout Derivative