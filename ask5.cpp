#include <iostream>

using namespace std;

void bubbleSort(int* array, int n)
{
    int temp;
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(array[j] > array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}


int main()
{
    int n;
    cout << "How many numbers? " << endl;
    cin >> n;
    int *table = new int[n];
    cout << "Give " << n << " numbers " << endl;

    for(int i=0; i<n; i++)
    {
        cin >> table[i];
    }
    cout << "\n";
    bubbleSort(table, n);

    for (int i=0; i<n; i++)
    {
        cout << table[i] << endl;
    }

    delete[] table;
    return 0;
}