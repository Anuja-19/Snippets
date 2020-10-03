#include <bits/stdc++.h>

using namespace std;

int partition(int *arr, int start, int end)
{
    int pivot = arr[end];
    int startIndex = start;
    for (int i = start; i <= end - 1; i++)
    {
        if (arr[i] <= pivot)
        {
            swap(arr[i], arr[startIndex]);
            startIndex = startIndex + 1;
        }
    }
    swap(arr[startIndex], arr[end]);
    return startIndex;
}
void quicksort(int *arr, int start, int end)
{
    int mid;
    if (start < end)
    {
        mid = partition(arr, start, end);
        quicksort(arr, start, mid - 1);
        quicksort(arr, mid + 1, end);
    }
}
int main()
{
    int size;
    cin >> size;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    quicksort(arr, 0, size - 1);
    cout << "\n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
    }
}