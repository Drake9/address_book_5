#include <iostream>

using namespace std;

class Adresat{

    int id, idUzytkownika;
    string imie, nazwisko, numerTelefonu, email, adres;

public:

    void ustawId(int noweID);
    void ustawIdUzytkownika(int noweID);
    void ustawImie(string noweImie);
    void ustawNazwisko(string noweNazwisko);
    void ustawNumerTelefonu(string nowyNumerTelefonu);
    void ustawEmail(string nowyEmail);
    void ustawAdres(string nowyAdres);

    int pobierzId();
    int pobierzIdUzytkownika();
    string pobierzImie();
    string pobierzNazwisko();
    string pobierzNumerTelefonu();
    string pobierzEmail();
    string pobierzAdres();
};
