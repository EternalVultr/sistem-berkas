#include <bits/stdc++.h>
using namespace std;

void SCAN(vector<int> arr, int head, string direction, int disk_size) {
    int seek_count = 0;
    int distance, cur_track;
    vector<int> left, right;
    vector<int> seek_sequence;

    // Tambahkan batas ujung disk sesuai algoritma SCAN [cite: 63, 65, 66]
    if (direction == "kiri") left.push_back(0);
    else if (direction == "kanan") right.push_back(disk_size - 1);

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < head) left.push_back(arr[i]);
        if (arr[i] > head) right.push_back(arr[i]);
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int run = 2;
    while (run--) {
        if (direction == "kiri") {
            for (int i = left.size() - 1; i >= 0; i--) {
                cur_track = left[i];
                seek_sequence.push_back(cur_track);
                distance = abs(cur_track - head);
                seek_count += distance;
                head = cur_track;
            }
            direction = "kanan";
        }
        else if (direction == "kanan") {
            for (int i = 0; i < right.size(); i++) {
                cur_track = right[i];
                seek_sequence.push_back(cur_track);
                distance = abs(cur_track - head);
                seek_count += distance;
                head = cur_track;
            }
            direction = "kiri";
        }
    }

    cout << "\n===============================" << endl;
    cout << "Total Seek: " << seek_count << endl;
    cout << "Sequence: ";
    for (int i = 0; i < seek_sequence.size(); i++) {
        cout << seek_sequence[i] << (i == seek_sequence.size() - 1 ? "" : " -> ");
    }
    cout << "\n===============================" << endl;
}

int main() {
    int head, disk_size = 200;
    string direction, line;
    vector<int> requests;

    cout << "Masukkan posisi awal kepala disk: ";
    cin >> head;
    cin.ignore(); // Membersihkan buffer

    cout << "Masukkan track permintaan (pisahkan dengan spasi): ";
    getline(cin, line);
    stringstream ss(line);
    int temp;
    while (ss >> temp) requests.push_back(temp);

    cout << "Masukkan arah gerak (kanan/kiri): ";
    cin >> direction;

    SCAN(requests, head, direction, disk_size);

    return 0;
}