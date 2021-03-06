#include <iostream>
#include "Adresat.h"

using namespace std;

void Adresat::ustawId(int noweID){
    if(noweID >= 0)
        id = noweID;
}

void Adresat::ustawIdUzytkownika(int noweID){
    if(noweID >= 0)
        idUzytkownika = noweID;
}

void Adresat::ustawImie(string noweImie){
    if(noweImie != "")
        imie = noweImie;
}

void Adresat::ustawNazwisko(string noweNazwisko){
    if(noweNazwisko != "")
        nazwisko = noweNazwisko;
}

void Adresat::ustawNumerTelefonu(string nowyNumerTelefonu){
    numerTelefonu = nowyNumerTelefonu;
}

void Adresat::ustawEmail(string nowyEmail){
    email = nowyEmail;
}

void Adresat::ustawAdres(string nowyAdres){
    adres = nowyAdres;
}

/**********************************************/

int Adresat::pobierzId(){
    return id;
};

int Adresat::pobierzIdUzytkownika(){
    return idUzytkownika;
}

string Adresat::pobierzImie(){
    return imie;
}

string Adresat::pobierzNazwisko(){
    return nazwisko;
}

string Adresat::pobierzNumerTelefonu(){
    return numerTelefonu;
}

string Adresat::pobierzEmail(){
    return email;
}

string Adresat::pobierzAdres(){
    return adres;
}
