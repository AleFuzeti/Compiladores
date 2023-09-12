#include "lexer.hpp"

void lexer::analyzer(std::string input, int transitions[NUMBER_OF_STATES][ALPHABET_SIZE], bool finals[NUMBER_OF_STATES]){
    this->_state._current_state = 1;
    this->_state._last_final = 0;

    std::string::iterator cursor = input.begin(),
                          cursor_buffer = cursor;

    std::string token;
    char c = 0;

    while(true){
        c = *cursor;

        get_state(c, transitions, finals);

        if(this->_state._current_state == 0){
            if(this->_state._last_final == 0){
                token.assign("ERRO");
                cursor++;
                cursor_buffer = cursor;
            } else {
                token.assign(cursor_buffer, cursor);
                cursor_buffer = cursor;
                if(*cursor == '\n'){
                    cursor++;
                    cursor_buffer = cursor;
                }
            }

            std::cout << token;
            std::cout << "\n";

            if(cursor == input.end()){
                break;
            }

            this->reset();
        } else {
            cursor++;
        }
    }
}

int lexer::get_state(char c, int transitions[NUMBER_OF_STATES][ALPHABET_SIZE], bool finals[NUMBER_OF_STATES]){
    if(c < 0)
        return 0;

    int i = get_state_2(c);
    this->_state._current_state = transitions[this->_state._current_state][i];

    if(finals[this->_state._current_state])
        this->_state._last_final = this->_state._current_state;

    return this->_state._current_state;
}

void lexer::reset(){
    this->_state._current_state = 1;
    this->_state._last_final = 0;
}

int lexer::get_state_2(char c){
    if(c == 'i') return 0;
    if(c == 'f') return 1;
    if(c >= 'a' && c <= 'z') return 2;
    if(c >= '0' && c <= '9') return 3;
    if(c == '.') return 4;
    if(c >= '-') return 5;
    if(c >= '\n') return 6;
    if(c >= ' ') return 7;
    
    if (this->_state._current_state == 1)
        return -1;
    return 8;
}