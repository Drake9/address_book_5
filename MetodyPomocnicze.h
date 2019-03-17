#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

class MetodyPomocnicze{

public:
    static string konwerjsaIntNaString(int liczba);
    static bool czyPlikJestPusty(fstream &plikTekstowy);
    static char wczytajZnak();
};
