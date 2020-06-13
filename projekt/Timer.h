#ifndef TIMER_H
#define TIMER_H
#include "Header.h"

class Timer
{
public:
    static double zliczanie;
    //static double elapsed;
    static double okienko_w_obie_strony;
    static void zarzadzaj_czasem(double timer);
    static void Initiate_statics();
    static bool czy_wpadlo_w_nawiasy_bitu(std::shared_ptr<Music> muzyka, double czas);
};

#endif // TIMER_H
