/* 
 * File:   Scale.cpp
 * Author: Bas
 * 
 * Created on 3 februari 2014, 17:08
 */

#include "Scale.h"
#include "Chord.h"
#include <float.h>
#include <stdlib.h>
#include <fstream>

Scale::Scale(int _root, Type type) {
    root = _root;

    switch (type) {
        case Major:
            initMajor();
            break;
        case NaturalMinor:
            initNaturalMinor();
            break;
        case HarmonicMinor:
            initHarmonicMinor();
            break;
        case MelodicMinor:
            initMelodicMinor();
            break;
    }
}

void Scale::initTrans() {
    trans.clear();
    for (int i = 0; i < chords.size(); i++) {
        trans.push_back(std::vector<int>(chords.size()));
        for (int j = 0; j < chords.size(); j++) {
            trans[i][j] = 0;
        }
    }
}

void Scale::initTransMajor() {
    initTrans();
    for (int i = 1; i < 6; i++)
        trans[0][i] = 1;
    trans[1][4] = trans[1][6] = 1;
//    trans[1][4] = 1;
    trans[2][5] = 1;
//    trans[3][4] = trans[3][6] = 1;
    trans[3][4] = 1;
    trans[4][0] = trans[4][6] = 1;
    trans[5][1] = trans[5][3] = trans [5][6] = 1;
    trans[6][0] = 1;
}

void Scale::initTransMinor() {
    initTrans();
    for (int i = 1; i < 7; i++)
        trans[0][i] = 1;
    trans[1][4] = trans[1][6] = 1;
    trans[2][5] = 1;
    trans[3][4] = trans[3][6] = 1;
    trans[4][0] = 1;
    trans[5][1] = trans[5][3] = 1;
    trans[6][0] = trans[6][2] = 1;
}

int Scale::bestNext(int last) {
    float r = (float)rand() / (float)RAND_MAX;
    int rowSum = 0;
    for (int i = 0; i < trans[last].size(); i++) 
        rowSum += trans[last][i];
    
    r *= (float)rowSum;
    float sum = 0.;
    for (int i = 0; i < trans[last].size(); i++) {
        sum += (float)trans[last][i];
        if(r < sum){
            return i;
        }
    }
    return -1;
}

int Scale::bestPrevious(int next) {
    float r = (float)rand() / (float)RAND_MAX;
    int colSum = 0;
    for (int i = 0; i < trans.size(); i++) 
        colSum += trans[i][next];
    
    r *= (float)colSum;
    float sum = 0.;
    for (int i = 0; i < trans.size(); i++) {
        sum += (float)trans[i][next];
        if(r < sum){
            return i;
        }
    }
    return -1;
}

void Scale::initMajor() {
    chords.clear();
    addChord(0, *((new Chord(root, Chord::MajorTh, Chord::Perfect, Chord::MajorSv, Chord::NoneInv))));
    addChord(2, *((new Chord())->setRoot(root + 2)->setThird(Chord::MinorTh)->setSeventh(Chord::MinorSv)));
    addChord(4, *((new Chord())->setRoot(root + 4)->setThird(Chord::MinorTh)->setSeventh(Chord::MinorSv)->setInversion(Chord::SecondInv)->setOctave(-1)));
    addChord(5, *((new Chord())->setRoot(root + 5)->setSeventh(Chord::MajorSv)->setInversion(Chord::SecondInv)->setOctave(-1)));
    addChord(7, *((new Chord())->setRoot(root + 7)->setSeventh(Chord::MinorSv)->setInversion(Chord::FirstInv)->setOctave(-1)));
    addChord(9, *((new Chord())->setRoot(root + 9)->setThird(Chord::MinorTh)->setSeventh(Chord::MinorSv)->setInversion(Chord::FirstInv)->setOctave(-1)));
//    addChord(11, *((new Chord())->setRoot(root + 11)->setThird(Chord::MinorTh)->setFifth(Chord::Diminished)->setInversion(Chord::FirstInv)->setSeventh(Chord::DiminishedSv)));
    addChord(11, *((new Chord())->setRoot(root + 11)->setThird(Chord::MinorTh)->setFifth(Chord::Diminished)->setSeventh(Chord::DiminishedSv)->setOctave(-1)));
//    addChord(11, *((new Chord())->setRoot(root + 11)->setFifth(Chord::Augmented)->setInversion(Chord::FirstInv)));
    initTransMajor();
}

void Scale::initNaturalMinor() {
    chords.clear();
    addChord(0, *((new Chord())->setRoot(root)->setThird(Chord::MinorTh)->setSeventh(Chord::MinorSv)));
    addChord(2, *((new Chord())->setRoot(root + 2)->setThird(Chord::MinorTh)->setFifth(Chord::Diminished)->setInversion(Chord::FirstInv)->setSeventh(Chord::MinorSv)));
    addChord(3, *((new Chord())->setRoot(root + 3)->setInversion(Chord::SecondInv)->setOctave(-1)->setSeventh(Chord::MinorSv)));
    addChord(5, *((new Chord())->setRoot(root + 5)->setThird(Chord::MinorTh)->setInversion(Chord::FirstInv)->setOctave(-1)->setSeventh(Chord::MinorSv)));
    addChord(7, *((new Chord())->setRoot(root + 7)->setThird(Chord::MinorTh)->setInversion(Chord::FirstInv)->setOctave(-1)->setSeventh(Chord::MinorSv)));
    addChord(8, *((new Chord())->setRoot(root + 8)->setInversion(Chord::FirstInv)->setOctave(-1)->setSeventh(Chord::MinorSv)));
    addChord(10, *((new Chord())->setRoot(root + 10)->setInversion(Chord::FirstInv)->setOctave(-1)->setSeventh(Chord::MinorSv)));
    initTransMinor();
}

void Scale::initHarmonicMinor() {
    chords.clear();
    addChord(0, *((new Chord())->setRoot(root)->setThird(Chord::MinorTh)));
    addChord(2, *((new Chord())->setRoot(root + 2)->setThird(Chord::MinorTh)->setFifth(Chord::Diminished)->setInversion(Chord::FirstInv)));
    addChord(3, *((new Chord())->setRoot(root + 3)->setFifth(Chord::Augmented)));
    addChord(5, *((new Chord())->setRoot(root + 5)->setThird(Chord::MinorTh)));
    addChord(7, *((new Chord())->setRoot(root + 7)));
    addChord(8, *((new Chord())->setRoot(root + 8)));
    addChord(11, *((new Chord())->setRoot(root + 11)->setThird(Chord::MinorTh)->setFifth(Chord::Diminished)));
    initTransMinor();
}

void Scale::initMelodicMinor() {
    chords.clear();
    addChord(0, *((new Chord())->setRoot(root)->setThird(Chord::MinorTh)));
    addChord(2, *((new Chord())->setRoot(root + 2)->setThird(Chord::MinorTh)));
    addChord(3, *((new Chord())->setRoot(root + 3)->setFifth(Chord::Augmented)));
    addChord(5, *((new Chord())->setRoot(root + 5)));
    addChord(7, *((new Chord())->setRoot(root + 7)));
    addChord(9, *((new Chord())->setRoot(root + 9)->setThird(Chord::MinorTh)->setFifth(Chord::Diminished)->setInversion(Chord::FirstInv)));
    addChord(11, *((new Chord())->setRoot(root + 11)->setThird(Chord::MinorTh)->setFifth(Chord::Diminished)));
    initTransMinor();
}

Scale::Scale(const Scale& orig) {
}

Scale::~Scale() {
}

void Scale::addChord(int i, Chord c) {
    scale.push_back(i);
    chords.push_back(c);
}

Chord Scale::getChord(int index) {
    return chords[index];
}

vector<Chord> Scale::getChords() {
    return chords;
}

int Scale::getNote(int index) {
    return scale[index];
}

int Scale::getRoot() {
    return root;
}