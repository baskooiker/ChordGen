/* 
 * File:   BackToFront.cpp
 * Author: Bas
 * 
 * Created on 27 maart 2014, 15:37
 */

#include "BackToFront.h"
#include <vector>
#include <stdlib.h>
#include <stdio.h>


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

vector<Chord> BackToFront::generateSeq(int nrOfChords, Scale &scale, int end) {
    vector<Chord> chords;
    for (int i = 0; i < nrOfChords; i++)
        chords.push_back(scale.getChord(end));
    int prev = end;
    for (int i = nrOfChords - 2; i >= 0; i--){
        prev = scale.bestPrevious(prev);
        chords[i] = scale.getChord(prev);
    }
    return chords;
}

ChordSequence BackToFront::generate(int root, Scale::Type scaleType, int sequenceLength, float density, int end = 0) {

    Scale scale = Scale(root, scaleType);

start_generate:
    ChordSequence seq = ChordSequence();

    RhythmGenerator rg = RhythmGenerator();
    std::vector<int> rhythm = rg.generate(density);

    int nrOfChords = 0;
    for (int i = 0; i < sequenceLength; i++)
        nrOfChords += rhythm[i % 8];

    int counter = 0;
    do {
        //        if(counter++ > 20)
        //            goto start_generate;
//        printf("in the loop\n");
        vector<Chord> chords = generateSeq(nrOfChords, scale, end);
        //        for (int i = 0; i < chords.size(); i++)
        //            printf("%s\n", chords[i].toString().c_str());
        //        printf("\n");
        int chordCount = 0;
        for (int i = 0; i < sequenceLength; i++)
            if (rhythm[i % 8] == 1)
                seq.set(i, chords[chordCount++]);
            else
                seq.set(i, seq.getChord(i - 1));
    } while (!checkProgression(seq));

    return seq;
}