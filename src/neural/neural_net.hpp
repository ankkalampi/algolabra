#pragma once

#include "components/behavior_component.hpp"

#include <Eigen/Dense>

namespace neural

{

struct NeuralNet {
    // an animal's neural net consists of:
    // INPUT LAYER: 48 neurons that get input from cells extending 3 cells each
    // direction from self
    // HIDDEN LAYER: 20 neurons, just an arbitrary number
    // OUTPUT LAYER: 12 neurons, 8 for each possible direction, and 3 for each
    // possible action (move, eat, reproduce)

    Eigen::Vector<float, 48> input;

    Eigen::Matrix<float, 48, 20> hiddenWeights;
    Eigen::Vector<float, 20> hiddenbiases;

    Eigen::Vector<float, 20> hidden;

    Eigen::Matrix<float, 20, 12> outputWeights;
    Eigen::Vector<float, 12> outputbiases;

    Eigen::Vector<float, 12> output;

    components::Direction outputDirection;
    components::Action outputAction;

    NeuralNet();

    void propagateForward();
};
}  // namespace neural