#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5 // Розмір матриці (наприклад, 5x5)

int main() {
    int matrix[N][N];
    int choice;

    // Ініціалізація генератора випадкових чисел
    srand(time(0));

    do {
        // Генерація та виведення матриці
        printf("Згенерована матриця:\n");
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                matrix[i][j] = rand() % 201 - 100; // Генерація числа в діапазоні [-100, 100]
                printf("%4d ", matrix[i][j]);
            }
            printf("\n");
        }

        // Перевірка на симетричність відносно бокової діагоналі
        int isSymmetric = 1;
        for (int i = 0; i < N && isSymmetric; ++i) {
            for (int j = 0; j < N - i - 1; ++j) {
                if (matrix[i][j] != matrix[N - j - 1][N - i - 1]) {
                    isSymmetric = 0;
                    break;
                }
            }
        }

        // Виведення результату
        if (isSymmetric) {
            printf("\nМатриця є симетричною відносно бокової діагоналі.\n");
        } else {
            printf("\nМатриця не є симетричною відносно бокової діагоналі.\n");
        }

        // Консольне меню
        printf("\nБажаєте продовжити? (так, введіть 1 / ні, введіть 0): ");
        scanf("%d", &choice);
        printf("\n");

    } while (choice == 1);

    return 0;
}
