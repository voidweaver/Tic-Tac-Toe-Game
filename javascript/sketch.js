var game = null;
var input;
var reset;
var less;

function setup() {
    input = select("#in");
    input.input(init);

    reset = select("#restart");
    reset.mousePressed(init);

    let margins = 126;

    less = windowWidth > windowHeight ? windowHeight - margins : windowWidth - margins;
    createCanvas(less, less);

    init();
}


function draw() {
    background(255);
    smooth();

    if (game != null) {
        game.drawboard();
        if(mouseX < width && mouseY < height && mouseX > 0 && mouseY > 0)
            game.drawFaded(mouseX, mouseY);
        game.checkWin();
    }
}

function init() {
    let board_width = parseInt(input.value());
    
    if (board_width == NaN) {
        alert("Invalid input for board size");
        game = null;
        noCanvas();
    } else {
        game = new TicTacToe(board_width, width);
        createCanvas(less, less);
    }
}

function mousePressed() {
    if (game != null && mouseX < width && mouseY < height && mouseX > 0 && mouseY > 0) {
        game.setState(mouseX, mouseY);
    }
}