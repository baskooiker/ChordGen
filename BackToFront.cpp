/* 
 * File:   BackToFront.cpp
 * Author: Bas
 * 
 * Created on 27 maart 2014, 15:37
 */

#include "BackToFront.h"
#include <vector>
#include <stdlib.h>


#include "ChordSequence.h"
#include "Scale.h"
#include "RhythmGenerator.h"
#include "Chord.h"

BackToFront::BackToFront() {
}

BackToFront::BackToFront(const BackToFront& orig) {
}

BackToFront::~BackToFront() {
}

ChordSequence BackToFront::generate(int root, Scale::Type scaleType, int sequenceLength, float density) {

    RhythmGenerator rg = RhythmGenerator();
    std::vector<int> rhythm = rg.generate(density);

    Scale scale = Scale(root, scaleType);

    ChordSequence seq = ChordSequence();
    int lastChord = -1;

generation_loop:
//    int lastInterval = -1;
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
//            lastInterval = -1;
            seq.set(i, scale.getChord(lastChord));
        } else if (rhythm[i % 8] == 1) {
//            int r;
            bool good = true;
            int chordLength = getChordLength(rhythm, i);
            int newChordIndex = 0;
            Chord newChord;
            int counter = 0;
            do {
                if (counter > 20) {
                    goto generation_loop;
                }
//                r = rand() % 3 + 2;
//                if (7 - r == lastInterval)
//                    good = false;
//                newChordIndex = (lastChord + r) % 7;
                newChordIndex = scale.bestNext(lastChord);
                
                newChord = Chord(scale.getChord(newChordIndex));
                if (chordLength > 2) {
                    Chord::Fifth fifth = newChord.getFifth();
                    if (fifth == Chord::Diminished || fifth == Chord::Augmented){
//                        printf("diminished or augmented\n");
                        good = false;
                    }
                }
                counter++;
            } while (!good);

//            lastInterval = r;
            lastChord = newChordIndex;

            seq.set(i, newChord);
        } else {
            seq.set(i, Chord(seq.getChord(i - 1)));
        }
    }

    return seq;
}