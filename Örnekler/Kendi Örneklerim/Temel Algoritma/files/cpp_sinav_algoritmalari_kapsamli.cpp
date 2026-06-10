#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;

// ╔════════════════════════════════════════════════════════════════════════════╗
// ║                     1. ASAL SAYI PROBLEMLERI                              ║
// ╚════════════════════════════════════════════════════════════════════════════╝

// 1.1 - Tek bir sayının asal olup olmadığını kontrol et
bool asal_kontrol(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    // Sadece √n'e kadar kontrol yap
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// 1.2 - N'e kadar tüm asal sayılar (Sieve of Eratosthenes)
void asal_bulma_sieve(int n) {
    vector<bool> asal(n + 1, true);
    asal[0] = asal[1] = false;
    
    for (int i = 2; i * i <= n; i++) {
        if (asal[i]) {
            // i'nin katlarını işaretle
            for (int j = i * i; j <= n; j += i) {
                asal[j] = false;
            }
        }
    }
    
    cout << "1 ile " << n << " arasindaki asal sayilar: ";
    for (int i = 2; i <= n; i++) {
        if (asal[i]) cout << i << " ";
    }
    cout << endl;
}

// 1.3 - Bir sayının asal çarpanlarını bul
void asal_carpanlar(int n) {
    cout << n << " = ";
    int orijinal = n;
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
    
    // Eğer n > 1 ise kendisi asal
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
// ║                     2. FIBONACCI PROBLEMLERI                              ║
// ╚════════════════════════════════════════════════════════════════════════════╝

// 2.1 - Fibonacci Recursive (Yavaş - gösterim için)
long long fibonacci_recursive(int n) {
    if (n <= 1) return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

// 2.2 - Fibonacci Iterative (Hızlı - önerilen)
long long fibonacci_iterative(int n) {
    if (n <= 1) return n;
    
    long long a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        long long temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

// 2.3 - Fibonacci Dynamic Programming (DP ile)
long long fibonacci_dp(int n) {
    if (n <= 1) return n;
    
    vector<long long> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// 2.4 - N'e kadar Fibonacci serisini yazdır
void fibonacci_seri(int n) {
    cout << "Fibonacci Serisi (ilk " << n << " terim): ";
    long long a = 0, b = 1;
    cout << a << " " << b << " ";
    
    for (int i = 2; i < n; i++) {
        long long temp = a + b;
        cout << temp << " ";
        a = b;
        b = temp;
    }
    cout << endl;
}

// ╔════════════════════════════════════════════════════════════════════════════╗
// ║                     3. SAYILAR İLE İŞLEMLER                              ║
// ╚════════════════════════════════════════════════════════════════════════════╝

// 3.1 - Faktöriyel
long long faktoriyel(int n) {
    if (n <= 1) return 1;
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// 3.2 - Kombinasyon C(n, k)
long long kombinasyon(int n, int k) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    return faktoriyel(n) / (faktoriyel(k) * faktoriyel(n - k));
}

// 3.3 - Permütasyon P(n, k)
long long permutasyon(int n, int k) {
    if (k > n) return 0;
    return faktoriyel(n) / faktoriyel(n - k);
}

// 3.4 - EBOB (En Büyük Ortak Bölen) - Euclid Algoritması
int ebob(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 3.5 - EKOK (En Küçük Ortak Kat)
int ekok(int a, int b) {
    return (a * b) / ebob(a, b);
}

// 3.6 - Basamak Toplamı
int basamak_toplami(int n) {
    int toplam = 0;
    while (n > 0) {
        toplam += n % 10;
        n /= 10;
    }
    return toplam;
}

// 3.7 - Sayıyı Tersine Çevir
int sayi_tersi(int n) {
    int tersi = 0;
    while (n > 0) {
        tersi = tersi * 10 + n % 10;
        n /= 10;
    }
    return tersi;
}

// 3.8 - Palindrom Sayı Kontrolü
bool palindrom_sayi(int n) {
    int orijinal = n;
    int tersi = sayi_tersi(n);
    return orijinal == tersi;
}

// 3.9 - Armstrong Sayı (Narcissistic Number) - 153 = 1³+5³+3³
bool armstrong_sayi(int n) {
    int orijinal = n;
    int basamak_sayisi = to_string(n).length();
    int toplam = 0;
    
    while (n > 0) {
        int rakam = n % 10;
        toplam += pow(rakam, basamak_sayisi);
        n /= 10;
    }
    
    return orijinal == toplam;
}

// 3.10 - Mükemmel Sayı (Perfect Number) - 6 = 1+2+3
bool mukemmel_sayi(int n) {
    int toplam = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            toplam += i;
        }
    }
    return toplam == n;
}

// 3.11 - Üss Hesapla (a^b)
long long uss_hesapla(long long taban, int kuvvet) {
    long long result = 1;
    for (int i = 0; i < kuvvet; i++) {
        result *= taban;
    }
    return result;
}

// 3.12 - Fibonacci Recursive (Özyinelemeli)
long long fib_recursive(int n) {
    if (n <= 1) return n;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

// ╔════════════════════════════════════════════════════════════════════════════╗
// ║                     4. ŞEKİL ÇİZME (PATTERN PRINTING)                    ║
// ╚════════════════════════════════════════════════════════════════════════════╝

// 4.1 - Dik Üçgen
void dik_ucgen(int n) {
    cout << "\n=== DIK UCGEN ===" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

// 4.2 - Dik Üçgen (Sayılarla)
void dik_ucgen_sayilar(int n) {
    cout << "\n=== DIK UCGEN (SAYILAR) ===" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j;
        }
        cout << endl;
    }
}

// 4.3 - Piramit (Ortalanmış)
void piramit(int n) {
    cout << "\n=== PİRAMİT ===" << endl;
    for (int i = 1; i <= n; i++) {
        // Boşluklar
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        // Yıldızlar
        for (int j = 1; j <= 2 * i - 1; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

// 4.4 - Piramit (Sayılarla)
void piramit_sayilar(int n) {
    cout << "\n=== PİRAMİT (SAYILAR) ===" << endl;
    for (int i = 1; i <= n; i++) {
        // Boşluklar
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        // Sayılar
        for (int j = 1; j <= i; j++) {
            cout << j;
        }
        for (int j = i - 1; j >= 1; j--) {
            cout << j;
        }
        cout << endl;
    }
}

// 4.5 - Ters Üçgen
void ters_ucgen(int n) {
    cout << "\n=== TERS UCGEN ===" << endl;
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

// 4.6 - Elmas (Diamond)
void elmas(int n) {
    cout << "\n=== ELMAS ===" << endl;
    // Üst yarı
    for (int i = 1; i <= n; i++) {
        // Boşluklar
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        // Yıldızlar
        for (int j = 1; j <= 2 * i - 1; j++) {
            cout << "*";
        }
        cout << endl;
    }
    // Alt yarı
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        for (int j = 1; j <= 2 * i - 1; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

// 4.7 - Boş Kare
void bos_kare(int n) {
    cout << "\n=== BOŞ KARE ===" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 || i == n || j == 1 || j == n) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

// 4.8 - Dolu Kare
void dolu_kare(int n) {
    cout << "\n=== DOLU KARE ===" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

// 4.9 - Çarpım Tablosu
void carpim_tablosu(int n) {
    cout << "\n=== CARPIM TABLOSU ===" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << i * j << "\t";
        }
        cout << endl;
    }
}

// 4.10 - Spiral Şekil
void spiral_ucgen(int n) {
    cout << "\n=== SPİRAL UCGEN ===" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << i;
        }
        cout << endl;
    }
}

// ╔════════════════════════════════════════════════════════════════════════════╗
// ║                     5. SIRALAMALAR (SORTING)                              ║
// ╚════════════════════════════════════════════════════════════════════════════╝

// 5.1 - Bubble Sort
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// 5.2 - Selection Sort
void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

// 5.3 - Insertion Sort
void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// 5.4 - Merge Sort Helper - Merge
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    vector<int> L(n1), R(n2);
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    
    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

// 5.5 - Merge Sort
void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// 5.6 - Quick Sort Helper - Partition
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            swap(arr[++i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// 5.7 - Quick Sort
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

// ╔════════════════════════════════════════════════════════════════════════════╗
// ║                     6. ARAMA (SEARCH)                                     ║
// ╚════════════════════════════════════════════════════════════════════════════╝

// 6.1 - Linear Search (Doğrusal Arama)
int linear_search(int arr[], int n, int hedef) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == hedef) return i;
    }
    return -1;
}

// 6.2 - Binary Search (İkili Arama) - Sıralı dizi için
int binary_search(int arr[], int n, int hedef) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
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

// ╔════════════════════════════════════════════════════════════════════════════╗
// ║                     7. STRİNG İŞLEMLERİ                                   ║
// ╚════════════════════════════════════════════════════════════════════════════╝

// 7.1 - Palindrom String
bool palindrom_string(string s) {
    int left = 0, right = s.length() - 1;
    
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

// 7.2 - String Tersi
string string_tersi(string s) {
    reverse(s.begin(), s.end());
    return s;
}

// 7.3 - Belirli Karakterin Frekansı
int karakter_frekans(string s, char c) {
    int sayac = 0;
    for (char ch : s) {
        if (ch == c) sayac++;
    }
    return sayac;
}

// 7.4 - Harf Sayısı
int harf_sayisi(string s) {
    int sayac = 0;
    for (char ch : s) {
        if (isalpha(ch)) sayac++;
    }
    return sayac;
}

// 7.5 - Ünlü Sayısı (Vowel)
int unlu_sayisi(string s) {
    int sayac = 0;
    string unlular = "aeiouAEIOU";
    for (char ch : s) {
        if (unlular.find(ch) != string::npos) {
            sayac++;
        }
    }
    return sayac;
}

// 7.6 - Ünsüz Sayısı (Consonant)
int unsuz_sayisi(string s) {
    int sayac = 0;
    string unsuzler = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
    for (char ch : s) {
        if (unsuzler.find(ch) != string::npos) {
            sayac++;
        }
    }
    return sayac;
}

// 7.7 - Kelime Sayısı
int kelime_sayisi(string s) {
    int sayac = 0;
    bool kelime_ici = false;
    
    for (char ch : s) {
        if (ch != ' ' && ch != '\t' && ch != '\n') {
            if (!kelime_ici) {
                sayac++;
                kelime_ici = true;
            }
        } else {
            kelime_ici = false;
        }
    }
    return sayac;
}

// 7.8 - Substring Kontrolü
bool substring_var(string s, string substring) {
    return s.find(substring) != string::npos;
}

// ╔════════════════════════════════════════════════════════════════════════════╗
// ║                     8. MATRİS İŞLEMLERİ                                   ║
// ╚════════════════════════════════════════════════════════════════════════════╝

// 8.1 - Matris Çarpımı
void matris_carp(int a[3][3], int b[3][3], int c[3][3], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = 0;
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// 8.2 - Matris Transpozesi
void matris_transpoz(int mat[3][3], int trans[3][3], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            trans[j][i] = mat[i][j];
        }
    }
}

// 8.3 - Matris Köşegen Toplamı
int kosegen_toplami(int mat[3][3], int n) {
    int toplam = 0;
    for (int i = 0; i < n; i++) {
        toplam += mat[i][i];
    }
    return toplam;
}

// 8.4 - Matris Satır Toplamı
void satir_toplami(int mat[3][3], int n) {
    cout << "Satir Toplamlari: ";
    for (int i = 0; i < n; i++) {
        int toplam = 0;
        for (int j = 0; j < n; j++) {
            toplam += mat[i][j];
        }
        cout << toplam << " ";
    }
    cout << endl;
}

// 8.5 - Matris Sütun Toplamı
void sutun_toplami(int mat[3][3], int n) {
    cout << "Sutun Toplamlari: ";
    for (int j = 0; j < n; j++) {
        int toplam = 0;
        for (int i = 0; i < n; i++) {
            toplam += mat[i][j];
        }
        cout << toplam << " ";
    }
    cout << endl;
}

// ╔════════════════════════════════════════════════════════════════════════════╗
// ║                     9. YARD. FONKSİYONLAR                                  ║
// ╚════════════════════════════════════════════════════════════════════════════╝

void dizi_yazdir(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;
}

void dizi_kopyala(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

void matris_yazdir(int mat[3][3], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

// ╔════════════════════════════════════════════════════════════════════════════╗
// ║                     10. MAIN - TEST FONKSIYONLARI                         ║
// ╚════════════════════════════════════════════════════════════════════════════╝

int main() {
    cout << "\n╔════════════════════════════════════════════════════════════════════════════╗" << endl;
    cout << "║         PROGRAMLAMA SINAVI - KLASIK ALGORITMA ÖRNEKLERİ (C++)            ║" << endl;
    cout << "╚════════════════════════════════════════════════════════════════════════════╝\n" << endl;
    
    // ===== ASAL SAYI TESTLERİ =====
    cout << "\n>>> 1. ASAL SAYI PROBLEMLERI <<<" << endl;
    cout << "17 asal mi? " << (asal_kontrol(17) ? "EVET" : "HAYIR") << endl;
    cout << "25 asal mi? " << (asal_kontrol(25) ? "EVET" : "HAYIR") << endl;
    asal_bulma_sieve(30);
    asal_carpanlar(60);
    
    // ===== FIBONACCI TESTLERİ =====
    cout << "\n>>> 2. FIBONACCI PROBLEMLERI <<<" << endl;
    cout << "F(10) - Iterative: " << fibonacci_iterative(10) << endl;
    cout << "F(10) - DP: " << fibonacci_dp(10) << endl;
    fibonacci_seri(12);
    
    // ===== SAYILAR İLE İŞLEMLER =====
    cout << "\n>>> 3. SAYILAR İLE İŞLEMLER <<<" << endl;
    cout << "5! = " << faktoriyel(5) << endl;
    cout << "C(5,2) = " << kombinasyon(5, 2) << endl;
    cout << "P(5,2) = " << permutasyon(5, 2) << endl;
    cout << "EBOB(48, 18) = " << ebob(48, 18) << endl;
    cout << "EKOK(48, 18) = " << ekok(48, 18) << endl;
    cout << "153'ün basamak toplamı = " << basamak_toplami(153) << endl;
    cout << "123'ün tersi = " << sayi_tersi(123) << endl;
    cout << "121 palindrom mu? " << (palindrom_sayi(121) ? "EVET" : "HAYIR") << endl;
    cout << "153 Armstrong sayi mi? " << (armstrong_sayi(153) ? "EVET" : "HAYIR") << endl;
    cout << "6 mükemmel sayi mi? " << (mukemmel_sayi(6) ? "EVET" : "HAYIR") << endl;
    cout << "2^8 = " << uss_hesapla(2, 8) << endl;
    
    // ===== ŞEKİL ÇİZME =====
    cout << "\n>>> 4. ŞEKİL ÇİZME (PATTERN PRINTING) <<<" << endl;
    dik_ucgen(5);
    dik_ucgen_sayilar(5);
    piramit(4);
    piramit_sayilar(5);
    ters_ucgen(4);
    elmas(3);
    bos_kare(4);
    dolu_kare(4);
    carpim_tablosu(5);
    spiral_ucgen(5);
    
    // ===== SIRALAMALAR =====
    cout << "\n>>> 5. SIRALAMALAR (SORTING) <<<" << endl;
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;
    
    int arr_copy[7];
    dizi_kopyala(arr, arr_copy, n);
    bubble_sort(arr_copy, n);
    cout << "Bubble Sort: ";
    dizi_yazdir(arr_copy, n);
    
    dizi_kopyala(arr, arr_copy, n);
    selection_sort(arr_copy, n);
    cout << "Selection Sort: ";
    dizi_yazdir(arr_copy, n);
    
    dizi_kopyala(arr, arr_copy, n);
    insertion_sort(arr_copy, n);
    cout << "Insertion Sort: ";
    dizi_yazdir(arr_copy, n);
    
    dizi_kopyala(arr, arr_copy, n);
    merge_sort(arr_copy, 0, n - 1);
    cout << "Merge Sort: ";
    dizi_yazdir(arr_copy, n);
    
    dizi_kopyala(arr, arr_copy, n);
    quick_sort(arr_copy, 0, n - 1);
    cout << "Quick Sort: ";
    dizi_yazdir(arr_copy, n);
    
    // ===== ARAMA =====
    cout << "\n>>> 6. ARAMA (SEARCH) <<<" << endl;
    int arr_sorted[] = {11, 12, 22, 25, 34, 64, 90};
    cout << "Linear Search (25): " << linear_search(arr_sorted, 7, 25) << endl;
    cout << "Binary Search (25): " << binary_search(arr_sorted, 7, 25) << endl;
    cout << "Binary Search (11): " << binary_search(arr_sorted, 7, 11) << endl;
    
    // ===== STRİNG İŞLEMLERİ =====
    cout << "\n>>> 7. STRİNG İŞLEMLERİ <<<" << endl;
    string text = "Merhaba Dunya";
    string pal = "racecar";
    
    cout << "racecar palindrom mu? " << (palindrom_string(pal) ? "EVET" : "HAYIR") << endl;
    cout << "hello'nun tersi: " << string_tersi("hello") << endl;
    cout << "Ünlü sayisi (" << text << "): " << unlu_sayisi(text) << endl;
    cout << "Ünsüz sayisi (" << text << "): " << unsuz_sayisi(text) << endl;
    cout << "Kelime sayisi (" << text << "): " << kelime_sayisi(text) << endl;
    cout << "Harf sayisi (" << text << "): " << harf_sayisi(text) << endl;
    cout << "'Dunya' kelimesi var mi? " << (substring_var(text, "Dunya") ? "EVET" : "HAYIR") << endl;
    
    // ===== MATRİS İŞLEMLERİ =====
    cout << "\n>>> 8. MATRİS İŞLEMLERİ <<<" << endl;
    int mat1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int mat2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    
    cout << "Matris 1:" << endl;
    matris_yazdir(mat1, 3);
    
    cout << "\nKosegen Toplami: " << kosegen_toplami(mat1, 3) << endl;
    satir_toplami(mat1, 3);
    sutun_toplami(mat1, 3);
    
    int trans[3][3];
    matris_transpoz(mat1, trans, 3);
    cout << "\nTranspoz:" << endl;
    matris_yazdir(trans, 3);
    
    cout << "\n╔════════════════════════════════════════════════════════════════════════════╗" << endl;
    cout << "║                          TESTLER TAMAMLANDI                              ║" << endl;
    cout << "╚════════════════════════════════════════════════════════════════════════════╝" << endl;
    
    return 0;
}
