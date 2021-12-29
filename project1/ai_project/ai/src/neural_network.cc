#include "neural_network.h"


// activation function implementation
matrix_t Sigmoid(const matrix_t& mat)
{
    // code
}


matrix_t Tanh(const matrix_t& mat)
{
    // code
}


matrix_t ReLU(const matrix_t& mat)
{
    // code
}


matrix_t Leaky_ReLU(const matrix_t& mat)
{
    // code
}


matrix_t ELU(const matrix_t& mat)
{
    // code
}


// neural network class implementation

// constructors
neural_network::neural_network(void)
{
    // code
}

// add layers
void neural_network::add_layer(int32_t input_size, int32_t output_size, ActivationFunction function)
{
    // code
}

void neural_network::add_layer(uint32_t input_size, uint32_t output_size, ActivationFunction function)
{
    // code
}

void neural_network::add_layer(int64_t input_size, int64_t output_size, ActivationFunction function)
{
    // code
}

void neural_network::add_layer(uint64_t input_size, uint64_t output_size, ActivationFunction function)
{
    // code
}

// run the neural network
matrix_t neural_network::run(matrix_t input)
{
    // code
}

