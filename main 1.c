#include <stdio.h>

int main() {
    int n, m, k, p;
    int choice; // змінна для зберігання вибору користувача
    int value;  // змінна для зберігання введеного значення

    do {
        // Введення розмірів матриці
        printf("Введіть кількість рядків матриці: ");
        while (scanf("%d", &n) != 1 || n <= 0) {
            printf("Некоректне введення. Спробуйте ще раз: ");
            while (getchar() != '\n'); // Очищення буфера вводу
        }

        printf("Введіть кількість стовпців матриці: ");
        while (scanf("%d", &m) != 1 || m <= 0) {
            printf("Некоректне введення. Спробуйте ще раз: ");
            while (getchar() != '\n'); // Очищення буфера вводу
        }

        int matrix[n][m]; // оголошення матриці

        // Введення елементів матриці з клавіатури
        printf("Введіть елементи матриці %dx%d:\n", n, m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                printf("Елемент [%d][%d]: ", i, j);
                while (scanf("%d", &value) != 1) {
                    printf("Некоректне введення. Спробуйте ще раз: ");
                    while (getchar() != '\n'); // Очищення буфера вводу
                }
                matrix[i][j] = value;
            }
        }

        // Введення номерів стовпців для обміну
        printf("Введіть номер першого стовпця (k): ");
        while (scanf("%d", &k) != 1 || k < 0 || k >= m) {
            printf("Некоректне введення. Спробуйте ще раз: ");
            while (getchar() != '\n'); // Очищення буфера вводу
        }

        printf("Введіть номер другого стовпця (p): ");
        while (scanf("%d", &p) != 1 || p < 0 || p >= m || p == k) {
            printf("Некоректне введення. Спробуйте ще раз: ");
            while (getchar() != '\n'); // Очищення буфера вводу
        }

        // Виведення початкової матриці
        printf("Початкова матриця:\n");
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }

        // Обмін стовпців k та p
        for (int i = 0; i < n; ++i) {
            int temp = matrix[i][k];
            matrix[i][k] = matrix[i][p];
            matrix[i][p] = temp;
        }

        // Виведення матриці після обміну стовпців
        printf("\nМатриця після обміну стовпців %d та %d:\n", k, p);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }

        // Консольне меню
        printf("\nБажаєте продовжити? (так, введіть 1 / ні, введіть 0): ");
        while (scanf("%d", &choice) != 1 || (choice != 0 && choice != 1)) {
            printf("Некоректне введення. Спробуйте ще раз: ");
            while (getchar() != '\n'); // Очищення буфера вводу
        }
        printf("\n");

    } while (choice == 1);

    return 0;
}
