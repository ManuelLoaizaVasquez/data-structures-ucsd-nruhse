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

    void build_heap(int a[], int n) {
        size = n;
        for (int i = 1; i <= n; i++) heap[i] = a[i];
        for (int i = n / 2; i >= 1; i--) sift_down(i);
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

void heap_sort(int a[], int n) {
    MaxHeap h(n);
    h.build_heap(a, n);
    for (int i = 0; i < n - 1; i++) {
        swap(h.heap[1], h.heap[h.size]);
        h.size--;
        h.sift_down(1);
    }
    for (int i = 1; i <= n; i++) a[i] = h.heap[i];
}

int main() {
    // Mi arreglo comienza desde la posicion 1
    int a[] = {INF, 69, -1, 0, 1000, 42, 314, 159, 359};
    int n = sizeof(a) / sizeof(int);
    n--;
    heap_sort(a, n);
    cout << "Arreglo ordenado: ";
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}