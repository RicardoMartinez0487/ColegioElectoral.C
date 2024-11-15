/*-------------------------------------------------------------------------------------
|  Autor: Ricardo Jesus Martinez Brito    Matricula:2-14-8591                          |
|  Fecha: 14/11/24                      Versi�:                                        |
|--------------------------------------------------------------------------------------|
|  Descripci�n del Programa: esta progrmado para sacar los diferentes resultados de una|
|   Eleciones municipales para saber cuales fuero los resultados de los datos de la     |
|   contienda electoral                                                                 |
| -------------------------------------------------------------------------------------*/

#include <stdio.h>
//Definen constantes simbólicas para el número de distritos (5) y el número de candidatos (4). 
//Esto hace que el código sea más fácil de leer y modificar.
#define Distritos 5
#define Candidatos 4
// se desclaran la variable para poder llamarla con el main 
void imprimirTabla(int votos[Distritos][Candidatos]);
void calcularTotales(int votos[Distritos][Candidatos], int totalVotos[Candidatos]);
void imprimirResultados(int totalVotos[Candidatos], int totalGeneral);
int obtenerMasVotado(int totalVotos[Candidatos]);
void segundaRonda(int totalVotos[Candidatos], int totalGeneral);

int main() {
    // esta funcion se utilizara para almacenar cadenas de caracteres,
    //matricez, arreglos entre otros 

    int votos[Distritos][Candidatos] = {
        {194, 48, 206, 45},
        {180, 20, 320, 16},
        {221, 20, 140, 54},
        {432, 50, 821, 14},
        {820, 61, 946, 18}
    };
    
    int totalVotos[Candidatos] = {0};
    
    imprimirTabla(votos);
    calcularTotales(votos, totalVotos);
    
    int totalGeneral = 0;
    for (int i = 0; i < Candidatos; i++) {
        totalGeneral += totalVotos[i];
    }
    
    imprimirResultados(totalVotos, totalGeneral);
    
    int masVotado = obtenerMasVotado(totalVotos);
    if ((totalVotos[masVotado] * 100) / totalGeneral > 50) {
        printf("El ganador es el candidato %c con más del 50%% de los votos.\n", 'A' + masVotado);
    } else {
        segundaRonda(totalVotos, totalGeneral);
    }

    return 0;
}
//esta funcion imprimira los mostrados los votos de los candidatos en las tablas de los distritos
void imprimirTabla(int votos[Distritos][Candidatos]) {
    printf("Distrito\tCandidato A\tCandidato B\tCandidato C\tCandidato D\n");
    for (int i = 0; i < Distritos; i++) {
        printf("%d\t\t", i + 1);
        for (int j = 0; j < Candidatos; j++) {
            printf("%d\t\t", votos[i][j]);
        }
        printf("\n");
    }
}
// aqui se sumaran los votos de los candidatos almacenados
void calcularTotales(int votos[Distritos][Candidatos], int totalVotos[Candidatos]) {
    for (int i = 0; i < Distritos; i++) {
        for (int j = 0; j < Candidatos; j++) {
            totalVotos[j] += votos[i][j];
        }
    }
}
//Imprime la tabla de votos, mostrando los distritos y los votos de cada candidato.
void imprimirResultados(int totalVotos[Candidatos], int totalGeneral) {
    printf("\nResultados:\n");
    for (int i = 0; i < Candidatos; i++) {
        printf("Candidato %c: %d votos (%.2f%%)\n", 'A' + i, totalVotos[i], (totalVotos[i] * 100.0) / totalGeneral);
    }
}
// aqui se estara imprimiendo el porcentaje general de los votos
int obtenerMasVotado(int totalVotos[Candidatos]) {
    int max = 0;
    for (int i = 1; i < Candidatos; i++) {
        if (totalVotos[i] > totalVotos[max]) {
            max = i;
        }
    }
    return max;
}
//aqui se imprimira los cadidatos mas votados con un 50% los que pasan a la segunda vuelta
void segundaRonda(int totalVotos[Candidatos], int totalGeneral) {
    int max1 = -1, max2 = -1;
    for (int i = 0; i < Candidatos; i++) {
        if (max1 == -1 || totalVotos[i] > totalVotos[max1]) {
            max2 = max1;
            max1 = i;
        } else if (max2 == -1 || totalVotos[i] > totalVotos[max2]) {
            max2 = i;
        }
    }
    printf("Ningún candidato obtuvo más del 50%%. Los candidatos %c y %c pasan a la segunda ronda.\n", 'A' + max1, 'A' + max2);
}
