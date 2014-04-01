/* 
 * File:   ChordGen.cpp
 * Author: Bas
 * 
 * Created on 27 januari 2014, 18:24
 */

#include "ChordGen.h"
#include <stdlib.h>
#include "ChordSequence.h"
#include "Scale.h"
#include "Chord.h"
#include <time.h>  
#include <fstream>
#include "FrontToBack.h"
#include "ChordGenStrategy.h"
#include "BackToFront.h"
#include <float.h>
#include <algorithm>

ChordGen::ChordGen() {
    seq = ChordSequence();

    srand(time(NULL));

    scaleType = Scale::Major;
    scaleTypeSet = false;

    sequenceLength = 8;
    sequenceLengthSet = false;

    root = 0;
    rootSet = false;

    density = .5;
    densitySet = false;

    //    generate();

    for (int i = 0; i < 32; i++)
        bank.push_back(new ChordSequence());
}

ChordGen::ChordGen(const ChordGen& orig) {
    // To-do!!!
}

ChordGen::~ChordGen() {
    for (int i = 0; i < bank.size(); i++)
        delete bank[i];
    bank.clear();
}

void ChordGen::generate() {
    // If root wasn't set by user, randomly step a fifth up, down or keep the same root.
    if (!rootSet)
        root = (root + (rand() % 3 - 1) * 7 + 12) % 12;

    // If the scale wasn't set, take a random scale type.
    if (!scaleTypeSet) { // find random scaleType
        switch (rand() % 4) {
            case 0: scaleType = Scale::Major;
                break;
            case 1: scaleType = Scale::NaturalMinor;
                break;
            case 2: scaleType = Scale::HarmonicMinor;
                break;
            case 3: scaleType = Scale::MelodicMinor;
                break;
        }
    }

    // set density if not set
    if (!densitySet)
        density = (float) rand() / (float) RAND_MAX;

    // determine sequenceLentgh
    if (!sequenceLengthSet) {
        if (((float) rand() / (float) RAND_MAX) < .5) {
            sequenceLength = 8;
        } else {
            sequenceLength = 16;
        }
    }

    FrontToBack ftb = FrontToBack();
    BackToFront btf = BackToFront();
    if (sequenceLength == 8) {
        seq = btf.generate(root, scaleType, 8, density, 4);
//        seq = ftb.generate(root, scaleType, sequenceLength, density);
    } else if (sequenceLength == 16){
        seq = btf.generate(root, scaleType, 8, density, 4);
        seq.append(btf.generate(root, scaleType, 8, density, 0).getChords());
    }
}

int ChordGen::getSequenceLength() {
    return sequenceLength;
}

vector<int> ChordGen::get(int i) {
    int index = i % sequenceLength;
    Chord c = seq.getChord(index);
    return c.get();
}

// Setters ===========================

void ChordGen::setRoot(int r) {
    if (r == -1)
        rootSet = false;
    else {
        root = r;
        rootSet = true;
    }
}

void ChordGen::setRoot() {
    rootSet = false;
}

void ChordGen::setSequenceLength(int l) {
    if (l == -1)
        sequenceLengthSet = false;
    else {
        if (l == 8 || l == 16 || l == 32 || l == 64) {
            sequenceLength = l;
            sequenceLengthSet = true;
        }
    }
}

void ChordGen::setSequenceLength() {
    sequenceLengthSet = false;
}

void ChordGen::setScaleType(Scale::Type t) {
    scaleType = t;
    scaleTypeSet = true;
}

void ChordGen::setScaleType() {
    scaleTypeSet = false;
}

void ChordGen::setDensity(float f) {
    density = min(1.f, max(f, 0.f));
    densitySet = true;
}

void ChordGen::setDensity() {
    densitySet = false;
}


// getters

ChordSequence* ChordGen::getChordSequence() {
    return &seq;
}

int ChordGen::getRoot() {
    return root;
}

Scale::Type ChordGen::getScaleType() {
    return scaleType;
}

float ChordGen::getDensity() {
    return density;
}

bool ChordGen::isRootSet() {
    return rootSet;
}

bool ChordGen::isSequenceLengthSet() {
    return sequenceLengthSet;
}

bool ChordGen::isScaleTypeSet() {
    return scaleTypeSet;
}

bool ChordGen::isDensitySet() {
    return densitySet;
}

// Bank methods ===================

void ChordGen::store(int i) {
    bank[i] = new ChordSequence(seq);
}

void ChordGen::recall(int i) {
    seq = ChordSequence(*(bank[i]));
}

