/**
File: Concordance
Dev: Matthew Herrera
Email: herreram81266@student.vvc.edu
Date: Sat Dec 15 18:21:52 PST 2018
Description: Stores a vector of every word from a text file, then checks to see how many times and on what line the word occurs.
**/


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include "word.h"


using namespace std;

int main()
{
    vector <Word> lexicon;

    string file_path = "alice.txt";
    ifstream text_file;
    
    text_file.open(file_path.c_str());

    string line;
    string word;

    int line_count = 1;

    while(!text_file.eof())
    {
        getline(text_file, line);
        istringstream read(line);     
        
        while(read >> word)
        {
              for(int i = 0, len = word.size(); i < len; i++)
              {
                    if(ispunct(word[i]))
                    {
                        word.erase(i--, 1);
                        len = word.size();
                    }
              }

              transform(word.begin(), word.end(), word.begin(), ::tolower);
              lexicon.push_back(Word(word, line_count));
             
        }
        line_count++;
    }
    
    for(int i = 0; i < lexicon.size(); i++)
        {
            int occurances = 0;

            cout << lexicon[i].get_word() << ": ";

            for(int b = 0; b < lexicon.size(); b++)
                {
                    if(lexicon[i].compare_word(lexicon[b].get_word()))
                        {   
                            lexicon[i].update_count();
                            occurances ++;

                                if(occurances > 1)
                                {
                                    lexicon[i].update_count();
                                    lexicon[i].add_location(lexicon[b].get_line());
                                    lexicon.erase(lexicon.begin() + b);
                                }
                        } 
                            
                }
            cout << lexicon[i].get_count() << " time(s). On line(s): " << lexicon[i].get_locations() << endl;
        }

    text_file.close();

    return 0;
}
