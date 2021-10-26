//
// Created by map on 27. 9. 2021.
//
#include "kruh.h"

/*
float Kruh::getObvod() const
{
    return 2 * PI * polomer;
}
*/
/*
float Kruh::getObsah() const
{
    return PI * polomer * polomer;
}
*/

Kruh Kruh::spocitajKruhy(Kruh other) const
{
    //Kruh Dalsi; // vytvorenie noveho kruhu
    //Dalsi.polomer = this -> polomer+other.polomer; //this = pointer na seba sameho (preto tam je sipka)
    //return Dalsi;
     return Kruh(this -> polomer+other.polomer);
    //return Kruh(this->polomer+other.polomer);
}

Kruh Kruh::spocitajKruhy(const Kruh *other) const
{
    //Kruh Dalsi;
    //Dalsi.polomer = this -> polomer + other->polomer;
    //return Dalsi;
    return Kruh(this->polomer + other->polomer);
}

Kruh Kruh::spocitajKruhy() const
{
    int polomer;
    std::cout<<"Polomer";
    std::cin>>polomer;
    return Kruh(this -> polomer+polomer);
}

Kruh::Kruh()
{
    //int mPolomer;
    //std::cout<<"Zadaj polomer";
    //std::cin>>mPolomer;
    ++p;
    this->polomer = getInt(false, false);
    this->pocitadlo = p;
}

Kruh::Kruh(int r):polomer(r) //iniciacny zoznam
{
    this->polomer=r;
}

bool Kruh::jeMensi(const Kruh *other) const
{
    return (this->polomer < other->polomer) ? true : false;
}

Kruh Kruh::odcitajKruhy(Kruh other) const
{
    Kruh Dalsi;
    if(this->polomer > other.polomer)
    {
        Dalsi.polomer = this->polomer - other.polomer;
        return Dalsi;
    }
    Dalsi.polomer = 1;
    return Dalsi;
}

Kruh Kruh::odcitajKruhy(Kruh *other) const
{
    Kruh Dalsi;
    if(this->polomer > other->polomer)
    {
        Dalsi.polomer =this->polomer - other->polomer;
        return Dalsi;
    }
    Dalsi.polomer = 1;
    return Dalsi;
}

Kruh Kruh::odcitajKruhy() const
{
    int polomer;
    std::cout<<"Zadaj polomer: ";
    std::cin>>polomer;
    if (this->polomer > polomer)
    {
        return Kruh(this->polomer - polomer);
    }
    return Kruh(1);
}

void Kruh::vymenKruhy(Kruh *prvy, Kruh *druhy)
{
    Kruh Temp;
    Temp = *prvy;
    *prvy = *druhy;
    *druhy = Temp;
}

void Kruh::vymenKruhy(Kruh &prvy, Kruh &druhy)
{
    Kruh Temp(0);
    Temp = prvy;
    prvy = druhy;
    druhy = Temp;
}

Kruh Kruh::operator+(const Kruh &other) const
{
    return Kruh(polomer+other.polomer);
    //return Kruh(polomer+other.polomer);
}

bool Kruh::operator<(const Kruh &other) const
{
    return polomer<other.polomer;
}

Kruh Kruh::operator+(int cislo) const
{
    return Kruh(polomer+cislo);
}

Kruh Kruh::operator*(int cislo) const
{
    return Kruh(polomer*cislo);
}

Kruh Kruh::operator-(int cislo) const
{
    if (polomer > cislo)
    {
        return Kruh(polomer-cislo);
    }
    return Kruh(1);
}

Kruh Kruh::operator-(const Kruh &other) const
{
    if(polomer>other.polomer)
    {
        return Kruh(polomer-other.polomer);
    }
    return Kruh(1);
}

const Kruh &Kruh::operator++()
{
    ++polomer;
    return {*this};
}

Kruh Kruh::operator++(int nepouzijem)
{
    Kruh Temp = *this;
    ++polomer;
    return {Temp};
}

const Kruh &Kruh::operator+=(int cislo)
{
    polomer += cislo;
    return {*this};
}

const Kruh &Kruh::operator-=(int cislo)
{
    if(polomer > cislo)
    {
        polomer -= cislo;
    }
    polomer = 1;
    return {*this};
}

const Kruh &Kruh::operator--()
{
    polomer = (polomer-1<0)?1:polomer-1;
    return (*this);
    /*
    Kruh Temp = *this;
    --polomer;
    return {Temp};
    */
}

Kruh operator+(int cislo, const Kruh &other)
{
    return other+cislo;
}

Kruh operator*(int cislo, const Kruh &other)
{
    return other*cislo;
}

std::ostream &operator<<(std::ostream &os, const Kruh &other)
{
    os<<"Kruh ma polomer "<<other.polomer<<std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, Kruh &other)
{
    std::cout<<"Zadaj polomer: ";
    is>>other.polomer;
    return is;
}

void Kruh::generujPoleKruhov(Kruh *pole, int pocet)
{
    srand(time(0));
    for(int i=0;i<pocet;i++)
    {
        (pole+i)->polomer = std::rand() %99+1;
    }
}

void Kruh::vypisPoleKruhov(const Kruh *pole, int pocet)
{
    for(int i=0;i<pocet;i++)
    {
        std::cout<<*(pole+i);
    }
}

Kruh Kruh::getMaxKruh(const Kruh *pole, int pocet)
{
    Kruh Max = pole[0];
    for(int i=1;i<pocet;i++)
    {
        Max = (Max < pole[i])?pole[i]:Max;
    }
    return Max;
}

Kruh *Kruh::getMaxKruh(Kruh *pole, int pocet)
{
    Kruh *kde = pole;
    for(int i=1;i<pocet;++i)
    {
        kde = (*(kde) < *(pole+i))?(pole+i):kde;
    }
    return kde;
}

Kruh::operator int() const
{
    return polomer;
}

Kruh::operator float() const
{
    return PI * 2 * polomer;
}

int Kruh::cmp(const void *a, const void *b)
{
    Kruh *prvy = (Kruh *)a; //pretypujeme pointer na void na konkretny pointer ktory potrebujeme, u nas Kruh
    Kruh *druhy = (Kruh *)b;
    return (prvy->polomer - druhy->polomer) * (-1);
}

void Kruh::utriedPoleKruhov(Kruh *pole, int pocet)
{
    std::qsort((Kruh *)pole,pocet,sizeof (Kruh),cmp);
}

int Kruh::getPocitadlo() const
{
    return this->pocitadlo;
}

int Kruh::cmpStable(const void *a,const void *b) //stable sort - triedi podla indexu prvkov
{
    Kruh *prvy = (Kruh *)a;
    Kruh *druhy = (Kruh *)b;
    int rozdiel = prvy->polomer - druhy->polomer;
    return (rozdiel==0)?prvy->pocitadlo-druhy->pocitadlo:rozdiel;
}

int Kruh::getInt(bool nula, bool zaporne)
{
    int tmp;
    while(true)
    {
        try
        {
            std::cout << "Zadaj cislo:";
            if (!(std::cin >> tmp)) //ak nebolo nacitanie uspesne t.j. nebolo zadane korektne cele cislo, nastvi sa chybovy bit
            {
                throw Kruh::noNumber("Nebolo zadane cislo!"); //vyhodime vynimku a posleme spravu konstruktoru
            }
            if(nula == false && tmp == 0)
            {
                throw Kruh::chybaNula("Nula nie je povolena!");
            }
            if(zaporne == false && tmp < 0)
            {
                throw Kruh::chybaZaporne("Bolo zadane zaporne cislo!");
            }
        }
        catch (const Kruh::noNumber & ex) //zachytime vynimku ak nebolo zadane cislo
        {
            std::cin.clear(); //vymazene chybovy bit nastaveny v objekte neuspesnym citanim
            std::cin.ignore(1000,'\n'); //vycisti vyrovnavaciu pamat klavesnice od zvysku zadaneho vstupu
            ex.getMsg(); //vypiseme spravu
            continue;
        }
        catch (const Kruh::chybaNula & ex)
        {
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            ex.getMsg();
            continue;
        }
        catch (const Kruh::chybaZaporne & ex)
        {
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            ex.getMsg();
            continue;
        }
        return tmp;
    }
}
