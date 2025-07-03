#include <random>

const int randomFrom = -9;
const int randomTo = 9;

std::random_device rd;
std::mt19937 gen(rd());

int generateInteger() {
    std::uniform_int_distribution<> dis(randomFrom, randomTo);
    int random_digit = dis(gen);
    return random_digit;
}

int generatePosInteger() {
    std::uniform_int_distribution<> dis(1, randomTo);
    int random_digit = dis(gen);
    return random_digit;
}
