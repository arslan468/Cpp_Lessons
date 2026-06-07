#include <iostream>
#include <string>
#include <cstring>

using namespace std;


int toplam(int dizi[], int boyut);
void carpim(int dizi[],int boyut, int deger);
void yazdir(int dizi[], int boyut);
void sifirla(int dizi[], int boyut);
void elemandegistirme(int dizi[], int indeks, int yenideger);
 
int main()
{
    int sayidizi[] = {10,20,30,40,50};

    int diziboyut = (sizeof(sayidizi)/sizeof(sayidizi[0]));

    int secim=0;
    while (secim!=4)
    {
            

        cout << "\n Yapmak istediğiniz işlemi seçiniz\n1.Dizinin Elemanların Topla\n2.Dizin tüm elemanlarını belirdiğin bir sayıyla çarp\n3.Dizinin tamamını sıfırla\n4.Çıkış\n5.Dizinin elemanlarını değiştirme"<< endl;
        cin >> secim;

        switch (secim)
        {
        case 1:
            cout << "Dizi elemanlarının toplamı: " << toplam(sayidizi, diziboyut)<<endl;
            break;
        case 2:
            int katsayi;
            cout << "Dizinin elemanları kaç ile çarpılsın? " << endl;
            cin >> katsayi;
            carpim(sayidizi, diziboyut, katsayi);
            yazdir(sayidizi,diziboyut);
            cout << "Dizi elemanlarının yeni toplamı: " << toplam(sayidizi, diziboyut)<<endl;
            break;
        case 3:
            sifirla(sayidizi,diziboyut);
            yazdir(sayidizi, diziboyut);
            
            break;
        case 5:
            int dizieleman,yenideger;
            cout << "Dizinin kaçıncı elemanını değiştirmek istersiniz: ";
            cin >> dizieleman;
            dizieleman--;
            cout << "Yeni değer ne olsun? ";
            cin >> yenideger;
            elemandegistirme(sayidizi, dizieleman, yenideger);
            yazdir(sayidizi, diziboyut);
        default:
            break;
        }

    }

    return 0;
}

int toplam(int dizi[], int boyut)
{
    int toplam=0;
    for (int i = 0; i < boyut; i++)
    {
        toplam+=dizi[i];
    }
    return toplam;
}

void carpim(int dizi[],int boyut,int deger)
{
    for (int i = 0; i < boyut; i++)
    {
        dizi[i] = dizi[i] * deger;
    }
}

void yazdir(int dizi[], int boyut)
{
    for(int i=0; i <boyut; i++)
    {
        cout << "Dizinin " << (i+1)<< ". elemanı: " << dizi[i]<< endl;
    }
}

void sifirla(int dizi[], int boyut)
{
    for(int i=0; i < boyut; i++)
    {
        dizi[i] = 0;
    }
}

void elemandegistirme(int dizi[], int indeks, int yenideger)
{
    dizi[indeks] = yenideger;
}
