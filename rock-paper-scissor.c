#include <stdio.h>
#include <stdbool.h>

#define ROCK 0
#define PAPER 1
#define SCISSOR 2
#define DRAW -1
#define PLAYER1WIN 0
#define PLAYER2WIN 1

/* Ingenious implementation of winning conditions using indexes as player1 move and stored values as player 2 move
  (taken from random source on internet)*/

//                     ROCK     PAPER SCISSOR
int winConditions[] = {SCISSOR, ROCK, PAPER};

int chooseMove(int number) {
    int move;
    printf("Player %d Move \n", number);
    printf("0 - Rock \n");
    printf("1 - Paper \n");
    printf("2 - Scissor \n");
    scanf("%d", &move);
    return move;
}

int gameRound(int firstPlayerMove, int secondPlayerMove) {
    if (firstPlayerMove == secondPlayerMove) {
        return DRAW;
    } else {
        if (winConditions[firstPlayerMove] == secondPlayerMove) {
            return PLAYER1WIN;
        } else {
            return PLAYER2WIN;
        }
    }
}

void announceWinner(int gameResult) {
    if (gameResult == DRAW) {
        printf("Draw !\n");
    } else if (gameResult == PLAYER1WIN) {
        printf("Player 1 win !\n");
    } else if (gameResult == PLAYER2WIN) {
        printf("Player 2 win !\n");
    } else {
        printf("Undefined gameResult value : %d \n", gameResult);
    }
}

void main() {
    bool finished = false;
    /*Modify the game
     Each player has 3 lives, when one of the players loses all life points, the game is over.
     Lose is -1 life point and draw does not affect life points.
     */
    while (!finished) {
        int firstPlayerMove = chooseMove(1);
        int secondPlayerMove = chooseMove(2);
        int gameResult = gameRound(firstPlayerMove, secondPlayerMove);
        announceWinner(gameResult);
        finished = true;
    }

}



