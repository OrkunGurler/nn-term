#include "mxlib.h"

typedef struct activation
{
    float (*func)(float);
    float (*func_d)(float);
} activ;
activ setactiv(float (*func)(float), float (*func_d)(float));

// Identity
float Identity(float x);
float Identity_d(float x);

// Binary Step
float BinaryStep(float x);
float BinaryStep_d(float x);

// Sigmoid
float Sigmoid(float x);
float Sigmoid_d(float x);

// TanH
float TanH(float x);
float TanH_d(float x);

// Rectified Linear Unit
float ReLU(float x);
float ReLU_d(float x);

// Gaussian Error Linear Unit
// float GELU(float x);
// float GELU_d(float x);

// SoftPlus
float SoftPlus(float x);
float SoftPlus_d(float x);

// Exponential Linear Unit
float ELU(float x, float alpha);
float ELU_d(float x, float alpha);

// Scaled Exponential Linear Unit
float SELU(float x);
float SELU_d(float x);

// Leaky Rectified Linear Unit
float Leaky_ReLU(float x, float alpha);
float Leaky_ReLU_d(float x, float alpha);

// Parameteric Rectified Linear Unit
float PReLU(float x, float alpha);
float PReLU_d(float x, float alpha);

// ArcTan
float ArcTan(float x);
float ArcTan_d(float x);

// ElliotSig
float ElliotSig(float x);
float ElliotSig_d(float x);

// Square Nonlinearity
float SQNL(float x);
float SQNL_d(float x);

// S-Shaped Rectified Linear Activation Unit

// Bent identity
float BentIdentity(float x);
float BentIdentity_d(float x);

// Sigmoid Linear Unit
float SiLU(float x);
float SiLU_d(float x);

// Sinusoid
float Sinusoid(float x);
float Sinusoid_d(float x);

// Sinc
float Sinc(float x);
float Sinc_d(float x);

// Gaussian
float Gaussian(float x);
float Gaussian_d(float x);

// SQ-RBF
float SQRBF(float x);
float SQRBF_d(float x);

// Softmax

// Maxout
// Matrix Maxout(Matrix x);
// Matrix Maxout_d(Matrix x);