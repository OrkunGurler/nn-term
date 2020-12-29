class NNET {
    constructor() {
        this.setActivation();
        this.setLearningRate();
    }
    setActivation(func = Sigmoid) { this.activation = func; }
    setLearningRate(learning_rate = 0.01) { this.learning_rate = learning_rate; }

    feedforward(input_data) {

        return output;
    }
}