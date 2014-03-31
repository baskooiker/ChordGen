/* 
 * File:   RhythmGenerator.cpp
 * Author: Bas
 * 
 * Created on 27 maart 2014, 10:53
 */

#include "RhythmGenerator.h"

#include <vector>
#include <stdlib.h>
#include <fstream>

RhythmGenerator::RhythmGenerator() {
}

RhythmGenerator::RhythmGenerator(const RhythmGenerator& orig) {
}

RhythmGenerator::~RhythmGenerator() {
}

int RhythmGenerator::densityOf(int index) {
    int sum = 0;
    for (int i = 0; i < 8; i++) {
        if (rhythms[index][i] == 1)
            sum++;
    }
    return sum;
}

std::vector<int> RhythmGenerator::generate(float density) {
    int rhythm;
    int discreteDensity = 1 + (int) (density * 5.9999f);
    do {
        rhythm = rand() % 34;
    } while (densityOf(rhythm) != discreteDensity);
    std::vector<int> r;
    for(int i = 0; i < 8; i++)
        r.push_back(rhythms[rhythm][i]);
    return r;
}

int const RhythmGenerator::rhythms[][8] = {
    // 1
    {1, 0, 0, 0, 0, 0, 0, 0},

    // 2
    // 1 1
    {1, 0, 0, 0, 1, 0, 0, 0},
    {1, 0, 0, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 0, 0, 0, 1},
    // 2 0
    {1, 0, 1, 0, 0, 0, 0, 0},

    // 3
    // 1 2
    {1, 0, 0, 0, 1, 0, 1, 0},
    {1, 0, 0, 0, 0, 0, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 1},
    // 2 1
    {1, 0, 1, 0, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 1, 0},
    {1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 1, 0, 0, 0},
    {1, 0, 0, 1, 0, 0, 1, 0},
    {1, 0, 0, 1, 0, 0, 0, 1},
    
    // 4
    // 1 3
    {1, 0, 0, 0, 1, 0, 1, 1},
    {1, 0, 0, 0, 1, 1, 1, 0},
    // 2 2
    {1, 0, 1, 0, 1, 0, 1, 0},
    {1, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 0, 1, 1, 0, 1, 0},
    {1, 0, 0, 1, 1, 0, 0, 1},
    // beyond std
    {1, 0, 1, 0, 0, 1, 1, 0},
    {1, 0, 1, 0, 0, 0, 1, 1},
    // 3 1
//    {1, 0, 1, 1, 1, 0, 0, 0},
//    {1, 1, 1, 0, 1, 0, 0, 0},
    // beyond std
//    {1, 1, 1, 0, 0, 0, 1, 0},
    

    // 5
    // 1 4
//    {1, 0, 0, 0, 1, 1, 1, 1},
    // 2 3
    {1, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 1, 0, 1, 1, 1, 0},
    {1, 0, 0, 1, 1, 0, 1, 1},
    {1, 0, 0, 1, 1, 1, 1, 0},
    // 3 2
    {1, 0, 1, 1, 1, 0, 1, 0},
    {1, 0, 1, 1, 1, 0, 0, 1},
    {1, 1, 1, 0, 1, 0, 1, 0},
    {1, 1, 1, 0, 1, 0, 0, 1},
    // 4 1
//    {1, 1, 1, 1, 1, 0, 0, 0},

    // 6 
    // 2 4
    {1, 0, 1, 0, 1, 1, 1, 1},
    {1, 0, 0, 1, 1, 1, 1, 1},
    // 3 3
//    {1, 0, 1, 1, 1, 1, 1, 0},
    {1, 0, 1, 1, 1, 0, 1, 1},
    {1, 1, 1, 0, 1, 1, 1, 0},
//    {1, 1, 1, 0, 1, 0, 1, 1},
    // 4 2
//    {1, 1, 1, 1, 1, 0, 1, 0},
//    {1, 1, 1, 1, 1, 0, 0, 1},

};
