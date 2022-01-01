# Project 2: Neural Network - Backword Propagation

## Backword Propagation and Learning

In Project 2, you will implement reverse propagation of neural networks.

There are two main ways to learn neural networks. The first is numerical differentiation, which is simple to implement but has the disadvantage of slow calculation. The second is backpropagation, which has the advantage of being relatively fast in calculating, although its implementation is complicated.

In this project, you will use backpropagation, a relatively fast method, to learn neural networks.

---

## Learning Algorithm

Learning of artificial neural networks proceeds through the following process.

1. Getting the learning data.
2. Calculate the gradient of each weight.
3. Update the weights slightly.
4. Repeat steps 2-3 until the error is small enough.

Getting the learning data is very easy. Just write some line of code to get the training data.

So, let's start with the second step.

---

## Gradient Calculation

Loss refers to the relationship between the actual value of the learning data and the predicted value. People mainly use MSE (mean square error).

Let $L$ be the loss function. $L = \frac{1}{2} \Sigma{(y_i - y)^2}$ where $y_i$ is the actual value of the learning data and $y$ is the predicted value.

L is the scalar value. However, we need to figure out how Loss changes with the change in the weight matrix. Therefore, we can see that the slope is the differentiation of Loss into a matrix. (The scalar can be differentiated by a matrix, and the result has the same dimension as the differential matrix.)



---

## Thank You

