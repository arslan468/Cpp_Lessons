#include <iostream>
#include <string>
#include <cctype>
#include "../../selam.h"



Bir ağ taramasında bulunan açık port numaralarını bellekte tutan ve en yüksek port numarasını (genelde en şüpheli olanı) bulup sıfırlayan bir sistem yazmanı istiyorum.

Görevlerin:

int* enYuksekPortBul(int* portlar, int boyut)

Bu fonksiyon dinamik diziyi ve boyutunu alacak.

Dizideki en büyük port numarasını bulacak.

Dikkat: En büyük değeri değil, o elemanın bellekteki adresini (pointer) döndürecek. (İpucu: Hafta 5, Fonksiyonun Pointer Döndürmesi).

void portuKapat(int& port)

Parametre olarak bir int değişkenin referansını (&) alacak.

Aldığı portun değerini kalıcı olarak 0 yapacak.

main İçindeki Akış:

Kullanıcıdan kaç adet açık port bulunduğunu iste ve bu boyutta bir dinamik dizi oluştur (new[]).

Diziye birkaç rastgele port numarası ata (Örn: 22, 80, 8080, 443).

enYuksekPortBul fonksiyonunu çağırarak dönen adresi bir pointer değişkende tut. Bulunan portun adresini ve değerini ekrana yazdır.

Bulduğun bu pointer'ı kullanarak, o portu portuKapat fonksiyonuna gönder ve sıfırla. (Burada pointer'ın gösterdiği değeri referans bekleyen bir fonksiyona nasıl sokacağına dikkat et).

Son güncel diziyi ekrana yazdırıp, dinamik belleği güvenli bir şekilde iade et.

using namespace std;

int* enYuksekPortBul(int* portlar, int boyut);

void portuKapat(int& port);

int* dizi_olustur(int boyut);

int main()
{

    int a = 0;
    cout << "Kaç adet açık port var: ";
    cin >> a;

    int *port_dizi = dizi_olustur(a);
    cout << port_dizi;

}

int* dizi_olustur(int boyut)
{
    int** portlar_iki_boyutlu = new int*[boyut];

    return *portlar_iki_boyutlu;
}

int* enYuksekPortBul(int* portlar, int boyut)
{

}

void portuKapat(int& port)
{

}

