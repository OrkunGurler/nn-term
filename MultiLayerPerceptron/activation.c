#include <math.h>
#include "activation.h"
#define INF 0xFFFFFFFF

Activation set_activation(float (*func)(float), float (*func_d)(float))
{
    Activation act;
    act.func = func;
    act.func_d = func_d;
    return act;
}

// Identity
float Identity(float x) { return x; }
float Identity_d(float x) { return 1; }

// Binary Step
float BinaryStep(float x) { return (x < 0 ? 0 : 1); }
float BinaryStep_d(float x) { return (x != 0 ? 0 : INF); }

// Sigmoid
float Sigmoid(float x) { return (1 / (1 + exp(-x))); }
float Sigmoid_d(float x) { return (Sigmoid(x) * (1 - Sigmoid(x))); }

// TanH
float TanH(float x) { return ((exp(x) - exp(-x)) / (exp(x) + exp(-x))); }
float TanH_d(float x) { return (1 - pow(TanH(x), 2)); }

// Rectified Linear Unit
float ReLU(float x) { return (x > 0 ? x : 0); }
float ReLU_d(float x) { return (x > 0 ? 1 : 0); }

// Gaussian Error Linear Unit
// float GELU(float x) {}
// float GELU_d(float x) {}

// SoftPlus
float SoftPlus(float x) { return (log(1 + exp(x))); }
float SoftPlus_d(float x) { return (1 / (1 + exp(-x))); }

// Exponential Linear Unit
float ELU(float x, float alpha) { return (x > 0 ? x : (alpha * (exp(x) - 1))); }
float ELU_d(float x, float alpha) { return (x > 0 ? 1 : (ELU(x, alpha) + alpha)); }

// Scaled Exponential Linear Unit
float SELU(float x)
{
    const float lambda = 1.0507;
    const float alpha = 1.67326;
    return (lambda * (x < 0 ? (alpha * (exp(x) - 1)) : x));
}
float SELU_d(float x)
{
    const float lambda = 1.0507;
    const float alpha = 1.67326;
    return (lambda * (x < 0 ? (alpha * exp(x)) : 1));
}

// Leaky Rectified Linear Unit
float Leaky_ReLU(float x, float alpha) { return (x < 0 ? (0.01 * x) : x); }
float Leaky_ReLU_d(float x, float alpha) { return (x < 0 ? 0.01 : x); }

// Parameteric Rectified Linear Unit
float PReLU(float x, float alpha) { return (x < 0 ? (alpha * x) : x); }
float PReLU_d(float x, float alpha) { return (x < 0 ? alpha : 1); }

// ArcTan
float ArcTan(float x) { return (atan(x)); }
float ArcTan_d(float x) { return (1 / (pow(x, 2) + 1)); }

// ElliotSig
float ElliotSig(float x)
{
    return (x / (1 + (x < 0 ? -x : x)));
}
float ElliotSig_d(float x)
{
    return (1 / pow(1 + (x < 0 ? -x : x), 2));
}

// Square Nonlinearity
float SQNL(float x)
{
    if (x > 2)
    {
        return 1;
    }
    else if ((x >= 0) && (x <= 2))
    {
        return (x - (pow(x, 2) / 4));
    }
    else if ((x >= -2) && (x < 0))
    {
        return (x + (pow(x, 2) / 4));
    }
    else
    {
        return -1;
    }
}
float SQNL_d(float x) { return (x < 0 ? (1 + (x / 2)) : (1 - (x / 2))); }

// S-Shaped Rectified Linear Activation Unit

// Bent identity
float BentIdentity(float x) { return (((sqrt(pow(x, 2) + 1) - 1) / 2) + x); }
float BentIdentity_d(float x) { return ((x / (2 * sqrt(pow(x, 2) + 1))) + 1); }

// Sigmoid Linear Unit
float SiLU(float x) { return (x / (1 + exp(-x))); }
float SiLU_d(float x) { return ((1 + exp(-x) + (x * exp(-x))) / pow(1 + exp(-x), 2)); }

// Sinusoid
float Sinusoid(float x) { return (sin(x)); }
float Sinusoid_d(float x) { return (cos(x)); }

// Sinc
float Sinc(float x) { return (x == 0 ? 1 : (sin(x) / x)); }
float Sinc_d(float x) { return (x == 0 ? 0 : ((cos(x) / x) - (sin(x) / pow(x, 2)))); }

// Gaussian
float Gaussian(float x) { return (exp(-pow(x, 2))); }
float Gaussian_d(float x) { return (-2 * x * exp(-pow(x, 2))); }

// SQ-RBF
float SQRBF(float x)
{
    float y = (x < 0 ? -x : x);
    if (y <= 1)
    {
        return (1 - (pow(x, 2) / 2));
    }
    else if ((y > 1) && (y < 2))
    {
        return ((1 / 2) * pow(2 - y, 2));
    }
    else
    {
        return 0;
    }
}
float SQRBF_d(float x)
{
    float y = (x < 0 ? -x : x);
    if (y <= 1)
    {
        return (-x);
    }
    else if ((y > 1) && (y < 2))
    {
        return (x - (2 * (x > 0 ? 1 : x == 0 ? 0 : -1)));
    }
    else
    {
        return 0;
    }
}

// Softmax

// Maxout
// Matrix Maxout(Matrix x) {}
// Matrix Maxout_d(Matrix x) {}