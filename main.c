#include <stdio.h>

void printBoard(char board[3][3]) {
    for (int y = 0; y < 3; y++ ) {
        for (int x = 0; x < 3; x++ ) {
            printf("%c", board[y][x]);
        }
        printf("\n");
    }
    return;
};

void aiMove(char (*board)[3], char human, char comp) {
    if(0 == board[1][1]) {
        board[1][1] = comp;
        return;
    }
    int outcomesHuman[8] = {0};
    int outcomesComp[8] = {0};
    //horizontal
    for (int y = 0; y < 3; y++ ) {
        for (int x = 0; x < 3; x++ ) {
            if (board[y][x] == human) outcomesHuman[y]++;
            if (board[y][x] == comp) outcomesComp[y]++;
        }
    }

    //vertical
    for (int x = 0; x < 3; x++ ) {
        for (int y = 0; y < 3; y++ ) {
            if (board[y][x] == human) outcomesHuman[3+x]++;
            if (board[y][x] == comp) outcomesComp[3+x]++;
        }
    }

    //diagonal
    int j = 2;
    for (int i = 0; i < 3; i++) {

        //first diagonal
        if (board[i][i] == human) outcomesHuman[6]++;
        if (board[i][i] == comp) outcomesComp[6]++;

        //second diagonal
        if (board[j][i] == human) outcomesHuman[7]++;
        if (board[j][i] == comp) outcomesComp[7]++;
        j--;
    }

    for (int i = 0; i < 8; i++) {
        printf("%d ", outcomesHuman[i]);
    }
    printf("\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", outcomesComp[i]);
    }
    printf("\n");

};

int main(void) {

    //struct
    char board[3][3] = {0};
    char p1 = 'x', p2 = 'o';
    int x = 0, y = 0;
    printBoard(board);
    //game loop
    while(1) {
        scanf("%d %d", &y, &x);
        board[y][x] = p1;
        printBoard(&board);
        aiMove(&board, p1, p2);
        printBoard(&board);
    }


}


