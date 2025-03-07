#include "neural_net.hpp"

#include "neural/neural_utils.hpp"

namespace neural
{
NeuralNet::NeuralNet() {}

void NeuralNet::propagateForward()
{
    // calculate hidden layer from input, and then output layer from hidden
    // layer. Functions chained for performance
    /*
    hidden = sigmoid(input * hiddenWeights + hiddenbiases);
    output = sigmoid(hidden * outputWeights + outputbiases);
    */
}
}  // namespace neural