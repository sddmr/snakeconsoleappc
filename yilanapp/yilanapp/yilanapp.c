#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

int width = 20;
int height = 20;
int gameOver;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
enum Direction dir;

void setup() {
    gameOver = 0;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
    nTail = 0;
}

void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y + 1, x + 1);  
}

void draw() {
    gotoxy(0, 0);  
    for (int i = 0; i < width + 2; i++)  // Üst sınır
        printf("-");
    printf("\n");

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                printf("|");  // Sol sınır
            if (i == y && j == x)
                printf("O");  // Yılanın başı
            else if (i == fruitY && j == fruitX)
                printf("F");  // Yem
            else {
                int print = 0;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        printf("o");  // Yılanın gövdesi
                        print = 1;
                    }
                }
                if (!print)
                    printf(" ");
            }

            if (j == width - 1)
                printf("|");  // Sağ sınır
        }
        printf("\n");
    }

    for (int i = 0; i < width + 2; i++)  // Alt sınır
        printf("-");
    printf("\n");
    printf("Score: %d\n", score);
}

void input() {
    if (_kbhit()) {  
        switch (_getch()) {
        case 'a':
            if (dir != RIGHT) dir = LEFT;
            break;
        case 'd':
            if (dir != LEFT) dir = RIGHT;
            break;
        case 'w':
            if (dir != DOWN) dir = UP;
            break;
        case 's':
            if (dir != UP) dir = DOWN;
            break;
        case 'x':
            gameOver = 1;
            break;
        }
    }
}

void logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    if (x < 0 || x >= width || y < 0 || y >= height)
        gameOver = 1;

    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = 1;
    }

    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}

int main() {
    srand(time(0));  
    setup();
    
    printf("\033[?25l");
    while (!gameOver) {
        draw();
        input();
        logic();
        Sleep(100);  
    }
  
    printf("\033[?25h");
    printf("Game Over! Your Score: %d\n", score);
    return 0;
}
