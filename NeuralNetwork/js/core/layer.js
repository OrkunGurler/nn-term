const Matrix = require("../lib/mxlib");

class LAYER extends NNET {
    constructor(prev_node_count, node_count, random_weights = true, random_bias = true) {
        super();
        this.createLayer(prev_node_count, node_count, random_weights, random_bias);
    }

    createLayer(prev_node_count, node_count, random_weights = true, random_bias = true) {
        this.nodes = new Matrix(node_count, 1);
        this.weights = new Matrix(prev_node_count, node_count);
        if (random_weights) {
            this.weights.randomize();
        }
        if (random_bias) {
            this.bias = Math.random();
        } else {
            this.bias = random_bias;
        }
    }
}