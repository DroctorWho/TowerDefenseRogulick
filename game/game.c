#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <termios.h>

const int x = 27;
const int y = 82;

void create_map(char Map[x][y]);
void drawing_map(char Map[x][y]);


void main() {
    printf("\033[0d\033[2J");
    printf("Привет игрок! Нажми любую клавишу и мы начнем!\n\n");
    static struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    char var;
    var = getchar();
    char Map[x][y], newMap[x][y];
    create_map(Map);
    do {
        drawing_map(Map);
        var = getchar();
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
