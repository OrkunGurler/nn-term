/* ##### ##### ##### ##### ##### ##### ##### ##### */
/*     Activation Functions for Neural Network     */
/* ##### ##### ##### ##### ##### ##### ##### ##### */

typedef struct Activation
{
    float (*func)(float);
    float (*func_d)(float);
} Activation;
Activation activation(float (*func)(float), float (*func_d)(float));

// Identity
float Identity(float x);

// Identity Derivative
float Identity_d(float x);

/* ##### ##### ##### ##### ##### ##### ##### ##### */

// Binary Step
float BinaryStep(float x);

// Binary Step Derivative
float BinaryStep_d(float x);

/* ##### ##### ##### ##### ##### ##### ##### ##### */

// Sigmoid
float Sigmoid(float x);

// Sigmoid Derivative
float Sigmoid_d(float x);

/* ##### ##### ##### ##### ##### ##### ##### ##### */

// TanH
float TanH(float x);

// TanH Derivative
float TanH_d(float x);

/* ##### ##### ##### ##### ##### ##### ##### ##### */

// Rectified Linear Unit
float ReLU(float x);

// Rectified Linear Unit Derivative
float ReLU_d(float x);

/* ##### ##### ##### ##### ##### ##### ##### ##### */

// Gaussian Error Linear Unit
float GELU(float x);

// Gaussian Error Linear Unit Derivative
float GELU_d(float x);

/* ##### ##### ##### ##### ##### ##### ##### ##### */

// SoftPlus
float SoftPlus(float x);

// SoftPlus Derivative
float SoftPlus_d(float x);

/* ##### ##### ##### ##### ##### ##### ##### ##### */

// Exponential Linear Unit
float ELU(float x, float alpha);

// Exponential Linear Unit Derivative
float ELU_d(float x, float alpha);

/* ##### ##### ##### ##### ##### ##### ##### ##### */

// Scaled Exponential Linear Unit
float SELU(float x, float alpha);

// Scaled Exponential Linear Unit Derivative
float SELU_d(float x, float alpha);

/* ##### ##### ##### ##### ##### ##### ##### ##### */

// Leaky Rectified Linear Unit
float Leaky_ReLU(float x, float alpha);

// Leaky Rectified Linear Unit Derivative
float Leaky_ReLU_d(float x, float alpha);

/* ##### ##### ##### ##### ##### ##### ##### ##### */

// Parameteric Rectified Linear Unit
float PReLU(float x, float alpha);

// Parameteric Rectified Linear Unit Derivative
float PReLU_d(float x, float alpha);

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