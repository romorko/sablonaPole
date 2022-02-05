#include "pole.h"


int main()
{
    Pole<int,3> moje;
    moje.push_back(1);
    moje.push_back(13);
    moje.push_back(5);
    moje.push_back(8);
    moje.push_back(10);
    moje.push_back(11);
    moje.push_back(2);
    moje.push_back(19);
    moje.push_back(14);
    moje.push_back(0);
    moje.push_back(21);
    moje.push_back(2);
    moje.push_back(23);
    moje.push_back(16);
    moje.push_back(25);
    moje[3]=44;
    std::cout<<moje<<std::endl;
    moje.sort('d');
    std::cout<<moje<<std::endl;
   //std::cout<<moje.in(14);
    return 0;
}
