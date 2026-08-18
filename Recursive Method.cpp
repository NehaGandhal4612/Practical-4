#include <iostream>
using namespace std;

// Recursive Heapify
void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Check left child
    if (left < n && a[left] > a[largest])
        largest = left;

    // Check right child
    if (right < n && a[right] > a[largest])
        largest = right;

    // If largest is not root
    if (largest != i)
    {
        swap(a[i], a[largest]);

        // Recursive call
        heapify(a, n, largest);
    }
}

// Heap Sort
void heapSort(int a[], int n)
{
    // Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    // Extract elements
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);

        // Heapify remaining elements
        heapify(a, i, 0);
    }
}

int main()
{
    int a[] = {20, 10, 30, 5, 15};
    int n = 5;

    cout << "Before Sorting: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    heapSort(a, n);

    cout << "\nAfter Sorting: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
