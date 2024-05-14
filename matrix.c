#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 24
#define SPEED 50 // Velocidade de queda dos caracteres (em milissegundos)

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    char chars[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@#$%^&*()_-+=";
    int num_chars = sizeof(chars) - 1;
    int matrix[WIDTH] = {0}; // Matriz para rastrear as posições dos caracteres

    srand(time(NULL)); // Inicializa a semente para números aleatórios

    while (1) { // Loop infinito
        // Limpa a tela
        system("cls");

        // Atualiza a matriz com novos caracteres em posições aleatórias
        for (int i = 0; i < WIDTH; i++) {
            if (matrix[i] == 0 || rand() % 10 == 0) { // Chance de iniciar um novo caractere em uma coluna
                matrix[i] = HEIGHT - 1;
            }
        }

        // Desenha os caracteres na tela
        for (int x = 0; x < WIDTH; x++) {
            if (matrix[x] > 0) {
                // Posiciona o cursor e imprime o caractere
                gotoxy(x, matrix[x]);
                printf("%c", chars[rand() % num_chars]);

                // Move o caractere para baixo na próxima iteração
                matrix[x]--;
            }
        }

        // Aguarda um curto intervalo de tempo para controlar a velocidade da animação
        Sleep(SPEED);
    }

    return 0;
}
