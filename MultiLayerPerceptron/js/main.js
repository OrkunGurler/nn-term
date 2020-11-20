// XOR
let training_data = [{
    inputs: [0, 0],
    outputs: [0]
},
{
    inputs: [0, 1],
    outputs: [1]
},
{
    inputs: [1, 0],
    outputs: [1]
},
{
    inputs: [1, 1],
    outputs: [0]
}];

let nn = new NeuralNet(2, 4, 1);


nn.setActivationFunction(tanh);

let data = {};
for (let i = 0; i < 1000000; i++) {
    data = training_data[Math.floor(Math.random() * training_data.length)];
    nn.train(data.inputs, data.outputs);
}

let predicted = nn.predict([0, 0]);

console.log(predicted);