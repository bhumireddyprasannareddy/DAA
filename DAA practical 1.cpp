#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

// Bubble Sort
void bubbleSort(vector<int> &a)
{
    int n = a.size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

// Selection Sort
void selectionSort(vector<int> &a)
{
    int n = a.size();

    for (int i = 0; i < n - 1; i++)
    {
        int smallest = i;

        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[smallest])
                smallest = j;
        }

        swap(a[i], a[smallest]);
    }
}

// Insertion Sort
void insertionSort(vector<int> &a)
{
    int n = a.size();

    for (int i = 1; i < n; i++)
    {
        int value = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > value)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = value;
    }
}

// Merge Function
void merge(vector<int> &a, int left, int mid, int right)
{
    vector<int> temp;

    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (a[i] <= a[j])
            temp.push_back(a[i++]);
        else
            temp.push_back(a[j++]);
    }

    while (i <= mid)
        temp.push_back(a[i++]);

    while (j <= right)
        temp.push_back(a[j++]);

    for (int k = 0; k < temp.size(); k++)
        a[left + k] = temp[k];
}

void mergeSort(vector<int> &a, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);

    merge(a, left, mid, right);
}

// Quick Sort
int partition(vector<int> &a, int low, int high)
{
    int pivot = a[high];
    int index = low - 1;

    for (int i = low; i < high; i++)
    {
        if (a[i] < pivot)
        {
            index++;
            swap(a[index], a[i]);
        }
    }

    swap(a[index + 1], a[high]);

    return index + 1;
}

void quickSort(vector<int> &a, int low, int high)
{
    if (low < high)
    {
        int p = partition(a, low, high);

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int main()
{
    const int SIZE = 100;

    vector<int> numbers(SIZE);
    vector<int> copy;

    srand(time(NULL));

    // Generate random numbers
    for (int i = 0; i < SIZE; i++)
        numbers[i] = rand() % 1000;

    cout << "Number of Elements = " << SIZE << "\n\n";

    auto start = high_resolution_clock::now();
    copy = numbers;
    bubbleSort(copy);
    auto end = high_resolution_clock::now();
    cout << "Bubble Sort    : "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds\n";

    start = high_resolution_clock::now();
    copy = numbers;
    selectionSort(copy);
    end = high_resolution_clock::now();
    cout << "Selection Sort : "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds\n";

    start = high_resolution_clock::now();
    copy = numbers;
    insertionSort(copy);
    end = high_resolution_clock::now();
    cout << "Insertion Sort : "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds\n";

    start = high_resolution_clock::now();
    copy = numbers;
    mergeSort(copy, 0, SIZE - 1);
    end = high_resolution_clock::now();
    cout << "Merge Sort     : "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds\n";

    start = high_resolution_clock::now();
    copy = numbers;
    quickSort(copy, 0, SIZE - 1);
    end = high_resolution_clock::now();
    cout << "Quick Sort     : "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds\n";

    return 0;
}