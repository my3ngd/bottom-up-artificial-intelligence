#include "neural_network.h"

vector<vector<real_t>> in = {
    {1},
    {2},
    {3},
    {4},
    {5},
    {6},
    {7},
    {8},
    {9},
};

vector<vector<real_t>> out = {
    {1},
    {2},
    {3},
    {4},
    {5},
    {6},
    {7},
    {8},
    {9},
};

int main(int argc, char const *argv[])
{
    neural_network_t nn;
    nn.add_layer(1, 10, LRELU);
    nn.add_layer(10, 10, LRELU);
    nn.add_layer(10, 10, LRELU);
    nn.add_layer(10, 10, LRELU);
    nn.add_layer(10, 1, LINEAR);
    nn.print();

    for (int i = 0; i < 1000; i++)
    {
        cout << "step " << i << endl;
        // char stop;
        // cin >> stop;
        nn.train(in, out, real_t("0.1"));
        nn.forward();
        matrix_t res = nn.get_output();
        // cout << i << endl;
        cout << res << endl;
    }

    for (int i = 0; i < nn.get_layers().size(); i++)
    {
        cout << "----------------------------------------" << endl;
        cout << "layer " << i << endl;
        matrix_t W = nn.get_layers()[i].get_W();
        cout << W << endl;
        // matrix_t B = nn.get_layers()[i].get_b();
        // cout << B << endl;
    }

    matrix_t res = nn.predict(in);
    cout << res << endl;

    return 0;
}
