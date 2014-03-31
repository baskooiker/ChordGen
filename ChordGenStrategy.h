/* 
 * File:   ChordGenStrategy.h
 * Author: Bas
 *
 * Created on 27 maart 2014, 10:08
 */

#ifndef CHORDGENSTRATEGY_H
#define	CHORDGENSTRATEGY_H

#include "ChordSequence.h"
#include "Scale.h"

class ChordGenStrategy {
public:
    ChordGenStrategy();
    ChordGenStrategy(const ChordGenStrategy& orig);
    virtual ~ChordGenStrategy();
    
    virtual ChordSequence generate(int root, Scale::Type scaleType, int sequenceLength, float density) = 0;
protected:
    int getChordLength(vector<int> rhythm, int index);
    

};

#endif	/* CHORDGENSTRATEGY_H */

