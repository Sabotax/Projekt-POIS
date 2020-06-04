#include "Header.h"

double Timer::zliczanie;
double Timer::elapsed;
double Timer::okienko_w_obie_strony;

void Timer::zarzadzaj_czasem() {
    zliczanie += elapsed;
}
void Timer::Initiate_statics() {
    zliczanie = 0;
    okienko_w_obie_strony = 0.5;
}
bool Timer::czy_wpadlo_w_nawiasy_bitu(std::shared_ptr<Music> muzyka) {

}
