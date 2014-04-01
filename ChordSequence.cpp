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
}

ChordSequence::ChordSequence(const ChordSequence& orig) {
    sequence = orig.sequence;
}

ChordSequence::~ChordSequence() {
}

void ChordSequence::set(int index, Chord chord){
    if(sequence.size() > index)
        sequence[index] = chord;
    else if (sequence.size() > 0){
        while(sequence.size() < index)
            sequence.push_back(sequence[sequence.size()-1]);
        sequence.push_back(chord);
    } else {
        while (sequence.size() <= index)
            sequence.push_back(chord);
    }
}

Chord ChordSequence::getChord(int index){
    return sequence[index];
}

vector<Chord> ChordSequence::getChords(){
    return sequence;
}

void ChordSequence::append(vector<Chord> chords){
    for(int i = 0; i < chords.size(); i++)
        sequence.push_back(chords[i]);
}