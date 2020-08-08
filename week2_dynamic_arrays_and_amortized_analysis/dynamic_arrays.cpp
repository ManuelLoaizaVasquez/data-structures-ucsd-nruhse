#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct DynamicArray {
    int* arr;
    int capacity;
    int size;

    DynamicArray() {
        arr = new int[1];
        capacity = 1;
        size = 0;
    }

    int Get(int pos) {
        if (pos < 0 or pos >= size) {
            cout << "ERROR: Fuera de limites." << endl;
            return -INF;
        } else {
            return arr[pos];
        }
    }

    void Set(int pos, int val) {
        if (pos < 0 or pos >= size) {
            cout << "ERROR: Fuera de limites." << endl;
            return;
        } else {
            arr[pos] = val;
        }
    }

    void PushBack(int val) {
        if (size == capacity) {
            int* new_arr = new int[2 * capacity];
            for (int i = 0; i < size; i++) new_arr[i] = arr[i];
            delete[] arr;
            arr = new_arr;
            capacity *= 2;
        }
        arr[size] = val;
        size++;
    }

    void Remove(int pos) {
        if (pos < 0 or pos >= size) {
            cout << "ERROR: Fuera de limites." << endl;
            return;
        } else {
            for (int i = pos; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            size--;
        }
    }

    int Size() { return size; }
};

void imprimir(DynamicArray &a) {
    int tamanio = a.Size();
    cout << "|a| = " << tamanio << endl;
    for (int i = 0; i < tamanio; i++) {
        cout << "a[" << i << "] = " << a.Get(i) << endl;
    }
    cout << endl;
}

int main() {
    DynamicArray a;
    a.PushBack(2);
    a.PushBack(3);
    a.PushBack(5);
    a.PushBack(7);
    a.PushBack(11);
    imprimir(a);
    a.PushBack(13);
    a.PushBack(16);
    a.PushBack(19);
    a.PushBack(23);
    imprimir(a);
    a.Set(6, 17);
    imprimir(a);
    a.PushBack(24);
    a.PushBack(29);
    a.PushBack(31);
    imprimir(a);
    a.Remove(9);
    imprimir(a);
    return 0;
}