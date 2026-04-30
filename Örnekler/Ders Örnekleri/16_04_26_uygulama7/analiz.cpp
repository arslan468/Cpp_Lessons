#include "analiz.h"

double gunlukOrtalama(const double* sicakliklar, int n)
{
    double ort=0;
    for(int i=0; i < n; i++)
    {
        ort += sicakliklar[i];
    }
    ort = (ort/n);
    return ort;

}

double enYuksek(const double* sicakliklar, int n)
{
    double enYuk=0;
    for(int i=0; i < n; i++)
    {
        if(enYuk < sicakliklar[i])
        {
            enYuk = sicakliklar[i];
        }
    }
    return enYuk;
}

double enDusuk(const double* sicakliklar, int n)
{
    double enDus=1000;
    for(int i=0; i<n; i++)
    {
        if(enDus > sicakliklar[i])
        {
            enDus = sicakliklar[i];
        }
    }

    return enDus;

}