#include "neural_network.h"


// activation function implementation

// matritix_t -> matrix_t
matrix_t Sigmoid(matrix_t& mat)
{
    // code
}


matrix_t Tanh(matrix_t& mat)
{
    // code
}


matrix_t ReLU(matrix_t& mat)
{
    // code
}


matrix_t Leaky_ReLU(matrix_t& mat)
{
    // code
}


matrix_t ExpLU(matrix_t& mat)
{
    // code
}


matrix_t Linear(matrix_t& mat)
{
    // code
}


// real_t -> real_t
real_t Sigmoid(real_t x)
{
    // code
}


real_t Tanh(real_t x)
{
    // code
}


real_t ReLU(real_t x)
{
    // code
}


real_t Leaky_ReLU(real_t x)
{
    const real_t alpha = real_t("0.01");
    // code
}


real_t ExpLU(real_t x)
{
    // code
}


real_t Linear(real_t x)
{
    // code
}

// ================================================================================================================================
// layer, neural network implementation
// ================================================================================================================================

// layer class

layer_t::layer_t(const layer_t& other)
{
    // code
}

layer_t::layer_t(int input_size, int output_size, const func_t& func)
{
    // code
}

layer_t::layer_t(const matrix_t& W, const matrix_t& b, const func_t& func)
{
    // code
}


// getters
const matrix_t& layer_t::get_W(void) const { return this->W; }
const matrix_t& layer_t::get_b(void) const { return this->b; }
const matrix_t& layer_t::get_X(void) const { return this->X; }
const matrix_t& layer_t::get_Z(void) const { return this->Z; }
const matrix_t& layer_t::get_d(void) const { return this->d; }

// forward propagation
matrix_t layer_t::forward(const matrix_t& X)
{
    // code
}

// backward propagation
/* @param
 * delta_:  delta of next layer
 * W_:      weight of next layer
 */
matrix_t layer_t::backward(const matrix_t& delta_, const matrix_t& W_)
{
    // code
}

// backword propagation (last layer)
/* @param
 * output:  output of neural network
 * labels:  labels of training data
 */
matrix_t layer_t::backlast(const matrix_t& output, const matrix_t& labels)
{
    // code
}

// update weights
void layer_t::update(const real_t& learning_rate)
{
    // code
}

// print
void layer_t::print(void) const
{
    cout << "|--------------------------------------------------" << endl;
    cout << "| input:  " << this->W.get_cols() << endl;
    cout << "| output: " << this->W.get_rows() << endl;
    string func_name = "";
    switch (this->func)
    {
    case SIGMOID:
        func_name = "Sigmoid";
        break;
    case TANH:
        func_name = "Tanh";
        break;
    case RELU:
        func_name = "ReLU";
        break;
    case LRELU:
        func_name = "Leaky ReLU";
        break;
    case ELU:
        func_name = "ExpLU";
        break;
    case LINEAR:
        func_name = "Linear";
        break;
    default:
        func_name = "Unknown";
        break;
    }
    cout << "| func:   " << func_name << endl;
    return ;
}

layer_t& layer_t::operator=(const layer_t& layer)
{
    // code
}

// neural network

// constructor
neural_network_t::neural_network_t(void)
{
    // code
}

neural_network_t::neural_network_t(const neural_network_t& other)
{
    // code
}

// getters
const vector<layer_t>& neural_network_t::get_layers(void) const { return this->layers; }
const matrix_t& neural_network_t::get_input(void)  const { return this->input;  }
const matrix_t& neural_network_t::get_output(void) const { return this->output; }

// setters (add layer)
void neural_network_t::add_layer(const layer_t& layer)
{
    // code
}

void neural_network_t::add_layer(const matrix_t& Weight, const matrix_t& bias, const func_t& func)
{
    // code
}

void neural_network_t::add_layer(const int32_t& input_size, const int32_t& output_size, const func_t& func)
{
    // code
}


// forward propagation
matrix_t neural_network_t::forward(void)
{
    // code
}

// backward propagation
void neural_network_t::backward(void)
{
    // code
}

// train
void neural_network_t::train(const matrix_t& input, const matrix_t& labels, const real_t& learning_rate)
{
    // code
}

// accuracy
// TODO

// predict
matrix_t neural_network_t::predict(const matrix_t& input)
{
    // code
}

// print
void neural_network_t::print(void) const
{
    cout << "============================================================" << endl;
    cout << "| neural network: " << this->layers.size() << " layers" << endl;
    for (auto& layer : this->layers)
        layer.print();
    cout << "============================================================" << endl;
}
