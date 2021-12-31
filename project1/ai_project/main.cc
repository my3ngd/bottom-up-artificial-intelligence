#include "neural_network.h"

vector<vector<real_t>> a = {
    {1, },
    {4, },
    {7, },
};

int main(int argc, char const *argv[])
{
    matrix_t mat(a);
    cout << mat << endl;

    neural_network nn;
    nn.add_layer(3, 100, SIGMOID);
    nn.add_layer(100, 100, RELU);
    nn.add_layer(100, 100, ELU);
    nn.add_layer(100, 100, LRELU);
    nn.add_layer(100, 100, ELU);
    nn.add_layer(100, 100, RELU);
    nn.add_layer(100, 100, ELU);
    nn.add_layer(100, 100, LRELU);
    nn.add_layer(100, 100, ELU);
    nn.add_layer(100, 100, RELU);
    nn.add_layer(100, 100, ELU);
    nn.add_layer(100, 100, LRELU);
    nn.add_layer(100, 100, ELU);
    nn.add_layer(100, 100, RELU);
    nn.add_layer(100, 3, LINEAR);
    nn.describe();

    matrix_t res = nn.run(mat);
    cout << res << endl;
    return 0;
}
