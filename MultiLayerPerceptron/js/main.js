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
nn_xor.setLearningRate(0.01);

let data = {};
for (let i = 0; i < 1000000; i++) {
    data = xor_data[Math.floor(Math.random() * xor_data.length)];
    nn_xor.train(data.inputs, data.outputs);
}

let predicted_xor = [];
for (let i = 0; i < xor_data.length; i++) {
    predicted_xor.push(nn_xor.predict(xor_data[i].inputs));
}

function createTable(rows, cols, gdata, predicted) {
    let tbl = document.getElementById('tbl');
    tbl.style.width = '100%';
    tbl.setAttribute('border', '1');
    for (let i = 0; i < rows + 1; i++) {
        let tr = document.createElement('tr');
        for (let j = 0; j < cols; j++) {
            let td = document.createElement('td');
            tr.appendChild(td);
        }
        tbl.appendChild(tr);
    }
    tbl.rows[0].cells[0].innerHTML = "Input Data";
    tbl.rows[0].cells[1].innerHTML = "Target Output";
    tbl.rows[0].cells[2].innerHTML = "Predicted Output";
    for (let i = 1; i < rows + 1; i++) {
        tbl.rows[i].cells[0].innerHTML = gdata[i - 1].inputs;
        tbl.rows[i].cells[1].innerHTML = gdata[i - 1].outputs;
        tbl.rows[i].cells[2].innerHTML = Math.round(predicted[i - 1]);
    }
}
createTable(xor_data.length, 3, xor_data, predicted_xor);

function userInput() {
    let input = [];
    input.push(document.getElementById('pT1').value);
    input.push(document.getElementById('pT2').value);
    input.push(document.getElementById('pT3').value);
    input.push(document.getElementById('pT4').value);
    let predicted_v = Math.round(nn_xor.predict(input));
    document.getElementById('predicted').value = predicted_v;
    document.getElementById('predicted').style.display = 'block';
}