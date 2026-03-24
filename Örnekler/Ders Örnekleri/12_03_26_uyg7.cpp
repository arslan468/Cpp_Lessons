#include <iostream>
#include <string>
#include "../selam.h"

using namespace std;

void hasarAl(int *hp, int hasar);

void seviyeAtla(int &hp, int &attack, int &armor, double katsayi);

void swapEkipman(int &attack1, int &armor1, int &attack2, int &armor2);

int *enDusukHP(int *hp1, int *hp2, int *hp3);

void karakterYazdir(string isim, int hp, int attack, int armor);

int main()
{
    // Karakter Tanımlamaları
    string isim1 = "Savaşçı", isim2 = "Büyücü", isim3 = "Koruyucu";
    int hp1 = 150, atk1 = 80, arm1 = 60;
    int hp2 = 90, atk2 = 120, arm2 = 30;
    int hp3 = 200, atk3 = 40, arm3 = 90;
    cout << "--- Karakterler Hazırlandı ---" << endl;
    // TODO: karakterYazdir fonksiyonunu kullanarak başlangıç durumlarını basın.
    karakterYazdir(isim1, hp1, atk1, arm1);
    karakterYazdir(isim2, hp2, atk2, arm2);
    karakterYazdir(isim3, hp3, atk3, arm3);

    // SENARYO 1: Çatışma
    // TODO: Savaşçı 50, Büyücü 100 hasar alıyor. hasarAl fonksiyonunu doğru parametrelerle çağırın.
    int *ptr1 = &hp1;
    int *ptr2 = &hp2;
    int *ptr3 = &hp3;

    hasarAl(ptr1, 50);
    hasarAl(ptr2, 100);

    cout << "\n[Savaş gerçekleşti!]" << endl;
    // SENARYO 2: Gelişim
    // TODO: Koruyucu seviye atlıyor (katsayı: 1.5). seviyeAtla fonksiyonunuçağırın.
    int &rfrs_atk = atk3;
    int &rfrs_arm = arm3;
    int &rfrs_hp = hp3;
    seviyeAtla(rfrs_hp, rfrs_atk, rfrs_arm, 1.5);
    cout << "\n[Koruyucu seviye atladı!]" << endl;

    // SENARYO 3: Strateji Değişimi
    // TODO: Savaşçı ve Büyücü ekipmanlarını (Atk ve Arm) takas ediyor.
    swapEkipman(atk1, arm1, atk2, arm2);
    cout << "\n[Ekipman takası yapıldı!]" << endl;

    // SENARYO 4: Kritik Müdahale
    // TODO: enDusukHP ile en zayıf karakteri bulun ve adres üzerinden HP'sini 50artırın.
    int *dusukcan = enDusukHP(ptr1, ptr2, ptr3);
    cout << "\n[Kritik İyileştirme Uygulanıyor...]" << endl;
    *dusukcan += 50;

    // Final Durumu
    cout << "\n=== OYUN SONU İSTATİSTİKLERİ ===" << endl;
    // TODO: Tüm karakterlerin son durumunu yazdırın.
    karakterYazdir(isim1, hp1, atk1, arm1);
    karakterYazdir(isim2, hp2, atk2, arm2);
    karakterYazdir(isim3, hp3, atk3, arm3);

    return 0;
}

void hasarAl(int *hp, int hasar)
{
    if (*hp > hasar)
    {
        cout << *hp << endl;
        *hp -= hasar;
        cout << *hp << endl;
    }
    else
    {
        *hp = 0;
        cout << "Öldünüz Can: 0";
    }
}

void seviyeAtla(int &hp, int &attack, int &armor, double katsayi)
{
    hp = hp * katsayi;
    attack = attack * katsayi;
    armor = armor * katsayi;
}

void swapEkipman(int &attack1, int &armor1, int &attack2, int &armor2)
{
    int tempAttack = attack1;
    attack1 = attack2;
    attack2 = tempAttack;

    int tempArmor = armor1;
    armor1 = armor2;
    armor2 = tempArmor;
}

int *enDusukHP(int *hp1, int *hp2, int *hp3)
{
    int *enDusuk = hp1;

    if (*hp2 < *enDusuk)
        enDusuk = hp2;
    if (*hp3 < *enDusuk)
        enDusuk = hp3;
    return enDusuk;
}

void karakterYazdir(string isim, int hp, int attack, int armor)
{
    cout << endl
         << "===========" << endl
         << "İsim: " << isim << endl
         << "Can: " << hp << endl
         << "Saldırı: " << attack << endl
         << "Kalkan: " << armor << endl
         << "===========" << endl;
}