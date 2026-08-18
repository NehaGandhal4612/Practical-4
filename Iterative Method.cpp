#include <iostream>
using namespace std;

void heapify(int a[], int n, int i)
{
    while (2 * i + 1 < n)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = left;

        if (right < n && a[right] > a[left])
            largest = right;

        if (a[i] >= a[largest])
            break;

        swap(a[i], a[largest]);
        i = largest;
    }
}

void heapSort(int a[], int n)
{
    // Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    // Sorting
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int main()
{
    int a[] = {20, 10, 30, 5, 15};
    int n = 5;

    heapSort(a, n);

    cout << "Sorted Array: ";

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
