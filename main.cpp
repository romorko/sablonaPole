#include "pole.h"


int main()
{
    Pole<int,3> moje;
    moje.push(1);
    moje.push(3);
    moje.push(5);
    moje.push(8);
    moje.push(10);
    //moje.printPole();
   std::cout<<moje;
    return 0;
}
