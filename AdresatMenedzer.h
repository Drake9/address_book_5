#include <iostream>
#include <vector>
#include "PlikZAdresatami.h"

using namespace std;

class AdresatMenedzer{

    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;
    int idOstatniegoAdresata, idUsunietegoAdresata;

    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);

public:

    AdresatMenedzer(string nazwaPlikuZAdresatami): plikZAdresatami(nazwaPlikuZAdresatami){
        idOstatniegoAdresata = 0;
        idUsunietegoAdresata = 0;
    };

    bool czyKsiazkaJestPusta();
    void wyczyscListeAdresatow();
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    void wyswietlWszystkichAdresatow();
    void wyswietlDaneAdresata(Adresat adresat);
    void dodajAdresata(int idZalogowanegoUzytkownika);
};
