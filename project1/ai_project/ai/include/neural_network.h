#ifndef __NEURAL_NETWORK_H__
#define __NEURAL_NETWORK_H__

#include "matrix.h"

// activation function
enum ActivationFunction {
    SIGMOID,
    RELU,
    TANH,
    LEAKY_RELU,
};


matrix_t sigmoid(const matrix_t&);
matrix_t relu(const matrix_t&);
// matrix_t tanh(const matrix_t&);
// matrix_t leaky_relu(const matrix_t&);
// matrix_t softmax(const matrix_t&);


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
