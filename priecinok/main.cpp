#include <iostream>
#include "kruh.h"

using std::cout;
using std::cin;
using std::endl;

//using namespace std;

int main()
{
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

    int pocet;
    //dynamicky generovane pole
    std::cout<<"Zadaj pocet prvkov pola: "<<endl;
    std::cin>>pocet;
    Kruh *dynamickePole = new Kruh [pocet]; //alokacia pamate na hromade operatom new
    if(dynamickePole == NULL)
    {
        std::cout<<"Memory not allocated!"<<endl;
        exit(1);
    }
    Kruh::generujPoleKruhov(dynamickePole,pocet);
    cout<<"Povodne pole kruhov:"<<endl;
    Kruh::vypisPoleKruhov(dynamickePole,pocet);
    /*
    Kruh::utriedPoleKruhov(dynamickePole,pocet);
    cout<<"Utriedene pole:"<<endl;
    Kruh::vypisPoleKruhov(dynamickePole,pocet);
    */
    for(int i=0;i<pocet;++i)
    {
        std::cout<<(*(dynamickePole+i)).getPocitadlo()<<std::endl;
    }
    delete [] dynamickePole; //uvolnenie pola
    dynamickePole = 0;

    return 0;
}