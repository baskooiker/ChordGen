/* 
 * File:   Scale.h
 * Author: Bas
 *
 * Created on 3 februari 2014, 17:08
 */

#include <vector>
#include "Chord.h"

using namespace std;

#ifndef SCALE_H
#define	SCALE_H

class Scale {
public:

    enum Type {
        Major, NaturalMinor, HarmonicMinor, MelodicMinor
    };
    
    static const char* toString(Type ty) {
     switch(ty) {
        case Major:
           return "Major";
        case NaturalMinor:
           return "NaturalMinor";
        case HarmonicMinor:
           return "HarmonicMinor";
        case MelodicMinor:
           return "MelodicMinor";
     }
}

    Scale(int _root, Type type);
    Scale(const Scale& orig);
    virtual ~Scale();
    
    Chord getChord(int index);
    int getNote(int index);
    int getRoot();
    vector<Chord> getChords();
    
    int bestNext(int last);
    int bestPrevious(int next);
    
private:
    int root;
    vector<int> scale;
    vector<Chord> chords;
    void addChord(int i, Chord c);
    
    void initMajor();
    void initNaturalMinor();
    void initHarmonicMinor();
    void initMelodicMinor();
    
    std::vector<std::vector<int> > trans;
    void initTransMajor();
    void initTransMinor();

    void initTrans();
};

#endif	/* SCALE_H */

