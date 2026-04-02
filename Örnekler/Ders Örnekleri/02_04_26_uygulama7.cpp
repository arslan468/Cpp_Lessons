#include <iostream>
#include "../selam.h"
#include <string>
#include <cctype>
using namespace std;
// TODO: 6 fonksiyonun prototiplerini buraya yazın

int *hastaKayitAc(int n);
void skorGir(int *hastalar, int n);
double ortalamaHesapla(const int *hastalar, int n);
int maksimumSkor(const int *hastalar, int n);
int minimumSkor(const int *hastalar, int n);
int *hastaEkle(int *eskiListe, int eskiN, int yeniSkor);

int ek_hasta_giris();
void skor_yazdir(int* hastalar, int n);


int main()
{
    selamlama();
    int n;
    cout << "Acilde ki hasta sayısı:  ";
    cin >> n;
    int *hastalar = hastaKayitAc(n);
    skorGir(hastalar, n);
    // TODO: Raporu yazdırın

    // Ortalama, en yüksek ve en düşük skoru ekrana basın
    cout << "Ortalama skor: " << ortalamaHesapla(hastalar, n) << endl;
    cout << "En yüksek skor: " << maksimumSkor(hastalar, n) << endl;
    cout << "En düşük skor: " << minimumSkor(hastalar, n) << endl;

    // Yeni hasta geldi — listeye ekle
    int yeniSkor;
    yeniSkor = ek_hasta_giris();

    hastalar = hastaEkle(hastalar, n, yeniSkor);
    n++;
    // TODO: Güncel listeyi yazdırın
    cout << "---- Güncel hasta skorları  ----" << endl;
    skor_yazdir(hastalar, n);
    cout << endl;
    // TODO: Belleği temizleyin
    delete[] hastalar;

    veda();
    return 0;
}
// TODO: 6 fonksiyonun gövdelerini buraya yazın

int *hastaKayitAc(int n)
{
    int *hastalar = new int[n];
    for(int i = 0; i < n; i++)
    {
        hastalar[i] = 0;
        cout << endl << hastalar[i] << endl;
    }
    return hastalar;
}

void skorGir(int *hastalar, int n)
{
    cout << "Hasta skorlarini giriniz (1-10 arasi): " << endl;
    for (int i = 0; i < n; i++)
    {
        while (true)
        {
            cout << "Hasta " << i + 1 << ": ";
            cin >> hastalar[i];

            if (hastalar[i] >= 1 && hastalar[i] <= 10) 
            {
                break;
            } 
            else 
            {
                cout << "YANLIŞ GİRİŞ🚨: Skor 1 ile 10 arasinda olmalidir. Lutfen tekrar giriniz.❗️" << endl;
            }
        }
    }
}

double ortalamaHesapla(const int *hastalar, int n)
{
    int toplam = 0;
    for (int i = 0; i < n; i++)
    {
        toplam += hastalar[i];
    }
    return (double)toplam / n;
}
int maksimumSkor(const int *hastalar, int n)
{
    int max = hastalar[0];
    for (int i = 1; i < n; i++)
    {
        if (hastalar[i] > max)
        {
            max = hastalar[i];
        }
    }
    return max;
}
int minimumSkor(const int *hastalar, int n)
{
    int min = hastalar[0];
    for (int i = 1; i < n; i++)
    {
        if (hastalar[i] < min)
        {
            min = hastalar[i];
        }
    }
    return min;
}
int *hastaEkle(int *eskiListe, int eskiN, int yeniSkor)
{
    int *yeniListe = new int[eskiN + 1];
    for (int i = 0; i < eskiN; i++)
    {
        yeniListe[i] = eskiListe[i];
    }
    yeniListe[eskiN] = yeniSkor;
    delete[] eskiListe;
    return yeniListe;
}

int ek_hasta_giris()
{
    int x=0;
    while (true)
        {
            cout << "Yeni hasta skoru: ";
            cin >> x;
            if (x>= 1 && x <= 10) 
            {
                return x;
                break;
            } 
            else 
            {
                cout << "YANLIŞ GİRİŞ🚨: Skor 1 ile 10 arasinda olmalidir. Lutfen tekrar giriniz.❗️" << endl;
            }
        }
}

void skor_yazdir(int* hastalar, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << endl << (i+1) << " numaralı hasta skoru: " << hastalar[i] << endl;
    }

}
