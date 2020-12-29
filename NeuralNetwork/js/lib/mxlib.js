class Matrix {
    constructor(rows, cols) {
        this.rows = rows;
        this.cols = cols;
        this.data = Array(this.rows).fill().map(() => Array(this.cols).fill(0));
    }

    randomize(min = 0, max = 1) {
        if (min >= max) {
            console.log("[ERR: randomize] Minimum must be lower than the maximum!");
            return undefined;
        }
        if (max <= 0) {
            [min, max] = [max, min];
        }
        return this
            .map(e => ((Math.random() * (max - min)) + min));
    }

    add(m) {
        if (m instanceof Matrix) {
            if (this.rows !== m.rows || this.cols !== m.cols) {
                console.log("[ERR: add] Columns and Rows must match!");
                return;
            }
            return this
                .map((e, i, j) => e + m.data[i][j]);
        } else {
            return this.map(e => e + m);
        }
    }

    static add(m1, m2) {
        if (m1.rows !== m2.rows || m1.cols !== m2.cols) {
            console.log("[ERR: static add] Columns and Rows must match!");
            return;
        }
        return new Matrix(m1.rows, m1.cols)
            .map((_, i, j) => m1.data[i][j] + m2.data[i][j]);
    }

    static sub(m1, m2) {
        if (m1.rows !== m2.rows || m1.cols !== m2.cols) {
            console.log("[ERR: static sub] Columns and Rows must match!");
            return;
        }
        return new Matrix(m1.rows, m1.cols)
            .map((_, i, j) => m1.data[i][j] - m2.data[i][j]);
    }

    mult(m) {
        if (m instanceof Matrix) {
            if (this.rows !== m.rows || this.cols !== m.cols) {
                console.log("[ERR: mult] Columns and Rows of Matrices must match.");
                return;
            }
            return this
                .map((e, i, j) => e * m.data[i][j]); // Hadamard Product
        } else {
            return this.map(e => e * m); // Scalar Product
        }
    }

    static dot(m1, m2) {
        if (!(m1 instanceof Matrix) || !(m2 instanceof Matrix)) {
            console.log("[ERR: static dot] Parameters must be a Matrix object!");
            return undefined;
        }
        if (m1.cols !== m2.rows) {
            console.log("[ERR: static dot] First matrix's column and second matrix's row sizes are not equal!");
            return undefined;
        }
        return new Matrix(m1.rows, m2.cols)
            .map((e, i, j) => {
                let sum = 0;
                for (let k = 0; k < m1.cols; k++) {
                    sum += m1.data[i][k] * m2.data[k][j];
                }
                return sum;
            });
    }
    static transpose(m) {
        return new Matrix(m.cols, m.rows)
            .map((_, i, j) => m.data[j][i]);
    }

    map(func) {
        let m;
        for (let i = 0; i < this.rows; i++) {
            for (let j = 0; j < this.cols; j++) {
                m = this.data[i][j];
                this.data[i][j] = func(m, i, j);
            }
        }
        return this;
    }

    static map(m, func) {
        return new Matrix(m.rows, m.cols)
            .map((e, i, j) => func(m.data[i][j], i, j));
    }

    copy() {
        let m = new Matrix(this.rows, this.cols);
        for (let i = 0; i < this.rows; i++) {
            for (let j = 0; j < this.cols; j++) {
                m.data[i][j] = this.data[i][j];
            }
        }
        return m;
    }

    print() {
        console.table(this.data);
        return this;
    }

    toArray() {
        let arr = [];
        for (let i = 0; i < this.rows; i++) {
            for (let j = 0; j < this.cols; j++) {
                arr.push(this.data[i][j]);
            }
        }
        return arr;
    }

    static fromArray(arr) {
        return new Matrix(arr.length, 1).map((e, i) => arr[i]);
    }

    serialize() {
        return JSON.stringify(this);
    }

    static deserialize(data) {
        if (typeof data == 'string') {
            data = JSON.parse(data);
        }
        let m = new Matrix(data.rows, data.cols);
        m.data = data.data;
        return m;
    }
}

if (typeof module !== 'undefined') {
    module.exports = Matrix;
}