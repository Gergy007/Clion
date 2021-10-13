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
     return {this -> polomer+other.polomer};
    //return Kruh(this->polomer+other.polomer);
}

Kruh Kruh::spocitajKruhy(const Kruh *other) const
{
    //Kruh Dalsi;
    //Dalsi.polomer = this -> polomer + other->polomer;
    //return Dalsi;
    return {this->polomer + other->polomer};
}

Kruh Kruh::spocitajKruhy() const
{
    int polomer;
    std::cout<<"Polomer";
    std::cin>>polomer;
    return { this -> polomer+polomer};
}


Kruh::Kruh()
{
    int mPolomer;
    std::cout<<"Zadaj polomer";
    std::cin>>mPolomer;
    this->polomer = mPolomer;
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
        return {this->polomer - polomer};
    }
    return {1};
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
    return {polomer+other.polomer};
    //return Kruh(polomer+other.polomer);
}

bool Kruh::operator<(const Kruh &other) const
{
    return polomer<other.polomer;
}

Kruh Kruh::operator+(int cislo) const
{
    return {polomer+cislo};
}

Kruh Kruh::operator*(int cislo) const
{
    return {polomer*cislo};
}

Kruh Kruh::operator-(int cislo) const
{
    if (polomer > cislo)
    {
        return {polomer-cislo};
    }
    return {1};
}

Kruh Kruh::operator-(const Kruh &other) const
{
    if(polomer>other.polomer)
    {
        return {polomer-other.polomer};
    }
    return {1};
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
