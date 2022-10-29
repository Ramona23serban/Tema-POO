#include<iostream>

class Formatii{
    std :: string nume;
    std :: string telefon;
    std :: string maneger;
    std :: string email;
public:
    Formatii(const std :: string& nume_, const std :: string& telefon_, 
    const std :: string& maneger_, const std :: string& email_) : nume{nume_},
    telefon{telefon_}, maneger{maneger_}, email{email_}{
        std :: cout << "Constructor formatii";
    }
    friend std :: ostream& operator<<(std::ostream& os, const Formatii& fo){
        os << "Informatii despre formatie: " << "\n" << "Nume: "<< fo.nume << "\n" << "Numar de telefon: " << fo.telefon << "\n" << "Maneger: " << fo.maneger <<"\n" << "Email :" << fo.email << "\n";
        return os;
    }
    ~Formatii();
};

class Muzicanti{
    std :: string nume;
    std :: string telefon;
    std :: string adresa;
public:

    Muzicanti(const std :: string& nume_, const std :: string& telefon_, 
    const std :: string& adresa_) : nume{nume_}, telefon{telefon_}, adresa{adresa_}{
        std :: cout << "Constructor artisti";
    }
    friend std :: ostream& operator<<(std::ostream& os, const Muzicanti& muz){
        os << "Informatii despre artisti: " << "\n" << "Nume: "<< muz.nume << "\n" << "Numar de telefon: " << muz.telefon << "\n" << "Adresa: " << muz.adresa <<"\n";
        return os;
    }
   // ~Muzicanti();
};

class Instrumente{
    std :: string nume;
    float pret;
public:

    Instrumente(const std :: string& nume_,
    float pret_) : nume{nume_}, pret{pret_}{
         std :: cout << "Constructor instrumente";
    }

    friend std :: ostream& operator<<(std::ostream& os, const Instrumente& ins){
        os << "Informatii despre intrument: " << "\n" << "Nume: "<< ins.nume << "\n" << "Pretul acestuia: " << ins.pret << "\n";
        return os;
    }
    ~Instrumente();
};

class Concerte{
    std :: string nume;
    std :: string detalii;
    int an;
    int durata;
    int pret;
    //Formatii formatie_1;
    //Muzicanti muzicant_1;
    //Instrumente instrument_1;

public:
    Concerte(int an_, int durata_, int pret_,
    const std :: string& nume_, const std :: string& detalii_) : an{an_}, 
    nume{nume_}, durata{durata_}, pret{pret_}, detalii{detalii_}{
        std :: cout << "Constructor concerte";
    };

    Concerte(const Concerte& other){
        an = other.an;
        nume = other.nume;
        durata = other.durata;
        pret = other.pret;
        detalii = other.detalii;
        std :: cout << "constructor copiere\n";

    }
    Concerte& operator=(const Concerte& other){
        an = other.an;
        nume = other.nume;
        durata = other.durata;
        pret = other.pret;
        detalii = other.detalii;
        std :: cout << "operator egal\n";
        return *this;

    }
    ~Concerte(){
        std :: cout << "Final!\n";
    }

    friend std :: ostream& operator<<(std::ostream& os, const Concerte& con) {
        os << "Informatii despre concert: " << "\n" << "Nume concert: " << con.nume << "\n" << "An: " << con.an << "\n" << "Durata :" << con.durata << "\n" << "Pret (in RON): " << con.pret << "\n";
        return os;
    }

};

int main() {
    Concerte concert_1{2010, 90, 290,"SGFG", "Prim concert"};
    Concerte concert_2{2013, 90, 300, "Concert 2","Deschidere album"};
    Concerte concert_3{2017, 100, 350, "Concert 3", "Lansare album"};
    Concerte concert_4 = concert_3;
    concert_3 = concert_2;
    Muzicanti muzicant_1{"Taylor", "0785687555", "LA"};
    Muzicanti muzicant_2{"Lana", "0785687888", "Anglia"};
    std :: cout << concert_1 << concert_2 << concert_3 << concert_4;
    std :: cout << muzicant_1 << muzicant_2;
    return 0;
}

