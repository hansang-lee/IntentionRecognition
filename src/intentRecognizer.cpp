#include <iostream>
#include <string>
#include <regex>
#include "intentRecognizer.h"

using namespace std;

IntentRecognizer::IntentRecognizer()
:m_Weather("")
,m_Fact("")
,m_Time("")
,m_Date("")
,m_Place("")
{

}

IntentRecognizer::~IntentRecognizer()
{

}

string IntentRecognizer::GetIntent(const int i_countWords, char** i_words)
{
    /* Convert char** in a string form */
    string converted = Convert2DCharArrayToString(i_countWords, i_words);

    return GetIntent(converted);
}

string IntentRecognizer::GetIntent(const string i_sentence)
{
    string recognizedIntent("");

    /* Search for keywords from string and register in member variables */
    RegisterKeywords(i_sentence);

    /* Recognize intent process */
    if(m_Weather != "")
    {
        recognizedIntent.append("Intent: Get Weather");
        
        if(m_Place != "")
        {
            recognizedIntent.append(" City");
        }
    }

    else if(m_Fact != "")
    {
        recognizedIntent.append("Intent: Get Fact");
    }

    else if(m_Time != "")
    {
        recognizedIntent.append("Intent: Check Calendar");
    }

    return recognizedIntent;
}

string IntentRecognizer::Convert2DCharArrayToString(const int i_count, char** i_array)
{
    string sentence(i_array[0]);

    for(int i=1; i<i_count; i++)
    {
        sentence.append(string(" "));
        sentence.append(string(i_array[i]));
    }

    return sentence;
}

void IntentRecognizer::RegisterKeywords(const string i_sentence)
{
    smatch searchedResult;
    regex searchTarget;
    
    /* WEATHER */
    searchTarget = regex("([w|W][e|E][a|A][t|T][h|H][e|E][r|R]"
                        "|[r|R][a|A][i|I][n|N]"
                        "|[d|D][r|R][y|Y]"
                        "|[c|C][l|L][o|O][u|U][d|D]"
                        "|[h|H][u|U][m|M][i|I][d|D]"
                        "|[s|S][u|U][n|N]"
                        "|[s|S][n|N][o|O][w|W]"
                        "|[w|W][i|I][n|N][d|D}"
                        "|[f|F][o|O][g|G])");

    if(regex_search(i_sentence, searchedResult, searchTarget))
    {
        m_Weather = string(searchedResult[0]);
    }

    /* FACT */
    searchTarget = regex("([f|F][a|A][c|C][t|T])");

    if(regex_search(i_sentence, searchedResult, searchTarget))
    {
        m_Fact = string(searchedResult[0]);
    }
    
    /* TIME */
    searchTarget = regex("([0-9][.|:][0-5][0-9]"
                        "|[1][0-9][.|:][0-5][0-9]"
                        "|[2][0-3][.|:][0-5][0-9])");

    if(regex_search(i_sentence, searchedResult, searchTarget))
    {
        m_Time = string(searchedResult[0]);
    }

    /* DATE */
    searchTarget = regex("([t|T][o|O][d|D][a|A][y|Y]"
                        "|[t|T][o|O][m|M][o|O][r|R][r|R][o|O][w|W]"
                        "|[y|Y][e|E][s|S][t|T][e|E][r|R][d|D][a|A][y|Y]"
                        "|[w|W][e|E][e|E][k|K][e|E][n|N][d|D][s|S])");

    if(regex_search(i_sentence, searchedResult, searchTarget))
    {
        m_Date = string(searchedResult[0]);
    }

    /* PLACE */
    searchTarget = regex("([p|P][a|A][r|R][i|I][s|S]"
                        "|[n|N][e|E][w|W] [y|Y][o|O][r|R][k|K])");

    if(regex_search(i_sentence, searchedResult, searchTarget))
    {
        m_Place = string(searchedResult[0]);
    }
}