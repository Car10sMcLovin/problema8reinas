/* 
Programador: Martinez Ramirez Carlos Moroni
Fecha Entrega: Septiembre 9, 2024
Archivo: ocho_reinas.c
Enlace: https://github.com/Car10sMcLovin/problema8reinas
*/

#include <stdio.h>
#include <stdbool.h>

#define N 8 

bool es_seguro(int tablero[N], int fila, int col) {
    for (int i = 0; i < fila; i++) {
        if (tablero[i] == col || 
            tablero[i] - i == col - fila || 
            tablero[i] + i == col + fila) {
            return false;
        }
    }
    return true;
}

bool resolver_8_reinas(int tablero[N], int fila) {
    if (fila == N) {
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
        return true; 
    }

    for (int col = 0; col < N; col++) {
        if (es_seguro(tablero, fila, col)) {
            tablero[fila] = col; 
            if (resolver_8_reinas(tablero, fila + 1)) 
                return true;
            tablero[fila] = -1;  
        }
    }

    return false; 
}

void resolver() {
    int tablero[N];  
    for (int i = 0; i < N; i++)
        tablero[i] = -1;  

    if (!resolver_8_reinas(tablero, 0)) {
        printf("No se encontró ninguna solución\n");
    }
}

int main() {
    resolver();
    return 0;
}
