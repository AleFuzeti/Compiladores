#include "lexer.hpp"

void lexer::analyzer(std::string input, int transitions[NUMBER_OF_STATES][ALPHABET_SIZE], bool finals[NUMBER_OF_STATES]){
    this->_state._current_state = 1;
    this->_state._last_final = 0;
    this->_state._lenght = 0;

    std::string::iterator cursor = input.begin(),
                          cursor_buffer = cursor,
                          cursor_last;

    std::string token;
    char c = 0;

    while(true){
        c = *cursor;

        get_state(c, transitions, finals);
        if(this->_state._current_state == 0){
            if(this->_state._last_final == 0){
                token.assign("ERRO");
                if  (*cursor == ' ') {
                    token.assign("BLANK");
                }
                cursor++;
                cursor_buffer = cursor;
            } else {
                cursor = cursor_last + 1;
                token.assign(cursor_buffer, cursor);

                cursor_buffer = cursor;
                
                if(*cursor == '\n'){
                    cursor++;
                    cursor_buffer = cursor;
                }
            }
            if (token == "ERRO"){
                for(int i = 0; i < this->_state._lenght; i++){
                    std::cout << token << '\n';
                }
            } else if (token == "BLANK"){
            } else if (get_tokens(this->_state._last_final) == "INTEIRO" || get_tokens(this->_state._last_final) == "REAL"){
                std::cout << get_tokens(this->_state._last_final);
                std::cout << " " << token << '\n';
            }
            else {
                std::cout << get_tokens(this->_state._last_final);
                std::cout << '\n';
            }

            if(cursor >= input.end()){
                break;
            }

            this->reset();
        } else {
            if (is_final(finals)){
                cursor_last = cursor;
                }
            cursor++;
        }
    }
}

void lexer::get_state(char c, int transitions[NUMBER_OF_STATES][ALPHABET_SIZE], bool finals[NUMBER_OF_STATES]){
    if(c < 0)
        this->_state._current_state = 0;

    int i = get_state_2(c);
    if(i < 0 || i > ALPHABET_SIZE)
        this->_state._current_state = 0;
    else this->_state._current_state = transitions[this->_state._current_state][i];    

    if(is_final(finals))
        this->_state._last_final = this->_state._current_state;

    this->_state._lenght++;
}


void lexer::reset(){
    this->_state._current_state = 1;
    this->_state._last_final = 0;
    this->_state._lenght = 0;
}

int lexer::get_state_2(char c){
    if(c == 'a') return 0;
    if(c == 'c') return 1;
    if(c == 'e') return 2;
    if(c == 'h') return 3;
    if(c == 'i') return 4;
    if(c == 'r') return 5;
    if(c == 's') return 6;
    if(c == 't') return 7;
    if(c >= '0' && c <= '9') return 8;
    if(c == '+') return 9;
    if(c == '-') return 10;
    if(c == ' ') return 11;
    if(c == '\n') return 11;

    if (this->_state._current_state == 1)
        return -1;
    return 12;
}

std::string lexer::get_tokens(int state) {
    if (state == 3)  return "ELE";
    if (state == 6)  return "ELA";
    if (state == 8)  return "DELE";
    if (state == 10) return "DELA";
    if (state == 13) return "GATO";
    if (state == 15) return "GATOS";
    if (state == 14) return "CARRO";
    if (state == 16) return "CARROS";

    if (state == 17) return "MAIS";
    if (state == 18) return "MENOS";
    if (state == 19) return "INTEIRO";
    if (state == 22) return "REAL";

    // Retornar uma string vazia se o estado não corresponder a nenhum token conhecido
    return "";
}

bool lexer::is_final(bool finals[NUMBER_OF_STATES]){
    return finals[this->_state._current_state];
}