#include <stdio.h>

// Fungsi pencarian interpolasi
int interpolationSearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int probes = 0; // Menghitung jumlah probe

    // Loop pencarian selama target berada dalam rentang low dan high
    while (low <= high && x >= arr[low] && x <= arr[high]) {
        
        // Menghindari pembagian dengan nol
        if (arr[high] == arr[low]) {
            if (arr[low] == x) {
                printf("Element found at index: %d\n", low);
                printf("Total probes: %d\n", probes + 1);
                return low;
            }
            return -1;
        }

        // Menghitung posisi perkiraan menggunakan rumus interpolasi
        int pos = low + ((double)(high - low) / (arr[high] - arr[low]) * (x - arr[low]));
        
        probes++; // Increment jumlah probe
        printf("Low: %d, High: %d, Position: %d\n", low, high, pos);
        printf("Comparing: arr[%d] (%d) with %d\n", pos, arr[pos], x);

        // Jika elemen ditemukan
        if (arr[pos] == x) {
            printf("Element found at index: %d\n", pos);
            printf("Total probes: %d\n", probes);
            return pos;
        }

        // Jika elemen lebih besar, cari di sebelah kanan
        if (arr[pos] < x) {
            low = pos + 1;
        }
        // Jika elemen lebih kecil, cari di sebelah kiri
        else {
            high = pos - 1;
        }
    }

    printf("Element not found.\n");
    printf("Total probes: %d\n", probes);
    return -1; // Jika elemen tidak ditemukan
}

int main() {
    int n;
    // Input ukuran array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    // Input elemen array (harus terurut)
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int x;
    // Input elemen yang ingin dicari
    printf("Enter the element to search for: ");
    scanf("%d", &x);

    // Panggil fungsi pencarian
    interpolationSearch(arr, n, x);

    return 0;
}