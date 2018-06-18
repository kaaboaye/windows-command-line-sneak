//
// Created by admin on 17.06.2018.
//

#ifndef SNEAK_CARTESIAN_H
#define SNEAK_CARTESIAN_H

struct Cartesian {
    typedef int Unit;

    Unit x;
    Unit y;

    bool operator== (const Cartesian &right) const;
    bool operator!= (const Cartesian &right) const;
    Cartesian operator+ (const Cartesian &c);
    Cartesian operator+= (const Cartesian &c);
    Cartesian operator* (const Unit &mul);
};


#endif //SNEAK_CARTESIAN_H
