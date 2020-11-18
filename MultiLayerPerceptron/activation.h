typedef struct Activation
{
    float (*func)(float);
    float (*func_d)(float);
} Activation;
Activation activation(float (*func)(float), float (*func_d)(float));

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
// float SoftPlus(float x);
// float SoftPlus_d(float x);

// Exponential Linear Unit
float ELU(float x, float alpha);
float ELU_d(float x, float alpha);

// Scaled Exponential Linear Unit
// float SELU(float x, float alpha);
// float SELU_d(float x, float alpha);

// Leaky Rectified Linear Unit
float Leaky_ReLU(float x, float alpha);
float Leaky_ReLU_d(float x, float alpha);

// Parameteric Rectified Linear Unit
// float PReLU(float x, float alpha);
// float PReLU_d(float x, float alpha);

// ArcTan

// Square Nonlinearity

// S-Shaped Rectified Linear Activation Unit

// Bent identity

// Sigmoid Linear Unit

// Sinusoid

// Sinc

// Gaussian

// SQ-RBF

// Softmax

// Maxout