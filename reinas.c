#include <stdio.h>
#include <stdbool.h>

#define N 8  // Tamaño del tablero (8x8)

// Función para verificar si es seguro colocar una reina en la posición (fila, col)
bool es_seguro(int tablero[N], int fila, int col) {
    for (int i = 0; i < fila; i++) {
        // Verificar si otra reina está en la misma columna o en las diagonales
        if (tablero[i] == col || 
            tablero[i] - i == col - fila || 
            tablero[i] + i == col + fila) {
            return false;
        }
    }
    return true;
}

// Función recursiva que resuelve el problema de las 8 reinas usando backtracking
bool resolver_8_reinas(int tablero[N], int fila) {
    if (fila == N) {
        // Si todas las reinas están colocadas, imprimir la solución
        printf("Solución encontrada:\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (tablero[i] == j)
                    printf(" Q ");
                else
                    printf(" . ");
            }
            printf("\n");
        }
        printf("\n");
        return true;  // Se ha encontrado una solución
    }

    // Intentar colocar la reina en cada columna de la fila actual
    for (int col = 0; col < N; col++) {
        if (es_seguro(tablero, fila, col)) {
            tablero[fila] = col;  // Colocar la reina
            if (resolver_8_reinas(tablero, fila + 1))  // Recursión
                return true;
            tablero[fila] = -1;  // Retroceder (Backtracking)
        }
    }

    return false;  // Si no es posible colocar la reina en esta fila
}

void resolver() {
    int tablero[N];  // Arreglo donde guardamos la columna de la reina en cada fila
    for (int i = 0; i < N; i++)
        tablero[i] = -1;  // Inicializar el tablero sin reinas

    if (!resolver_8_reinas(tablero, 0)) {
        printf("No se encontró ninguna solución\n");
    }
}

// Función principal
int main() {
    resolver();
    return 0;
}
