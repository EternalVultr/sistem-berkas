#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Menggunakan konstanta untuk ukuran array agar lebih aman
const int SIZE = 8; 

void FCFS(int arr[], int head)
{
    int seek_count = 0;
    int distance, cur_track;

    for(int i = 0; i < SIZE; i++) {
        cur_track = arr[i];

        // Hitung jarak absolut antara head saat ini dan track tujuan
        distance = abs(cur_track - head);

        // Tambahkan ke total seek count
        seek_count += distance;

        // Head berpindah ke track yang baru saja diakses
        head = cur_track;
    }

    cout << "Total number of seek operations = " << seek_count << endl;

    // Menampilkan urutan pencarian (Seek Sequence)
    cout << "Seek Sequence is: " << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << (i == SIZE - 1 ? "" : " -> ");
    }
    cout << endl;
}

int main()
{
    // Request array (tadi kurang titik koma di sini)
    int arr[SIZE] = {176, 79, 34, 60, 92, 11, 41, 114};
    int head = 50;

    FCFS(arr, head);

    return 0;
}