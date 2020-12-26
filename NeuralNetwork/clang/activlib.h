#include <math.h>

typedef struct activlib
{
    float (*func)(float);
    float (*func_d)(float);
} activ;
activ set_activfunc(float (*func)(float), float (*func_d)(float));

// Identity
float identity(float x);
float identity_d(float x);

// Binary Step
float binary_step(float x);
float binary_step_d(float x);

// Sigmoid
float sigmoid(float x);
float sigmoid_d(float x);

// TanH
float tan_h(float x);
float tan_h_d(float x);

// Rectified Linear Unit
float relu(float x);
float relu_d(float x);

// Gaussian Error Linear Unit
// float gelu(float x);
// float gelu_d(float x);

// SoftPlus
float softplus(float x);
float softplus_d(float x);

// Exponential Linear Unit
float elu(float x, float alpha);
float elu_d(float x, float alpha);

// Scaled Exponential Linear Unit
float selu(float x);
float selu_d(float x);

// Leaky Rectified Linear Unit
float leaky_relu(float x, float alpha);
float leaky_relu_d(float x, float alpha);

// Parameteric Rectified Linear Unit
float prelu(float x, float alpha);
float prelu_d(float x, float alpha);

// ArcTan
float arctan(float x);
float arctan_d(float x);

// ElliotSig
float elliot_sig(float x);
float elliot_sig_d(float x);

// Square Nonlinearity
float sqnl(float x);
float sqnl_d(float x);

// S-Shaped Rectified Linear Activation Unit

// Bent identity
float bent_identity(float x);
float bent_identity_d(float x);

// Sigmoid Linear Unit
float silu(float x);
float silu_d(float x);

// Sinusoid
float sinusoid(float x);
float sinusoid_d(float x);

// Sinc
float sinc(float x);
float sinc_d(float x);

// Gaussian
float gaussian(float x);
float gaussian_d(float x);

// SQ-RBF
float sqrbf(float x);
float sqrbf_d(float x);

// Softmax

// Maxout
// Matrix maxout(Matrix x);
// Matrix maxout_d(Matrix x);