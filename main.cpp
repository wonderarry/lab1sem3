#include <iostream>
#include <chrono>
#include <functional>
#include "randIntGenerator.h"
#include "ArraySequence.h"
#include "shakerSort.h"
#include "insertionSort.h"
#include "selectionSort.h"
#include "intComparison.h"
//Has built-in console interface.

using std::cin;
using std::cout;

class UI
{
private:
    int currentMenuState;
    int testingType;
    //int sortingAlgorithmType;
    double timeElapsed[3];

    ArraySequence<int> testingStorage;

    void TimedTest()
    {

        ArraySequence<int> tempCopy(testingStorage);
        auto start = std::chrono::steady_clock::now();
        genericShaker<ArraySequence, int>(&testingStorage);
        auto end = std::chrono::steady_clock::now();
        auto double_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        timeElapsed[0] = double_ms.count();

        testingStorage = ArraySequence<int>(tempCopy);
        start = std::chrono::steady_clock::now();
        genericShaker<ArraySequence, int>(&testingStorage);
        end = std::chrono::steady_clock::now();
        double_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        timeElapsed[1] = double_ms.count();

        testingStorage = ArraySequence<int>(tempCopy);
        start = std::chrono::steady_clock::now();
        genericShaker<ArraySequence, int>(&testingStorage);
        end = std::chrono::steady_clock::now();
        double_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        timeElapsed[2] = double_ms.count();
    }

    void generateArrayInt(int desiredLength = 1)
    {
        testingStorage.Resize(0);
        int *a = new int;
        for (int i = 0; i < desiredLength; ++i)
        {
            *a = generateInt();
            testingStorage.Append(a);
        }
    }

    void inputArrayInt(int desiredLength = 1)
    {
        testingStorage.Resize(0);
        int *a = new int;
        for (int i = 0; i < desiredLength; ++i)
        {
            cout << "\nInput the element with index " << i << ": ";
            cin >> *a;
            testingStorage.Append(a);
        }
    }

    void menu0()
    {
        cout << "\nSelect type of testing:\n1.Automatic\n2.Manual";
        cout << "\nEnter your choice: ";
        cin >> testingType;
        if (testingType == 1 || testingType == 2)
        {
            currentMenuState = 1;
            Invoke();
        }
    }

    void menu1()
    {
        //cout << "\nSelect the algorithm used:\n1.Shaker\n2.Insertion\n3.Selection\n4.Compare all methods";
        //cout << "\nEnter your choice: ";
        //cin >> sortingAlgorithmType;
        //if (sortingAlgorithmType > 0 && sortingAlgorithmType < 5)
        //{
        currentMenuState = 2;
        Invoke();
        //}
    }

    void menu2()
    {
        int inputLength;
        cout << "\nSpecify number of elements of the tested sequence: ";
        cin >> inputLength;
        if (testingType == 1)
        {
            generateArrayInt(inputLength);
        }
        else if (testingType == 2)
        {
            inputArrayInt(inputLength);
        }
        currentMenuState = 3;
        Invoke();
    }

    void menu3()
    {
        cout << "\nInput parameters:";
        cout << "\nType of testing - " << testingType;
        //cout << "\nSorting Algorithm - " << sortingAlgorithmType;
        cout << "\nLength of the provided sequence - " << testingStorage.GetLength();

        TimedTest();
        //if (sortingAlgorithmType > 0 && sortingAlgorithmType < 4)
        //{
        //     cout << "\nExecution time in milliseconds:" << timeElapsed[0] << " " << timeElapsed[1] << " " << timeElapsed[2];
        //}
        //else if (sortingAlgorithmType == 4)
        //{
        cout << "\nShaker - Execution time in milliseconds:" << timeElapsed[0];
        cout << "\nInsertion - Execution time in milliseconds:" << timeElapsed[1];
        cout << "\nSelection - Execution time in milliseconds:" << timeElapsed[2];
        //}
    }

public:
    UI(int setState = 0) : currentMenuState(setState), testingType(0)//, sortingAlgorithmType(0)
    {
    }

    void Invoke()
    {

        switch (currentMenuState)
        {
        case 0:
            menu0();
            break;

        case 1:
            menu1();
            break;

        case 2:
            menu2();
            break;

        case 3:
            menu3();
            break;

        default:
            break;
        }
    }
};

int main()
{
    UI object(0);
    object.Invoke();
    return 0;
}