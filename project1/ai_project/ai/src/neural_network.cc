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
    // TODO: implement
    return mat;
}


// neural network class implementation

// constructors
neural_network::neural_network(void)
{
    this->Weights = vector<matrix_t>();
    this->Biases = vector<matrix_t>();
    this->functions = vector<string>();
}


// add layers
void neural_network::add_layer(const int32_t& input_size,  const int32_t& output_size,  ActivationFunction function) { return this->add_layer((uint64_t)input_size, (uint64_t)output_size, function); }

void neural_network::add_layer(const uint32_t& input_size, const uint32_t& output_size, ActivationFunction function) { return this->add_layer((uint64_t)input_size, (uint64_t)output_size, function); }

void neural_network::add_layer(const int64_t& input_size,  const int64_t& output_size,  ActivationFunction function) { return this->add_layer((uint64_t)input_size, (uint64_t)output_size, function); }

void neural_network::add_layer(const uint64_t& input_size, const uint64_t& output_size, ActivationFunction function)
{
    // first layes
    if (this->Weights.size() == 0)
    {
        this->Weights.push_back(matrix_t(input_size, output_size));
        this->Biases.push_back(matrix_t(output_size, 1));
        switch (function)
        {
            case SIGMOID:
                this->functions.push_back("Sigmoid");
                break;
            case TANH:
                this->functions.push_back("Tanh");
                break;
            case RELU:
                this->functions.push_back("ReLU");
                break;
            case LRELU:
                this->functions.push_back("Leaky_ReLU");
                break;
            case ELU:
                this->functions.push_back("ExpLU");
                break;
        }
        return ;
    }
    // output dimension must be defined by user
    if (output_size == 0)
    {
        cout << "Error: output dimension must be defined by user, but given 0" << endl;
        throw std::runtime_error("output_size must be greater than 0");
    }
    if (input_size > 0 && input_size != this->Biases.back().get_rows())
    {
        cout << "Error: input size must be equal with last layer (which is " << this->Biases.back().get_rows() << "), got " << input_size << endl;
        throw std::runtime_error("input_size must be equal to the previous layer's output_size");
    }
    // automatically fix dimension
    if (input_size < 1)
    {
        uint64_t dim = this->Weights.back().get_cols();
        this->Weights.push_back(matrix_t(dim, output_size));
        this->Biases.push_back(matrix_t(output_size, (uint64_t)1));
    }
    else
    {
        // it is slow for huge matrix
        this->Weights.push_back(matrix_t(input_size, output_size));
        this->Biases.push_back(matrix_t(output_size, (uint64_t)1));
    }
    switch (function)
    {
        case SIGMOID:
            this->functions.push_back("Sigmoid");
            break;
        case TANH:
            this->functions.push_back("Tanh");
            break;
        case RELU:
            this->functions.push_back("ReLU");
            break;
        case LRELU:
            this->functions.push_back("Leaky_ReLU");
            break;
        case ELU:
            this->functions.push_back("ExpLU");
            break;
        default:
            this->functions.push_back("Linear");
            break;
    }
    return ;
}


// describe the neural network
void neural_network::describe(void)
{
    cout << "==========================================================" << endl;
    cout << "| Neural network:" << endl;
    cout << "| - #layers: " << this->Weights.size() << endl;
    cout << "|---------------------------------------------------------" << endl;
    for (uint64_t i = 0; i < this->Weights.size(); i++)
    {
        cout << "| layer: " << i+1 << endl;
        cout << "|\tinput  dimension: " << this->Weights[i].get_rows() << endl;
        cout << "|\toutput dimension: " << this->Weights[i].get_cols() << endl;
        cout << "|\tactivation function: " << this->functions[i] << endl;
        cout << "|---------------------------------------------------------" << endl;
    }
    cout << "| Summary:" << endl;
    cout << "| input dimension: " << this->Weights[0].get_rows() << endl;
    cout << "| output dimension: " << this->Weights.back().get_cols() << endl;
    cout << "==========================================================" << endl;
    return ;
}


// run the neural network
matrix_t neural_network::run(matrix_t input)
{
    // check input dimension
    if (input.get_rows() != this->Weights.front().get_rows())
    {
        cout << "Error: input dimension does not match" << endl;
        cout << "input of nn:   (" << this->Weights.front().get_rows() << " " << this->Weights.front().get_cols() << ")" << endl;
        cout << "input of user: (" << input.get_rows() << " " << input.get_cols() << ")" << endl;
        throw std::runtime_error("input dimension does not match");
    }

    // run the network
    matrix_t Z = input;
    for (uint64_t i = 0; i < this->Weights.size(); i++)
    {
        // Z = WX + b
        Z = trans(this->Weights[i]) * Z + this->Biases[i];
        // Z := func(Z)
        if      (this->functions[i] == "Sigmoid")
            Z = Sigmoid(Z);
        else if (this->functions[i] == "Tanh")
            Z = Tanh(Z);
        else if (this->functions[i] == "ReLU")
            Z = ReLU(Z);
        else if (this->functions[i] == "Leaky_ReLU")
            Z = Leaky_ReLU(Z, 0.01);
        else if (this->functions[i] == "ExpLU")
            Z = ExpLU(Z);
    }
    return Z;
}

