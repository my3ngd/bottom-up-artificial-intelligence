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
    {10},
    {11},
    {12},
    {13},
    {14},
    {15},
    {16},
    {17},
    {18},
    {19},
    {20},
};

vector<vector<real_t>> out = {
    {1},
    {4},
    {9},
    {16},
    {25},
    {36},
    {49},
    {64},
    {81},
    {100},
    {121},
    {144},
    {169},
    {196},
    {225},
    {256},
    {289},
    {324},
    {361},
    {400},
};

vector<vector<real_t>> I = {
    {1, 2, 3, 4, 4, 4, 3, 2, 1, 0, },
    {0, 2, 1, 4, 2, 4, 2, 2, 1, 6, },
    {1, 2, 3, 4, 5, 4, 3, 2, 1, 0, },
    {1, 3, 3, 4, 5, 4, 1, 2, 1, 1, },
    {0, 2, 2, 4, 1, 4, 3, 2, 1, 2, },
    {1, 2, 3, 4, 2, 4, 3, 2, 1, 3, },
    {0, 2, 2, 4, 5, 4, 1, 3, 1, 4, },
    {0, 1, 3, 4, 3, 4, 3, 2, 1, 1, },
    {1, 2, 3, 4, 1, 4, 3, 2, 1, 3, },
    {3, 0, 3, 4, 5, 2, 0, 2, 1, 2, },
};

vector<vector<real_t>> J = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
};

int main(int argc, char const *argv[])
{
    // I will train "x" to be "x^2"
    neural_network_t nn;
    nn.add_layer(1, 10, RELU);
    nn.add_layer(I, J, RELU);
    nn.add_layer(I, J, RELU);
    nn.add_layer(I, J, RELU);
    nn.add_layer(10, 1, LINEAR);
    nn.print();

    for (int i = 0; i < 1; i++)
    {
        // char stop;
        // cin >> stop;
        nn.train(in, out, real_t("0.001"));
        nn.forward();
        matrix_t res = nn.get_output();
        cout << i << endl;
        cout << res << endl;
    }

    for (int i = 0; i < nn.get_layers().size(); i++)
    {
        cout << "----------------------------------------" << endl;
        cout << "layer " << i << endl;
        matrix_t W = nn.get_layers()[i].get_W();
        cout << W << endl;
        matrix_t B = nn.get_layers()[i].get_b();
        cout << B << endl;
    }

    return 0;
}
