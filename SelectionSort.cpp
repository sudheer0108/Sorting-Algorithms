/* Selection sort : it is an inplace algorithm means it does not uses extra space.
complexity : O(N^2)*/

#include <iostream>
using namespace std;

void selectionSort(int A[], int n)
{
    int min_id;
    for (int i = 0; i < n - 1; i++)
    {
        min_id = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[min_id])
            {
                min_id = j;
            }
        }
        swap(A[i], A[min_id]);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    selectionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "";
}