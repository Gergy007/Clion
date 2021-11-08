#include "kruh.h"
#include <fstream> //sluzi na pracu so subormi

using std::cout;
using std::cin;
using std::endl;
using std::ifstream; //sluzi na vstup zo suboru
using std::ofstream; //sluzi na vystup zo suboru

int main()
{
    /*
    Kruh Jedna(10);
    Kruh Dva(5);
    Kruh::vymenKruhy(&Jedna,&Dva);
    std::cout<<Jedna.getPolomer()<<" "<<Dva.getPolomer();


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


    int pocet;
    //dynamicky generovane pole
    std::cout<<"Zadaj pocet prvkov pola: "<<endl;
    std::cin>>pocet;
    Kruh *dynamickePole;
    try
    {
        dynamickePole = new Kruh[pocet]; //alokacia pamate na hromade operatom new
    }
    catch (std::bad_alloc & ex)
    {
        std::cout<<"Chyba pridelenia pamate";
    }


    //Kruh::generujPoleKruhov(dynamickePole,pocet);
    //cout<<"Povodne pole kruhov:"<<endl;
    //Kruh::vypisPoleKruhov(dynamickePole,pocet);

    Kruh::utriedPoleKruhov(dynamickePole,pocet);
    cout<<"Utriedene pole:"<<endl;
    Kruh::vypisPoleKruhov(dynamickePole,pocet);


    delete [] dynamickePole; //uvolnenie pola
    dynamickePole = 0;
    */

    /*
    //citanie zo suboru
    ifstream fin; //vytvoreny objekt pre citanie zo suboru
    fin.open("citaj.txt"); //inicializujeme objekt konkretnym suborom
    //ifstream fin("citaj.txt"); alternativnysposob otvorenia suboru pomocou konstruktoru

    ofstream fout;
    fout.open("zapis.txt");
    try
    {
        if(!fin.is_open()) //otestujem otvorenie suboru, ak sa nepodarilo otvorit, vyhodim vynimku
        {
            throw Kruh::streamError("Nepodarilo sa otvorit subor na citanie!");
        }
        Kruh K(0); //objekt do ktoreho budeme citat jednotlice kruhy
        if(!fout.is_open())
        {
            throw Kruh::streamError("Nepodarilo sa otvorit subor na zapis!");
        }
        while(fin>>K) //kym je citanie uspesne
        {
            cout<<K; //vypiseme precitany kruh na obrazovku
            fout<<K; //zapiseme kruh do suboru
        }


        fin.close(); //uzatvorime stream
        fout.close();
    }
    catch (const Kruh::streamError & ex) //zachytenie vynimky
    {
        ex.getMsg();
        return 1;
    }
    */

    Kruh K;
    K.generujSuborKruhov("skuska",10);
    K.precitajSuborKruhov("skuska",10);


    return 0;
}