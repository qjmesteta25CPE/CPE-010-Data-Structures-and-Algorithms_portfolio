/*

//PART B SUPPLEMENTARY

#include <iostream>
#include <thread>

int globalVar = 0;

void add(int value) {

    globalVar += value;

}

int main() {
    std::cout << "Display 1 (Before T1.join()): globalVar = " << globalVar << std::endl;

    std::thread T1(add, 10);

    T1.join();

    std::cout << "Display 2 (After T1.join()):  globalVar = " << globalVar << std::endl;

    std::thread T2(add, 20);

    T2.join();

    std::cout << "Display 3 (After T2.join()):  globalVar = " << globalVar << std::endl;

    std::thread T3(add, 30);

    T3.join();

    std::cout << "Display 4 (After T3.join()):  globalVar = " << globalVar << std::endl;

    return 0;

}

*/

// PART C SUPPLEMENTARY

#include <iostream>
#include <vector>
#include <thread>
#include <utility>

int partition(std::vector<int> &arr, int low, int high)
{

    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j < high; j++)
    {

        if (arr[j] < pivot)
        {

            i++;

            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);

    return i + 1;
}

void quickSort(std::vector<int> &arr, int low, int high)
{

    if (low < high)
    {

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);

        quickSort(arr, pi + 1, high);
    }
}

void parallelQuickSort(std::vector<int> &arr, int low, int high)
{

    if (low < high)
    {

        int pi = partition(arr, low, high);

        std::thread leftThread(quickSort, std::ref(arr), low, pi - 1);

        std::thread rightThread(quickSort, std::ref(arr), pi + 1, high);

        leftThread.join();

        rightThread.join();
    }
}

int main()
{

    std::vector<int> data = {42, 15, 8, 99, 23, 4, 16, 55, 12, 77};

    std::cout << "Unsorted array: ";

    for (int val : data)
    {

        std::cout << val << " ";
    }

    std::cout << std::endl;

    quickSort(data, 0, data.size() - 1);
    std::cout << "Sorted array using Quick Sort: ";

    for (int val : data)
    {

        std::cout << val << " ";
    }

    std::cout << std::endl;

    parallelQuickSort(data, 0, data.size() - 1);

    std::cout << "Sorted array using Multithreaded Quick Sort: ";

    for (int val : data)
    {

        std::cout << val << " ";
    }

    std::cout << std::endl;

    return 0;
}
