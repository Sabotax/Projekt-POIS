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
    static bool jednorazowa_kara;
    static bool oberwal_juz;
    static bool czy_wyszlo_poza_nawiasy_bitu_z_prawej(std::shared_ptr<Music> muzyka, double czas);
    static double czas_na_wstep;
};

#endif // TIMER_H
