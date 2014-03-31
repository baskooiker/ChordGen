/* 
 * File:   Chord.h
 * Author: Bas Kooiker
 *
 * Created on 29 januari 2014, 18:09
 */

#include <vector>
#include <string>

using namespace std;

#ifndef CHORD_H
#define	CHORD_H

class Chord {
public:
    enum Third {
        MinorTh, MajorTh, Sus2, Sus4
    };

    enum Fifth {
        Perfect, Diminished, Augmented
    };

    enum Seventh {
        NoneSv, MajorSv, MinorSv, DiminishedSv
    };

    enum Inversion {
        NoneInv, FirstInv, SecondInv
    };

    Chord();
    Chord(int r, Third th, Fifth f, Seventh sv, Inversion inv);
    Chord(const Chord& orig);
    virtual ~Chord();

    Chord* setRoot(int r);
    Chord* setThird(Third t);
    Chord* setFifth(Fifth f);
    Chord* setSeventh(Seventh s);
    Chord* setInversion(Inversion i);
    Chord* setOctave(int oct);
    vector<int> get();
    std::string toString();
    Fifth getFifth();

private:
    int root;
    Third third;
    Fifth fifth;
    Seventh seventh;
    Inversion inversion;
    int octave;
    static const char* roots[];
    
    static const int defaultOctave = 4;
};

#endif	/* CHORD_H */

