/* 
 * File:   FrontToBack.h
 * Author: Bas
 *
 * Created on 27 maart 2014, 10:11
 */

#ifndef FRONTTOBACK_H
#define	FRONTTOBACK_H

#include "ChordGenStrategy.h"
#include "ChordSequence.h"

class FrontToBack : public ChordGenStrategy {
public:
    FrontToBack();
    FrontToBack(const FrontToBack& orig);
    virtual ~FrontToBack();
    
    ChordSequence generate(int root, Scale::Type scaleType, int sequenceLength, float density, int start = 0);
protected:

};

#endif	/* FRONTTOBACK_H */

