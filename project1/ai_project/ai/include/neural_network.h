#ifndef __NEURAL_NETWORK_H__
#define __NEURAL_NETWORK_H__

#include "matrix.h"

// activation function
enum ActivationFunction {
    Sigmoid,
    Tanh,
    ReLU,
    LReLU,
    ELU,
};


matrix_t Sigmoid(const matrix_t&);
matrix_t Tanh(const matrix_t&);
matrix_t ReLU(const matrix_t&);
matrix_t Leaky_ReLU(const matrix_t&);
matrix_t ELU(const matrix_t&);


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
    template<typename T>
    void add_layer(T input_size, T output_size, ActivationFunction function);

    // run the neural network
    matrix_t run(matrix_t input);
};

#endif  // __NEURAL_NETWORK_H__
