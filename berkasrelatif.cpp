#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // untuk std::setw

class HashTable {
private:
    int size; 
    std::vector<std::string> table; 

public:
    HashTable(int s) : size(s) {
        table.resize(size); 
    }

    int hashFunction(int key) {
        // Tetap menggunakan logika Anda: (key % size + 1) % size
        return (key % size + 1) % size; 
    }

    void insert(int key) {
        int index = hashFunction(key);
        
        // Linear probing jika terjadi tabrakan
        int originalIndex = index;
        while (!table[index].empty()) {
            index = (index + 1) % size;
            // Mencegah loop tak terbatas jika tabel penuh
            if (index == originalIndex) {
                std::cout << "Tabel penuh! Tidak bisa memasukkan: " << key << std::endl;
                return;
            }
        }
        table[index] = std::to_string(key);
    }

    void display() {
        std::cout << std::setw(10) << "Index" << std::setw(15) << "Key" << std::endl;
        std::cout << std::string(25, '-') << std::endl; 
        for (int i = 0; i < size; ++i) {
            std::cout << std::setw(10) << i 
                      << std::setw(15) << (table[i].empty() ? "-" : table[i]) 
                      << std::endl;
        }
    }
};

int main() {
    int tableSize, n, key;

    // Input dinamis untuk ukuran tabel
    std::cout << "Masukkan ukuran tabel hash: ";
    std::cin >> tableSize;
    HashTable hashTable(tableSize);

    // Input dinamis untuk jumlah data
    std::cout << "Masukkan jumlah kunci yang akan dimasukkan: ";
    std::cin >> n;

    // Input data kunci
    for (int i = 0; i < n; ++i) {
        std::cout << "Masukkan kunci ke-" << i + 1 << ": ";
        std::cin >> key;
        hashTable.insert(key);
    }

    // Tampilkan hasil
    std::cout << "\nHash Table Content:\n";
    hashTable.display();

    return 0;
}