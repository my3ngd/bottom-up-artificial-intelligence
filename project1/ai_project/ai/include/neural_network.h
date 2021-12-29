#ifndef __NEURAL_NETWORK_H__
#define __NEURAL_NETWORK_H__

#include "matrix.h"

// activation function
enum ActivationFunction {
    SIGMOID,
    TANH,
    RELU,
    LRELU,
    ELU,
};


matrix_t Sigmoid(matrix_t&);
matrix_t Tanh(matrix_t&);
matrix_t ReLU(matrix_t&);
matrix_t Leaky_ReLU(matrix_t&, const real_t&);
matrix_t ExpLU(matrix_t&);


// neural network class
class neural_network
{
private:
    vector<matrix_t> Weights;   // Weights of the neural network
    vector<matrix_t> Biases;    // Biases of the neural network
    vector<string> functions;   // Activation functions of the neural network
public:
    // constructors
    neural_network(void);

    // add layers
    void add_layer(const  int32_t& input_size, const  int32_t& output_size, ActivationFunction function);
    void add_layer(const uint32_t& input_size, const uint32_t& output_size, ActivationFunction function);
    void add_layer(const  int64_t& input_size, const  int64_t& output_size, ActivationFunction function);
    void add_layer(const uint64_t& input_size, const uint64_t& output_size, ActivationFunction function);

    // describe the neural network
    void describe(void);

    // run the neural network
    matrix_t run(matrix_t input);
};

#endif  // __NEURAL_NETWORK_H__
