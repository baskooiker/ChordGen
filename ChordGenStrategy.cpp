/* 
 * File:   ChordGenStrategy.cpp
 * Author: Bas
 * 
 * Created on 27 maart 2014, 10:08
 */

#include "ChordGenStrategy.h"

#include <stdio.h>

#include "Chord.h"

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

bool ChordGenStrategy::checkProgression(ChordSequence seq) {
    vector<Chord> chords = seq.getChords();
    for (int i = 0; i < chords.size(); i++) {
        bool check = false;
        if (i == 0)
            check = true;
        else if (!(chords[i] == chords[i - 1]))
            check = true;

        if (check) {
            Chord::Fifth fifth = chords[i].getFifth();
            int chordLength = 0;
            while (chords[i] == chords[i + chordLength] && (i + ++chordLength < chords.size())) {
            }
            if (fifth == Chord::Diminished || fifth == Chord::Augmented) {
                if (chordLength > 2 || i % 4 == 0) {
                    printf("false\n");
                    return false;
                }
            }
        }
    }
    printf("true\n");
    return true;
}
