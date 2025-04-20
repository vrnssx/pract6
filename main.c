#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n;

    printf("Введіть кількість рядків (M): ");
    scanf("%d", &m);
    printf("Введіть кількість стовпців (N): ");
    scanf("%d", &n);

    if (m < 2) {
        printf("Матриця повинна мати щонайменше два рядки для виконання операції.\n");
        return 1; 
    }

    int **B = (int **)malloc(m * sizeof(int *));
    if (B == NULL) {
        printf("Помилка виділення пам'яті.\n");
        return 1;
    }
    for (int i = 0; i < m; i++) {
        B[i] = (int *)malloc(n * sizeof(int));
        if (B[i] == NULL) {
            printf("Помилка виділення пам'яті.\n");
            for (int j = 0; j < i; j++) {
                free(B[j]);
            }
            free(B);
            return 1; 
        }
    }

    printf("Введіть елементи матриці:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("B[%d][%d] = ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    int secondRowIndex = 1; 
    int lastRowIndex = m - 1;      

    for (int j = 0; j < n; j++) {
        B[secondRowIndex][j] = B[secondRowIndex][j] + B[lastRowIndex][j];
    }

   
    printf("\nОновлена матриця B:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", B[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < m; i++) {
        free(B[i]);
    }
    free(B);

    return 0; 
}