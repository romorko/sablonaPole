#include "pole.h"


int main()
{
    Pole<int,3> moje;
    moje.push(1);
    moje.push(13);
    moje.push(5);
    moje.push(8);
    moje.push(10);
    moje.push(11);
    moje.push(2);
    moje.push(19);
    moje.push(14);
    moje.push(0);
    moje.push(21);
    moje.push(2);
    moje.push(23);
    moje.push(16);
    moje.push(25);
    moje[3]=44;
    std::cout<<moje<<std::endl;
    moje.sort('d');
    std::cout<<moje<<std::endl;
   //std::cout<<moje.in(14);
    return 0;
}
