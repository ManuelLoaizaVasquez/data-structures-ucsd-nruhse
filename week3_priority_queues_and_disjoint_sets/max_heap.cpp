#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 1e5;

struct MaxHeap {
    int max_size;
    int size;
    int* heap;
    MaxHeap() {
        max_size = N;
        size = 0;
        heap = new int[N + 1];
    }
    MaxHeap(int n) {
        max_size = n;
        size = 0;
        heap = new int[max_size + 1];
    }

    int parent(int current) {
        return current / 2;
    }

    int left_child(int current) {
        return 2 * current;
    }

    int right_child(int current) {
        return 2 * current + 1;
    }

    void sift_up(int current) {
        while (current > 1 and heap[parent(current)] < heap[current]) {
            swap(heap[parent(current)], heap[current]);
            current = parent(current);
        }
    }

    void sift_down(int current) {
        int max_index = current;
        int l = left_child(current);
        if (l <= size and heap[l] > heap[max_index]) {
            max_index = l;
        }
        int r = right_child(current);
        if (r <= size and heap[r] > heap[max_index]) {
            max_index = r;
        }
        if (current != max_index) {
            swap(heap[current], heap[max_index]);
            sift_down(max_index);
        }
    }

    void insert(int new_value) {
        if (size == max_size) {
            cout << "Error: Limite de memoria alcanzado." << endl;
            return;
        }
        size++;
        heap[size] = new_value;
        sift_up(size);
    }

    int extract_max() {
        int result = heap[1];
        heap[1] = heap[size];
        size--;
        sift_down(1);
        return result;
    }

    void remove(int current) {
        heap[current] = INF;
        sift_up(current);
        extract_max();
    }

    void change_priority(int current, int new_priority) {
        int old_priority = heap[current];
        heap[current] = new_priority;
        if (new_priority > old_priority) sift_up(current);
        else sift_down(current);
    }
};

void imprimir_insertar(int who, MaxHeap &h) {
    cout << "Inserto " << who << endl;
    h.insert(who);
}

void imprimir_extraer(MaxHeap &h) {
    int result = h.extract_max();
    cout << "Extraigo el maximo " << result << endl;
}

int main() {
    MaxHeap h(16);
    imprimir_insertar(-1, h);
    imprimir_insertar(10, h);
    imprimir_insertar(-100, h);
    imprimir_insertar(42, h);
    imprimir_extraer(h);
    imprimir_extraer(h);
    imprimir_extraer(h);
    imprimir_insertar(69, h);
    imprimir_extraer(h);
    imprimir_extraer(h);
    imprimir_extraer(h);
    imprimir_insertar(1, h);
    imprimir_insertar(2, h);
    imprimir_insertar(3, h);
    imprimir_insertar(4, h);
    imprimir_insertar(5, h);
    cout << "Cambio la prioridad del maximo a 4" << endl;
    h.change_priority(1, 4);
    imprimir_extraer(h);
    imprimir_extraer(h);
    cout << "Elimino el maximo" << endl;
    h.remove(1);
    imprimir_extraer(h);
    return 0;
}