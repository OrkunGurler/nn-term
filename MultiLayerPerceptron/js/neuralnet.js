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
            let n = input;
            this.input = n.input;
            this.hidden = n.hidden;
            this.output = n.output;

            this.weights_ih = n.weights_ih.copy();
            this.weights_ho = n.weights_ho.copy();

            this.bias_h = n.bias_h.copy();
            this.bias_o = n.bias_o.copy();
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

    setActivationFunction(func) {
        this.activation_function = func;
    }

    predict(input_array) {
        let inputs = Matrix.fromArray(input_array);

        let hidden = Matrix.scalar(this.weights_ih, inputs);
        hidden.add(this.bias_h);
        hidden.map(this.activation_function.func);

        let output = Matrix.scalar(this.weights_ho, hidden);
        output.add(this.bias_o);
        output.map(this.activation_function.func);

        return output.toArray();
    }

    train(input_array, target_array) {
        let inputs = Matrix.fromArray(input_array);
        let hidden = Matrix.scalar(this.weights_ih, inputs);
        hidden.add(this.bias_h);
        hidden.map(this.activation_function.func);

        let outputs = Matrix.scalar(this.weights_ho, hidden);
        outputs.add(this.bias_o);
        outputs.map(this.activation_function.func);

        let targets = Matrix.fromArray(target_array);
        let output_errors = Matrix.sub(targets, outputs);
        let gradients = Matrix.map(outputs, this.activation_function.dfunc);
        gradients.multiply(output_errors);
        gradients.multiply(this.learning_rate);

        let hidden_T = Matrix.transpose(hidden);
        let weight_ho_deltas = Matrix.scalar(gradients, hidden_T);
        this.weights_ho.add(weight_ho_deltas);
        this.bias_o.add(gradients);

        let who_t = Matrix.transpose(this.weights_ho);
        let hidden_errors = Matrix.scalar(who_t, output_errors);
        let hidden_gradient = Matrix.map(hidden, this.activation_function.dfunc);
        hidden_gradient.multiply(hidden_errors);
        hidden_gradient.multiply(this.learning_rate);

        let inputs_T = Matrix.transpose(inputs);

        let weight_ih_deltas = Matrix.scalar(hidden_gradient, inputs_T);
        this.weights_ih.add(weight_ih_deltas);

        this.bias_h.add(hidden_gradient);

        outputs.print();
        targets.print();
        error.print();
    }

    serialize() {
        return JSON.stringify(this);
    }

    static deserialize(data) {
        if (typeof data == 'string') {
            data = JSON.parse(data);
        }

        let nn = new NeuralNet(data.input, data.hidden, data.output);

        nn.weights_ih = Matrix.deserialize(data.weights_ih);
        nn.weights_ho = Matrix.deserialize(data.weights_ho);

        nn.bias_h = Matrix.deserialize(data.bias_h);
        nn.bias_o = Matrix.deserialize(data.bias_o);

        nn.learning_rate = data.learning_rate;
        return nn;
    }

    copy() {
        return new NeuralNet(this);
    }

    mutate(func) {
        this.weights_ih.map(func);
        this.weights_ho.map(func);

        this.bias_h.map(func);
        this.bias_o.map(func);
    }
}