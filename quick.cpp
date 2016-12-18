#include <iostream>

using namespace std;


int part(int *arr, int left, int right) {
    int pivot = arr[right];

    int i = left;
    int j = right;

    while(i <= j) {
        while ( arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
       // cout << " j: " << j << endl;
    }
    return j;
}

void  quick(int *arr, int left, int right) {
    if ( left >= right) { 
        return;
    }

    int partition = part(arr, left, right);

    quick(arr, left, partition);
    quick(arr, partition+1, right);
}

using namespace std;

int main() {
    int hello[] = {3, 0, 1, 8, 7 , 2, 5, 4, 9 ,6};

    quick(hello, 0, 4);

    for (int i = 0; i < 9; i++) {
        cout << hello[i] << endl;
    }
}