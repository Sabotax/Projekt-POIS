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
int randomInt(int min, int max) {
    static std::default_random_engine e{};
    std::uniform_int_distribution<int> d{min, max};
    return d(e);
}
