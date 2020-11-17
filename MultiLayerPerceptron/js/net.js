class Net {
    constructor(input, hidden, output) {
        this.input = input;
        this.hidden = hidden;
        this.output = output;

        this.weights_ih = new Matrix(this.hidden, this.input);
        this.weights_ih.randomize(-1, 1);
        this.weights_ho = new Matrix(this.output, this.hidden);
        this.weights_ho.randomize(-1, 1);

        this.bias_h = new Matrix(this.hidden, 1);
        this.bias_o = new Matrix(this.output, 1);
    }

    feedforward(arr) {
        let input = Matrix.fromArray(arr);
        let hidden = Matrix.scalar(this.weights_ih, input);
        hidden.add(this.bias_h);
        return predict;
    }

    backpropagation() { }
}