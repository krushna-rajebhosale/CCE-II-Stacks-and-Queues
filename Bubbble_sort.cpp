#include <iostream>
using namespace std;

void bubble_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    int a[10];
    cout << "Enter the size of the array: ";
    cin >> n;

    cout << "Enter " << n << " integers in any order: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    bubble_sort(a, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

// PS C:\Users\student\Desktop\Rajebhosale_krushna> cd "c:\Users\student\Desktop\Rajebhosale_krushna\" ; if ($?) { g++ Bubbble_sort.cpp -o Bubbble_sort } ; if ($?) { .\Bubbble_sort }
// Enter the size of the array: 6
// Enter 6 integers in any order:
// 5
// 3
// 6
// 1
// 4
// 2
// Sorted array: 1 2 3 4 5 6