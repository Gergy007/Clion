#ifndef PRVY_KRUH_H
#define PRVY_KRUH_H
#include <iostream>

class Kruh
{
    //rodicovska trieda, od ktorej odvodime triedy chyb
    class Chyba
    {
    protected:  //chraneny clen, potomkovia maju k nemu pristup ako k verejnemu, ostatne triedy ako k privatnemu
        const char *msg;
        int kodChyby;
    public:
        Chyba(const char *sprava):msg(sprava){};
        virtual void getMsg()const {std::cout<<msg<<std::endl;};
        int vratKodChyby(){return kodChyby;};
    };
    //vlozene triedy sluziace na vytvorenie vynimiek

public: class streamError:public Chyba
    {
    public:
        streamError(const char *sprava): Chyba(sprava){};
    };


    class noNumber:public Chyba //trieda je verejne odvodena od triedy Chyba
    {
    private:
        const char *mojaMsg;
    public:
        noNumber(const char *sprava, const char * mojaSprava): Chyba(sprava){mojaMsg = mojaSprava;};
        const char *getMojaMsg(){return mojaMsg;};
        void getMsg()const {std::cout<<msg<<mojaMsg<<std::endl;};
    };

    class chybaNula:public Chyba
    {
    public:
        chybaNula(const char *sprava): Chyba(sprava){};
    };

    class chybaZaporne:public Chyba
    {
    public:
        chybaZaporne(const char *sprava): Chyba(sprava){};
    };


private:
    int polomer;
    int pocitadlo;
public:
    //~Kruh(); //destruktor
    Kruh(); //vypyta si polomer vznikajuceho kruhu
    explicit Kruh(int r); //vytvori kruh a nastavi jeho polomer na hodnotu r

    int getPolomer() const { return polomer;}; //inline metoda
    void setPolomer(int r) { polomer = r;}; //inline metoda
    float getObvod() const { return 2 * Kruh::PI * polomer;};
    float getObsah() const { return Kruh::PI * Kruh::PI * Kruh::PI;};
    int getPocitadlo() const;

    //pretazovanie operatorov
    operator int() const;
    operator float() const;
    Kruh operator+(const Kruh &other) const; //pripocita ku kruhu cislo
    friend Kruh operator+(int cislo, const Kruh &other); //priatelska funkcia, ktora pripocita k cislu kruh
    friend Kruh operator*(int cislo, const Kruh &other); //priatelska funkcia, ktora vynasobi cislo kruhom
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

    //pretazenie operatorov
    friend std::ostream & operator <<(std::ostream& os, const Kruh &other); //pretazenie operatora vystup
    friend std::istream & operator >>(std::istream& is, Kruh &other); //pretazenie operatora vstup
    //koniec pretazenia operatorov

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

    static void generujPoleKruhov(Kruh *pole,int pocet);
    static void vypisPoleKruhov(const Kruh *pole, int pocet);
    static Kruh getMaxKruh(const Kruh *pole, int pocet);
    static Kruh* getMaxKruh(Kruh *pole, int pocet);
    static void utriedPoleKruhov(Kruh *pole, int pocet);
    static int cmp(const void *a, const void *b);
    static int cmpStable(const void *a,const void *b);
    static int getInt(bool nula = true,bool zaporne = true);
    static int generujSuborKruhov(const char *nazov, int kolko);
    static Kruh * precitajSuborKruhov(const char *nazov, int kolko);

};
    //const float PI = 3.14;
    static int p = 0;
    //du urobit stablesort aby porovnavane hodnoty s rovnakym polomerom nemenili poradie



#endif //PRVY_KRUH_H
