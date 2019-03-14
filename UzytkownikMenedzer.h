#include <iostream>
#include <vector>
#include "PlikZUzytkownikami.h"

using namespace std;

class UzytkownikMenedzer{

    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;
    PlikZUzytkownikami plikZUzytkownikami;

    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    Uzytkownik podajDaneNowegoUzytkownika();

public:

    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();

};
