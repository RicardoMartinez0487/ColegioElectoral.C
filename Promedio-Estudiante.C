/*----------------------------------------------------------------
|  Autor:Ricardo Jesus M.B                 Matricula: 2-14-8591   |
|  Fecha: 26-11-2024               Version: 		      
|-----------------------------------------------------------------|
|  Descripcion del Programa:  Este programaesta diseñado          |
| para obtener los datos de la notas de 5 estudiates y 3 materia. |
|  los cuales se podran visualizar el promedio de los estudiantes  |
|  el mas sobre saliente en las materias                           |
| ----------------------------------------------------------------*/


#include <stdio.h>

// Constantes
#define ESTUDIANTES 5
#define MATERIAS 3

// Prototipos de funciones
void ingresarNotas(float notas[ESTUDIANTES][MATERIAS], const char materias[MATERIAS][20]);
void mostrarNotas(float notas[ESTUDIANTES][MATERIAS], const char materias[MATERIAS][20]);
void calcularPromedioEstudiantes(float notas[ESTUDIANTES][MATERIAS], float promedios[ESTUDIANTES]);
int determinarMejorEstudiante(float promedios[ESTUDIANTES]);

int main() {
    float notas[ESTUDIANTES][MATERIAS];
    float promedios[ESTUDIANTES];
    int opcion;

    // Nombres de las materias
    const char materias[MATERIAS][20] = {
        "Lengua Española",
        "Matemática",
        "Naturales"
    };

    do {
        printf("\n=== Gestión de Notas ===\n");
        printf("1. Ingresar notas\n");
        printf("2. Ver todas las notas\n");
        printf("3. Calcular promedio por estudiante\n");
        printf("4. Determinar estudiante con el mayor promedio\n");
        printf("0. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresarNotas(notas, materias);
                break;
            case 2:
                mostrarNotas(notas, materias);
                break;
            case 3:
                calcularPromedioEstudiantes(notas, promedios);
                break;
            case 4: {
                int mejorEstudiante = determinarMejorEstudiante(promedios);
                printf("El estudiante con el mayor promedio es el Estudiante %d con un promedio de %.2f\n",
                       mejorEstudiante + 1, promedios[mejorEstudiante]);
                break;
            }
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (opcion != 0);

    return 0;
}

// Implementación de funciones
void ingresarNotas(float notas[ESTUDIANTES][MATERIAS], const char materias[MATERIAS][20]) {
    printf("\nIngrese las notas de los estudiantes:\n");
    for (int i = 0; i < ESTUDIANTES; i++) {
        printf("Estudiante %d:\n", i + 1);
        for (int j = 0; j < MATERIAS; j++) {
            printf("  %s: ", materias[j]);
            scanf("%f", *(notas + i) + j); // Uso de punteros
        }
    }
}

void mostrarNotas(float notas[ESTUDIANTES][MATERIAS], const char materias[MATERIAS][20]) {
    printf("\nNotas de los estudiantes:\n");
    for (int i = 0; i < ESTUDIANTES; i++) {
        printf("Estudiante %d:\n", i + 1);
        for (int j = 0; j < MATERIAS; j++) {
            printf("  %s: %.2f\n", materias[j], *(*(notas + i) + j)); // Uso de punteros
        }
    }
}

void calcularPromedioEstudiantes(float notas[ESTUDIANTES][MATERIAS], float promedios[ESTUDIANTES]) {
    printf("\nPromedio por estudiante:\n");
    for (int i = 0; i < ESTUDIANTES; i++) {
        float suma = 0;
        for (int j = 0; j < MATERIAS; j++) {
            suma += *(*(notas + i) + j); // Uso de punteros
        }
        promedios[i] = suma / MATERIAS;
        printf("Estudiante %d: %.2f\n", i + 1, promedios[i]);
    }
}

int determinarMejorEstudiante(float promedios[ESTUDIANTES]) {
    int indiceMejor = 0;
    float mejorPromedio = promedios[0];

    for (int i = 1; i < ESTUDIANTES; i++) {
        if (promedios[i] > mejorPromedio) {
            mejorPromedio = promedios[i];
            indiceMejor = i;
        }
    }
    return indiceMejor;
}
