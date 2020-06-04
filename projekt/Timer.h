#ifndef TIMER_H
#define TIMER_H
#include "Header.h"

class Timer
{
public:
    static double zliczanie;
    static double elapsed;
    static double okienko_w_obie_strony;
    static void zarzadzaj_czasem();
    static void Initiate_statics();
    bool czy_wpadlo_w_nawiasy_bitu(std::shared_ptr<Music> muzyka);
};

#endif // TIMER_H
