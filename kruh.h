
#ifndef PRVY_KRUH_H
#define PRVY_KRUH_H
#include <iostream>

class Kruh
{
private:
    int polomer;
public:
    Kruh(); //vypyta si polomer vznikajuceho kruhu
    Kruh(int r); //vytvori kruh a nastavi jeho polomer na hodnotu r

    int getPolomer() const { return polomer;}; //inline metoda
    void setPolomer(int r) { polomer = r;}; //inline metoda
    float getObvod() const;
    float getObsah() const;

    //pretazovanie operatorov
    Kruh operator+(const Kruh &other) const;
    bool operator<(const Kruh &other) const;
    Kruh operator+(int cislo) const;
    Kruh operator*(int cislo) const;
    Kruh operator-(int cislo) const;
    Kruh operator-(const Kruh &other) const;
    //du spravit pretazenie operatora: Kruh - Kruh

    const Kruh& operator++(); //prefix
    Kruh operator++(int nepouzijem); //parameter sa nepouzije, ale znamena ze sa pretazuje postfix

    const Kruh& operator+=(int cislo);
    const Kruh& operator-=(int cislo);
    const Kruh& operator--();

    //koniec pretazovania operatorov
    Kruh spocitajKruhy(Kruh other) const;
    Kruh spocitajKruhy(const Kruh *other) const;
    Kruh spocitajKruhy() const; //zalozi novy kruh, vypita si jeho polomer a spocita ho s volajucim

    Kruh odcitajKruhy(Kruh other) const;
    Kruh odcitajKruhy(Kruh *other) const;
    Kruh odcitajKruhy() const;

    bool jeMensi(const Kruh *other) const;
    //static const float PI;
    static constexpr float PI = 3.14;
    static void vymenKruhy(Kruh *prvy, Kruh *druhy);
    static void vymenKruhy(Kruh &prvy, Kruh &druhy);


};
    const float PI = 3.14;

#endif //PRVY_KRUH_H
