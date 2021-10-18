#include <iostream>
#include "kruh.h"

using std::cout;
using std::cin;
using std::endl;

//using namespace std;

/*
namespace Juraj
{
    int vek;
    int getVek(){;};
}

namespace Roman
{
    int vek;
    int getVek(){;};
}
*/

int main()
{
    /*
    using Roman::vek;
    using Juraj::vek;
    Roman::vek;
    Juraj::vek;
    Roman::getVek();
    Juraj::getVek();
    */

    //Kruh poleKruhov[5];


    /*
    Kruh Prvy;
    Prvy.setPolomer(10);
    Kruh Druhy(9);
    //Druhy.setPolomer(5);
    Kruh Sucet = Prvy.spocitajKruhy(Druhy);
    cout<<Sucet.getPolomer()<<endl;
    Kruh Treti = Sucet.spocitajKruhy(Prvy);
    cout<<Treti.getPolomer()<<endl;

    Kruh Stvrty;
    Stvrty.setPolomer(8);
    Kruh Piaty = Stvrty.spocitajKruhy(&Prvy);
    cout<<Piaty.getPolomer()<<endl;

    Kruh Siesty = Stvrty.spocitajKruhy();
    */

    /*
    Kruh Prvy;
    Kruh Druhy(10);
    Kruh Treti = Kruh(5);
    Kruh Stvrty = Kruh();
    Kruh Piaty {6};
    auto cislo = 10;
    auto realne = 5.14;
    auto znak = 'a';
    auto siesty = Kruh();
    */
    /*
    Kruh Jedna(10);
    Kruh Dva(5);
    Kruh::vymenKruhy(&Jedna,&Dva);
    std::cout<<Jedna.getPolomer()<<" "<<Dva.getPolomer();
    */

    /*
    Kruh K1(4);
    Kruh K2(8);
    int cislo = 2;
    //Kruh::vymenKruhy(&K1,&K2);
    //std::cout<<K1.getPolomer()<<" "<<K2.getPolomer();
    Kruh Spocitane = K1 + K2;
    std::cout<<Spocitane.getPolomer()<<std::endl;
    std::cout<<(K1<K2)<<std::endl;
    Kruh Znasobene = K1 * cislo;
    Kruh ScitaneC = K1 + cislo;
    Kruh Odcitane = K1 - K2;
    Kruh OdcitaneC = K1 - cislo;
    std::cout<<Znasobene<<std::endl;
    std::cout<<ScitaneC<<std::endl;
    std::cout<<Odcitane<<std::endl;
    std::cout<<OdcitaneC<<std::endl;
    */

    /*
    //12.10.
    Kruh Novy(5);
    ++Novy;
    std::cout<<(++Novy)<<endl;
    K2++;

    //13.10.
    std::cout<<(10+K1)<<std::endl;
    std::cout<<K1;
    std::cin>>K2;
    std::cout<<K2;
    */

    const int kolko = 50;
    Kruh Kruhy[kolko];
    Kruh::generujPoleKruhov(Kruhy,kolko);
    Kruh::vypisPoleKruhuv(Kruhy,kolko);

    return 0;
}
