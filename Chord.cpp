/* 
 * File:   Chord.cpp
 * Author: Bas
 * 
 * Created on 29 januari 2014, 18:09
 */

#include "Chord.h"
#include <string>
#include <string.h>

Chord::Chord() {
    root = 0;
    third = MajorTh;
    fifth = Perfect;
    seventh = NoneSv;
    octave = 0;

    inversion = NoneInv;
}

Chord::Chord(int r, Third th, Fifth f, Seventh sv, Inversion inv) {
    root = r;
    third = th;
    fifth = f;
    seventh = sv;
    octave = 0;

    inversion = inv;
}

Chord::Chord(const Chord& orig) {
    root = orig.root;
    third = orig.third;
    fifth = orig.fifth;
    seventh = orig.seventh;
    octave = orig.octave;
    inversion = orig.inversion;
}

Chord::~Chord() {
}

const char* Chord::roots[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};

Chord* Chord::setRoot(int r) {
    root = r;
    return this;
}

Chord* Chord::setThird(Third t) {
    third = t;
    return this;
}

Chord* Chord::setFifth(Fifth f) {
    fifth = f;
    return this;
}

Chord* Chord::setSeventh(Seventh s) {
    seventh = s;
    return this;
}

Chord* Chord::setInversion(Inversion i) {
    inversion = i;
    return this;
}

Chord* Chord::setOctave(int oct) {
    octave = oct;
    return this;
}

vector<int> Chord::get() {
    std::vector<int> chord;

    int skip = 0;
    if (inversion != Chord::NoneInv)
        skip = 12;

    int note = root;
    note += skip;
    note += 12 * (octave + defaultOctave);
    chord.push_back(note);



    if (inversion != Chord::SecondInv)
        skip = 0;

    int t = 0;
    if (third == Chord::MinorTh)
        t = -1;
    chord.push_back(root + t + 4 + skip + 12 * (octave + defaultOctave));

    int f = 0;
    if (fifth == Chord::Diminished)
        f = -1;
    else if (fifth == Chord::Augmented)
        f = 1;
    chord.push_back(root + 7 + f + 12 * (octave + defaultOctave));

    if (seventh == Chord::DiminishedSv)
        chord.push_back(root + 9 + 12 * (octave + defaultOctave));
    else if (seventh == Chord::MinorSv)
        chord.push_back(root + 10 + 12 * (octave + defaultOctave));
    else if (seventh == Chord::MajorSv)
        chord.push_back(root + 11 + 12 * (octave + defaultOctave));

    return chord;
}

Chord::Fifth Chord::getFifth() {
    return fifth;
}

string Chord::toString() {
    string r = string(roots[root % 12]);
    string m = "";
    string f = "";
    string s = "";

    if (third == MinorTh)
        m = "m";

    switch (fifth) {
        case Diminished:
            m = "";
            f = "dim";
            break;
        case Augmented:
            m = "";
            f = "aug";
            break;
    }

    switch (seventh) {
        case MajorSv:
            s = "maj7";
            break;
        case MinorSv:
            s = "7";
            break;
        case DiminishedSv:
            s = "7";
            break;
        default:
            break;
    }

    return (r + m + f + s);
}