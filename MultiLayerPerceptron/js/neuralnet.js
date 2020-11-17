class Activations {
    constructor(func, func_d) {
        this.func = func;
        this.func_d = func_d;
    }
}

let sigmoid = new Activations(
    x => 1 / (1 + Math.exp(-x)),
    y => y * (1 - y)
);

let tanh = new Activations(
    x => Math.tanh(x),
    y => 1 - (y * y)
);


class NeuralNet {
    constructor(input, hidden, output) {
        if (input instanceof NeuralNet) {
            let a = input;
            this.input = a.input;
            this.hidden = a.hidden;
            this.output = a.output;

            this.weights_ih = a.weights_ih.copy();
            this.weights_ho = a.weights_ho.copy();

            this.bias_h = a.bias_h.copy();
            this.bias_o = a.bias_o.copy();
        } else {
            this.input = input;
            this.hidden = hidden;
            this.output = output;

            this.weights_ih = new Matrix(this.hidden, this.input);
            this.weights_ih.randomize(-1, 1);
            this.weights_ho = new Matrix(this.output, this.hidden);
            this.weights_ho.randomize(-1, 1);

            this.bias_h = new Matrix(this.hidden, 1);
            this.bias_h.randomize(-1, 1);
            this.bias_o = new Matrix(this.output, 1);
            this.bias_o.randomize(-1, 1);
        }
        this.setLearningRate();
        this.setActivationFunction();
    }
    setLearningRate(learning_rate = 0.1) {
        this.learning_rate = learning_rate;
    }

    setActivationFunction(func = sigmoid) {
        this.activation_function = func;
    }
}