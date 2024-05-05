#include <iostream>
using namespace std;

class heap {
public:
    int arr[100];
    int size;

    heap() {
        arr[0] = 101; // Assuming the maximum possible value for this problem
        size = 0;
    }

    void print() {
        for (int i = 1; i <= size; i++) { // Index 0 is null so start from index 1
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void delete1() {
        if (size == 0) {
            cout << "Nothing to delete" << endl;
        }
        int i = 1;
        arr[1] = arr[size];
        size--; // Decrease the size
        while (i < size) {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;
            int smallestIndex = i;

            if (leftIndex <= size && arr[leftIndex] < arr[smallestIndex]) {
                smallestIndex = leftIndex;
            }

            if (rightIndex <= size && arr[rightIndex] < arr[smallestIndex]) {
                smallestIndex = rightIndex;
            }

            if (smallestIndex != i) {
                swap(arr[i], arr[smallestIndex]);
                i = smallestIndex; // Move down the tree
            } else {
                break; // Heap property is satisfied, terminate the loop
            }
        }
    }

    void heapify(int arr[], int n, int i) {
        int smallest = i;
        int left = 2 * i;
        int right = 2 * i + 1;
        if (left <= n && arr[left] < arr[smallest]) {
            smallest = left;
        }
        if (right <= n && arr[right] < arr[smallest]) {
            smallest = right;
        }
        if (smallest != i) {
            swap(arr[smallest], arr[i]);
            heapify(arr, n, smallest); // Put the index in the correct position if there is need
        }
    }

    void heapsort(int arr[], int n) {
        // Step 1: Swap the first and last nodes
        int size = n;
        while (size > 1) {
            // Step 1: Swap
            swap(arr[size], arr[1]);
            // Step 2:
            size--;
            heapify(arr, size, 1);
        }
    }
};

int main() {
    heap h;
    int arr[6] = {101, 54, 53, 55, 52, 50}; // Initialized with a maximum value
    int n = 5;
    for (int i = n / 2; i > 0; i--) {
        h.heapify(arr, n, i);
    }
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Heapsort
    h.heapsort(arr, n);
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
