#include "word.h"

using namespace std;

Word::Word()
{
    m_word = "";
    m_count = 0;
}

Word::Word(string new_word, int line)
{
    m_word = new_word;
    m_count = 0;
    m_line = line;
    m_lines.push_back(line);
}

string Word::get_word()
{
    return m_word;
}

void Word::set_word(string new_word)
{
    m_word = new_word;
}

bool Word::compare_word(string new_word)
{
    if(m_word == new_word)
    {
        return true;
    } else {
        return false;
    }
}

void Word::update_count()
{
    m_count ++;
}

int Word::get_count()
{
    return m_count;
}

int Word::get_line()
{
    return m_line;
}

string Word::get_locations()
{
    string list = "";
    for(int i = 0; i < m_lines.size(); i++)
    {
        if(i < (m_lines.size() - 1))
        {
        list += to_string(m_lines[i]) + ", ";
        } else {
        list += to_string(m_lines[i]) + ".";
        }
    }
    return list;
}

void Word::add_location(int line)
{
    m_lines.push_back(line);
}

string Word::print_data()
{
    string output;
    //stubbed for now.
    cout << output;
}
