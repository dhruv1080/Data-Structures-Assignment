// Dhruv agrawal
// 21105070
// ECE

#include <iostream>
using namespace std;

/*
QUESTION:How would you search for an element in an array/list whose size is unknown?
SOLUTION: We can search an element in an array whose size is unknown in O(logn) time complexity provided that the array is in sorted order (here i am taking case of ascending order).We can do this by making some modification in binary search technique.
The concept behind this approach is:
  ->Take inital value of i as 0 and j as 1.
  ->Now increase j to j*2 until arr[j] exceed the key to be searched.
  ->Now search the key using binary search between i and j.
*/

int binary_search(int arr[], int i, int j, int key)
{
    int bs = (i + j) / 2;
    while (i <= j)
    {
        if (arr[bs] == key)
        {
            return bs;
        }
        else
        {
            if (arr[bs] < key)
            {
                i = bs + 1;
            }
            else
            {
                j = bs - 1;
            }
        }
        bs = (i + j) / 2;
    }
    return -1;
}
int binary_search_unknown(int arr[], int key)
{
    int i = 0, j = 1;
    while (arr[j] < key)
    {
        i = j;
        j = 2 * j;
    }
    return binary_search(arr, i, j, key);
}
