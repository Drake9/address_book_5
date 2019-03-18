#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

#ifndef METODY_POMOCNICZE_H
#define METODY_POMOCNICZE_H

class MetodyPomocnicze{

public:
    static string konwerjsaIntNaString(int liczba);
    static int konwersjaStringNaInt(string liczba);
    static bool czyPlikJestPusty(fstream &plikTekstowy);
    static char wczytajZnak();
    static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    static string wczytajLinie();
};

#endif
