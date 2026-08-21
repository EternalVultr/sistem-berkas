import matplotlib.pyplot as plt

def visualize_clook(sequence, initial_head, distances):
    # Menambahkan posisi awal ke dalam urutan untuk grafik
    full_sequence = [initial_head] + sequence
    steps = list(range(len(full_sequence)))

    plt.figure(figsize=(12, 7))
    
    # Plot pergerakan head
    plt.plot(full_sequence, steps, marker='o', color='royalblue', linestyle='-', linewidth=2, markersize=8)
    
    # Membalik sumbu Y (langkah 0 di atas)
    plt.gca().invert_yaxis()
    
    plt.title("Visualisasi Pergerakan Head Disk (C-LOOK)", fontsize=14)
    plt.xlabel("Nomor Track", fontsize=12)
    plt.ylabel("Langkah Urutan", fontsize=12)
    plt.grid(True, linestyle='--', alpha=0.7)

    # Menambahkan label angka track dan jarak tempuh pada titik
    for i, txt in enumerate(full_sequence):
        label = f"T:{txt}"
        if i > 0:
            label += f" (+{distances[i-1]})"
        plt.annotate(label, (full_sequence[i], steps[i]), textcoords="offset points", xytext=(5,5), fontsize=9)

    plt.tight_layout()
    plt.show()

def clook_with_details():
    print("=== Simulasi C-LOOK: Perhitungan Track Detail ===")
    
    try:
        line = input("Masukkan antrean track (pisahkan dengan koma, misal: 86, 147, 91, 177, 94, 150, 102, 47, 13): ")
        tracks = [int(x.strip()) for x in line.split(",")]
        head = int(input("Masukkan posisi awal Head: "))
        print("Pilih arah: 1. Kiri (Mengecil) | 2. Kanan (Membesar)")
        choice = input("Pilihan (1/2): ")
        direction = "kiri" if choice == "1" else "kanan"
    except ValueError:
        print("Error: Input tidak valid!")
        return

    left = sorted([x for x in tracks if x < head])
    right = sorted([x for x in tracks if x > head])
    
    seek_sequence = []
    step_distances = []
    total_seek = 0
    current_pos = head

    print("\n--- Rincian Pergerakan ---")

    if direction == "kiri":
        # Melayani arah kiri (menurun) [cite: 11]
        for track in reversed(left):
            dist = abs(track - current_pos)
            step_distances.append(dist)
            seek_sequence.append(track)
            print(f"Dari {current_pos} ke {track} = {dist} track")
            total_seek += dist
            current_pos = track
        
        # Lompatan C-LOOK ke track terbesar [cite: 5, 12, 30]
        if right:
            jump_dist = abs(current_pos - right[-1])
            step_distances.append(jump_dist)
            current_pos = right[-1]
            print(f">> LOMPATAN C-LOOK ke {current_pos} = {jump_dist} track")
            total_seek += jump_dist
            
            # Melayani sisa track di kanan (tetap arah kiri)
            for track in reversed(right):
                dist = abs(track - current_pos)
                step_distances.append(dist)
                seek_sequence.append(track)
                print(f"Dari {current_pos} ke {track} = {dist} track")
                total_seek += dist
                current_pos = track

    else: # Arah Kanan
        for track in right:
            dist = abs(track - current_pos)
            step_distances.append(dist)
            seek_sequence.append(track)
            print(f"Dari {current_pos} ke {track} = {dist} track")
            total_seek += dist
            current_pos = track
            
        if left:
            jump_dist = abs(current_pos - left[0])
            step_distances.append(jump_dist)
            current_pos = left[0]
            print(f">> LOMPATAN C-LOOK ke {current_pos} = {jump_dist} track")
            total_seek += jump_dist
            
            for track in left:
                dist = abs(track - current_pos)
                step_distances.append(dist)
                seek_sequence.append(track)
                print(f"Dari {current_pos} ke {track} = {dist} track")
                total_seek += dist
                current_pos = track

    print("-" * 30)
    print(f"TOTAL JARAK SEEK: {total_seek} track")
    print("-" * 30)

    visualize_clook(seek_sequence, head, step_distances)

if __name__ == "__main__":
    clook_with_details()