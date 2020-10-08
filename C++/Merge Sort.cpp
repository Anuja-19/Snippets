#include <bits/stdc++.h>
using namespace std;
void merge(int *arr, int *left, int lsize, int *right, int rsize)
{
    int i = 0, j = 0, k = 0;
    while (i < lsize && j < rsize)
    {
        if (left[i] < right[j])
        {
            arr[k] = left[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = right[j];
            k++;
            j++;
        }
    }
    while (i < lsize)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < rsize)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}
void mergesort(int *arr, int size)
{
    int mid, i, *left, *right;
    if (size < 2)
        return;
    mid = size / 2;
    left = new int[mid];
    right = new int[size - mid];
    for (i = 0; i < mid; i++)
    {
        left[i] = arr[i];
    }
    for (i = mid; i < size; i++)
    {
        right[i - mid] = arr[i];
    }
    mergesort(left, mid);
    mergesort(right, size - mid);
    merge(arr, left, mid, right, size - mid);
    free(left);
    free(right);
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
    mergesort(arr, size);
    cout << "\n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}