#include <iostream>
#include <windows.h>
#include "AdresatMenedzer.h"

using namespace std;

void AdresatMenedzer::wyswietlWszystkichAdresatow(){
    system("cls");
    if (!adresaci.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat){

    cout << endl << "Id:         " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}

void AdresatMenedzer::dodajAdresata(){
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    if(plikZAdresatami.dopiszAdresataDoPliku(adresat))
        cout << "Nowy adresat zostal dodany." << endl;
    else
        cout << "NIE udalo sie dodac nowego adresata do pliku." << endl;
    system("pause");
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata(){
    Adresat adresat;

    adresat.ustawId(plikZAdresatami.pobierzIdOstatniegoAdresata()+1);
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cout << "Podaj imie: ";
    adresat.ustawImie(MetodyPomocnicze::wczytajLinie());
    adresat.ustawImie(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzImie()));

    cout << "Podaj nazwisko: ";
    adresat.ustawNazwisko(MetodyPomocnicze::wczytajLinie());
    adresat.ustawNazwisko(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzNazwisko()));

    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres(MetodyPomocnicze::wczytajLinie());

    return adresat;
}

void AdresatMenedzer::usunAdresata(){
    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    int idUsuwanegoAdresata = podajIdWybranegoAdresata();

    char znak;
    bool czyIstniejeAdresat = false;

    for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++){
        if (itr -> pobierzId() == idUsuwanegoAdresata){

            czyIstniejeAdresat = true;
            wyswietlDaneAdresata(*itr);
            cout << endl << "Potwierdz usuniecie naciskajac klawisz 't': ";
            znak = MetodyPomocnicze::wczytajZnak();
            if (znak == 't' || znak == 'T'){
                if(plikZAdresatami.usunAdresataZPliku(idUsuwanegoAdresata)){
                    adresaci.erase(itr);
                    cout << endl << endl << "Szukany adresat zostal USUNIETY." << endl << endl;
                }
                else
                    cout << endl << endl << "NIE udalo sie usunac adresata z pliku." << endl;
            }
            else{
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety." << endl << endl;
            }
            system("pause");
            return;
        }
    }
    if (czyIstniejeAdresat == false){
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej." << endl << endl;
        system("pause");
    }
}

int AdresatMenedzer::podajIdWybranegoAdresata(){
    int idWybranegoAdresata = 0;
    cout << "Podaj numer ID Adresata: ";
    idWybranegoAdresata  = MetodyPomocnicze::wczytajLiczbeCalkowita();
    return idWybranegoAdresata;
}

void AdresatMenedzer::edytujAdresata(){
    system("cls");
    Adresat adresat;
    int idEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";
    string tymczasowa = "";
    char wybor;
    bool czyIstniejeAdresat = false, sukces = true;

    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    idEdytowanegoAdresata = podajIdWybranegoAdresata();

    for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
    {
        if (itr -> pobierzId() == idEdytowanegoAdresata)
        {
            czyIstniejeAdresat = true;
            wyswietlDaneAdresata(*itr);
            wybor = wybierzOpcjeZMenuEdycja();

            switch (wybor)
            {
            case '1':
                cout << "Podaj nowe imie: ";
                tymczasowa = MetodyPomocnicze::wczytajLinie();
                itr -> ustawImie(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(tymczasowa));
                sukces = plikZAdresatami.zaktualizujDaneEdytowanegoAdresataWPliku(*itr);
                break;
            case '2':
                cout << "Podaj nowe nazwisko: ";
                tymczasowa = MetodyPomocnicze::wczytajLinie();
                itr -> ustawNazwisko(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(tymczasowa));
                sukces = plikZAdresatami.zaktualizujDaneEdytowanegoAdresataWPliku(*itr);
                break;
            case '3':
                cout << "Podaj nowy numer telefonu: ";
                itr -> ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());
                sukces = plikZAdresatami.zaktualizujDaneEdytowanegoAdresataWPliku(*itr);
                break;
            case '4':
                cout << "Podaj nowy email: ";
                itr -> ustawEmail(MetodyPomocnicze::wczytajLinie());
                sukces = plikZAdresatami.zaktualizujDaneEdytowanegoAdresataWPliku(*itr);
                break;
            case '5':
                cout << "Podaj nowy adres zamieszkania: ";
                itr -> ustawAdres(MetodyPomocnicze::wczytajLinie());
                sukces = plikZAdresatami.zaktualizujDaneEdytowanegoAdresataWPliku(*itr);
                break;
            case '6':
                cout << endl << "Powrot do menu uzytkownika." << endl << endl;
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                break;
            }
        }
    }
    if (czyIstniejeAdresat == false){
        cout << endl << endl << "Nie ma takiego adresata." << endl << endl;
    }
    else if (!sukces){
        cout << endl << endl << "NIE udalo sie usunac adresata z pliku." << endl;
    }
    system("pause");
}

char AdresatMenedzer::wybierzOpcjeZMenuEdycja(){
    char wybor;

    cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Ktore dane zaktualizowac: " << endl;
    cout << "1 - Imie" << endl;
    cout << "2 - Nazwisko" << endl;
    cout << "3 - Numer telefonu" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Adres" << endl;
    cout << "6 - Powrot " << endl;
    cout << endl << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}

void AdresatMenedzer::wyszukajAdresatowPoImieniu(){
    string imiePoszukiwanegoAdresata = "";
    int liczbaAdresatow = 0;

    system("cls");
    if (!adresaci.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        imiePoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
        imiePoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imiePoszukiwanegoAdresata);

        for (vector <Adresat>::iterator  itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            if (itr -> pobierzImie() == imiePoszukiwanegoAdresata)
            {
                wyswietlDaneAdresata(*itr);
                liczbaAdresatow++;
            }
        }
        wyswietlLiczbeWyszukanychAdresatow(liczbaAdresatow);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AdresatMenedzer::wyszukajAdresatowPoNazwisku(){
    string nazwiskoPoszukiwanegoAdresata;
    int liczbaAdresatow = 0;

    system("cls");
    if (!adresaci.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O NAZWISKU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o nazwisku: ";
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwiskoPoszukiwanegoAdresata);

        for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            if (itr -> pobierzNazwisko() == nazwiskoPoszukiwanegoAdresata)
            {
                wyswietlDaneAdresata(*itr);
                liczbaAdresatow++;
            }
        }
         wyswietlLiczbeWyszukanychAdresatow(liczbaAdresatow);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AdresatMenedzer::wyswietlLiczbeWyszukanychAdresatow(int liczbaAdresatow){
    if (liczbaAdresatow == 0)
        cout << endl << "Brak adresatow spelniajacych podane kryteria." << endl;
    else
        cout << endl << "Liczba wynikow wyszukiwania: " << liczbaAdresatow << endl << endl;
}
