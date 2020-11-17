class Activation {
    constructor(func, func_d) {
        this.func = func;
        this.func_d = func_d;
    }
}

let sigmoid = new Activation(
    x => 1 / (1 + Math.exp(-x)),
    y => y * (1 - y)
);