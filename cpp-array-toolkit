#include <iostream>
using namespace std;

void printConsole();
void printArray(int arr[], int n);
int removeDuplicates(int arr[], int n);
void swapAdjacentElements(int arr[], int n);
void reverseArray(int arr[], int n);
void pushZeros(int arr[], int n);
void sortArray(int arr[], int n);
void minMax(int arr[], int n);

int main() {

    int n;
    int input = 0;
    int arr[100];
    cout << "Enter N: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    do {
        printConsole();
        cin >> input;

        switch (input) {
            case 1:
                //remove duplicates
                n = removeDuplicates(arr, n);
                printArray(arr, n);
                cout << endl;
                break;
            case 2:
                //swap adjacent elements
                swapAdjacentElements(arr, n);
                printArray(arr, n);
                cout << endl;
                break;
            case 3:
                //reverse the array
                reverseArray(arr, n);
                printArray(arr, n);
                cout << endl;
                break;
            case 4:
                //push zeros to the back
                pushZeros(arr, n);
                printArray(arr, n);
                cout << endl;
                break;
            case 5:
                sortArray(arr, n);
                printArray(arr, n);
                break;
            case 6:
                minMax(arr, n);
                break;
            case 0:
                break;
            default:
                cout << "Invalid input" << endl;
        }
    } while (input != 0);

    return 0;
}
void printConsole() {
    cout << "1. Remove duplicates" << endl;
    cout << "2. Swap adjacent elements" << endl;
    cout << "3. Reverse array" << endl;
    cout << "4. Push zeros to the back" << endl;
    cout << "5. Sort array" << endl;
    cout << "6. Find min and max" << endl;
    cout << "0. Exit" << endl;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int removeDuplicates(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < n - 1; k++) {   //shift left
                    arr[k] = arr[k + 1];
                }
                j--;
                n--;
            }
        }
    }
    return n;
}

void swapAdjacentElements(int arr[], int n) {
    int temp;

    for (int i = 0; i < n - 1; i+=2) {
        temp = arr[i + 1];
        arr[i + 1] = arr[i];
        arr[i] = temp;
    }
}

void reverseArray(int arr[], int n) {
    int *start = &arr[0];
    int *end = &arr[n - 1];
    int temp;

    while (start < end) {

        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}
void pushZeros(int arr[], int n) {
    bool hasZeros = false;
    int write = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            hasZeros = true;
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[write] = arr[i];
            write++;
        }
    }
    for (int i = write; i < n; i++) {
        arr[i] = 0;
    }
}
void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void minMax(int arr[], int n) {
    int min = arr[0];
    int max = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    cout << min << " " << max << endl;
}
