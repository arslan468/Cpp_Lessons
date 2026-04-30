#include <iostream>
#include <fstream>
#include <string>
#include <fstream>

// Gerekli diğer kütüphaneleri ekleyiniz
using namespace std;
/** * LABORATUVAR GÖREVİ:
* 1. stokuListele: Dosyayı okuma modunda açıp içeriği ekrana basmalı.
* 2. urunEkle: Mevcut veriyi bozmadan dosya sonuna ekleme yapmalı.
* 3. urunSil & fiyatGuncelle: "Oku-Yaz" algoritmasını kullanmalı.
* (İpucu: Orijinal dosyayı okurken, kriter dışı verileri geçici bir dosyaya
aktarın.)
*/
// Fonksiyon prototiplerini buraya tanımlayın
void stokuListele(const string& dosyaAdi);
void urunEkle(const string& dosyaAdi, const string& urun, double fiyat, int adet);
void urunSil(const string& dosyaAdi, const string& hedef);
void fiyatGuncelle(const string& dosyaAdi, const string& hedef, double yeniFiyat);

int main() {
    string dosya_adim = "urun_stok.txt";
    // 1. ADIM: urun_stok.txt dosyasını oluşturun ve içine örnek 3 adet ürün yazdırın.
    ofstream kls;
    kls.open(dosya_adim);
    if (!kls)
    {
        cout << "Dosya açılamadı!" << endl;
        return 1;
    }
    else
    {

        kls << "Modem" << " " << "2350" << " " << "33"<<endl;
        kls  << "Mouse" << " " << " 1599" << " " << "12"<< endl;
        kls << "Klavye" << " " << "2200" << " " << "2"<< endl;

        cout << endl  << "3 adet ürün urun_stok adlı dosyaya yazıldı" << endl << endl;
    }
    kls.close();

    stokuListele(dosya_adim);

    //string yeni_urun = "Pil";
    //double yeni_fiyat = 58, guncel_f=558;
    //int yeni_stok = 4;
    //urunEkle(dosya_adim, yeni_urun, yeni_fiyat, yeni_stok);
    //urunSil(dosya_adim, yeni_urun);
    //fiyatGuncelle(dosya_adim, yeni_urun, guncel_f);
    //stokuListele(dosya_adim);

    int secim = 0;
    string urunAdi;
    double fiyat;
    int adet;

    while (secim != 5) 
    {
        cout << "\n--- MENÜ ---\n";
        cout << "1) Stok listeleme\n";
        cout << "2) Yeni ürün ekleme\n";
        cout << "3) Ürün sil\n";
        cout << "4) Fiyat güncelle (ürün adina göre)\n";
        cout << "5) Çıkış\n";
        cout << "Seçiminiz: ";
        cin >> secim;

        cout << endl;

        switch (secim) 
        {
            case 1:
                stokuListele(dosya_adim);
                break;
                
            case 2:
                cout << "Eklenecek urun adini, fiyatini ve adedini girin (Boşluk birakarak): ";
                cin >> urunAdi >> fiyat >> adet;
                urunEkle(dosya_adim, urunAdi, fiyat, adet);
                break;
                
            case 3:
                cout << "Silinecek urunun adini girin: ";
                cin >> urunAdi;
                urunSil(dosya_adim, urunAdi);
                break;
                
            case 4:
                cout << "Güncellenecek ürünün adını ve yeni fiyatini girin : ";
                cin >> urunAdi >> fiyat;
                fiyatGuncelle(dosya_adim, urunAdi, fiyat);
                break;
                
            case 5:
                cout << "Programdan cikiliyor..." << endl;
                break;
                
            default:
                cout << "Gecersiz secim! Lutfen tekrar deneyin." << endl;
                break;
        }
    }







    return 0;
}



// 4. ADIM: Fonksiyon gövdelerini aşağıya yazın.

void stokuListele(const string& dosyaAdi)
{
    cout << endl << "LİSTELEME BAŞLADI" << endl;
    ifstream ikra;
    ikra.open(dosyaAdi, ios::in);
    if (!ikra)
    {
        cout << "Dosya açılamadı! stok listele fonksiyonu" << endl;
        return;
    }
    string isim;
    double fiyat=0;
    int stok=0;

    while (ikra >> isim >> fiyat >> stok)
    {
        cout << isim << ": " << fiyat << "TL    Stok Adedi: " << stok <<  endl;
    }

    ikra.close();   
    cout << endl << "LİSTELEME BİTTİ" << endl;

}

void urunEkle(const string& dosyaAdi, const string& urun, double fiyat, int adet)
{
    ofstream f;

    f.open(dosyaAdi, ios::app);
    if (!f)
    {
        cout << "Dosya açılamadı! ürünekle fonksiyonu" << endl;
        return;
    }

    f << urun << " " << fiyat << " " << adet << endl; 
    f.close();
}

void urunSil(const string& dosyaAdi, const string& hedef)
{
    ifstream okuma;
    okuma.open(dosyaAdi, ios::in);// normalde varsayılan ama kullanımı göstermek için bu şekilde kullanmak istedim
    ofstream yazma;
    yazma.open("gecici.txt", ios::out);// normalde varsayılan ama kullanımı göstermek için bu şekilde kullanmak istedim

    if (!okuma || !yazma )
    {
        cout << "Dosya açılamadı! ürün sil metodu" << endl;
        return;
    }

    string isim;
    double fiyat =0;
    int stok = 0;
    bool silindi = false;
    while (okuma >> isim >> fiyat >> stok)
    {
        if (isim != hedef)
        {
            yazma << isim << " " << fiyat << " " << stok << endl; 
        }
        else
        {
            silindi = true;
        }
    }

    okuma.close();
    yazma.close();

    remove(dosyaAdi.c_str());
    rename("gecici.txt", dosyaAdi.c_str());
    if (silindi)
    {
        cout << hedef << " isimli ürün başarıyla silindi." << endl;
    }
    else
    {
        cout << hedef << " isimli ürün bulunamadı" << endl;
    }
    
    

    
}

void fiyatGuncelle(const string& dosyaAdi, const string& hedef, double yeniFiyat)
{
    ifstream okuma;
    okuma.open(dosyaAdi, ios::in);// normalde varsayılan ama kullanımı göstermek için bu şekilde kullanmak istedim
    ofstream yazma;
    yazma.open("gecici.txt", ios::out);// normalde varsayılan ama kullanımı göstermek için bu şekilde kullanmak istedim

    if (!okuma || !yazma )
    {
        cout << "Dosya açılamadı! ürün sil metodu" << endl;
        return;
    }

    string isim;
    double fiyat =0;
    int stok = 0;
    bool guncellendi = false;
    while (okuma >> isim >> fiyat >> stok)
    {
        if (isim == hedef)
        {
            fiyat = yeniFiyat;
            guncellendi = true;
        }
        yazma << isim << " " << fiyat << " " << stok << endl; 
    }

    okuma.close();
    yazma.close();

    remove(dosyaAdi.c_str());
    rename("gecici.txt", dosyaAdi.c_str());
    if (guncellendi)
    {
        cout << hedef << " isimli ürünün fiyatı başarıyla güncellendi. Yeni Fiyat: " << yeniFiyat << "TL" << endl;
    }
    else
    {
        cout << hedef << " isimli ürün bulunamadı" << endl;
    }
    
}
// Önemli: Dosya açma modlarını (ios::in, ios::out, ios::app) doğru seçtiğiniz denemin olun.