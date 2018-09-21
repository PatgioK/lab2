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
    reading.open("Readings.txt");

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
    readFile();
    return 0;
}

void readFile() {

    std::string str;
    std::ifstream book;

    book.open("Readings.txt");
    int count;
    double average;
    double median;
    double largest = 50;
    double lowest = 90;
    double number;
    double total = 0;
    int intnumber;
    std::vector<double> read;

    while(book >> number) {
        count++;
        book >> intnumber >> number;
        if (number > largest) {
            largest = number;
        } else if (number < lowest) {
            number = lowest;
        }
        total += number;
        read.push_back(number);

        int size = read.size();
        std::sort(read.begin(), read.end());
        median = read[floor(size / 2.0)];
    }
    average = total / count;
    std::cout << "there are " << count << " readings in the file." << std::endl;
    std::cout << "the average reading is " << std::fixed << std::setprecision(3) << average << std::endl;
    std::cout << "the highest reading is " << std::fixed << std::setprecision(3) << largest << std::endl;
    std::cout << "the lowest reading is " << std::fixed << std::setprecision(3) << lowest << std::endl;
    std::cout << "the median reading is " << std::fixed << std::setprecision(3) << median << std::endl;
}