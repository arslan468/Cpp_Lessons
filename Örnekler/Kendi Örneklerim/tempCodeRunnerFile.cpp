    int adet = sizeof(notlar) / sizeof(notlar[0]);
    for (int i = 0; i < adet; i++) {
    cout << notlar[i] << " ";
    }
    // → 85 90 72 68 95
    for (int not : notlar) {
    cout << not << " ";
    }