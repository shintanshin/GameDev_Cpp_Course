#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <chrono>
#include <stack>
#include <queue>

std::vector<int> generateVector(int size)
{
    std::vector<int> numbers;
    numbers.reserve(size);
    for (int i = 0; i < size; i++)
    {
        numbers.push_back(std::rand());
    }
    return numbers;
}

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high, int numThreads) {
    std::stack<std::tuple<int, int>> stack;
    stack.push(std::make_tuple(low, high));

    while (!stack.empty()) {
        std::tie(low, high) = stack.top();
        stack.pop();

        if (low < high) {
            int pi = partition(arr, low, high);

            if (numThreads == 1) {
               
                stack.push(std::make_tuple(low, pi - 1));
                stack.push(std::make_tuple(pi + 1, high));
            }
            else {
                
                if (numThreads > 1) {
                    std::vector<std::thread> threads;

                    for (int i = 0; i < numThreads; ++i) {
                        int threadLow = low + i * (high - low) / numThreads;
                        int threadHigh = low + (i + 1) * (high - low) / numThreads - 1;
                        threads.emplace_back(quickSort, std::ref(arr), threadLow, threadHigh, 1);
                    }

                    for (auto& thread : threads) {
                        thread.join();
                    }
                }
            }
        }
    }
}

void printVector(const std::vector<int>& arr) { //for cheking sort function
    for (const auto& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main()
{
    const int SIZE = 100;
    std::vector<int> numbers1 = generateVector(SIZE);

    //std::cout << "Original array: "; //for cheking sort function
    //printVector(numbers1);

    const int numThreads = 24;

    auto beg = std::chrono::high_resolution_clock::now();  
    quickSort(numbers1, 0, numbers1.size() - 1, numThreads);
    auto end = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - beg);
    std::cout << "Sorting arrays in " << numThreads << " threads: " << duration.count() << " microseconds" << std::endl;

    /*std::cout << "Sorted array: "; //for cheking sort function
    printVector(numbers1);*/ 
}
