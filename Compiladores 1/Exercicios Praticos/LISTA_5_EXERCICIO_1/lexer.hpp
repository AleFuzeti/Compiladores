#ifndef COMPILADOR_HPP
#define COMPILADOR_HPP

#include <iostream>
#include <string>

#include "defs.hpp"

struct states{
    int _current_state,
        _last_final;
};

class lexer{
    public:
        void analyzer(std::string input, int transitions[NUMBER_OF_STATES][ALPHABET_SIZE], bool finals[NUMBER_OF_STATES]);
        int get_state(char c, int transitions[NUMBER_OF_STATES][ALPHABET_SIZE], bool finals[NUMBER_OF_STATES]);
        void reset();

    private:
        struct states _state;
        int get_state_2(char c);
};

#endif