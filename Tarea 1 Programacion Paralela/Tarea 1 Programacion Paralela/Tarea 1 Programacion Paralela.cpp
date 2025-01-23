// Tarea 1 Programacion Paralela.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <omp.h>
#include <cstdlib> // Para generar n�meros aleatorios
#include <ctime>   // Para inicializar la semilla aleatoria

#define N 100 // Esto define la cantidad de elementos en los arreglos.
#define MOSTRAR 10// Este n�mero determina cu�ntos elementos imprimimos para verificar los resultados.
#define CHUNK 25 // Tama�o de los bloques asignados a cada hilo.

void imprimeArreglo(int* arr, int size); // Te explico abajo: esta funci�n sirve para imprimir los elementos de un arreglo.

int main() {
    // Aqu� creamos tres arreglos: 
    // "a" y "b" tendr�n los datos iniciales, y "c" almacenar� el resultado de la suma.
    int a[N], b[N], c[N];

    // Inicializamos el generador de n�meros aleatorios.
    srand(static_cast<unsigned int>(time(0))); // time(0) es la semilla. La conversi�n asegura compatibilidad.

    // Llenamos los arreglos "a" y "b" con n�meros aleatorios entre 0 y 99.
    for (int i = 0; i < N; i++) {
        a[i] = rand() % 100; // Aqu� llenamos "a".
        b[i] = rand() % 100; // Y aqu� llenamos "b".
    }

    int i; // Declaramos "i" para usarla en el bucle paralelo.

    // Ahora hacemos la suma en paralelo. 
    // OpenMP distribuye las operaciones entre varios hilos, as� que cada hilo suma una parte de los arreglos.
#pragma omp parallel for shared(a, b, c) private(i)
    for (i = 0; i < N; i++) {
        c[i] = a[i] + b[i]; // Aqu� sumamos los elementos correspondientes de "a" y "b".
    }

    // Imprimimos los primeros "MOSTRAR" elementos de cada arreglo para verificar el resultado.
    std::cout << "Arreglo A: "; imprimeArreglo(a, MOSTRAR);
    std::cout << "Arreglo B: "; imprimeArreglo(b, MOSTRAR);
    std::cout << "Arreglo C: "; imprimeArreglo(c, MOSTRAR);

    return 0; // Fin del programa.
}

// Esta funci�n imprime los primeros "size" elementos de un arreglo.
// La llamo para mostrar las partes importantes de los arreglos sin saturar la pantalla.
void imprimeArreglo(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " "; // Imprime cada elemento seguido de un espacio.
    }
    std::cout << std::endl; // Salto de l�nea al final para que se vea ordenado.
}
