/* 
 * File:   ChordGenStrategy.cpp
 * Author: Bas
 * 
 * Created on 27 maart 2014, 10:08
 */

#include "ChordGenStrategy.h"

ChordGenStrategy::ChordGenStrategy() {
}

ChordGenStrategy::ChordGenStrategy(const ChordGenStrategy& orig) {
}

ChordGenStrategy::~ChordGenStrategy() {
}

int ChordGenStrategy::getChordLength(vector<int> rhythm, int beatIndex) {
    int l = 1;
    for (int i = beatIndex % 8 + 1; i < 8; i++) {
        if (rhythm[i] == 1)
            return l;
        l++;
    }
    return l;
}
