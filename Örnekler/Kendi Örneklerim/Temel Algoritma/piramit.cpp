#include <iostream>

int main() {
    int N;
    std::cout << "Boyut giriniz (N): ";
    std::cin >> N;

    // i satırları, j ise sütunları temsil eder
    for (int i = 1; i <= N; i++) {
        
        // --- 1. KISIM: DİK ÜÇGEN ---
        // Üçgende her satırda, satır numarası kadar yıldız basılır
        for (int j = 1; j <= i; j++) {
            std::cout << "*";
        }

        // Üçgen ile kare arasındaki boşluğu ayarlama
        // Sol üçgen bittikten sonra satırın sonuna kadar boşluk bırakıyoruz
        for (int j = i + 1; j <= N; j++) {
            std::cout << " ";
        }

        // İki şekil karışmasın diye araya fazladan 1 sabit boşluk
        std::cout << " ";

        // --- 2. KISIM: İÇİ BOŞ KARE ---
        // Karenin koordinatları için ayrı bir döngü
        for (int j = 1; j <= N; j++) {
            // Şartlar: İlk satır, son satır, ilk sütun veya son sütun ise yıldız bas
            if (i == 1 || i == N || j == 1 || j == N) {
                std::cout << "*";
            } else {
                std::cout << " "; // İç kısımlar boş kalır
            }
        }

        // Bir satır bittiğinde alt satıra geç
        std::cout << std::endl;
    }

    return 0;
}