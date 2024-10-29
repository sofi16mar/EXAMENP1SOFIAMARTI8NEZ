#include <stdio.h>
#include <string.h>

#define COUNT 5

void Ingresarnombre(char nombre[COUNT][50]) {
    for (int i = 0; i < COUNT; i++) {
        printf("Ingresar nombre de Persona %d: ", i + 1);
        fgets(nombre[i], 50, stdin);
        // Eliminar el salto de línea al final de fgets
        nombre[i][strcspn(nombre[i], "\n")] = '\0';
    }
}

void Ingresaredad(int edad[COUNT]) {
    for (int i = 0; i < COUNT; i++) {
        printf("Ingresar edad de Persona %d: ", i + 1);
        scanf("%d", &edad[i]);
        while (edad[i] <= 0 || edad[i] > 100) {
            printf("Edad errónea, ingrese nuevamente: ");
            scanf("%d", &edad[i]);
        }
    }
    // Limpiar el buffer de entrada
    while (getchar() != '\n');
}

void Ingresarestadocivil(char estadocivil[COUNT][50]) {
    for (int i = 0; i < COUNT; i++) {
        printf("Ingresar estado civil de Persona %d: ", i + 1);
        fgets(estadocivil[i], 50, stdin);
        // Eliminar el salto de línea al final de fgets
        estadocivil[i][strcspn(estadocivil[i], "\n")] = '\0';
    }
}

int main() {
    char nombre[COUNT][50];
    int edad[COUNT];
    char estadocivil[COUNT][50];
    int abcd;

    printf("Ingrese una opción (1-4): ");
    scanf("%d", &abcd);
    // Limpiar el buffer de entrada
    while (getchar() != '\n');

    switch (abcd) {
        case 1:
            Ingresarnombre(nombre);
            break;
        case 2:
            Ingresaredad(edad);
            break;
        case 3:
            Ingresarestadocivil(estadocivil);
            break;
        case 4:
            printf("¿Desea otra opción? (1 para sí, 0 para no): ");
            int opcion;
            scanf("%d", &opcion);
            if (opcion == 1) {
                printf("Alguno de nuestros asesores se comunicará con usted, gracias por su visita.\n");
            }
            break;
        default:
            printf("Opción no válida.\n");
            break;
    }

    return 0;
}
