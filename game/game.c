#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <termios.h>

const int x = 16;
const int y = 43;

struct information {
    int lvl;
    int maxenemy;
    int enemy;
    int atacktower;
    int hp;
    int hpenemy;
    int atackenemy;
};

void create_map(char Map[x][y]);
void drawing_map(char Map[x][y]);
void enemy_turn(char Map[x][y], struct information *p_game);


void main() {

    static struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    char var;

    char Map[x][y], newMap[x][y];
    struct information game;
    game.lvl = 1;
    game.maxenemy = 5;
    game.enemy = 0;
    game.atacktower = 10;
    game.hp = 9;
    game.hpenemy = 100;
    game.atackenemy = 1;
    struct information *p_game = &game;
    create_map(Map);

    printf("\033[0d\033[2JПривет игрок! Нажми любую клавишу и мы начнем!\n\n");
    var = getchar();

    do {
        drawing_map(Map);
        var = getchar();
        enemy_turn(Map, p_game);
    } while (var != 'q');
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

void create_map(char Map[x][y]) {
    char tmp;
    FILE *w;
    w = fopen("w.txt", "rt");
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            fscanf(w, "%c", &tmp);
            if (tmp == '\n') {
                j--;
            } else {
                Map[i][j] = tmp;
            }
        }
    }
}

void drawing_map(char Map[x][y]) {
    printf("\033[0d\033[2J");
    for (int i = 0; i < x; i++) {
        printf("\n");
        for (int j = 0; j < y; j++)
            printf("%c", Map[i][j]);
    }
    printf("\n");
}

void enemy_turn(char Map[x][y], struct information *p_game) {
    if (Map[2][35] == '*') {
        Map[1][35]--;
        Map[2][35] = ' ';
    }
    if (Map[3][34] == '*') {
        Map[2][35] = '*';
        Map[3][34] = ' ';
    }
    if (Map[4][34] == '*') {
        Map[3][34] = '*';
        Map[4][34] = ' ';
    }
    if (Map[5][34] == '*') {
        Map[4][34] = '*';
        Map[5][34] = ' ';
    }
    if (Map[6][33] == '*') {
        Map[5][34] = '*';
        Map[6][33] = ' ';
    }
    if (Map[7][32] == '*') {
        Map[6][33] = '*';
        Map[7][32] = ' ';
    }
    if (Map[8][31] == '*') {
        Map[7][32] = '*';
        Map[8][31] = ' ';
    }
    if (Map[9][30] == '*') {
        Map[8][31] = '*';
        Map[9][30] = ' ';
    }
    if (Map[10][29] == '*') {
        Map[9][30] = '*';
        Map[10][29] = ' ';
    }
    if (Map[11][28] == '*') {
        Map[10][29] = '*';
        Map[11][28] = ' ';
    }
    if (Map[11][27] == '*') {
        Map[11][28] = '*';
        Map[11][27] = ' ';
    }
    if (Map[11][26] == '*') {
        Map[11][27] = '*';
        Map[11][26] = ' ';
    }
    if (Map[12][25] == '*') {
        Map[11][26] = '*';
        Map[12][25] = ' ';
    }
    if (Map[12][24] == '*') {
        Map[12][25] = '*';
        Map[12][24] = ' ';
    }
    if (Map[12][23] == '*') {
        Map[12][24] = '*';
        Map[12][23] = ' ';
    }
    if (Map[12][22] == '*') {
        Map[12][23] = '*';
        Map[12][22] = ' ';
    }
    if (Map[12][21] == '*') {
        Map[12][22] = '*';
        Map[12][21] = ' ';
    }
    if (Map[12][20] == '*') {
        Map[12][21] = '*';
        Map[12][20] = ' ';
    }
    if (Map[12][19] == '*') {
        Map[12][20] = '*';
        Map[12][19] = ' ';
    }
    if (Map[12][18] == '*') {
        Map[12][19] = '*';
        Map[12][18] = ' ';
    }
    if (Map[12][18] == '*') {
        Map[12][19] = '*';
        Map[12][18] = ' ';
    }
    if (Map[12][17] == '*') {
        Map[12][18] = '*';
        Map[12][17] = ' ';
    }
    if (Map[11][16] == '*') {
        Map[12][17] = '*';
        Map[11][16] = ' ';
    }
    if (Map[11][15] == '*') {
        Map[11][16] = '*';
        Map[11][15] = ' ';
    }
    if (Map[11][14] == '*') {
        Map[11][15] = '*';
        Map[11][14] = ' ';
    }
    if (Map[10][13] == '*') {
        Map[11][14] = '*';
        Map[10][13] = ' ';
    }
    if (Map[9][12] == '*') {
        Map[10][13] = '*';
        Map[9][12] = ' ';
    }
    if (Map[8][11] == '*') {
        Map[9][12] = '*';
        Map[8][11] = ' ';
    }
    if (Map[7][10] == '*') {
        Map[8][11] = '*';
        Map[7][10] = ' ';
    }
    if (Map[6][9] == '*') {
        Map[7][10] = '*';
        Map[6][9] = ' ';
    }
    if (Map[5][8] == '*') {
        Map[6][9] = '*';
        Map[5][8] = ' ';
    }
    if (Map[4][8] == '*') {
        Map[5][8] = '*';
        Map[4][8] = ' ';
    }
    if (Map[3][8] == '*') {
        Map[4][8] = '*';
        Map[3][8] = ' ';
    }
    if (Map[2][7] == '*') {
        Map[3][8] = '*';
        Map[2][7] = ' ';
    }
    if (Map[1][7] == '*') {
        Map[2][7] = '*';
        Map[1][7] = ' ';
    }
    if ((*p_game).enemy < (*p_game).maxenemy) {
       Map[1][7] = '*';
       (*p_game).enemy++;
   }
}