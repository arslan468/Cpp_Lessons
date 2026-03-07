#include <iostream>
#include <iomanip>
using namespace std;

double sinyalFiltrele(double hamMesafe);
void hataRaporla();
bool kritikSeviye(double mesafe);
void sistemDurumu(double ham, double filtreli);
void acilFren();

int main() {
    double sensorVerileri[] = {25.5, -5.0, 30.2, 999.9, 4.0, 45.0};

    cout << "--- OTONOM ARAC KONTROL MERKEZI ---" << endl;

    for (int i = 0; i < 6; i++) 
    {
        double ham = sensorVerileri[i];
        // 1. Veriyi filtrele
        double temiz = sinyalFiltrele(ham);
        // 2. Durumu ekrana yazdir
        sistemDurumu(ham, temiz);
        // 3. Kritik mesafe kontrolü yap
        if (kritikSeviye(temiz)) 
        {
        acilFren();
        }
    }

    return 0;
}

double sinyalFiltrele(double hamMesafe)
{
    if (hamMesafe > 0 && hamMesafe < 100)
    {
        return hamMesafe;
    }
    else
    {
        hataRaporla();
        return 0;
    }
}

void hataRaporla()
{
    static int sayac;
    sayac++;
    cout << endl << "Sensör hatası! Toplam Hata: " << sayac << endl;
}

bool kritikSeviye(double mesafe)
{
    if (mesafe < 5 )
    {
        return true;
    }
    else
    {
        return false;
    }
}

void sistemDurumu(double ham, double filtreli)
{
    cout << endl << "Ham veri: " << ham << "    //      " << "Filtrelenmiş veri: " << filtreli << endl; 
}

void acilFren()
{
    cout << endl << "!!! ACİL DURUM FRENİ AKTİF !!!" << endl;
}