#include <iostream>
using namespace std;
void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Insertion at the beginning\n";
    cout << "2. Insertion at the end\n";
    cout << "3. Insertion at a specific location\n";
    cout << "4. Deletion from the beginning\n";
    cout << "5. Deletion from the end\n";
    cout << "6. Deletion from a specific location\n";
    cout << "7. Traverse the array\n";
    cout << "8. Merge with another array\n";
    cout << "9. Sort the array\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}
void displayArray(int arr[], int size) {
    cout << "Array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void insertAtBeginning(int arr[], int &size, int element) {
    for (int i = size - 1; i >= 0; --i) {
        arr[i + 1] = arr[i];
    }
    arr[0] = element;
    ++size;
}
void insertAtEnd(int arr[], int &size, int element) {
    arr[size] = element;
    ++size;
}
void insertAtLocation(int arr[], int &size, int element, int location) {
    for (int i = size - 1; i >= location; --i) {
        arr[i + 1] = arr[i];
    }
    arr[location] = element;
    ++size;
}
void deleteFromBeginning(int arr[], int &size) {
    if (size > 0) {
        for (int i = 0; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        --size;
    } else {
        cout << "Array is empty. Deletion not possible.\n";
    }
}
void deleteFromEnd(int arr[], int &size) {
    if (size > 0) {
        --size;
    } else {
        cout << "Array is empty. Deletion not possible.\n";
    }
}
void deleteFromLocation(int arr[], int &size, int location) {
    if (size > 0 && location >= 0 && location < size) {
        for (int i = location; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        --size;
    } else {
        cout << "Invalid location. Deletion not possible.\n";
    }
}
void mergeArrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int i = 0, j = 0, k = 0;
    
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }

    while (i < size1) {
        result[k++] = arr1[i++];
    }

    while (j < size2) {
        result[k++] = arr2[j++];
    }
}
void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int size = 0;
    cout << "Enter the size of the array: ";
    cin >> size;
    cout << "Enter elements of the array:\n";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                int element;
                cout << "Enter element to insert at the beginning: ";
                cin >> element;
                insertAtBeginning(arr, size, element);
                break;
            }
            case 2: {
                int element;
                cout << "Enter element to insert at the end: ";
                cin >> element;
                insertAtEnd(arr, size, element);
                break;
            }
            case 3: {
                int element, location;
                cout << "Enter element to insert: ";
                cin >> element;
                cout << "Enter location to insert at: ";
                cin >> location;
                insertAtLocation(arr, size, element, location);
                break;
            }
            case 4:
                deleteFromBeginning(arr, size);
                break;
            case 5:
                deleteFromEnd(arr, size);
                break;
            case 6: {
                int location;
                cout << "Enter location to delete from: ";
                cin >> location;
                deleteFromLocation(arr, size, location);
                break;
            }
            case 7:
                displayArray(arr, size);
                break;
            case 8: {
                int size2;
                cout << "Enter size of the second array: ";
                cin >> size2;

                int arr2[MAX_SIZE];
                cout << "Enter elements of the second array:\n";
                for (int i = 0; i < size2; ++i) {
                    cin >> arr2[i];
                }

                int result[MAX_SIZE * 2]; // Assuming the maximum size
                mergeArrays(arr, size, arr2, size2, result);

                cout << "Arrays merged successfully.\n";
                displayArray(result, size + size2);
                break;
            }
            case 9:
                sortArray(arr, size);
                cout << "Array sorted successfully.\n";
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 0);

    return 0;
}
