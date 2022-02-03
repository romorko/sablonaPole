#include "pole.h"


int main()
{
    Pole<int,3> moje;
    moje.push(1);
    moje.push(3);
    moje.push(5);
    moje.push(8);
    moje.push(10);
    moje.push(11);
    moje.push(12);
    moje.push(13);
    moje.push(14);
    moje.push(20);
    moje.push(21);
    moje.push(22);
    moje.push(23);
    moje.push(24);
    moje.push(25);
    moje[3]=44;
    //moje.printPole();
   std::cout<<moje;
    return 0;
}
