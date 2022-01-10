#include "neural_network.h"


// activation function implementation

// matritix_t -> matrix_t
matrix_t Sigmoid(matrix_t& mat)
{
    // cout << __func__ << endl;
    matrix_t result(mat.get_rows(), mat.get_cols());
    for (int i = 0; i < mat.get_rows(); i++)
        for (int j = 0; j < mat.get_cols(); j++)
            result[i][j] = real_t(1) / (real_t(1) + exp(-mat[i][j]));
    return result;
}


matrix_t Tanh(matrix_t& mat)
{
    // cout << __func__ << endl;
    return mat;
}


matrix_t ReLU(matrix_t& mat)
{
    // cout << __func__ << endl;
    matrix_t result(mat.get_rows(), mat.get_cols());
    for (int i = 0; i < mat.get_rows(); i++)
        for (int j = 0; j < mat.get_cols(); j++)
            result[i][j] = mat[i][j] > 0 ? mat[i][j] : 0;
    return result;
}


matrix_t Leaky_ReLU(matrix_t& mat)
{
    // cout << __func__ << endl;
    const real_t alpha = real_t("0.01");
    matrix_t result(mat);
    for (int i = 0; i < mat.get_rows(); i++)
        for (int j = 0; j < mat.get_cols(); j++)
            result[i][j] *= mat[i][j] > 0 ? real_t(1) : alpha;
    return result;
}


matrix_t ExpLU(matrix_t& mat)
{
    // cout << __func__ << endl;
    // TODO: implement
    return mat;
}


matrix_t Linear(matrix_t& mat)
{
    // cout << __func__ << endl;
    return mat;
}


// real_t -> real_t
real_t Sigmoid(real_t x)
{
    // cout << __func__ << endl;
    return real_t(1) / (real_t(1) + exp(-x));
}


real_t Tanh(real_t x)
{
    // cout << __func__ << endl;
    // TODO
    return x;
}


real_t ReLU(real_t x)
{
    // cout << __func__ << endl;
    return x > 0 ? x : 0;
}


real_t Leaky_ReLU(real_t x)
{
    // cout << __func__ << endl;
    const real_t alpha = real_t("0.01");
    return x > 0 ? x : alpha;
}


real_t ExpLU(real_t x)
{
    // cout << __func__ << endl;
    // TODO
}


real_t Linear(real_t x)
{
    // cout << __func__ << endl;
    return x;
}

// ================================================================================================================================
// layer, neural network implementation
// ================================================================================================================================

// layer class

layer_t::layer_t(const layer_t& other)
{
    // cout << __func__ << endl;
    W = other.W;
    b = other.b;
    func = other.func;
    layer_idx = other.layer_idx;
}

layer_t::layer_t(int input_size, int output_size, const func_t& func)
{
    // cout << __func__ << endl;
    W = matrix_t(output_size, input_size, 'r');
    b = matrix_t(output_size, 1, 'r');
    this->func = func;
}

layer_t::layer_t(const matrix_t& W, const matrix_t& b, const func_t& func)
{
    // cout << __func__ << endl;
    this->W = W;
    this->b = b;
    this->func = func;
}


// getters
const matrix_t& layer_t::get_W(void) const { return W; }
const matrix_t& layer_t::get_b(void) const { return b; }
const matrix_t& layer_t::get_X(void) const { return X; }
const matrix_t& layer_t::get_Z(void) const { return Z; }
const matrix_t& layer_t::get_d(void) const { return d; }

// forward propagation
matrix_t layer_t::forward(const matrix_t& X)
{
    // cout << __func__ << endl;
    this->X = X;
    this->Z = this->W * this->X;// + this->b.broadcast(this->W.get_rows(), this->X.get_cols());
    switch (this->func)
    {
    case SIGMOID:
        return Sigmoid(this->Z);
    case TANH:
        return Tanh(this->Z);
    case RELU:
        return ReLU(this->Z);
    case LRELU:
        return Leaky_ReLU(this->Z);
    case ELU:
        return ExpLU(this->Z);
    case LINEAR:
        return Linear(this->Z);
    default:
        cout << "Error: unknown activation function" << endl;
        exit(1);
    }
}

// backward propagation
/* @param
 * delta_:  delta of next layer
 * W_:      weight of next layer
 */
matrix_t layer_t::backward(const matrix_t& delta_, const matrix_t& W_)
{
    // cout << __func__ << endl;
    matrix_t W = W_;
    matrix_t dt = delta_;
    matrix_t delta = trans(W) * dt;
    // Hadamard product
    for (int i = 0; i < delta.get_rows(); i++)
        for (int j = 0; j < delta.get_cols(); j++)
            delta[i][j] *= df(this->func, this->Z[i][j]);
    this->d = delta;
    return delta;
}

// backword propagation (last layer)
/* @param
 * output:  output of neural network
 * labels:  labels of training data
 */
matrix_t layer_t::backlast(const matrix_t& output, const matrix_t& labels)
{
    // cout << __func__ << endl;
    matrix_t label = labels;
    matrix_t delta = output - trans(label);
    // Hadamard product
    for (int i = 0; i < delta.get_rows(); i++)
        for (int j = 0; j < delta.get_cols(); j++)
            delta[i][j] *= df(this->func, this->Z[i][j]);
    this->d = delta;
    return delta;
}

// update weights
void layer_t::update(const real_t& learning_rate)
{
    // cout << __func__ << endl;
    matrix_t res = this->d * trans(X);
    this->W -= res * learning_rate;
    // this->b -= this->d.sum_cols() * learning_rate;
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
    // cout << __func__ << endl;
    this->W = layer.W;
    this->b = layer.b;
    this->func = layer.func;
    this->layer_idx = layer.layer_idx;
    return *this;
}

// neural network

// constructor
neural_network_t::neural_network_t(void)
{
    // cout << __func__ << endl;
    this->layers.clear();
}

neural_network_t::neural_network_t(const neural_network_t& other)
{
    // cout << __func__ << endl;
    this->layers = other.layers;
}

// getters
const vector<layer_t>& neural_network_t::get_layers(void) const { return this->layers; }
const matrix_t& neural_network_t::get_input(void)  const { return this->input;  }
const matrix_t& neural_network_t::get_output(void) const { return this->output; }

// setters (add layer)
void neural_network_t::add_layer(const layer_t& layer)
{
    // cout << __func__ << endl;
    this->layers.push_back(layer);
}

void neural_network_t::add_layer(const matrix_t& Weight, const matrix_t& bias, const func_t& func)
{
    // cout << __func__ << endl;
    layer_t layer(Weight, bias, func);
    layer.layer_idx = this->layers.size();
    this->layers.push_back(layer);
}

void neural_network_t::add_layer(const int32_t& input_size, const int32_t& output_size, const func_t& func)
{
    // cout << __func__ << endl;
    layer_t layer(input_size, output_size, func);
    layer.layer_idx = this->layers.size();
    this->layers.push_back(layer);
}


// forward propagation
matrix_t neural_network_t::forward(void)
{
    // cout << __func__ << endl;
    matrix_t X = this->input;
    for (auto& layer : this->layers)
    {
        X = layer.forward(X);
        // cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        // cout << "layer " << layer.layer_idx << endl;
        // cout << "got X = " << layer.get_X() << endl;
        // cout << "got W = " << layer.get_W() << endl;
        // cout << "out Z = " << layer.get_Z() << endl;
        // cout << "result= " << X << endl;
    }
    return this->output = X;
}

// backward propagation
void neural_network_t::backward(void)
{
    // cout << __func__ << endl;
    // last layer
    auto delta = this->layers.back().backlast(this->output, this->labels);
    this->layers.back().update(this->learning_rate);
    // hidden layers
    for (int i = this->layers.size() - 2; i >= 0; i--)
    {
        delta = this->layers[i].backward(delta, this->layers[i+1].get_W());
        // cout << "delta : " << delta << endl;
        this->layers[i].update(this->learning_rate);
    }
    return ;
}

// train
void neural_network_t::train(const matrix_t& input, const matrix_t& labels, const real_t& learning_rate)
{
    // cout << __func__ << endl;
    this->input = input;
    this->input = trans(this->input);
    this->labels = labels;
    this->learning_rate = learning_rate;
    this->forward();
    this->backward();
    return ;
}

// accuracy
// TODO

// predict
matrix_t neural_network_t::predict(const matrix_t& input)
{
    // cout << __func__ << endl;
    this->input = input;
    this->input = trans(this->input);
    this->forward();
    return this->output;
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
