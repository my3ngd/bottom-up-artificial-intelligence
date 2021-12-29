# Project 1: Neural Network - Forword Propagation

## Moving Documents

Use the decimal.h and matrix.h created in Project 1. Therefore, copy and paste `matrix.*`, `decimal.*` files from Project 1 directory to files from Project 2 directory.

---

## Neural Network Description

Artificial neural networks are designed to perform well in situations such as classification and prediction. Artificial neural networks basically use matrix multiplication.

What the matrix represents is the connection between the two layers of the neural network. For example, suppose that a synapse connected by L+1 in layer L is represented by a matrix "W".

The synapse in which the i-th artificial neuron of layer L connects to the j-th artificial neuron of layer L+1 becomes the element of row i and column j of W.

Therefore, if the L layer of the neural network has a artificial neuron and the L+1 layer has b artificial neurons, the size of W will be a×b.

However, since the operation of the matrix is linear, artificial neural networks made of matrix product alone cannot solve problems other than linear classification no matter how many layers exist.

Being able to solve only linear problems can be seen as the same as when there is only one layer.

Therefore, we will use the "activate function" to change the problem nonlinearly. Mainly used are sigmoid, ReLU, tanh, etc.

In this project, you will implement forward propagation of artificial neural networks by referring to the figure below.

{figure}

---

## Activation Function

※ For matrix operations, refer to the previous project and the previous description.

As briefly introduced above, the active function plays a role in enabling artificial neural networks to solve nonlinear problems. We mainly use the following three functions as active functions.

+ Sigmoid function:

    $$
    f(x) = \frac{1}{1 + e^{-x}}
    $$

    The sigmoid function is an increasing function with a value of (0, 1). It can also be differentiated in all definitions. However, if x moves away from zero, the slope approaches zero, so if the number of layers increases too much, it tends to be disadvantageous to backpropagation.

+ ReLU function:

    $$
    f(x) = \max(0, x)
    $$

    ReLU is an abbreviation for Reflected Linear Unit. It is designed to solve the problem that the slope of the Sigmoid function approaches zero. The disadvantage is that when x becomes 0, differentiation becomes impossible.

+ Tanh function:

    $$
    f(x) = \tanh(x)
    $$

---

## Forward Propagation

Learning of artificial neural networks consists of two main steps. These are Forward and Backward, and this project implements the Forward step, which is the step to produce results.

The artificial neural network is expressed in the following form.

``` c++
class neural_network_t
{
private:
    vector<matrix_t> Weights;
    vector<matrix_t> Biases;
    vector<string> functions;
public:
    /* member functions */
};
```
One layer of artificial neural network multiplies the input value by weight, adds Bias, and then goes through activate function. At this time, complete the given code, noting that the value that enters the active function is `matrix_t`. That is, activate functions must return a matrix that has performed a scalar operation for all entries of the entered matrix.

---

## Thank You

