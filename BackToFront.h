/* 
 * File:   BackToFront.h
 * Author: Bas
 *
 * Created on 27 maart 2014, 15:37
 */

#ifndef BACKTOFRONT_H
#define	BACKTOFRONT_H

#include "ChordSequence.h"
#include "Scale.h"
#include "ChordGenStrategy.h"

class BackToFront : public ChordGenStrategy{
public:
    BackToFront();
    BackToFront(const BackToFront& orig);
    virtual ~BackToFront();
    
    ChordSequence generate(int root, Scale::Type scaleType, int sequenceLength, float density);
private:

};

#endif	/* BACKTOFRONT_H */

