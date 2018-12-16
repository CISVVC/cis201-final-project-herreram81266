#ifndef WORD_H
#define WORD_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Word
{
    public:
       Word();
       Word(string new_word, int line);

       string get_word();
       void set_word(string new_word);

       bool compare_word(string new_word);

       void update_count();
       int get_count();
       
       int get_line();

       string get_locations();
       void add_location(int line);

       string print_data();

    private:
        string m_word;
        int m_count;
        int m_line;
        vector <int> m_lines;
};

#endif
