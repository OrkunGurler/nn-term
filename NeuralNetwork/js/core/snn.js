class SNN extends LAYER {
    constructor() {
        super();
        this.setNodeSize();

    }
    setNodeSize(input_node, hidden_node, hidden_layer, output_node) {
        for (let i = 0; i < hidden_layer + 2; i++) {
            this.layers[i] = new LAYER();
        }
    }

    backpropagation() {

    }
}