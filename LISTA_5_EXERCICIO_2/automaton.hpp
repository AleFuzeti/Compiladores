#ifndef AUTOMATON_HPP
#define AUTOMATON_HPP

#include "defs.hpp"

bool is_final[NUMBER_OF_STATES]={false, false, true, true, true, true, true, true, true, true, false, true, true, true};

int edges[NUMBER_OF_STATES][ALPHABET_SIZE] = {
    /*input       i   f  a-z 0-9  .   -  \n  blk oth */ 
    /*state 0*/  {0,  0,  0,  0,  0,  0,  0,  0,  0},
    /*state 1*/  {2,  4,  4,  7,  5,  9,  0, 12, 13},
    /*state 2*/  {4,  3,  4,  4,  0,  0,  0,  0,  0},
    /*state 3*/  {4,  4,  4,  4,  0,  0,  0,  0,  0},
    /*state 4*/  {4,  4,  4,  4,  0,  0,  0,  0,  0},
    /*state 5*/  {0,  0,  0,  6,  0,  0,  0,  0,  0},
    /*state 6*/  {0,  0,  0,  6,  0,  0,  0,  0,  0},
    /*state 7*/  {0,  0,  0,  7,  8,  0,  0,  0,  0},
    /*state 8*/  {0,  0,  0,  8,  0,  0,  0,  0,  0},
    /*state 9*/  {0,  0,  0,  0,  0, 10,  0,  0,  0},
    /*state 10*/ {10,10, 10,  0,  0,  0, 11,  0,  0},
    /*state 11*/ {0,  0,  0,  0,  0,  0,  0,  0,  0},
    /*state 12*/ {0,  0,  0,  0,  0,  0,  0, 12,  0},
    /*state 13*/ {0,  0,  0,  0,  0,  0,  0,  0,  0},
};
#endif