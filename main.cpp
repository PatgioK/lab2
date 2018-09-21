
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>

void readFile();

int main() {

    std::ofstream reading;


    double min = 50;
    double max = 90;


    std::default_random_engine generator(time(0));
    std::uniform_real_distribution<double>
            distribution(min, max);

    srand(time(NULL));
    int nums = (rand() % 513 + 512);
    for (int i = 0; i < nums; i++) {
        double randnum = distribution(generator);
        std::cout << i << std::setw(10) << std::fixed << std::setprecision(3) << randnum << std::endl;
        reading << i << std::setw(10) << std::fixed << std::setprecision(3) << randnum << std::endl;
    }
    return 0;
}
