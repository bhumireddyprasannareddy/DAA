#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Iterative Factorial using while loop
unsigned long long findFactorialLoop(int number)
{
    unsigned long long answer = 1;
    int count = 1;

    while (count <= number)
    {
        answer *= count;
        count++;
    }

    return answer;
}

// Recursive Factorial
unsigned long long findFactorialRecursion(int number)
{
    if (number == 0 || number == 1)
        return 1;

    return number * findFactorialRecursion(number - 1);
}

int main()
{
    int number;

    cout << "Enter a non-negative number: ";
    cin >> number;

    if (number < 0)
    {
        cout << "Factorial is not defined for negative numbers." << endl;
        return 0;
    }

    // Measure Iterative Time
    auto beginLoop = high_resolution_clock::now();
    unsigned long long loopResult = findFactorialLoop(number);
    auto finishLoop = high_resolution_clock::now();

    // Measure Recursive Time
    auto beginRec = high_resolution_clock::now();
    unsigned long long recResult = findFactorialRecursion(number);
    auto finishRec = high_resolution_clock::now();

    auto loopTime = duration_cast<nanoseconds>(finishLoop - beginLoop);
    auto recTime = duration_cast<nanoseconds>(finishRec - beginRec);

    cout << "\n========== FACTORIAL COMPARISON ==========\n";
    cout << "Input Number        : " << number << endl;
    cout << "------------------------------------------" << endl;
    cout << "Iterative Factorial : " << loopResult << endl;
    cout << "Execution Time      : " << loopTime.count() << " ns" << endl;
    cout << "------------------------------------------" << endl;
    cout << "Recursive Factorial : " << recResult << endl;
    cout << "Execution Time      : " << recTime.count() << " ns" << endl;
    cout << "==========================================" << endl;

    return 0;
}