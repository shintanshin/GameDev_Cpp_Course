#include <iostream>

bool binarySearch(int arr[], int size, int x)
{
    int l = 0;
    int r = size - 1;

    while (l <= r) {
        const int m = l + (r - l) / 2;

        if (arr[m] == x)
            return true;

        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
                         // time complexity for this code is: O(log N) where N = array size
    return false;        // space complexity for this code is: O(1+3*4) where 1 = constant space usage, and 3*4 = quantity of integer variables * int size in bites
}

// Algorithmic complexity of this program including array initialization = O(20*log30)+O((20*30+3)*4)
                         // where O(20*log30) - time complexity
                         // O((20*30+3+1)*4) - space complexity where 1 = integer i and 3 = quantity of integer variables using by binarySearch function
//int main()
//{
//    const int ROWS = 20;
//    const int COLUMNS = 30;
//    int arr[ROWS][COLUMNS] = {};
//    const int toFind = 0;
//
//    //...
//    //Code to setup array and value to find 
//    //in one way or another
//    //..
//
//    for (int i = 0; i < ROWS; i++)
//    {
//        if (binarySearch(arr[i], COLUMNS, toFind))
//        {
//            std::cout << "FOUND";
//            break;
//        }
//    }
//}