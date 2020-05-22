#include "Header.h"

void debug(std::string id, int opis) {
    std::cout << "ID: " << id << "->\t" << opis << std::endl;
}
void debug(std::string id, double opis) {
    std::cout << "ID: " << id << "->\t" << opis << std::endl;
}
void debug(std::string id, std::string opis) {
    std::cout << "ID: " << id << "->\t" << opis << std::endl;
}
void debug(std::string id) {
    std::cout << "ID: " << id << std::endl;
}
