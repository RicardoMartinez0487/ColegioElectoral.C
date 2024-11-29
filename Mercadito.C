
/*----------------------------------------------------------------
|  Autor:Ricardo Jesus M.B                 Matricula: 2-14-8591   |
|  Fecha: 26-11-2024               Version: 		      
|-----------------------------------------------------------------|
|  Descripcion del Programa:  Este programaesta diseñado          |
| para modificar valores con ficheros y uso de estructura ,       |
|  el programa debde de modificar                                 | 
|el valor del producto seleccionado y imprimir el valor nuevo .   |
| ----------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definir de la estructura Producto
typedef struct {
    char nombre[20];
    float precio;
} Producto;

// funcion para leer la info desde el archivo 
void leerProductos(Producto productos[], int numProductos) {
    FILE *archivo = fopen("articulos.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }
    int i;

    for ( i = 0; i < numProductos; i++) {
        fscanf(archivo, "%s %f\n", productos[i].nombre, &productos[i].precio);
    }

    fclose(archivo);
}

// funcion para escribir la info de los productos en el archivo
void escribirProductos(Producto productos[], int numProductos) {
    FILE *archivo = fopen("articulos.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }
int i;
    for ( i = 0; i < numProductos; i++) {
        fprintf(archivo, "%s %.2f\n", productos[i].nombre, productos[i].precio);
    }

    fclose(archivo);
}


void modificarPrecio(Producto *producto) {
    printf("Ingrese el nuevo precio para %s: ", producto->nombre);
    scanf("%f", &producto->precio);
}

int main() {
    // definir los valores iniciales de los productos
    Producto productos[] = {
        {"ARROZ SELECTO", 25.10},
        {"HABICHUELA SELECTO", 35.0},
        {"CAMARONES IMPORTADO", 64.5},
        {"LATA MAIZ LOCAL", 55.0},
        {"CARNE IMPORTADO", 80.3}
    };
    int numProductos = sizeof(productos) / sizeof(productos[0]);

    int opcion;
    do {
        //  menu
        printf("\nSeleccione  el producto a modificar :\n");
        int i;
        for (i = 0; i < numProductos; i++) {
            printf("%d. %s: %.2f\n", i + 1, productos[i].nombre, productos[i].precio);
        }
        printf("%d. Salir\n", numProductos + 1);
        printf("Opcion: ");
        scanf("%d", &opcion);

        if (opcion >= 1 && opcion <= numProductos) {
            modificarPrecio(&productos[opcion - 1]);
            printf("%s modificado: %.2f\n", productos[opcion - 1].nombre, productos[opcion - 1].precio);
        } else if (opcion != numProductos + 1) {
            printf("Opcion invalida.\n");
        }
    } while (opcion != numProductos + 1);

    
    escribirProductos(productos, numProductos);

    system("pause");

    return 0;
}