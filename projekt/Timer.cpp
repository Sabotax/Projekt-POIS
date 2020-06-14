#include "Header.h"

double Timer::zliczanie;
//double Timer::elapsed;
double Timer::okienko_w_obie_strony;

void Timer::zarzadzaj_czasem(double elapsed) {
    zliczanie += elapsed;
    std::shared_ptr<Music> obecna_muzyka = Music::obecna_muzyka;
//    if( czy_wpadlo_w_nawiasy_bitu(obecna_muzyka, zliczanie ) ) {
//        Tile::migaj_szachownica(obecna_muzyka->obecny_index % 2 ==0);
//        obecna_muzyka->obecny_index++;
//        //debug("Timer test", ("miganie" + std::to_string(  zliczanie  ) ) ) ;


//        baner_odliczanie::ob = std::make_shared<baner_odliczanie>(obecna_muzyka->okienka_czasowe[obecna_muzyka->obecny_index],obecna_muzyka->okienka_czasowe[obecna_muzyka->obecny_index+1]);
//    }

    if( zliczanie >= obecna_muzyka->okienka_czasowe[obecna_muzyka->obecny_index] ) {
        Tile::migaj_szachownica(obecna_muzyka->obecny_index % 2 == 0);
        obecna_muzyka->obecny_index++;
        //debug("Timer test", ("zliczanie: " + std::to_string(  zliczanie  ) ) ) ;
        //debug("Timer test", ("obecny index: " , obecna_muzyka->obecny_index ) ) ;


        baner_odliczanie::ob = std::make_shared<baner_odliczanie>(obecna_muzyka->okienka_czasowe[obecna_muzyka->obecny_index],obecna_muzyka->okienka_czasowe[obecna_muzyka->obecny_index+1]);
    }

    if( czy_wpadlo_w_nawiasy_bitu(obecna_muzyka, zliczanie ) ) {
        //debug("Czy wpadlo test", ("zliczanie: " , zliczanie   ) ) ;


        //baner_odliczanie::ob = std::make_shared<baner_odliczanie>(obecna_muzyka->okienka_czasowe[obecna_muzyka->obecny_index],obecna_muzyka->okienka_czasowe[obecna_muzyka->obecny_index+1]);
    }

    if(baner_odliczanie::ob->check_for_destroy() ) {


    }
}
void Timer::Initiate_statics() {
    zliczanie = 0;
    okienko_w_obie_strony = 0.25;
}
bool Timer::czy_wpadlo_w_nawiasy_bitu(std::shared_ptr<Music> muzyka, double czas) {
    if( czas < muzyka->okienka_czasowe[muzyka->obecny_index] + Timer::okienko_w_obie_strony && czas > muzyka->okienka_czasowe[muzyka->obecny_index] - Timer::okienko_w_obie_strony ) {
        //debug("pierwszy warunek: ", czas < muzyka->okienka_czasowe[muzyka->obecny_index] + Timer::okienko_w_obie_strony );
        //debug("drugi warunek: ", czas > muzyka->okienka_czasowe[muzyka->obecny_index] - Timer::okienko_w_obie_strony );
        //debug("Czy wpadlo, pierwszy if: ", czas);
        return true;
    }
    else if(czas < muzyka->okienka_czasowe[muzyka->obecny_index-1] + Timer::okienko_w_obie_strony && czas > muzyka->okienka_czasowe[muzyka->obecny_index-1] ) {
        //debug("Czy wpadlo, drugi if: ", czas);
        return true;
    }
    else {
        //debug("czy wpadlo: ", "false");
        return false;
    }
}
