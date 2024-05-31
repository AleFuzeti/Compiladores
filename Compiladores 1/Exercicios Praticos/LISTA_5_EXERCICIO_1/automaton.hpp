#ifndef AUTOMATON_HPP
#define AUTOMATON_HPP

#include "defs.hpp"

bool is_final[NUMBER_OF_STATES]={false, false, true, true, true, true, false, false, true};

int edges[NUMBER_OF_STATES][ALPHABET_SIZE] = {
    /*input      +   -  0-9  e  a-z  . */
    /*state 0*/ {0,  0,  0,  0,  0,  0},
    /*state 1*/ {3,  4,  5,  2,  2,  0},
    /*state 2*/ {0,  0,  2,  2,  2,  0},
    /*state 3*/ {0,  0,  0,  0,  0,  0},
    /*state 4*/ {0,  0,  0,  0,  0,  0},
    /*state 5*/ {0,  0,  5,  6,  0,  0},
    /*state 6*/ {7,  7,  8,  0,  0,  0},
    /*state 7*/ {0,  0,  8,  0,  0,  0},
    /*state 8*/ {0,  0,  8,  0,  0,  0},
};
#endif