#include "activlib.h"

// Identity
float identity(float x) { return x; }
float identity_d(float x) { return 1; }

// Binary Step
float binary_step(float x) { return (x < 0 ? 0 : 1); }
float binary_step_d(float x) { return (x != 0 ? 0 : 0xFFFFFFFF); }

// Sigmoid
float sigmoid(float x) { return (1 / (1 + exp(-x))); }
float sigmoid_d(float x) { return (sigmoid(x) * (1 - sigmoid(x))); }

// TanH
float tan_h(float x) { return ((exp(x) - exp(-x)) / (exp(x) + exp(-x))); }
float tan_h_d(float x) { return (1 - pow(tanh(x), 2)); }

// Rectified Linear Unit
float relu(float x) { return (x > 0 ? x : 0); }
float relu_d(float x) { return (x > 0 ? 1 : 0); }

// Gaussian Error Linear Unit
// float gelu(float x) {}
// float gelu_d(float x) {}

// SoftPlus
float softplus(float x) { return (log(1 + exp(x))); }
float softplus_d(float x) { return (1 / (1 + exp(-x))); }

// Exponential Linear Unit
float elu(float x, float alpha) { return (x > 0 ? x : (alpha * (exp(x) - 1))); }
float elu_d(float x, float alpha) { return (x > 0 ? 1 : (elu(x, alpha) + alpha)); }

// Scaled Exponential Linear Unit
float selu(float x)
{
    const float lambda = 1.0507;
    const float alpha = 1.67326;
    return (lambda * (x < 0 ? (alpha * (exp(x) - 1)) : x));
}
float selu_d(float x)
{
    const float lambda = 1.0507;
    const float alpha = 1.67326;
    return (lambda * (x < 0 ? (alpha * exp(x)) : 1));
}

// Leaky Rectified Linear Unit
float leaky_relu(float x, float alpha) { return (x < 0 ? (0.01 * x) : x); }
float leaky_relu_d(float x, float alpha) { return (x < 0 ? 0.01 : x); }

// Parameteric Rectified Linear Unit
float prelu(float x, float alpha) { return (x < 0 ? (alpha * x) : x); }
float prelu_d(float x, float alpha) { return (x < 0 ? alpha : 1); }

// ArcTan
float arctan(float x) { return (atan(x)); }
float arctan_d(float x) { return (1 / (pow(x, 2) + 1)); }

// ElliotSig
float elliot_sig(float x)
{
    return (x / (1 + (x < 0 ? -x : x)));
}
float elliot_sig_d(float x)
{
    return (1 / pow(1 + (x < 0 ? -x : x), 2));
}

// Square Nonlinearity
float sqnl(float x)
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
float sqnl_d(float x) { return (x < 0 ? (1 + (x / 2)) : (1 - (x / 2))); }

// S-Shaped Rectified Linear Activation Unit

// Bent identity
float bent_identity(float x) { return (((sqrt(pow(x, 2) + 1) - 1) / 2) + x); }
float bent_identity_d(float x) { return ((x / (2 * sqrt(pow(x, 2) + 1))) + 1); }

// Sigmoid Linear Unit
float silu(float x) { return (x / (1 + exp(-x))); }
float silu_d(float x) { return ((1 + exp(-x) + (x * exp(-x))) / pow(1 + exp(-x), 2)); }

// Sinusoid
float sinusoid(float x) { return (sin(x)); }
float sinusoid_d(float x) { return (cos(x)); }

// Sinc
float sinc(float x) { return (x == 0 ? 1 : (sin(x) / x)); }
float sinc_d(float x) { return (x == 0 ? 0 : ((cos(x) / x) - (sin(x) / pow(x, 2)))); }

// Gaussian
float gaussian(float x) { return (exp(-pow(x, 2))); }
float gaussian_d(float x) { return (-2 * x * exp(-pow(x, 2))); }

// SQ-RBF
float sqrbf(float x)
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
float sqrbf_d(float x)
{
    float y = (x < 0 ? -x : x);
    if (y <= 1)
    {
        return (-x);
    }
    else if ((y > 1) && (y < 2))
    {
        return (x - (2 * (x > 0 ? 1 : x == 0 ? 0
                                             : -1)));
    }
    else
    {
        return 0;
    }
}

// Softmax

// Maxout
// Matrix maxout(Matrix x) {}
// Matrix maxout_d(Matrix x) {}