#include <iostream>
#include <string>
#include "../../selam.h"
using namespace std;

class Calisan {
private:
    // TODO: Gerekli değişkenleri tanımlayınız (ad, departman, maas)
    string personelAdi;
    string calistigiDepartman;
    double aylikMaas;

public:
    // 1. ADIM: Varsayılan ve parametreli yapıcıları (constructor)
    
    // Varsayılan constructor
    Calisan() {
        personelAdi = "-";
        calistigiDepartman = "-";
        aylikMaas = 0.0;
    }
    
    // Parametreli constructor
    Calisan(string ad, string departman, double maas) {
        personelAdi = ad;
        calistigiDepartman = departman;
        aylikMaas = maas;
    }
    
    // 2. ADIM: Private değişkenlere erişim için gerekli 'Getter' metotları
    string getAd() {
        return personelAdi;
    }
    
    string getDepartman() {
        return calistigiDepartman;
    }
    
    double getMaas() {
        return aylikMaas;
    }
    
    void zamYap(double oran) {
        aylikMaas = aylikMaas + (aylikMaas * oran / 100.0);
    }
    
    void bilgiGoster() {
        cout << personelAdi << " | " << calistigiDepartman << " | " 
             << aylikMaas << " TL" << endl;
    }
};

int main() {
    selamlama();
    Calisan personelListesi[3];
    
    personelListesi[0] = Calisan("Mehmet", "Yazilim", 58000);
    personelListesi[1] = Calisan("Alp", "Pazarlama", 38000);
    personelListesi[2] = Calisan("Arslan", "Yazilim", 45000);



    
    cout << "===== BAŞLANGIÇ MAAŞLARI =====" << endl;
    for(int i = 0; i < 3; i++) {
        personelListesi[i].bilgiGoster();
    }
    cout << endl;






    
    double zamOrani = 15.0;
    cout << "===== %" << zamOrani << " ZAM UYGULANMASI =====" << endl;
    
    for(int i = 0; i < 3; i++) {
        personelListesi[i].zamYap(zamOrani);
    }
    
    cout << "Tüm çalışanlara %" << zamOrani << " zam uygulandı." << endl;
    cout << endl;
    
    cout << "===== ZAM SONRASI MAAŞLAR =====" << endl;
    for(int i = 0; i < 3; i++) {
        personelListesi[i].bilgiGoster();
    }
    cout << endl;
    



    
    cout << "===== EN YÜKSEK MAAŞLI PERSONEL =====" << endl;
    
    double enYuksekMaas = personelListesi[0].getMaas();
    int enYuksekMaasliIndex = 0;
    
    for(int i = 1; i < 3; i++) {
        if(personelListesi[i].getMaas() > enYuksekMaas) {
            enYuksekMaas = personelListesi[i].getMaas();
            enYuksekMaasliIndex = i;
        }
    }
    
    cout << "En yüksek maaşlı çalışan: ";
    personelListesi[enYuksekMaasliIndex].bilgiGoster();
    cout << endl;



        
    cout << "===== YAZILIM DEPARTMANI ÇALIŞANLARI =====" << endl;
    
    string arananDepartman = "Yazilim";
    bool yazilimDprt = false;
    
    for(int i = 0; i < 3; i++) {
        if(personelListesi[i].getDepartman() == arananDepartman) {
            personelListesi[i].bilgiGoster();
            yazilimDprt = true;
        }
    }


    
    if(!yazilimDprt) {
        cout << "Yazilim departmanında çalışan bulunamadı." << endl;
    }

    veda();
    return 0;
}