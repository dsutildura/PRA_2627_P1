#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <iostream>
#include <stdexcept>
#include "List.h"

template <typename T>
class ListArray : public List<T> {
private:
    T* arr;
    int max;
    int n;
    static const int MINSIZE = 2;

    // Método privado para redimensionar el array
    void resize(int new_size) {
        T* new_arr = new T[new_size];
        
        // Copiamos los elementos antiguos al nuevo array
        // Nos aseguramos de no copiar más elementos de los que caben o de los que hay
        int elements_to_copy = (new_size < n) ? new_size : n;
        for (int i = 0; i < elements_to_copy; i++) {
            new_arr[i] = arr[i];
        }

        delete[] arr;
        arr = new_arr;
        max = new_size;
    }

public:
    // Constructor
    ListArray() {
        arr = new T[MINSIZE];
        max = MINSIZE;
        n = 0;
    }

    // Destructor
    ~ListArray() override {
        delete[] arr;
    }

    // --- Implementación de los métodos de List<T> ---

    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Posición inválida en insert");
        }

        // Si el array está lleno, duplicamos su capacidad
        if (n == max) {
            resize(max * 2);
        }

        // Desplazamos los elementos a la derecha para hacer hueco
        for (int i = n; i > pos; i--) {
            arr[i] = arr[i - 1];
        }

        arr[pos] = e;
        n++;
    }

    void append(T e) override {
        insert(n, e); // Reutilizamos insert
    }

    void prepend(T e) override {
        insert(0, e); // Reutilizamos insert
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición inválida en remove");
        }

        T removed_element = arr[pos];

        // Desplazamos los elementos a la izquierda para rellenar el hueco
        for (int i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;

        // Si el array está muy vacío (menos de 1/4 de ocupación) 
        // y su tamaño es mayor que MINSIZE, lo reducimos a la mitad
        if (n > 0 && n < max / 4 && max / 2 >= MINSIZE) {
            resize(max / 2);
        } else if (n == 0) {
             // Si se queda vacío, lo devolvemos al tamaño mínimo
             resize(MINSIZE);
        }

        return removed_element;
    }

    T get(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición inválida en get");
        }
        return arr[pos];
    }

    int search(T e) override {
        for (int i = 0; i < n; i++) {
            if (arr[i] == e) {
                return i;
            }
        }
        return -1; // No encontrado
    }

    bool empty() override {
        return n == 0;
    }

    int size() override {
        return n;
    }

    // --- Métodos específicos de ListArray<T> ---

    T operator[](int pos) {
        return get(pos); // Reutilizamos get que ya controla los límites
    }

    friend std::ostream& operator<<(std::ostream &out, ListArray<T> &list) {
        out << "List => [";
        for (int i = 0; i < list.size(); i++) {
            out << "\n  " << list.get(i);
        }
        out << "\n]";
        return out;
    }
};

#endif
