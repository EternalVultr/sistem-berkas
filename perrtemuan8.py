import matplotlib.pyplot as plt

def plot_fcfs(initial_head, requests):
    # Gabungkan posisi awal dengan urutan permintaan
    path = [initial_head] + requests
    
    # Menghitung Total Head Movement
    total_movement = 0
    for i in range(len(path) - 1):
        total_movement += abs(path[i+1] - path[i])
    
    # Menentukan urutan langkah (0, 1, 2, ...) untuk sumbu Y
    steps = list(range(len(path)))

    plt.figure(figsize=(10, 6))
    
    # Plot garis pergerakan
    plt.plot(path, steps, marker='o', linestyle='-', color='b', linewidth=2, markersize=8)
    
    # Membalikkan sumbu Y agar langkah 0 berada di paling atas
    plt.gca().invert_yaxis()
    
    # Memberi label pada setiap titik koordinat
    for i, txt in enumerate(path):
        plt.annotate(txt, (path[i], steps[i]), textcoords="offset points", xytext=(0,10), ha='center')

    # Pengaturan judul dan label
    plt.title(f"Grafik Disk Scheduling - FCFS\nTotal Head Movement: {total_movement} Cylinders", fontsize=14)
    plt.xlabel("Posisi Silinder", fontsize=12)
    plt.ylabel("Urutan Permintaan (Waktu)", fontsize=12)
    plt.grid(True, linestyle='--', alpha=0.6)
    
    print(f"\nTotal Head Movement: {total_movement}")
    print("Menampilkan grafik... (Tutup jendela grafik untuk mengakhiri program)")
    plt.show()

if __name__ == "__main__":
    try:
        print("=== Program Simulasi FCFS Disk Scheduling ===")
        
        # Input deretan permintaan
        raw_input = input("Masukkan urutan permintaan (pisahkan dengan spasi, contoh: 16 79 34): ")
        
        # Input posisi awal
        posisi_awal = int(input("Masukkan posisi head awal (contoh: 38): "))
        
        # Mengubah string input menjadi list of integers
        permintaan = [int(x) for x in raw_input.split()]
        
        if not permintaan:
            print("Error: Daftar permintaan tidak boleh kosong!")
        else:
            plot_fcfs(posisi_awal, permintaan)
            
    except ValueError:
        print("Error: Mohon masukkan angka yang valid!")