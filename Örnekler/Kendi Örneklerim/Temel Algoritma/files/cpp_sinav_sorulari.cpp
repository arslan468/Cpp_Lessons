/*
╔════════════════════════════════════════════════════════════════════════════╗
║                  C++ SINAVI - PRAKTIK SORU ÖRNEKLERİ                      ║
║                                                                            ║
║  Bu dosya gerçek sınav sorularına benzer problemleri içerir               ║
╚════════════════════════════════════════════════════════════════════════════╝
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

// ╔════════════════════════════════════════════════════════════════════════════╗
// ║                       SORU 1: ASAL SAYI KONTROLÜ                         ║
// ╚════════════════════════════════════════════════════════════════════════════╝

/*
SORU: Verilen bir sayının asal olup olmadığını kontrol eden bir program yazınız.
      Eğer asal ise "Asal", değilse "Asal Degil" yazdırınız.

ÖRNEK:
Giriş: 17
Çıkış: Asal

Giriş: 20
Çıkış: Asal Degil
*/

bool asal_kontrol_q1(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

void soru1() {
    cout << "\n>>> SORU 1: ASAL SAYI KONTROLÜ <<<" << endl;
    int sayi;
    cout << "Bir sayi giriniz: ";
    cin >> sayi;
    
    if (asal_kontrol_q1(sayi)) {
        cout << sayi << " = Asal" << endl;
    } else {
        cout << sayi << " = Asal Degil" << endl;
    }
}

// ╔════════════════════════════════════════════════════════════════════════════╗
// ║              SORU 2: ARMSTRONG SAYI BULMA (1-1000 Arası)                 ║
// ╚════════════════════════════════════════════════════════════════════════════╝

/*
SORU: 1 ile 1000 arasında Armstrong sayıları bulan program yazınız.
      Armstrong sayısı: rakamlarının kuvvetlerinin toplamı = kendisi
      
ÖRNEK:
153 = 1³ + 5³ + 3³
370 = 3³ + 7³ + 0³
*/

void soru2() {
    cout << "\n>>> SORU 2: ARMSTRONG SAYILARI (1-1000) <<<" << endl;
    cout << "1 ile 1000 arasindaki Armstrong sayilari:" << endl;
    
    for (int n = 1; n <= 1000; n++) {
        int orijinal = n;
        int basamak_sayisi = to_string(n).length();
        int toplam = 0;
        
        while (n > 0) {
            int rakam = n % 10;
            toplam += pow(rakam, basamak_sayisi);
            n /= 10;
        }
        
        if (orijinal == toplam) {
            cout << orijinal << " ";
        }
    }
    cout << endl;
}

// ╔════════════════════════════════════════════════════════════════════════════╗
// ║                  SORU 3: FIBONACCI SERİSİ YAZDIRMA                       ║
// ╚════════════════════════════════════════════════════════════════════════════╝

/*
SORU: N. Fibonacci sayısını bulup, seriyi yazdıran program yazınız.
      
ÖRNEK:
N = 8
Seri: 0 1 1 2 3 5 8 13
Sonuc: 13
*/

void soru3() {
    cout << "\n>>> SORU 3: FIBONACCI SERİSİ <<<" << endl;
    int n;
    cout << "Kac tane Fibonacci sayisi istiyor?: ";
    cin >> n;
    
    cout << "Seri: ";
    long long a = 0, b = 1;
    cout << a << " " << b << " ";
    
    for (int i = 2; i < n; i++) {
        long long temp = a + b;
        cout << temp << " ";
        a = b;
        b = temp;
    }
    cout << "\nSonuc: " << b << endl;
}

// ╔════════════════════════════════════════════════════════════════════════════╗
// ║            SORU 4: BASAMAKLARI TERS İŞLEMİ VE KARŞILAŞTIRMA             ║
// ╚════════════════════════════════════════════════════════════════════════════╝

/*
SORU: Girilen bir sayının basamaklarını ters çeviren ve orijinal sayı ile
      karşılaştıran program yazınız.
      
ÖRNEK:
Giriş: 1234
Ters: 4321
Fark: 4321 - 1234 = 3087
*/

void soru4() {
    cout << "\n>>> SORU 4: BASAMAK TERSİ İŞLEMİ <<<" << endl;
    int sayi;
    cout << "Bir sayi giriniz: ";
    cin >> sayi;
    
    int orijinal = sayi;
    int tersi = 0;
    
    while (sayi > 0) {
        tersi = tersi * 10 + sayi % 10;
        sayi /= 10;
    }
    
    cout << "Orijinal: " << orijinal << endl;
    cout << "Tersi: " << tersi << endl;
    cout << "Fark: " << abs(tersi - orijinal) << endl;
    cout << "Palindrom mu? " << (orijinal == tersi ? "EVET" : "HAYIR") << endl;
}

// ╔════════════════════════════════════════════════════════════════════════════╗
// ║                    SORU 5: ASAL ÇARPANLARA AYIRMA                        ║
// ╚════════════════════════════════════════════════════════════════════════════╝

/*
SORU: Verilen bir sayıyı asal çarpanlarına ayıran program yazınız.
      
ÖRNEK:
Giriş: 60
Çıkış: 60 = 2 × 2 × 3 × 5
*/

void soru5() {
    cout << "\n>>> SORU 5: ASAL ÇARPANLARA AYIRMA <<<" << endl;
    int n;
    cout << "Bir sayi giriniz: ";
    cin >> n;
    
    int orijinal = n;
    cout << orijinal << " = ";
    
    vector<int> carpanlar;
    
    // 2 ile böl
    while (n % 2 == 0) {
        carpanlar.push_back(2);
        n /= 2;
    }
    
    // Tek sayılarla böl
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            carpanlar.push_back(i);
            n /= i;
        }
    }
    
    if (n > 1) {
        carpanlar.push_back(n);
    }
    
    for (int i = 0; i < carpanlar.size(); i++) {
        cout << carpanlar[i];
        if (i < carpanlar.size() - 1) cout << " × ";
    }
    cout << endl;
}

// ╔════════════════════════════════════════════════════════════════════════════╗
// ║                     SORU 6: EBOB VE EKOK HESAPLAMA                       ║
// ╚════════════════════════════════════════════════════════════════════════════╝

/*
SORU: İki sayının EBOB ve EKOK'unu bulan program yazınız.
      
ÖRNEK:
Giriş: 12 18
EBOB: 6
EKOK: 36
*/

int ebob_q6(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void soru6() {
    cout << "\n>>> SORU 6: EBOB VE EKOK <<<" << endl;
    int a, b;
    cout << "Birinci sayi: ";
    cin >> a;
    cout << "Ikinci sayi: ";
    cin >> b;
    
    int ebob = ebob_q6(a, b);
    int ekok = (a * b) / ebob;
    
    cout << "EBOB(" << a << ", " << b << ") = " << ebob << endl;
    cout << "EKOK(" << a << ", " << b << ") = " << ekok << endl;
}

// ╔════════════════════════════════════════════════════════════════════════════╗
// ║                     SORU 7: DİZİ SIRALAMASI (BUBBLE SORT)               ║
// ╚════════════════════════════════════════════════════════════════════════════╝

/*
SORU: N elemanlı bir dizini Bubble Sort ile sıralayan program yazınız.
      Kaç tane takas (swap) işlemi yapıldığını da yazdırınız.
      
ÖRNEK:
Giriş: 5 4 3 2 1
Çıkış: 1 2 3 4 5
Takas sayisi: 10
*/

int bubble_sort_q7(int arr[], int n) {
    int swap_count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swap_count++;
            }
        }
    }
    return swap_count;
}

void soru7() {
    cout << "\n>>> SORU 7: BUBBLE SORT <<<" << endl;
    int n;
    cout << "Dizi boyutu: ";
    cin >> n;
    
    int arr[100];
    cout << "Dizinin elemanlarini giriniz: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int swaps = bubble_sort_q7(arr, n);
    
    cout << "Siralanmis dizi: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nTakas sayisi: " << swaps << endl;
}

// ╔════════════════════════════════════════════════════════════════════════════╗
// ║                    SORU 8: LİNEER VE İKİLİ ARAMA                        ║
// ╚════════════════════════════════════════════════════════════════════════════╝

/*
SORU: Verilen bir dizide elemanı bulan Linear Search ve Binary Search
      programını yazınız. Her ikisinin performansını karşılaştırınız.
      
ÖRNEK:
Dizi: 10 20 30 40 50 60
Aranan: 40
Linear: Konum 3 (4 karşılaştırma)
Binary: Konum 3 (2 karşılaştırma)
*/

int linear_search_q8(int arr[], int n, int hedef, int& comp_count) {
    for (int i = 0; i < n; i++) {
        comp_count++;
        if (arr[i] == hedef) return i;
    }
    return -1;
}

int binary_search_q8(int arr[], int n, int hedef, int& comp_count) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
        comp_count++;
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == hedef) {
            return mid;
        } else if (arr[mid] < hedef) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

void soru8() {
    cout << "\n>>> SORU 8: LİNEER VE İKİLİ ARAMA <<<" << endl;
    int n;
    cout << "Dizi boyutu: ";
    cin >> n;
    
    int arr[100];
    cout << "Siralanmis diziyi giriniz: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int hedef;
    cout << "Aranan eleman: ";
    cin >> hedef;
    
    int comp_linear = 0, comp_binary = 0;
    int pos_linear = linear_search_q8(arr, n, hedef, comp_linear);
    int pos_binary = binary_search_q8(arr, n, hedef, comp_binary);
    
    if (pos_linear != -1) {
        cout << "Linear Search: Konum " << pos_linear << " (" << comp_linear << " karsilastirma)" << endl;
    } else {
        cout << "Linear Search: Bulunamadi" << endl;
    }
    
    if (pos_binary != -1) {
        cout << "Binary Search: Konum " << pos_binary << " (" << comp_binary << " karsilastirma)" << endl;
    } else {
        cout << "Binary Search: Bulunamadi" << endl;
    }
}

// ╔════════════════════════════════════════════════════════════════════════════╗
// ║                   SORU 9: PALİNDROM KONTROL (STRING)                     ║
// ╚════════════════════════════════════════════════════════════════════════════╝

/*
SORU: Girilen bir kelimenin palindrom olup olmadığını kontrol eden 
      program yazınız.
      
ÖRNEK:
Giriş: racecar
Çıkış: Palindrom
*/

bool palindrom_q9(string s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

void soru9() {
    cout << "\n>>> SORU 9: PALİNDROM KONTROL <<<" << endl;
    string kelime;
    cout << "Bir kelime giriniz: ";
    cin >> kelime;
    
    if (palindrom_q9(kelime)) {
        cout << "'" << kelime << "' = PALINDROM" << endl;
    } else {
        cout << "'" << kelime << "' = PALINDROM DEGIL" << endl;
    }
}

// ╔════════════════════════════════════════════════════════════════════════════╗
// ║                  SORU 10: MATRIS TÖ OPERASYONLARI                        ║
// ╚════════════════════════════════════════════════════════════════════════════╝

/*
SORU: Verilen bir matrisin:
      a) Köşegen toplamını hesaplayınız
      b) Satır toplamlarını hesaplayınız
      c) Sütun toplamlarını hesaplayınız
*/

void soru10() {
    cout << "\n>>> SORU 10: MATRİS OPERASYONLARI <<<" << endl;
    int n;
    cout << "Matris boyutu (n x n): ";
    cin >> n;
    
    int mat[10][10];
    cout << "Matris elemanlarini giriniz:" << endl;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "[" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
    
    // Köşegen toplamı
    int kosegen = 0;
    for (int i = 0; i < n; i++) {
        kosegen += mat[i][i];
    }
    
    cout << "\nKosegen Toplami: " << kosegen << endl;
    
    // Satır toplamları
    cout << "Satir Toplamlari: ";
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += mat[i][j];
        }
        cout << sum << " ";
    }
    
    // Sütun toplamları
    cout << "\nSutun Toplamlari: ";
    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += mat[i][j];
        }
        cout << sum << " ";
    }
    cout << endl;
}

// ╔════════════════════════════════════════════════════════════════════════════╗
// ║                        MAIN - TEST MENÜSÜ                                ║
// ╚════════════════════════════════════════════════════════════════════════════╝

int main() {
    cout << "\n╔════════════════════════════════════════════════════════════════════════════╗" << endl;
    cout << "║                  C++ SINAVI - PRAKTIK SORU ÖRNEKLERİ                     ║" << endl;
    cout << "║                          (10 Soru Demisi)                                ║" << endl;
    cout << "╚════════════════════════════════════════════════════════════════════════════╝\n" << endl;
    
    while (true) {
        cout << "\n╔══════════════════════════════════════════════════════════════╗" << endl;
        cout << "║  Hangi soruyu cözmek istiyorsunuz? (0 = Cikis)              ║" << endl;
        cout << "╚══════════════════════════════════════════════════════════════╝" << endl;
        cout << "1. Asal Sayi Kontrolu" << endl;
        cout << "2. Armstrong Sayilari Bulma" << endl;
        cout << "3. Fibonacci Serisi" << endl;
        cout << "4. Basamak Tersi Islemi" << endl;
        cout << "5. Asal Carpanlar" << endl;
        cout << "6. EBOB ve EKOK" << endl;
        cout << "7. Bubble Sort (Takas Sayısı)" << endl;
        cout << "8. Linear ve Binary Search" << endl;
        cout << "9. Palindrom Kontrol" << endl;
        cout << "10. Matris Operasyonlari" << endl;
        cout << "\nSeciminiz (0-10): ";
        
        int choice;
        cin >> choice;
        
        switch(choice) {
            case 1: soru1(); break;
            case 2: soru2(); break;
            case 3: soru3(); break;
            case 4: soru4(); break;
            case 5: soru5(); break;
            case 6: soru6(); break;
            case 7: soru7(); break;
            case 8: soru8(); break;
            case 9: soru9(); break;
            case 10: soru10(); break;
            case 0: 
                cout << "\nProgram sonlandirildi. Basarilar!" << endl;
                return 0;
            default:
                cout << "\nGecersiz secim!" << endl;
        }
    }
    
    return 0;
}
