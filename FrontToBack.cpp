/* 
 * File:   FrontToBack.cpp
 * Author: Bas
 * 
 * Created on 27 maart 2014, 10:11
 */

#include "FrontToBack.h"
#include "RhythmGenerator.h"
#include <stdlib.h>
#include <stdio.h>

FrontToBack::FrontToBack() {
}

FrontToBack::FrontToBack(const FrontToBack& orig) {
}

FrontToBack::~FrontToBack() {
}

ChordSequence FrontToBack::generate(int root, Scale::Type scaleType, int sequenceLength, float density) {

    RhythmGenerator rg = RhythmGenerator();
    vector<int> rhythm = rg.generate(density);
    for (int i = 0; i < rhythm.size(); i++)
        printf("%d ", rhythm[i]);
    printf("\n");

    Scale scale = Scale(root, scaleType);

    ChordSequence seq = ChordSequence();
    int lastChord = -1;

generation_loop:
    for (int i = 0; i < sequenceLength; i++) {
        if (i % 8 == 0) {
            if (i == 0) {
                lastChord = 0;
            } else {
                if (rand() % 2)
                    lastChord = 0;
                else
                    lastChord = 4;
            }
            seq.set(i, scale.getChord(lastChord));
        } else if (rhythm[i % 8] == 1) {
            bool good = true;
            int chordLength = getChordLength(rhythm, i);
            int newChordIndex = 0;
            Chord newChord;
            int counter = 0;
            do {
                if (counter > 20)
                    goto generation_loop;
                newChordIndex = scale.bestNext(lastChord);
                newChord = scale.getChord(newChordIndex);
                Chord::Fifth fifth = newChord.getFifth();
                if (fifth == Chord::Diminished || fifth == Chord::Augmented) {
                    if (chordLength > 2 || i % 4 == 0) {
                        good = false;
                    }
                } else if ((float)rand() / (float)RAND_MAX < .75){
                    newChord.setSeventh(Chord::NoneSv);
                }
                counter++;
            } while (!good);
            lastChord = newChordIndex;

            seq.set(i, newChord);
        } else {
            seq.set(i, seq.getChord(i - 1));
        }
    }

    return seq;
}