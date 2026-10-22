#ifndef LIST_LINKED_H
#define LIST_LINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first;
    int n;

public:
    // Método constructor
    ListLinked() {
        first = nullptr;
        n = 0;
    }

    // Método destructor (sigue exactamente la estrategia del enunciado)
    ~ListLinked() override {
        while (first != nullptr) {
            Node<T>* aux = first->next; // 1. Situar aux
            delete first;               // 2. Liberar nodo apuntado por first
            first = aux;                // 3. Actualizar first
        }                               // 4. Repetir hasta el final
    }

    // --- Implementación de los métodos heredados de List<T> ---

    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Posición inválida en insert");
        }
        
        if (pos == 0) {
            // Insertar al principio
            first = new Node<T>(e, first);
        } else {
            // Insertar en otra posición (buscar el nodo anterior)
            Node<T>* current = first;
            for (int i = 0; i < pos - 1; i++) {
                current = current->next;
            }
            // Crear el nuevo nodo enlazándolo con el siguiente de current,
            // y actualizar el next de current para que apunte al nuevo nodo.
            current->next = new Node<T>(e, current->next);
        }
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

        T removed_data;

        if (pos == 0) {
            // Eliminar el primer nodo
            Node<T>* to_delete = first;
            removed_data = to_delete->data;
            first = first->next;
            delete to_delete;
        } else {
            // Eliminar un nodo en otra posición
            Node<T>* current = first;
            for (int i = 0; i < pos - 1; i++) {
                current = current->next;
            }
            Node<T>* to_delete = current->next;
            removed_data = to_delete->data;
            current->next = to_delete->next;
            delete to_delete;
        }
        n--;
        return removed_data;
    }

    T get(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición inválida en get");
        }
        
        Node<T>* current = first;
        for (int i = 0; i < pos; i++) {
            current = current->next;
        }
        return current->data;
    }

    int search(T e) override {
        Node<T>* current = first;
        int pos = 0;
        
        while (current != nullptr) {
            if (current->data == e) {
                return pos;
            }
            current = current->next;
            pos++;
        }
        return -1; // No se ha encontrado
    }

    bool empty() override {
        return n == 0;
    }

    int size() override {
        return n;
    }

    // --- Métodos específicos de ListLinked<T> ---

    T operator[](int pos) {
        return get(pos); // Reutilizamos get
    }

    friend std::ostream& operator<<(std::ostream &out, ListLinked<T> &list) {
        out << "List => [";
        Node<T>* current = list.first;
        while (current != nullptr) {
            out << "\n  " << current->data;
            current = current->next;
        }
        out << "\n]";
        return out;
    }
};

#endif
