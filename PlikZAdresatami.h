#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "MetodyPomocnicze.h"
#include "Adresat.h"

using namespace std;

class PlikZAdresatami{

    int idOstatniegoAdresata;
    const string NAZWA_PLIKU_Z_ADRESATAMI;
    const string NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI;

    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    string zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(Adresat adresat);

public:

    PlikZAdresatami(string nazwaPlikuZAdresatami):
        NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami),
        NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI("Adresaci_tymczasowy.txt")
    {
        idOstatniegoAdresata = 0;
    };
    int pobierzIdOstatniegoAdresata();
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    bool dopiszAdresataDoPliku(Adresat adresat);
    bool usunAdresataZPliku(int idUsuwanegoAdresata);
    bool zaktualizujDaneEdytowanegoAdresataWPliku(Adresat adresat);

};
