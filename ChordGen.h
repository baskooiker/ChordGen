/* 
 * File:   ChordGen.h
 * Author: Bas
 *
 * Created on 27 januari 2014, 18:24
 */

#include <vector>
#include "ChordSequence.h"
#include "Scale.h"

using namespace std;

#ifndef CHORDGEN_H
#define	CHORDGEN_H

class ChordGen {
public:
    ChordGen();
    ChordGen(const ChordGen& orig);
    virtual ~ChordGen();
    
    void generate();
    vector<int> get(int index);
    void setRoot(int r);
    void setRoot();
    void setSequenceLength(int l);
    void setSequenceLength();
    void setScaleType(Scale::Type t);
    void setScaleType();
    void setDensity(float f);
    void setDensity();
    void store(int i);
    void recall(int i);
    ChordSequence* getChordSequence();
    
    int getRoot();
    bool isRootSet();
    int getSequenceLength();
    bool isSequenceLengthSet();
    Scale::Type getScaleType();
    bool isScaleTypeSet();
    float getDensity();
    bool isDensitySet();
    
private:
    static int const scales[][7];
    
    vector<int> sequence;
    ChordSequence seq;
    int getChordLength(int rhythmIndex, int beatIndex);
    int densityOf(int index);
    Scale::Type scaleType;
    bool scaleTypeSet;
    
    int root;
    bool rootSet;
    
    int sequenceLength;
    bool sequenceLengthSet;
    
    float density;
    bool densitySet;
    
    vector<ChordSequence*> bank;
    
    void init();
};

#endif	/* CHORDGEN_H */

