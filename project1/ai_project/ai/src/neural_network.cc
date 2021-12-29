#include "neural_network.h"


// activation function implementation
matrix_t Sigmoid(matrix_t& mat)
{
    matrix_t result(mat.get_rows(), mat.get_cols());
    for (int i = 0; i < mat.get_rows(); i++)
        for (int j = 0; j < mat.get_cols(); j++)
            result[i][j] = real_t(1) / (real_t(1) + exp(-mat[i][j]));
    return result;
}


matrix_t Tanh(matrix_t& mat)
{
    matrix_t result(mat.get_rows(), mat.get_cols());
    for (int i = 0; i < mat.get_rows(); i++)
        for (int j = 0; j < mat.get_cols(); j++)
            result[i][j] = tanh(mat[i][j]);
    return result;
}


matrix_t ReLU(matrix_t& mat)
{
    matrix_t result(mat.get_rows(), mat.get_cols());
    for (int i = 0; i < mat.get_rows(); i++)
        for (int j = 0; j < mat.get_cols(); j++)
            result[i][j] = mat[i][j] > 0 ? mat[i][j] : 0;
    return result;
}


matrix_t Leaky_ReLU(matrix_t& mat, const real_t& alpha)
{
    matrix_t result(mat);
    for (int i = 0; i < mat.get_rows(); i++)
        for (int j = 0; j < mat.get_cols(); j++)
            result[i][j] *= mat[i][j] > 0 ? real_t(1) : alpha;
    return result;
}


matrix_t ExpLU(matrix_t& mat)
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
void neural_network::add_layer(const int32_t& input_size,  const int32_t& output_size,  ActivationFunction function)
{
    // code
}

void neural_network::add_layer(const uint32_t& input_size, const uint32_t& output_size, ActivationFunction function)
{
    // code
}

void neural_network::add_layer(const int64_t& input_size,  const int64_t& output_size,  ActivationFunction function)
{
    // code
}

void neural_network::add_layer(const uint64_t& input_size, const uint64_t& output_size, ActivationFunction function)
{
    // code
}


// describe the neural network
void neural_network::describe(void)
{
    // code
}


// run the neural network
matrix_t neural_network::run(matrix_t input)
{
    // code
}

