#include <iostream>
#include <vector>

using namespace std;

void binarySearch(const vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    int probes = 0;
    bool found = false;

    while (low <= high) {
        probes++; // Menghitung setiap kali perbandingan dilakukan
        int mid = low + (high - low) / 2;

        cout << "Low: " << low << ", High: " << high << ", Mid: " << mid << endl;
        cout << "Comparing: add[" << mid << "] (" << arr[mid] << ") with " << target << endl;

        if (arr[mid] == target) {
            cout << "Element found at index: " << mid << endl;
            found = true;
            break;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (!found) {
        cout << "Element not found." << endl;
    }
    cout << "Total probes: " << probes << endl;
}

int main() {
    int n, target;

    cout << "Enter the number of elements in the add: ";
    cin >> n;

    vector<int> data(n);
    cout << "Enter " << n << " sorted key:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    cout << "Enter the key to search for: ";
    cin >> target;

    binarySearch(data, target);

    return 0;
}