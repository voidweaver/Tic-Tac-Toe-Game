class TicTacToe {

    constructor(board_size, screen_width) {
        this.board_width = board_size;
        this.board_area = board_size * board_size;
        this.end = false;
        this.winner = null; //1: x 2: o
        this.currentrow;
        this.currentcolumn;
        this.tile_width = screen_width / this.board_width;
        this.round = 0;
        this.win_type = 0; //1:hori 2:vert 3:diag\ 4:diag/
        this.win_at = null;

        this.tile_raw = []; // Dynamic Allocation for the board
        for (let row = 0; row < this.board_width; row++)
            this.tile_raw[row] = [];

        for (let row = 0; row < this.board_width; row++)
            for (let column = 0; column < this.board_width; column++) // set all tiles on the board with numbers
                this.tile_raw[row][column] = null;
    }

    setState(mX, mY) {
        if (this.winner == null) {
            var x = null;
            var y = null;
            for (let i = 1; i <= this.board_width; i++) {
                if (x == null && mX < this.tile_width * i) {
                    x = i - 1;
                }
                if (y == null && mY < this.tile_width * i) {
                    y = i - 1;
                }
            }
            if (this.tile_raw[x][y] == null) {
                this.tile_raw[x][y] = this.round % 2 + 1;
                this.round++;
            }
        }
    }

    drawboard() {
        for (let i = 1; i < this.board_width; i++) {
            strokeWeight(2);
            stroke(0);
            noFill();
            line(this.tile_width * i, 0, this.tile_width * i, this.tile_width * this.board_width);
            line(0, this.tile_width * i, this.tile_width * this.board_width, this.tile_width * i);
        }
        for (let i = 0; i < this.board_width; i++) {
            for (let j = 0; j < this.board_width; j++) {
                if (this.tile_raw[i][j] == 1) {
                    strokeWeight(2);
                    stroke(255, 0, 0);
                    this.drawCross(this.tile_width * i + this.tile_width / 2, this.tile_width * j + this.tile_width / 2, this.tile_width / 4);
                } else if (this.tile_raw[i][j] == 2) {
                    strokeWeight(2);
                    stroke(0, 0, 255);
                    this.drawO(this.tile_width * i + this.tile_width / 2, this.tile_width * j + this.tile_width / 2, this.tile_width / 4);
                }
            }
        }
        if (this.winner != null) {
            this.drawWinLine();
        }
    }

    drawCross(midX, midY, radius) {
        line(midX - radius, midY - radius, midX + radius, midY + radius);
        line(midX + radius, midY - radius, midX - radius, midY + radius);
    }

    drawO(x, y, radius) {
        //ellipse(x - radius, y - radius, radius * 2, radius * 2);
        ellipse(x, y, radius * 2, radius * 2);
    }

    drawWinLine() {
        var m = 6;
        strokeWeight(3);
        if (this.winner == 2) stroke(0, 0, 255);
        else stroke(255, 0, 0);
        switch (this.win_type) {
            case 2: //horizontal
                line(this.tile_width / m, this.win_at * this.tile_width + this.tile_width / 2, this.board_width * this.tile_width - this.tile_width / m, this.win_at * this.tile_width + this.tile_width / 2);
                break;
            case 1: //vertical
                line(this.win_at * this.tile_width + this.tile_width / 2, this.tile_width / m, this.win_at * this.tile_width + this.tile_width / 2, this.board_width * this.tile_width - this.tile_width / m);
                break;
            case 3: //diagonal \
                line(this.tile_width / m, this.tile_width / m, this.board_width * this.tile_width - this.tile_width / m, this.board_width * this.tile_width - this.tile_width / m);
                break;
            case 4: //diagonal /
                line(this.tile_width / m, this.board_width * this.tile_width - this.tile_width / m, this.board_width * this.tile_width - this.tile_width / m, this.tile_width / m);
                break;
        }
    }

    checkWin() {
        var havewin = false;
        var th, tv, tdl = 0,
            tdr = 0;
        for (let i = 0; i < this.board_width && !havewin; i++) { // For player 1
            th = 0;
            tv = 0;
            for (let j = 0; j < this.board_width && !havewin; j++) {

                if (this.tile_raw[i][j] != 1) { // Horizontal
                    th = 0;
                } else if (th == this.board_width - 1) {
                    havewin = true;
                    this.win_type = 1;
                    this.win_at = i;
                    this.winner = 1;
                    this.end = true;
                } else th++;
                if (this.tile_raw[j][i] != 1) { // Vertical
                    tv = 0;
                } else if (tv == this.board_width - 1) {
                    havewin = true;
                    this.win_type = 2;
                    this.win_at = i;
                    this.winner = 1;
                    this.end = true;
                } else tv++;
            }
            if (this.tile_raw[i][i] != 1) { // Diagonal
                tdl = 0;
            } else if (tdl == this.board_width - 1) {
                havewin = true;
                this.win_type = 3;
                this.win_at = i;
                this.winner = 1;
                this.end = true;
            } else tdl++;
            if (this.tile_raw[i][this.board_width - i - 1] != 1) { // Diagonal
                tdr = 0;
            } else if (tdr == this.board_width - 1) {
                havewin = true;
                this.win_type = 4;
                this.win_at = i;
                this.winner = 1;
                this.end = true;
            } else tdr++;
        }

        th = 0;
        tv = 0;
        tdl = 0;
        tdr = 0;
        for (let i = 0; i < this.board_width && !havewin; i++) { // For player 2
            th = 0;
            tv = 0;
            for (let j = 0; j < this.board_width && !havewin; j++) {

                if (this.tile_raw[i][j] != 2) { // Horizontal
                    th = 0;
                } else if (th == this.board_width - 1) {
                    havewin = true;
                    this.win_type = 1;
                    this.win_at = i;
                    this.winner = 2;
                    this.end = true;
                } else th++;
                if (this.tile_raw[j][i] != 2) { // Vertical
                    tv = 0;
                } else if (tv == this.board_width - 1) {
                    havewin = true;
                    this.win_type = 2;
                    this.win_at = i;
                    this.winner = 2;
                    this.end = true;
                } else tv++;
            }
            if (this.tile_raw[i][i] != 2) { // Diagonal
                tdl = 0;
            } else if (tdl == this.board_width - 1) {
                havewin = true;
                this.win_type = 3;
                this.win_at = i;
                this.winner = 2;
                this.end = true;
            } else tdl++;
            if (this.tile_raw[i][this.board_width - i - 1] != 2) { // Diagonal
                tdr = 0;
            } else if (tdr == this.board_width - 1) {
                havewin = true;
                this.win_type = 4;
                this.win_at = i;
                this.winner = 2;
                this.end = true;
            } else tdr++;
        }
        if (round == this.board_area + 1)
            this.end = true;
    }
}