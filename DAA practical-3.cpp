#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace chrono;

// Iterative Heapify Function
void heapify(vector<int> &arr, int size, int root, bool maxHeap)
{
    while (true)
    {
        int selected = root;
        int left = 2 * root + 1;
        int right = 2 * root + 2;

        if (maxHeap)
        {
            if (left < size && arr[left] > arr[selected])
                selected = left;

            if (right < size && arr[right] > arr[selected])
                selected = right;
        }
        else
        {
            if (left < size && arr[left] < arr[selected])
                selected = left;

            if (right < size && arr[right] < arr[selected])
                selected = right;
        }

        if (selected == root)
            break;

        swap(arr[root], arr[selected]);
        root = selected;
    }
}

// Heap Sort Function
void heapSort(vector<int> &arr, bool maxHeap)
{
    int n = arr.size();

    // Build Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, maxHeap);

    // Sorting
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, maxHeap);
    }

    // Reverse for ascending if Min Heap is used
    if (!maxHeap)
        reverse(arr.begin(), arr.end());
}

// Print Array
void display(vector<int> arr)
{
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}

int main()
{
    int n, option;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> data(n);

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> data[i];

    cout << "\n1. Ascending Order (Max Heap)";
    cout << "\n2. Descending Order (Min Heap)";
    cout << "\nEnter your choice: ";
    cin >> option;

    vector<int> sorted = data;

    auto start = high_resolution_clock::now();

    if (option == 1)
        heapSort(sorted, true);
    else
        heapSort(sorted, false);

    auto stop = high_resolution_clock::now();

    auto ns = duration_cast<nanoseconds>(stop - start);
    auto us = duration_cast<microseconds>(stop - start);
    auto ms = duration_cast<milliseconds>(stop - start);
    duration<double> sec = stop - start;

    cout << "\nOriginal Array:\n";
    display(data);

    cout << "\nSorted Array:\n";
    display(sorted);

    cout << "\nExecution Time";
    cout << "\n----------------------";
    cout << "\nNanoseconds  : " << ns.count() << " ns";
    cout << "\nMicroseconds : " << us.count() << " us";
    cout << "\nMilliseconds : " << ms.count() << " ms";
    cout << "\nSeconds      : " << sec.count() << " s";

    cout << "\n\nTime Complexity : O(n log n)";
    cout << "\nSpace Complexity: O(1)" << endl;

    return 0;
}