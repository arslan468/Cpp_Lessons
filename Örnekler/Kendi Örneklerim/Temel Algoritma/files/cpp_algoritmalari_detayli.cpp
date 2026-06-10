/*
╔════════════════════════════════════════════════════════════════════════════╗
║    C++ PROGRAMLAMA SINAVI - DETAYLI ALGORITMA AÇIKLAMALARI               ║
║                                                                            ║
║  Bu dosya, sınavlarda sık çıkan algoritmaların:                           ║
║  - Teorik açıklamalarını                                                  ║
║  - Kod uygulamalarını                                                     ║
║  - Kompleksity analizini (Big O notation)                                 ║
║  - Örnekleri                                                              ║
║  içerir.                                                                   ║
╚════════════════════════════════════════════════════════════════════════════╝
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

// ╔════════════════════════════════════════════════════════════════════════════╗
// ║           RÖKÜRSİON PROBLEMLERI (RECURSION PROBLEMS)                      ║
// ╚════════════════════════════════════════════════════════════════════════════╝

/*
TANNIM: Bir fonksiyon kendisini çağırırsa buna Recursion denir.

ÖNEMLİ ŞARTLAR:
1. Base Case (Taban Durum) - Özyinelemenin durduğu nokta
2. Recursive Case - Fonksiyonun kendisini çağırdığı kısım
3. Parametrelerin değişmesi gerekir

TEMPLATİ:
int recursive_fonk(int n) {
    // Base case
    if (n == 0) return 1;
    
    // Recursive case
    return recursive_fonk(n-1) * n;
}
*/

// 1. Faktöriyel - Recursive
long long faktorial_recursive(int n) {
    if (n <= 1) return 1;  // Base case
    return n * faktorial_recursive(n - 1);  // Recursive case
}

// Time: O(n), Space: O(n) - call stack kullanır

// 2. Fibonacci - Recursive (Yavaş - O(2^n))
long long fib_slow(int n) {
    if (n <= 1) return n;
    return fib_slow(n - 1) + fib_slow(n - 2);
}

// 3. Fibonacci - Tail Recursion (daha verimli)
long long fib_tail(int n, long long a = 0, long long b = 1) {
    if (n == 0) return a;
    return fib_tail(n - 1, b, a + b);
}

// 4. Üs Hesapla (Power) - Divide and Conquer
long long uss_hesapla(long long taban, int kuvvet) {
    if (kuvvet == 0) return 1;  // Base case
    
    if (kuvvet % 2 == 0) {
        long long temp = uss_hesapla(taban, kuvvet / 2);
        return temp * temp;  // a^10 = (a^5)^2
    } else {
        return taban * uss_hesapla(taban, kuvvet - 1);  // a^11 = a * a^10
    }
}

// Time: O(log n), Space: O(log n)

// 5. Hanoi Kulesi Problemi
void hanoi(int n, char kaynak, char hedef, char yardimci) {
    if (n == 1) {
        cout << "Disk 1: " << kaynak << " -> " << hedef << endl;
        return;
    }
    
    // n-1 diski kaynak'tan yardımcı'ya taşı
    hanoi(n - 1, kaynak, yardimci, hedef);
    
    // En büyük diski kaynak'tan hedef'e taşı
    cout << "Disk " << n << ": " << kaynak << " -> " << hedef << endl;
    
    // n-1 diski yardımcı'dan hedef'e taşı
    hanoi(n - 1, yardimci, hedef, kaynak);
}

// Time: O(2^n), Space: O(n)

// 6. Dizi Toplamı - Recursive
int dizi_toplami_recursive(int arr[], int n) {
    if (n == 0) return 0;
    return arr[n - 1] + dizi_toplami_recursive(arr, n - 1);
}

// 7. Dizi Maksimumu - Recursive
int dizi_max_recursive(int arr[], int n) {
    if (n == 1) return arr[0];
    return max(arr[n - 1], dizi_max_recursive(arr, n - 1));
}

// 8. Dizi Minimumu - Recursive
int dizi_min_recursive(int arr[], int n) {
    if (n == 1) return arr[0];
    return min(arr[n - 1], dizi_min_recursive(arr, n - 1));
}

// ╔════════════════════════════════════════════════════════════════════════════╗
// ║     GEOMETRİK SIRALAMALAR (GEOMETRIC/SPIRAL PATTERNS)                    ║
// ╚════════════════════════════════════════════════════════════════════════════╝

// 1. Simetrik Piramit
void simetrik_piramit(int n) {
    cout << "\n=== SİMETRİK PİRAMİT ===" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) cout << " ";
        for (int j = 1; j <= 2 * i - 1; j++) cout << "*";
        cout << endl;
    }
}

// 2. Hourglass (Kum Saati)
void kum_saati(int n) {
    cout << "\n=== KUM SAATI ===" << endl;
    // Üst yarı
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i - 1; j++) cout << " ";
        for (int j = 1; j <= 2 * (n - i) + 1; j++) cout << "*";
        cout << endl;
    }
    // Alt yarı
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= i - 1; j++) cout << " ";
        for (int j = 1; j <= 2 * (n - i) + 1; j++) cout << "*";
        cout << endl;
    }
}

// 3. Pascal Üçgeni
void pascal_ucgeni(int n) {
    cout << "\n=== PASCAL UCGENI ===" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) cout << " ";
        
        int val = 1;
        for (int j = 0; j <= i; j++) {
            cout << val << " ";
            val = val * (i - j) / (j + 1);
        }
        cout << endl;
    }
}

// 4. Floyd Üçgeni
void floyd_ucgeni(int n) {
    cout << "\n=== FLOYD UCGENI ===" << endl;
    int num = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
}

// ╔════════════════════════════════════════════════════════════════════════════╗
// ║                 ADVANCED SIRALAMALAR (ADVANCED SORTS)                     ║
// ╚════════════════════════════════════════════════════════════════════════════╝

// Counting Sort - Negatif olmayan sayılar için
void counting_sort(int arr[], int n, int max_val) {
    cout << "\n=== COUNTING SORT ===" << endl;
    vector<int> count(max_val + 1, 0);
    
    // Sayıları say
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    
    // Kümülatif sayıları hesapla
    for (int i = 1; i <= max_val; i++) {
        count[i] += count[i - 1];
    }
    
    vector<int> output(n);
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Time: O(n + k), Space: O(k) - k = range

// Radix Sort
void radix_sort(int arr[], int n) {
    cout << "\n=== RADIX SORT ===" << endl;
    int max_num = *max_element(arr, arr + n);
    
    for (int exp = 1; max_num / exp > 0; exp *= 10) {
        counting_sort(arr, n, 9);
    }
    
    cout << "Sonuc: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

// ╔════════════════════════════════════════════════════════════════════════════╗
// ║                     STACK VE QUEUE UYGULAMALARI                          ║
// ╚════════════════════════════════════════════════════════════════════════════╝

// 1. Stack ile DFS (Depth First Search)
void dfs_stack(int start, vector<vector<int>>& graph) {
    cout << "\nDFS (Stack ile): ";
    stack<int> s;
    vector<bool> visited(graph.size(), false);
    
    s.push(start);
    visited[start] = true;
    
    while (!s.empty()) {
        int node = s.top();
        s.pop();
        cout << node << " ";
        
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                s.push(neighbor);
            }
        }
    }
}

// 2. Queue ile BFS (Breadth First Search)
void bfs_queue(int start, vector<vector<int>>& graph) {
    cout << "\nBFS (Queue ile): ";
    queue<int> q;
    vector<bool> visited(graph.size(), false);
    
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

// ╔════════════════════════════════════════════════════════════════════════════╗
// ║              DYNAMIC PROGRAMMING PROBLEMLERI                             ║
// ╚════════════════════════════════════════════════════════════════════════════╝

// 1. Fibonacci DP
long long fib_dp(int n) {
    if (n <= 1) return n;
    vector<long long> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// Time: O(n), Space: O(n)

// 2. Merdiven Problem - N basamağı 1 veya 2 adımda tırman
long long merdiven_problem(int n) {
    if (n <= 2) return n;
    
    vector<long long> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;
    
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// 3. Coin Change Problem
int coin_change(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    
    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (coin <= i) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    
    return dp[amount] > amount ? -1 : dp[amount];
}

// ╔════════════════════════════════════════════════════════════════════════════╗
// ║                  GREEDY ALGORITHM PROBLEMLERI                            ║
// ╚════════════════════════════════════════════════════════════════════════════╝

// Activity Selection Problem
void activity_selection(vector<pair<int, int>>& activities) {
    cout << "\n=== ACTIVITY SELECTION ===" << endl;
    
    sort(activities.begin(), activities.end(), 
         [](const pair<int, int>& a, const pair<int, int>& b) {
             return a.second < b.second;
         });
    
    cout << "Etkinlikler (baslangic, bitis): ";
    int last_end = -1;
    
    for (auto& activity : activities) {
        if (activity.first >= last_end) {
            cout << "(" << activity.first << "," << activity.second << ") ";
            last_end = activity.second;
        }
    }
}

// ╔════════════════════════════════════════════════════════════════════════════╗
// ║                     DETAYLI AÇIKLAMALAR                                  ║
// ╚════════════════════════════════════════════════════════════════════════════╝

/*
BIG O NOTASYONU KÖK SÖZLÜĞÜ:
═══════════════════════════════════════════════════════════════════════════

O(1)     - Sabit zaman      - Dizi indexe erişme, Hash table lookup
O(log n) - Logaritmik       - Binary search, Balanced tree operations
O(n)     - Lineer           - Simple loop, Linear search
O(n log n) - Linearitmik    - Merge sort, Quick sort (avg), Heap sort
O(n²)    - Kuadratik        - Bubble sort, Nested loops
O(n³)    - Kübik            - 3 nested loops
O(2^n)   - Eksponensiyel    - Fibonacci recursive, Permütasyon
O(n!)    - Faktörial        - Tüm kombinasyonlar (çok kötü!)

SIRALAMADA KULLANILACAK:
═══════════════════════════════════════════════════════════════════════════

ALGORITMA          | BEST CASE  | AVERAGE    | WORST CASE | SPACE | STABLE
───────────────────────────────────────────────────────────────────────────
Bubble Sort        | O(n)       | O(n²)      | O(n²)      | O(1)  | Evet
Selection Sort     | O(n²)      | O(n²)      | O(n²)      | O(1)  | Hayır
Insertion Sort     | O(n)       | O(n²)      | O(n²)      | O(1)  | Evet
Merge Sort         | O(n log n) | O(n log n) | O(n log n) | O(n)  | Evet
Quick Sort         | O(n log n) | O(n log n) | O(n²)      | O(log n)| Hayır
Heap Sort          | O(n log n) | O(n log n) | O(n log n) | O(1)  | Hayır
Counting Sort      | O(n + k)   | O(n + k)   | O(n + k)   | O(k)  | Evet
Radix Sort         | O(nk)      | O(nk)      | O(nk)      | O(n)  | Evet

ARAMA İŞLEMLERİ:
═══════════════════════════════════════════════════════════════════════════

Linear Search      | O(n)       | Sırasız veri
Binary Search      | O(log n)   | Sıralı veri (ön koşul!)
Hash Table         | O(1)       | O(n) (collision durumunda)
Binary Search Tree | O(log n)   | O(n) (skewed durumunda)

RÖKÜRSİON ANALIZI:
═══════════════════════════════════════════════════════════════════════════

Master Theorem:
T(n) = aT(n/b) + f(n)

Durumlar:
- f(n) < n^(log_b(a))  →  T(n) = O(n^(log_b(a)))
- f(n) = n^(log_b(a))  →  T(n) = O(n^(log_b(a)) * log n)
- f(n) > n^(log_b(a))  →  T(n) = O(f(n))

ÖRNEK - Binary Search:
T(n) = T(n/2) + O(1)
a=1, b=2
log_b(a) = log_2(1) = 0
f(n) = O(1) = O(n^0)
→ Durum 2: T(n) = O(log n)

STRATEJİ SEÇİMİ:
═══════════════════════════════════════════════════════════════════════════

DURUM                           → ALGORİTMA
──────────────────────────────────────────────────────────────────────────
Küçük veri seti (< 50)         → Bubble Sort, Selection Sort, Insertion Sort
Rastgele sıralı veri           → Quick Sort, Merge Sort
Hemen hemen sıralı veri        → Insertion Sort, Bubble Sort
Aralık biliniyorsa (0-100)     → Counting Sort
Bağlı liste                    → Merge Sort (Quick Sort yerine)
Minimum bellek gerekli         → Heap Sort, Selection Sort
Stabil sıralama gerekli        → Merge Sort, Insertion Sort, Bubble Sort
*/

// ╔════════════════════════════════════════════════════════════════════════════╗
// ║                            TEST FONKSİYONU                               ║
// ╚════════════════════════════════════════════════════════════════════════════╝

int main() {
    cout << "\n╔════════════════════════════════════════════════════════════════════════════╗" << endl;
    cout << "║            C++ SINAVI - DETAYLI ALGORITMA AÇIKLAMALARI                  ║" << endl;
    cout << "╚════════════════════════════════════════════════════════════════════════════╝\n" << endl;
    
    // ===== RÖKÜRSİON =====
    cout << ">>> RECURSION (ÖZYINELEME) <<<" << endl;
    cout << "5! = " << faktorial_recursive(5) << endl;
    cout << "2^10 = " << uss_hesapla(2, 10) << endl;
    cout << "Hanoi (3 disk):" << endl;
    hanoi(3, 'A', 'C', 'B');
    
    int arr[] = {1, 2, 3, 4, 5};
    cout << "Dizi toplamı: " << dizi_toplami_recursive(arr, 5) << endl;
    
    // ===== ŞEKİLLER =====
    simetrik_piramit(4);
    kum_saati(4);
    pascal_ucgeni(6);
    floyd_ucgeni(5);
    
    // ===== DYNAMIC PROGRAMMING =====
    cout << "\n>>> DYNAMIC PROGRAMMING <<<" << endl;
    cout << "F(15) DP: " << fib_dp(15) << endl;
    cout << "Merdiven(5): " << merdiven_problem(5) << " yol" << endl;
    
    vector<int> coins = {1, 2, 5};
    cout << "Coin Change (amount=5): " << coin_change(coins, 5) << " para" << endl;
    
    // ===== GRAPH OPERATIONS =====
    cout << "\n>>> GRAPH OPERATIONS (DFS / BFS) <<<" << endl;
    vector<vector<int>> graph = {{1, 2}, {0, 3}, {0, 3}, {1, 2}};
    dfs_stack(0, graph);
    bfs_queue(0, graph);
    
    // ===== GREEDY =====
    cout << "\n\n>>> GREEDY ALGORITHM <<<" << endl;
    vector<pair<int, int>> activities = {{1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};
    activity_selection(activities);
    
    cout << "\n\n╔════════════════════════════════════════════════════════════════════════════╗" << endl;
    cout << "║                    DETAYLI ANLATIMLAR TAMAMLANDI                          ║" << endl;
    cout << "╚════════════════════════════════════════════════════════════════════════════╝" << endl;
    
    return 0;
}
