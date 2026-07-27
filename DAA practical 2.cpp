#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Linear Search Function
int linearSearch(const vector<int> &numbers, int target)
{
    for (int position = 0; position < numbers.size(); position++)
    {
        if (numbers[position] == target)
            return position;
    }
    return -1;
}

// Binary Search Function
int binarySearch(const vector<int> &numbers, int target)
{
    int left = 0;
    int right = numbers.size() - 1;

    while (left <= right)
    {
        int center = left + (right - left) / 2;

        if (numbers[center] == target)
            return center;
        else if (numbers[center] < target)
            left = center + 1;
        else
            right = center - 1;
    }

    return -1;
}

int main()
{
    int size = 100000;
    vector<int> numbers(size);

    // Initialize sorted array
    for (int count = 0; count < size; count++)
    {
        numbers[count] = count + 1;
    }

    int target;
    cout << "Enter element to search: ";
    cin >> target;

    int resultIndex;

    // Linear Search Execution Time
    auto beginTime = high_resolution_clock::now();
    resultIndex = linearSearch(numbers, target);
    auto endTime = high_resolution_clock::now();

    cout << "\nLinear Search\n";
    if (resultIndex != -1)
        cout << "Element found at index " << resultIndex << endl;
    else
        cout << "Element not found\n";

    cout << "Execution Time: "
         << duration_cast<microseconds>(endTime - beginTime).count()
         << " microseconds\n";

    // Binary Search Execution Time
    beginTime = high_resolution_clock::now();
    resultIndex = binarySearch(numbers, target);
    endTime = high_resolution_clock::now();

    cout << "\nBinary Search\n";
    if (resultIndex != -1)
        cout << "Element found at index " << resultIndex << endl;
    else
        cout << "Element not found\n";

    cout << "Execution Time: "
         << duration_cast<microseconds>(endTime - beginTime).count()
         << " microseconds\n";

    return 0;
}