#ifndef __NEURAL_NETWORK_H__
#define __NEURAL_NETWORK_H__

#include "matrix.h"


// matrix_t -> matrix_t
matrix_t Sigmoid(matrix_t&);
matrix_t Tanh(matrix_t&);
matrix_t ReLU(matrix_t&);
matrix_t Leaky_ReLU(matrix_t&);
matrix_t ExpLU(matrix_t&);
matrix_t Linear(matrix_t&);

// real_t -> real_t
real_t Sigmoid(real_t);
real_t Tanh(real_t);
real_t ReLU(real_t);
real_t Leaky_ReLU(real_t);
real_t ExpLU(real_t);
real_t Linear(real_t);



// layer class
class layer_t
{
private:
    matrix_t W;  // weights
    matrix_t b;  // bias
    matrix_t X;  // input
    matrix_t Z;  // output
    func_t func;
    matrix_t d;  // gradient?
public:
    int layer_idx = -1;
    // constructor
    layer_t(const layer_t&);
    layer_t(int, int, const func_t&);
    layer_t(const matrix_t&, const matrix_t&, const func_t&);

    // getters
    const matrix_t& get_W(void) const;
    const matrix_t& get_b(void) const;
    const matrix_t& get_X(void) const;
    const matrix_t& get_Z(void) const;
    const matrix_t& get_d(void) const;

    // forward propagation
    matrix_t forward(const matrix_t&);

    // backward propagation
    matrix_t backward(const matrix_t&, const matrix_t&);
    matrix_t backlast(const matrix_t&, const matrix_t&);

    // update weights
    void update(const real_t&);

    // print
    void print(void) const;

    // operators
    layer_t& operator=(const layer_t&);
};


// neural network class
class neural_network_t
{
private:
    vector<layer_t> layers;
    matrix_t input;   // #batch x #in_dim
    matrix_t output;  // #batch x #out_dim
    matrix_t labels;  // #batch x #out_dim
    real_t learning_rate;
public:
    // constructor
    neural_network_t(void);
    neural_network_t(const neural_network_t&);

    // getters
    const vector<layer_t>& get_layers(void) const;
    const matrix_t& get_input(void) const;
    const matrix_t& get_output(void) const;

    // setters (add layer)
    void add_layer(const layer_t&);
    void add_layer(const matrix_t&, const matrix_t&, const func_t&);
    void add_layer(const int32_t&, const int32_t&, const func_t&);

    // forward propagation
    matrix_t forward(void);

    // backward propagation
    void backward(void);

    // update weights
    void update(void);

    // train
    void train(const matrix_t&, const matrix_t&, const real_t&);

    // accuracy
    // real_t accuracy(void);

    // predict
    matrix_t predict(const matrix_t&);

    // print
    void print(void) const;
};

#endif  // __NEURAL_NETWORK_H__
