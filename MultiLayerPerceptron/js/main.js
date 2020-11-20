let xor_data = [{
    inputs: [0, 0, 0, 0],
    outputs: [0]
},
{
    inputs: [0, 0, 0, 1],
    outputs: [1]
},
{
    inputs: [0, 0, 1, 0],
    outputs: [1]
},
{
    inputs: [0, 0, 1, 1],
    outputs: [0]
},
{
    inputs: [0, 1, 0, 0],
    outputs: [1]
},
{
    inputs: [0, 1, 0, 1],
    outputs: [0]
},
{
    inputs: [0, 1, 1, 0],
    outputs: [0]
},
{
    inputs: [0, 1, 1, 1],
    outputs: [1]
},
{
    inputs: [1, 0, 0, 0],
    outputs: [1]
},
{
    inputs: [1, 0, 0, 1],
    outputs: [0]
},
{
    inputs: [1, 0, 1, 0],
    outputs: [0]
},
{
    inputs: [1, 0, 1, 1],
    outputs: [1]
},
{
    inputs: [1, 1, 0, 0],
    outputs: [0]
},
{
    inputs: [1, 1, 0, 1],
    outputs: [1]
},
{
    inputs: [1, 1, 1, 0],
    outputs: [1]
},
{
    inputs: [1, 1, 1, 1],
    outputs: [0]
}];

let nn_xor = new NeuralNet(4, 16, 1);

nn_xor.setActivationFunction(sigmoid);

let data = {};
for (let i = 0; i < 1000000; i++) {
    data = xor_data[Math.floor(Math.random() * xor_data.length)];
    nn_xor.train(data.inputs, data.outputs);

}

let predicted_xor = [];
for (let i = 0; i < xor_data.length; i++) {
    predicted_xor.push(nn_xor.predict(xor_data[i].inputs));
}

console.table(predicted_xor);