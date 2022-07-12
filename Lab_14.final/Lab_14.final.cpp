// Lab_14.final.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

template<class Class>
void sorting(Class arr[], int size) 
{
    int j = 0;
    for (int i = 0; i < size; i++) 
    {
        int x = arr[i];
        for (j = i - 1; j >= 0 && x < arr[j]; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = x;
    }
}

int main()
{
    int arr[] = { 88,1,32,24,7,6 };
    char arrchar[] = "ffffffffggggggggaaaaaaaa";
    double arrdouble[] = { 1.1, 5.2,0.7,8.4,9.3,3.33 };
    int k1 = sizeof(arr) / sizeof(arr[0]);
    int k2 = sizeof(arrdouble) / sizeof(arrdouble[0]);
    int k3 = sizeof(arrchar) / sizeof(arrchar[0]) - 1;
    sorting(arr, k1);
    for (int i = 0; i < k1; i++) cout << arr[i] << ";";
    cout << endl;
    sorting(arrdouble, k2);
    for (int i = 0; i < k2; i++) cout << arrdouble[i] << ";";
    cout << endl;
    sorting(arrchar, k3);
    for (int i = 0; i < k3; i++) cout << arrchar[i] << ";";
    cout << endl;
}