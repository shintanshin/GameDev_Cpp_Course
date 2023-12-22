#include <iostream>
#include <algorithm>

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i <size - 1; ++i) {
        for (int j = 0; j <size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

constexpr unsigned int ROWS = 5;
constexpr unsigned int COLUMNS = 6;
enum class SortingDirection
{
    ByRows,
    ByColumns
};
void sort(int arr[ROWS][COLUMNS], SortingDirection direction) {
    if (direction == SortingDirection::ByRows) {
        for (int i = 0; i < ROWS; ++i) {
            bubbleSort(arr[i], COLUMNS);
        }
    }
    else if (direction == SortingDirection::ByColumns) {
        for (int j = 0; j < COLUMNS; ++j) {
            int column[ROWS];
            for (int i = 0; i < ROWS; ++i) {
                column[i] = arr[i][j];
            }
            bubbleSort(column, ROWS);
            for (int i = 0; i < ROWS; ++i) {
                arr[i][j] = column[i];
            }
        }
    }
}
void printArray(int arr[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
int main()
{
        int arr[] = { 5, 1, 9, 7, 3 };
        int size = sizeof(arr) / sizeof(arr[0]);
        std::cout << "Input: ";
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
            }
        std::cout << std::endl;
        bubbleSort(arr, size);
        std::cout << "Output: ";
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;

        int arr2[ROWS][COLUMNS] = { {1, 5, 4, 11, 7, 9},
                                   {3, 8, 6, -1, 24, 0},
                                   {9, 5, 1, 0, 6, 3},
                                   {1, 2, 3, 4 ,5, -11},
                                   {7, 9, 0, -2, 45},};
        std::cout << "Input (By Rows):\n";
        printArray(arr2);
        sort(arr2, SortingDirection::ByRows);
        std::cout << "\nOutput (Sorted By Rows):\n";
        printArray(arr2);
        std::cout << "\nInput (By Columns):\n";
        printArray(arr2);
        sort(arr2, SortingDirection::ByColumns);
        std::cout << "\nOutput (Sorted By Columns):\n";
        printArray(arr2);

}
