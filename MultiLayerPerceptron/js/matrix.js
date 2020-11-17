class Matrix {
    constructor(rows, cols) {
        this.rows = rows;
        this.cols = cols;
        this.data = [];

        for (let i = 0; i < this.rows; i++) {
            this.data[i] = [];
            for (let j = 0; j < this.cols; j++) {
                this.data[i][j] = 0;
            }
        }
    }

    randomize(a, b) {
        if (a >= b) {
            console.log("[ERR: randomize] First value must be lower than the second one!");
            return undefined;
        }
        if (b <= 0) {
            [a, b] = [b, a];
        }
        return this.map(e => ((Math.random() * (b - a)) + a));
    }

    static transpose(matrix) {
        return new Matrix(matrix.cols, matrix.rows).map((_, i, j) => matrix.data[j][i]);
    }

    add(v) {
        if (v instanceof Matrix) {
            if (this.rows !== v.rows || this.cols !== v.cols) {
                console.log("[ERR: add] Columns and Rows must match!");
                return;
            }
            return this.map((e, i, j) => e + v.data[i][j]);
        } else {
            return this.map(e => e + v);
        }
    }

    map(func) {
        let val;
        for (let i = 0; i < this.rows; i++) {
            for (let j = 0; j < this.cols; j++) {
                val = this.data[i][j];
                this.data[i][j] = func(val, i, j);
            }
        }
        return this;
    }

    static scalar(m1, m2) {
        if (!(m1 instanceof Matrix) || !(m2 instanceof Matrix)) {
            console.log("[ERR: scalar] Parameters must be a Matrix object!");
            return undefined;
        }
        if (m1.cols !== m2.rows) {
            console.log("[ERR: scalar] First matrix's column and second matrix's row sizes are not equal!");
            return undefined;
        }
        return new Matrix(m1.rows, m2.cols).map((e, i, j) => {
            let sum = 0;
            for (let k = 0; k < a.cols; k++) {
                sum += m1.data[i][k] * m2.data[k][j];
            }
            return sum;
        });
    }

    print() {
        console.table(this.data);
        return this;
    }
}