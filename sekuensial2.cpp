#include <stdio.h>

/**
 * Fungsi Binary Search yang diperbaiki.
 * Menggunakan const untuk array agar data asli tidak berubah secara tidak sengaja.
 */
int binarySearch(const int arr[], int n, int x) {
    int low = 0;
    int high = n - 1;
    int probes = 0;

    // Tambahan: Cek jika array kosong untuk menghindari error logika
    if (n <= 0) return -1;

    while (low <= high) {
        probes++;
        
        /* * Penggunaan low + (high - low) / 2 sudah benar untuk mencegah integer overflow 
         * dibandingkan dengan (low + high) / 2.
         */
        int mid = low + (high - low) / 2;

        printf("Iterasi ke-%d -> Low: %d, High: %d, Mid: %d | Membandingkan: arr[%d] (%d) dengan %d\n", 
                probes, low, high, mid, mid, arr[mid], x);

        if (arr[mid] == x) {
            printf("--- Hasil: Elemen ditemukan pada indeks %d ---\n", mid);
            printf("Total probes: %d\n", probes);
            return mid;
        }

        if (arr[mid] > x) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("--- Hasil: Elemen tidak ditemukan ---\n");
    printf("Total probes: %d\n", probes);
    return -1;
}

int main() {
    // Array harus dalam keadaan terurut agar Binary Search bekerja
    int data[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(data) / sizeof(data[0]);
    int target = 17;

    printf("Mencari angka %d dalam array...\n", target);
    binarySearch(data, n, target);

    return 0;
}