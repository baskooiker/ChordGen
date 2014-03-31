/* 
 * File:   RhythmGenerator.h
 * Author: Bas
 *
 * Created on 27 maart 2014, 10:53
 */

#ifndef RHYTHMGENERATOR_H
#define	RHYTHMGENERATOR_H

#include <vector>

class RhythmGenerator {
public:
    RhythmGenerator();
    RhythmGenerator(const RhythmGenerator& orig);
    virtual ~RhythmGenerator();
    
    std::vector<int> generate(float density);
    
protected:
    static int const rhythms[][8];
    int densityOf(int index);
};

#endif	/* RHYTHMGENERATOR_H */

