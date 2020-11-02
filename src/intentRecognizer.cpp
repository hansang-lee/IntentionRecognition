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
    string converted = Convert2DCharArrayToString(i_countWords, i_words);
    return GetIntent(converted);
}

string IntentRecognizer::GetIntent(const string i_sentence)
{
    string recognizedIntent("");

    m_Weather.clear();
    m_Fact.clear();
    m_Time.clear();
    m_Date.clear();
    m_Place.clear();

    /* Search for keywords from string */
    RegisterKeywords(i_sentence);

    /* Process for intent-recognition */
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

    else if((m_Time != "") || (m_Date != ""))
    {
        recognizedIntent.append("Intent: Check Calendar");
    }

    else
    {
        recognizedIntent.append("No Intent Recognized");
    }

    return recognizedIntent;
}

string IntentRecognizer::Convert2DCharArrayToString(const int i_count, char** i_array)
{
    /* Convert char** to string */
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
                        "[0-9][.|:][0-5][0-9][ |][a|A][m|M]"
                        "[0-9][.|:][0-5][0-9][ |][p|P][m|M]"
                        "|[1][0-9][.|:][0-5][0-9]"
                        "|[1][0-9][.|:][0-5][0-9][ |][a|A][m|M]"
                        "|[1][0-9][.|:][0-5][0-9][ |][p|P][m|M]"
                        "|[2][0-3][.|:][0-5][0-9]"
                        "|[2][0-3][.|:][0-5][0-9][ |][a|A][m|M]"
                        "|[2][0-3][.|:][0-5][0-9][ |][p|P][m|M])");

    if(regex_search(i_sentence, searchedResult, searchTarget))
    {
        m_Time = string(searchedResult[0]);
    }

    /* DATE */
    searchTarget = regex("([t|T][o|O][d|D][a|A][y|Y]"
                        "|[t|T][o|O][m|M][o|O][r|R][r|R][o|O][w|W]"
                        "|[y|Y][e|E][s|S][t|T][e|E][r|R][d|D][a|A][y|Y]"
                        "|[w|W][e|E][e|E][k|K][e|E][n|N][d|D][s|S]"
                        "|[m|M][o|O][n|N][d|D][a|A][y|Y]"
                        "|[t|T][u|U][e|E][s|S][d|D][a|A][y|Y]"
                        "|[w|W][e|E][d|D][n|N][e|E][s|S][d|D][a|A][y|Y]"
                        "|[t|T][h|H][u|U][r|R][s|S][d|D][a|A][y|Y]"
                        "|[f|F][r|R][i|I][d|D][a|A][y|Y]"
                        "|[s|S][a|A][t|T][u|U][r|R][d|D][a|A][y|Y]"
                        "|[s|S][u|U][n|N][d|D][a|A][y|Y])");

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
