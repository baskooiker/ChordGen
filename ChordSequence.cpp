/* 
 * File:   ChordSequence.cpp
 * Author: Bas
 * 
 * Created on 29 januari 2014, 18:18
 */

#include "ChordSequence.h"
#include <vector>
#include "Chord.h"

using namespace std;

ChordSequence::ChordSequence() {
//    sequence = vector<Chord*>(8, new Chord());
    for(int i = 0; i < 64; i++)
        sequence.push_back(Chord());
//    sequence
}

ChordSequence::ChordSequence(const ChordSequence& orig) {
    sequence = orig.sequence;
}

ChordSequence::~ChordSequence() {
}

void ChordSequence::set(int index, Chord chord){
    sequence[index] = chord;
}

Chord ChordSequence::getChord(int index){
    return sequence[index];
}

vector<Chord> ChordSequence::getChords(){
    return sequence;
}