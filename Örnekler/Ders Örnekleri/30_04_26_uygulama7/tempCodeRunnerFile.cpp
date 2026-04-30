
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