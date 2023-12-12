#include <stdio.h>
#include <string.h>
#define TAMA 3

// Declaro las estructuras
typedef struct {
    int dia;
    int mes;
    int anio;
} Fecha;
typedef struct {
    char nombreCliente[15];
    int cuil;
    char mail[15];
    int cantSucursales;
} Cliente;
typedef struct {
    char nombreProducto[15];
    char categoria[15];
    float precioProducto;
    Fecha vencimiento;
    int stock;
    Cliente clientes[5];  // guardo 5 clientes por producto
} Producto;

// tama es el tamaño del arreglo de productos
void listarClientesCerveza(Producto productos[], int tama);
void listarClientesCerveza(Producto productos[], int tama) {
    printf("=== Listado de clientes de CERVEZA === \n");
    printf("\n");
    // recorro con el for todos los productos que haya guardados en el array
    for (int i = 0; i < tama; i++) {
        // Con el if controlo que sea cerveza y bravante como pide el enunciado, uso strcmp para comparar cadenas
        if (strcmp(productos[i].categoria, "Cerveza") == 0 && strcmp(productos[i].nombreProducto, "Bravante") == 0) {
            // ahora que estoy en el producto correcto, recorro el arreglo de clientes 5 veces, que es la cantidad de clientes por producto que pide el enunciado
            for (int j = 0; j < 5; j++) {
                if (productos[i].clientes[j].cantSucursales > 2) {
                    printf("== Cliente nro: %d ==\n", j + 1);
                    printf("Nombre: %s\n", productos[i].clientes[j].nombreCliente);
                    printf("Cuil: %d\n", productos[i].clientes[j].cuil);
                    printf("Mail: %s\n", productos[i].clientes[j].mail);
                    printf("Cantidad de sucursales: %d\n", productos[i].clientes[j].cantSucursales);
                    printf("=== === === ===\n");
                }
            }
        }
    }
}

void aumentarPrecio(Producto *productos, int tama);
void aumentarPrecio(Producto *productos, int tama) {
    for (int i = 0; i < tama; i++) {
        if (productos[i].stock < 300) {
            productos[i].precioProducto = productos[i].precioProducto + (productos[i].precioProducto * 10) / 100;
        }
    }
}

int main() {
    // creo el arreglo de 3 tipos de productos
    // incializo el arreglo
    Producto productos[TAMA] = {
        {"Bravante", "Cerveza", 2500, {1, 1, 2024}, 500, {{"Juan", 123456, "juan@mail.com", 3}, {"Martin", 123456, "martin@mail.com", 4}, {"Teo", 123456, "teo@mail.com", 3}, {"Peron", 123456, "peron@mail.com", 2}, {"Ibai", 123456, "ibai@mail.com", 1}}},
        {"Uvita", "Vinos", 1500, {1, 1, 2024}, 200, {{"Pedro", 9876543, "pedro@mail.com", 2}}},
        {"Corona", "Cerveza", 3000, {1, 1, 2024}, 100, {{"María", 1111222, "maria@mail.com", 4}}}};
    // este es el tamanio del arreglo que recibiran las funciones para usar en el bucle for
    int tama = TAMA;
    // llamo a las funciones
    listarClientesCerveza(productos, tama);
    //aumentar precio
    printf("Precio viejo: %2.f \n", productos[1].precioProducto);
    aumentarPrecio(productos, tama);
    printf("Precio actual: %2.f \n", productos[1].precioProducto);

    return 0;
}