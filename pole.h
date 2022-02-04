#ifndef POLE_POLE_H
#define POLE_POLE_H

#include <cstdlib> //kvoli realloc a malloc
#include <iostream>
template <typename  Any=int, unsigned pocet=10>
class Pole;

template <typename T>
int comp(const void * a, const void *b);

template <typename  Any, unsigned int pocet>
std::ostream & operator<<(std::ostream & ,const Pole <Any,pocet> &);

template <typename  Any, unsigned pocet>
class Pole
{
private:
    Any * array;
    unsigned maxIndex;//maximalny pocet prvkov pola
    unsigned curIndex;//index posledneho vlozeneho prvku
    unsigned numRealoc;//kolkokrat som realokoval
public:
    Pole();
    ~Pole(); //destruktor uvolni pamat po zaniknuti objektu
    explicit Pole(unsigned kolko);
    Any &operator[](unsigned index);
    Any operator[](unsigned index) const;
    bool push(Any hodnota);
    bool in(Any hladam) const;//zisti ci je prvok v poli
    Any max() const;
    Any min() const;
    void sort(char ako='a'); //implicitne vzostupne
    void printPole() const;
    friend std::ostream & operator<< <>(std::ostream &,const Pole<Any,pocet> &);
    static int cmpA(const void * a, const void *b);
    static int cmpD(const void * a, const void *b);
};

template<typename Any, unsigned int pocet>//vytvorim implicitne velke pole
Pole<Any, pocet>::Pole()
{
    array = (Any *)std::malloc(pocet* sizeof(Any) );
    curIndex=0;
    maxIndex=pocet-1;
    numRealoc=1;
}

template<typename Any, unsigned int pocet>
Pole<Any, pocet>::~Pole()
{
    free(array);
    array= nullptr;
}

template<typename Any, unsigned int pocet>//urcim pocet prvkov ktore budu k dispozicii po vytvoreni objektu
Pole<Any, pocet>::Pole(unsigned int kolko)
{
    array = (Any *)std::malloc(kolko* sizeof(Any) );
    curIndex=0;
    maxIndex=kolko-1;
    numRealoc=1;
}

template<typename Any, unsigned int pocet> //pretazeny operator aby sa dalo priamo pristupovat k prvkom array
Any &Pole<Any, pocet>::operator[](unsigned int index)
{
    return array[index];
}

template<typename Any, unsigned int pocet> //pretazeny operator aby sa dalo priamo pristupovat k prvkom array
Any Pole<Any, pocet>::operator[](unsigned int index) const
{
    return array[index];
}

template<typename Any, unsigned int pocet>
bool Pole<Any, pocet>::push(Any hodnota)
{
    if(curIndex<maxIndex) //pocet prvkov je mensi ako mam pripravene
    {
        array[curIndex]=hodnota;
        ++curIndex;
        return true;
    }
    ++numRealoc;
    Any * tmp=(Any *) realloc(array,numRealoc*maxIndex* sizeof(Any));
    if(tmp== NULL)
    {
        return false;
    }
    array=tmp;
    array[curIndex]=hodnota;
    ++curIndex;
    maxIndex*=numRealoc;
    return true;
}

template<typename Any, unsigned int pocet>
void Pole<Any, pocet>::printPole() const
{
    for(unsigned i=0;i<curIndex;++i)
    {
        std::cout<<array[i]<<" ";
    }
}

template<typename Any, unsigned int pocet>
std::ostream &operator<< (std::ostream &os, const Pole<Any,pocet>& other)
{
    for (unsigned i = 0; i < other.curIndex; ++i)
    {
        os << other[i] << " ";
    }
    return os;
}

template<typename Any, unsigned int pocet>
bool Pole<Any, pocet>::in(Any hladam) const
{
    for(int i=0;i<curIndex;++i)
    {
        if(hladam==(*this)[i])
        {
            return true;
        }
    }
    return false;
}

template<typename Any, unsigned int pocet>
int Pole<Any, pocet>::cmpD(const void *a, const void *b)
{
   Any * prvy= (Any *)a;
   Any * druhy= (Any *)b;
   return (*prvy)<(*druhy)?1:(*prvy)>(*druhy)?-1:0;
}

template<typename Any, unsigned int pocet>
int Pole<Any, pocet>::cmpA(const void *a, const void *b)
{
    Any * prvy= (Any *)a;
    Any * druhy= (Any *)b;
    return (*prvy)<(*druhy)?-1:(*prvy)>(*druhy)?1:0;
}

template<typename Any, unsigned int pocet>
void Pole<Any, pocet>::sort(char ako)
{
    if(ako=='a')
    {
        qsort(array,curIndex, sizeof(array[0]),Pole<Any,pocet>::cmpA);
    }
    else
    {
        qsort(array,curIndex, sizeof(array[0]),Pole<Any,pocet>::cmpD);
    }
    //qsort(array,curIndex, sizeof(array[0]),comp<Any>);
}

template <typename T>
int comp(const void * a, const void *b)
{
    T * prvy= (T *)a;
    T * druhy= (T *)b;
    return (*prvy)<(*druhy)?1:(*prvy)>(*druhy)?-1:0;
}

#endif //POLE_POLE_H
