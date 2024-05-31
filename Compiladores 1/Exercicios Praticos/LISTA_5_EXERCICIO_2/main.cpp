#include <iostream>
#include <cstdio>

#include "automaton.hpp"
#include "lexer.hpp"

int main() {
    lexer analyzer;
    std::string input;
    char ch;

    while((ch = getchar()) != EOF) {
        input += ch;
    }

    analyzer.analyzer(input, edges, is_final);
    return 0;
}