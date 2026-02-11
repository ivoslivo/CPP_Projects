#include <iostream>
using namespace std;

void commandList();
int sumArray(int arr[], int n);
double averageArray(int arr[], int n);
double findMedian(int arr[], int n);
int findSecondLargest(int arr[], int n);
int countOccurrences(int arr[], int n, int value);
void sortArray(int arr[], int n);

int main() {

    int n;
    int input = 0;
    int arr[100];
    cout << "Enter N: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid input" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    do {
        commandList();
        cin >> input;

        switch (input) {
            case 1:
                cout << "The sum is: " << sumArray(arr, n) << endl;
                break;
            case 2:
                cout << "The average is: " << averageArray(arr, n) << endl;
                break;
            case 3:
                cout << "Find median " << findMedian(arr, n) << endl;
                break;
            case 4:
                cout << "Second largest: " << findSecondLargest(arr, n) << endl;
                break;
            case 5: {       //use {} because of a value's init
                int value;
                cin >> value;
                cout << value << " occurrence is " << countOccurrences(arr, n, value) << endl;
                break;
            }
            case 0:
                break;
            default:
                cout << "Invalid input" << endl;
        }
    }while (input != 0);

    return 0;
}
void commandList() {
    cout << "1. Sum array" << endl;
    cout << "2. Average in the array" << endl;
    cout << "3. Find median" << endl;
    cout << "4. Find second largest" << endl;
    cout << "5. Count occurrence" << endl;
    cout << "0. Exit" << endl;
}
int sumArray(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}
double averageArray(int arr[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
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

double findMedian(int arr[], int n) {

    sortArray(arr, n);
    if (n % 2 == 1) {
        return arr[n/2];
    }
    return (arr[n/2 - 1] + arr[n/2]) / 2.0;
}

int findSecondLargest(int arr[], int n) {
    int temp;
    int largest = arr[0];
    int secondLargest = arr[1];

    if (n < 2) {
        cout << "You need at least two elements" << endl;
        return arr[0];
    }
    if (secondLargest > largest) {
        temp = largest;
        largest = secondLargest;
        secondLargest = temp;
    }

    for (int i = 2; i < n; i++) {
        if (arr[i] > largest) {
            temp = largest;
            largest = arr[i];
            secondLargest = temp;
        }
        else if (arr[i] >= secondLargest && arr[i] < largest) {
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}
int countOccurrences(int arr[], int n, int value) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            count++;
        }
    }
    return count;
}
