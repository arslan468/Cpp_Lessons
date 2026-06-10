/*
╔════════════════════════════════════════════════════════════════════════════╗
║                  C++ SINAVI - HIZLI REFERANS KILAVUZU                     ║
║                         (Kopya-Yapıştır Parçalar)                         ║
║                                                                            ║
║  Sınavda hızlıca ihtiyacınız olan kod parçalarını bu dosyada bulabilirsiniz ║
╚════════════════════════════════════════════════════════════════════════════╝
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
using namespace std;

// ═══════════════════════════════════════════════════════════════════════════
//                         HIZLI REFERANS TABLOSU
// ═══════════════════════════════════════════════════════════════════════════

/*

┌─────────────────────────────────────────────────────────────────────────┐
│ 1. ASAL SAYI İŞLEMLERİ                                                  │
└─────────────────────────────────────────────────────────────────────────┘

Asal Kontrol (tek sayı):
    bool asal(int n) {
        if (n < 2) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;
        for (int i = 3; i * i <= n; i += 2)
            if (n % i == 0) return false;
        return true;
    }

N'e kadar asal sayılar (Sieve):
    vector<bool> asal(n+1, true);
    asal[0] = asal[1] = false;
    for (int i = 2; i * i <= n; i++)
        if (asal[i])
            for (int j = i*i; j <= n; j += i)
                asal[j] = false;

┌─────────────────────────────────────────────────────────────────────────┐
│ 2. FIBONACCI VE RÖKÜRSİON                                               │
└─────────────────────────────────────────────────────────────────────────┘

Fibonacci İteratif (hızlı):
    long long fib(int n) {
        if (n <= 1) return n;
        long long a = 0, b = 1;
        for (int i = 2; i <= n; i++)
            swap(a, b), b = a + b;
        return b;
    }

Fibonacci Rekursif (yavaş, gösterim için):
    long long fib(int n) {
        if (n <= 1) return n;
        return fib(n-1) + fib(n-2);
    }

Faktöriyel:
    long long fact(int n) {
        long long res = 1;
        for (int i = 2; i <= n; i++) res *= i;
        return res;
    }

Üs Hesaplama (a^b):
    long long power(long long a, int b) {
        long long res = 1;
        while (b) {
            if (b & 1) res *= a;
            a *= a;
            b >>= 1;
        }
        return res;
    }

┌─────────────────────────────────────────────────────────────────────────┐
│ 3. SAYISAL OPERASYONLAR                                                 │
└─────────────────────────────────────────────────────────────────────────┘

EBOB (GCD):
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

EKOK (LCM):
    int lcm(int a, int b) { return a / gcd(a, b) * b; }

Basamak Toplamı:
    int digitSum(int n) {
        int sum = 0;
        while (n) { sum += n % 10; n /= 10; }
        return sum;
    }

Sayı Tersi:
    int reverse(int n) {
        int rev = 0;
        while (n) { rev = rev * 10 + n % 10; n /= 10; }
        return rev;
    }

Palindrom (sayı):
    bool isPalindrome(int n) {
        return n == reverse(n);
    }

Armstrong Sayı:
    bool isArmstrong(int n) {
        int orig = n, len = to_string(n).length(), sum = 0;
        while (n) {
            sum += pow(n % 10, len);
            n /= 10;
        }
        return sum == orig;
    }

┌─────────────────────────────────────────────────────────────────────────┐
│ 4. ŞEKİL ÇİZME                                                          │
└─────────────────────────────────────────────────────────────────────────┘

Dik Üçgen:
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) cout << "*";
        cout << "\n";
    }

Piramit (merkez):
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) cout << " ";
        for (int j = 1; j <= 2*i - 1; j++) cout << "*";
        cout << "\n";
    }

Ters Üçgen:
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) cout << "*";
        cout << "\n";
    }

Elmas:
    // Üst yarı
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) cout << " ";
        for (int j = 1; j <= 2*i - 1; j++) cout << "*";
        cout << "\n";
    }
    // Alt yarı
    for (int i = n-1; i >= 1; i--) {
        for (int j = 1; j <= n - i; j++) cout << " ";
        for (int j = 1; j <= 2*i - 1; j++) cout << "*";
        cout << "\n";
    }

Boş Kare:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << (i == 0 || i == n-1 || j == 0 || j == n-1 ? "*" : " ");
        cout << "\n";
    }

┌─────────────────────────────────────────────────────────────────────────┐
│ 5. SIRALAMALAR                                                          │
└─────────────────────────────────────────────────────────────────────────┘

Bubble Sort:
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);

Selection Sort:
    for (int i = 0; i < n-1; i++) {
        int min = i;
        for (int j = i+1; j < n; j++)
            if (arr[j] < arr[min]) min = j;
        swap(arr[i], arr[min]);
    }

Insertion Sort:
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

Binary Search (sıralı dizi):
    int left = 0, right = n-1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;

Linear Search:
    for (int i = 0; i < n; i++)
        if (arr[i] == target) return i;
    return -1;

┌─────────────────────────────────────────────────────────────────────────┐
│ 6. STRİNG İŞLEMLERİ                                                     │
└─────────────────────────────────────────────────────────────────────────┘

Palindrom (string):
    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

String Tersi:
    reverse(s.begin(), s.end());

Karakter Frekansı:
    int count = 0;
    for (char c : s)
        if (c == target) count++;

Ünlü Sayısı:
    int vowels = 0;
    for (char c : s)
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            vowels++;

Substring Var mı:
    if (s.find(substring) != string::npos) {
        // Var
    }

Kelime Sayısı:
    int words = 0;
    bool inWord = false;
    for (char c : s) {
        if (c != ' ') {
            if (!inWord) { words++; inWord = true; }
        } else {
            inWord = false;
        }
    }

┌─────────────────────────────────────────────────────────────────────────┐
│ 7. MATRİS İŞLEMLERİ                                                     │
└─────────────────────────────────────────────────────────────────────────┘

Matris Çarpımı:
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            c[i][j] = 0;
            for (int k = 0; k < n; k++)
                c[i][j] += a[i][k] * b[k][j];
        }

Transpoze:
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            trans[j][i] = mat[i][j];

Köşegen Toplamı:
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += mat[i][i];

Satır Toplamları:
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++)
            sum += mat[i][j];
        cout << sum << " ";
    }

Sütun Toplamları:
    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += mat[i][j];
        cout << sum << " ";
    }

┌─────────────────────────────────────────────────────────────────────────┐
│ 8. VERI YAPILARI                                                        │
└─────────────────────────────────────────────────────────────────────────┘

Stack Kullanımı:
    stack<int> st;
    st.push(x);              // Ekle
    int top = st.top();      // Tepesi al (çıkarmaz)
    st.pop();                // Çıkar
    bool empty = st.empty(); // Boş mu?

Queue Kullanımı:
    queue<int> q;
    q.push(x);               // Ekle (arkaya)
    int front = q.front();   // Önü al
    q.pop();                 // Çıkar
    bool empty = q.empty();  // Boş mu?

Vector Kullanımı:
    vector<int> v;
    v.push_back(x);          // Sona ekle
    v.pop_back();            // Sondan çıkar
    int size = v.size();     // Boyut
    v[i];                    // Index erişim
    v.clear();               // Temizle

┌─────────────────────────────────────────────────────────────────────────┐
│ 9. SIK KULLANILAN KÜTÜPHANELER                                         │
└─────────────────────────────────────────────────────────────────────────┘

İçerimleri:
    #include <iostream>     // cin, cout
    #include <vector>       // vector
    #include <algorithm>    // sort, reverse, swap
    #include <cmath>        // pow, sqrt
    #include <string>       // string
    #include <queue>        // queue, priority_queue
    #include <stack>        // stack
    #include <set>          // set, unordered_set
    #include <map>          // map, unordered_map

Sık Fonksiyonlar:
    sort(arr, arr + n);              // Sırala
    reverse(arr, arr + n);           // Tersine çevir
    swap(a, b);                      // Değiş tokuş
    max(a, b), min(a, b);            // Max, min
    sqrt(x);                         // Karekök
    pow(x, y);                       // Üs
    abs(x);                          // Mutlak değer

┌─────────────────────────────────────────────────────────────────────────┐
│ 10. SINAV İPUÇLARI                                                      │
└─────────────────────────────────────────────────────────────────────────┘

✓ Daima Base Case'i yazın (recursion için)
✓ Döngü koşullarını iki kez kontrol edin
✓ Array bounds'a dikkat edin (0 tabanlı)
✓ Integer overflow'e karşı dikkat edin (long long kullan)
✓ Infinite loop'tan dikkat edin
✓ Empty input kontrolü yap
✓ Çıktı formatını kontrol et

╔════════════════════════════════════════════════════════════════════════════╗
║                      KOPYA YAPMA TESTLERI                                 ║
╚════════════════════════════════════════════════════════════════════════════╝
*/

// KULLANIMA HAZIR TEMPLATE

#define nl "\n"
#define ll long long
#define fo(i, n) for(int i = 0; i < n; i++)
#define rfo(i, n) for(int i = n-1; i >= 0; i--)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // ═══════════════════════════════════════════════════════════════════════
    // TESTPADİ - ÖNEMLİ KONTROL LİSTESİ
    // ═══════════════════════════════════════════════════════════════════════
    
    cout << "\n╔════════════════════════════════════════════════════════════════╗" << nl;
    cout << "║           C++ SINAVI - HIZLI REFERANS TESTLERİ               ║" << nl;
    cout << "╚════════════════════════════════════════════════════════════════╝\n" << nl;
    
    // Test 1: Asal Kontrol
    cout << "TEST 1 - Asal Kontrol:" << nl;
    int test_asal = 17;
    bool asal = true;
    if (test_asal < 2) asal = false;
    else if (test_asal == 2) asal = true;
    else if (test_asal % 2 == 0) asal = false;
    else {
        for (int i = 3; i * i <= test_asal; i += 2) {
            if (test_asal % i == 0) {
                asal = false;
                break;
            }
        }
    }
    cout << "17 asal mi? " << (asal ? "EVET" : "HAYIR") << nl;
    
    // Test 2: Fibonacci
    cout << "\nTEST 2 - Fibonacci:" << nl;
    int fib_n = 10;
    ll a = 0, b = 1;
    fo(i, fib_n - 1) {
        ll temp = a + b;
        a = b;
        b = temp;
    }
    cout << "F(10) = " << b << nl;
    
    // Test 3: Faktöriyel
    cout << "\nTEST 3 - Faktöriyel:" << nl;
    int n = 5;
    ll fact = 1;
    for (int i = 2; i <= n; i++) fact *= i;
    cout << "5! = " << fact << nl;
    
    // Test 4: EBOB
    cout << "\nTEST 4 - EBOB:" << nl;
    int x = 48, y = 18;
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    cout << "EBOB(48, 18) = " << x << nl;
    
    // Test 5: Dizi Sırala
    cout << "\nTEST 5 - Bubble Sort:" << nl;
    int arr[] = {5, 2, 8, 1, 9};
    int arr_size = 5;
    for (int i = 0; i < arr_size - 1; i++) {
        for (int j = 0; j < arr_size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    cout << "Siralanmis: ";
    fo(i, arr_size) cout << arr[i] << " ";
    cout << nl;
    
    // Test 6: Binary Search
    cout << "\nTEST 6 - Binary Search:" << nl;
    int sorted_arr[] = {1, 2, 5, 8, 9};
    int target = 5;
    int left = 0, right = 4;
    int pos = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (sorted_arr[mid] == target) {
            pos = mid;
            break;
        } else if (sorted_arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << "5 bulundu, konum: " << pos << nl;
    
    // Test 7: Palindrom
    cout << "\nTEST 7 - Palindrom:" << nl;
    string test_str = "racecar";
    int l = 0, r = test_str.length() - 1;
    bool is_palindrome = true;
    while (l < r) {
        if (test_str[l++] != test_str[r--]) {
            is_palindrome = false;
            break;
        }
    }
    cout << "'racecar' palindrom mu? " << (is_palindrome ? "EVET" : "HAYIR") << nl;
    
    // Test 8: Armstrong Sayı
    cout << "\nTEST 8 - Armstrong Sayı:" << nl;
    int armstrong_test = 153;
    int orig = armstrong_test;
    int digit_count = to_string(armstrong_test).length();
    int sum = 0;
    while (armstrong_test > 0) {
        int digit = armstrong_test % 10;
        sum += pow(digit, digit_count);
        armstrong_test /= 10;
    }
    cout << "153 Armstrong sayi mi? " << (sum == orig ? "EVET" : "HAYIR") << nl;
    
    // Test 9: Matris Köşegen
    cout << "\nTEST 9 - Matris Köşegen Toplamı:" << nl;
    int mat[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int kosegen_sum = 0;
    for (int i = 0; i < 3; i++)
        kosegen_sum += mat[i][i];
    cout << "Kosegen toplami: " << kosegen_sum << nl;
    
    // Test 10: Vector Kullanımı
    cout << "\nTEST 10 - Vector Operasyonları:" << nl;
    vector<int> v = {3, 1, 4, 1, 5, 9};
    sort(v.begin(), v.end());
    cout << "Siralanmis vector: ";
    for (int x : v) cout << x << " ";
    cout << nl;
    
    cout << "\n╔════════════════════════════════════════════════════════════════╗" << nl;
    cout << "║                 TÜM TESTLER TAMAMLANDI                         ║" << nl;
    cout << "╚════════════════════════════════════════════════════════════════╝" << nl;
    
    return 0;
}
