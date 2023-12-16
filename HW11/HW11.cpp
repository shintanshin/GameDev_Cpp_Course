#include <iostream>
constexpr unsigned int ROWS = 4;
constexpr unsigned int COLUMNS = 6;

bool find(int arr_2d[ROWS][COLUMNS], int toFind) {
    for (unsigned int i = 0; i < ROWS; i++) {
        for (unsigned int j = 0; j < COLUMNS; j++) {
            if (arr_2d[i][j] == toFind) {
                return true;
            }
        }
    }
    return false;
}
enum class SortingDirection
{
    Ascending,
    Descending
};
bool isSorted(const int* arr, int size, SortingDirection direction) {
    if (size <= 1) {return true;}
    for (int i = 1; i < size; i++) {
        if ((direction == SortingDirection::Ascending && arr[i - 1] > arr[i]) ||
            (direction == SortingDirection::Descending && arr[i - 1] < arr[i])) {
            return false;
        }
    }
    return true;
}
void traverseTopDownRightLeftByColumns(int arr_2d[ROWS][COLUMNS])
{
    for (int i = COLUMNS - 1; i >= 0; i--) {
        for (int j = 0; j < ROWS; j++) {
            std::cout << arr_2d[j][i]<< " ";
        }
        std::cout << std::endl;
    }
}
void traverseLeftRightDownTopSwitchingByRows(int arr_2d[ROWS][COLUMNS])
{
    for (int i = ROWS - 1; i >= 0; i--) {
        if ((ROWS - 1 - i) % 2 == 0) {
            for (int j = 0; j < COLUMNS; j++) {
                std::cout << arr_2d[i][j] << " ";
            }
        }
        else {
            for (int j = COLUMNS - 1; j >= 0; j--) {
                std::cout << arr_2d[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}



int main()
{
    int arr_2d[ROWS][COLUMNS] = {
      {11, 12, 13, 14, 15, 16 },
      {21, 22, 23, 24, 25, 26 },
      {31, 32, 33, 34, 35, 36 },
      {41, 42, 43, 44, 45, 46 }
    };

    std::cout<<find(arr_2d, 41)<<std::endl;

    const int size = 5;
    int arr_asc[size] = { 1, 2, 3, 4, 5 };
    int arr_desc[size] = { 5, 4, 3, 2, 1 };
    int arr_unsorted[size] = { 2, 1, 3, 5, 4 };
    std::cout << isSorted(arr_desc, size, SortingDirection::Descending) << std::endl;
  
    traverseTopDownRightLeftByColumns(arr_2d);
    std::cout << std::endl;
    traverseLeftRightDownTopSwitchingByRows(arr_2d);
}
