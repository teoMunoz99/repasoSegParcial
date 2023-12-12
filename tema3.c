#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMA 6

typedef struct {
    int dia;
    int mes;
    int anio;
} Fecha;
typedef struct {
    char nombrePasajero[15];
    char apellidoPasajero[15];
    int dni;
    float costoPasaje;
} Pasajero;
typedef struct {
    int numVuelo;
    char origen[15];
    char destino[15];
    Fecha fechaVuelo;
    int cantAsientos;
    Pasajero *pasajeros;
} Vuelo;

void listarVuelos(Vuelo *vuelos, int tama);
void listarVuelos(Vuelo *vuelos, int tama) {
    for (int i = 0; i < tama; i++) {
        if (strcmp(vuelos[i].origen, "Tucuman") == 0 && strcmp(vuelos[i].destino, "Cordoba") == 0) {
            printf("== Vuelos TUC a COR ==\n");
            printf("\n");
            printf("N de vuelo: %d\n", vuelos[i].numVuelo);
            printf("Origen: %s\n", vuelos[i].origen);
            printf("Destino: %s\n", vuelos[i].destino);
            printf("Fecha del vuelo: %d/%d/%d\n", vuelos[i].fechaVuelo.dia, vuelos[i].fechaVuelo.mes, vuelos[i].fechaVuelo.anio);
            printf("Cantidad de asientos: %d", vuelos[i].cantAsientos);
        }
    }
}

int main() {
    int asientos = 3;
    Vuelo vuelos[TAMA];
    
    for (int i = 0; i < TAMA; i++) {
        vuelos->pasajeros = (Pasajero *)malloc(asientos * sizeof(Pasajero));
    }
    vuelos[0] = {111, "Tucuman", "Cordoba", {1, 12, 2023}, asientos, {{"nombre", "apellido", 99999, 35000}, {"nombre2", "apellido2", 99999, 65000},{"nombre3", "apellido3", 99999, 145000}}};
/*    vuelos[] = {
        {111, "Tucuman", "Cordoba", {1, 12, 2023}, asientos, {{"nombre", "apellido", 99999, 35000}, {"nombre2", "apellido2", 99999, 65000},{"nombre3", "apellido3", 99999, 145000}}},
        {222, "Tucuman", "Salta", {1, 12, 2023}, asientos, {{"nombre5", "apellido5", 99999, 65000},{"nombre4", "apellido4", 99999, 65000},{"nombre7", "apellido7", 99999, 65000}}},
        {333, "Tucuman", "Venecia", {1, 12, 2023}, asientos, {{"nombre6", "apellido6", 99999, 85000},{"nombre11", "apellido11", 99999, 85000},{"nombre12", "apellido13", 99999, 85000}}},
        {444, "Tucuman", "Cordoba", {4, 12, 2025}, asientos, {{"nombre8", "apellido8", 99999, 95000},{"nombre14", "apellido14", 99999, 95000},{"nombre14", "apellido14", 99999, 95000}}},
        {555, "Tucuman", "Cordoba", {9, 12, 2024}, asientos, {{"nombre9", "apellido9", 99999, 55000},{"nombre15", "apellido15", 99999, 55000},{"nombre16", "apellido16", 99999, 55000}}},
        {666, "Tucuman", "Roma", {1, 12, 2023}, asientos, {{"nombre10", "apellido10", 99999, 25000},{"nombre17", "apellido17", 99999, 25000},{"nombre18", "apellido18", 99999, 25000}}}};
*/
    listarVuelos(vuelos, TAMA);
    for (int i = 0; i < TAMA; i++) {
        free(vuelos->pasajeros);
    }
}