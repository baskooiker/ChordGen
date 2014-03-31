/* 
 * File:   main.cpp
 * Author: Bas
 *
 * Created on 18 februari 2014, 12:28
 */

#include "Chord.h"
#include "ChordGen.h"

//#include <cstdlib>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
//#include <unistd.h>
//#include <dos.h>
//#include <windows.h>


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ChordGen cg = ChordGen();
//    cg->setScaleType(Scale::MelodicMinor); // Pretty solid. 1000 okays with the two others on, that is.
//    cg->setSequenceLength(16); // weird stuff. Pretty fatal errors
//    cg->setDensity(.5); // weird stuff going on. Infinite loops and all that
    printf("ChordGen opened!\n");
//    Sleep(10);
    for (int i = 0; i < 100000; i++) {
        cg.generate();
//        printf("sequence length = %d, density = %f\n", cg->getSequenceLength(), cg->getDensity());
        for(int j = 0; j < cg.getSequenceLength(); j++){
            printf("%d %s\n", j, cg.getChordSequence()->getChord(j).toString().c_str());
        }
        printf("\n");
    }
    return 0;
}

