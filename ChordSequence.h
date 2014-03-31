/* 
 * File:   ChordSequence.h
 * Author: Bas
 *
 * Created on 29 januari 2014, 18:18
 */

#include "Chord.h"

#include <vector>

using namespace std;

#ifndef CHORDSEQUENCE_H
#define	CHORDSEQUENCE_H

class ChordSequence {
public:
    ChordSequence();
    ChordSequence(const ChordSequence& orig);
    virtual ~ChordSequence();
    
    void set(int index, Chord chord);
    Chord getChord(int index);
    vector<Chord> getChords();
    
private:
    vector<Chord> sequence;
};

#endif	/* CHORDSEQUENCE_H */

