#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 10000

int nCompare = 0, nSwap = 0;
void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
    nSwap++;
}
int partition(int arr[], int start, int end)
{
    int pivot = arr[end], l = start - 1;
    for (int i = start; i < end; i++)
    {
        if (arr[i] <= pivot)
        {
            l++;
            swap(arr[i], arr[l]);
        }
        nCompare++;
    }
    l++;
    nSwap++;
    arr[end] = arr[l];
    arr[l] = pivot;
    return l;
}
void quickSort(int arr[], int start, int end)
{
    nCompare++;
    if (start < end)
    {
        // int pid = start + rand() % (end - start + 1);
        // swap(arr[end], arr[pid]);
        /*in normal quicksort above two step not required*/
        int mid = partition(arr, start, end);
        quickSort(arr, start, mid - 1);
        quickSort(arr, mid + 1, end);
    }
}
void printAns()
{
    cout << "\nCompare=" << nCompare << " ;; Swap=" << nSwap << "\n";
}
void solve(int arr[], int len)
{
    nCompare = 0;
    nSwap = 0;
    quickSort(arr, 0, len - 1);
    printAns();
}

int main()
{
    int arr1[] = {9, 8, 7, 6, 5, 4, 3, 2, 1},
        arr2[] = {10, 32, -3, 4, 5, 46, 7, 81, 9},
        arr3[] = {100, -5, 73, -645, 93, 18, -85, 186, 26, -35},
        arr4[] = {118, 789, -456, 354, 654, 12, 39, -85, 46, 234};

    int arr5[MAX_SIZE], arr6[MAX_SIZE], arr7[MAX_SIZE];

    for (int i = 0; i < MAX_SIZE; i++)
    {
        arr6[MAX_SIZE - i - 1] = arr5[i] = i + 150;
        arr7[i] = rand();
    }

    solve(arr1, sizeof(arr1) / sizeof(arr1[0]));
    solve(arr2, sizeof(arr2) / sizeof(arr2[0]));
    solve(arr3, sizeof(arr3) / sizeof(arr3[0]));
    solve(arr4, sizeof(arr4) / sizeof(arr4[0]));
    solve(arr5, sizeof(arr5) / sizeof(arr5[0]));
    solve(arr6, sizeof(arr6) / sizeof(arr6[0]));
    solve(arr7, sizeof(arr7) / sizeof(arr7[0]));

    return 0;
}
