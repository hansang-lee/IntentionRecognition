#include <iostream>
#include <string>
#include <regex>
#include "intentRecognizer.h"

using namespace std;

IntentRecognizer::IntentRecognizer()
:m_eTopic(TOPIC_UNDEFINED)
,m_Point("NONE")
,m_Place("NONE")
,m_Date("NONE")
,m_Time("NONE")
{

}

IntentRecognizer::~IntentRecognizer()
{

}

void IntentRecognizer::PerformIntentRecognition(const int i_numberWords, char** i_sentence)
{
    vector<string> words;

    /* Convert char* to string and push to a vector */
    for(int i=0; i<i_numberWords; i++)
    {
        words.push_back(string(i_sentence[i]));
    }

    DeduceIntent(words);
    ShowAnswer();
}

void IntentRecognizer::DeduceIntent(const vector<string>& i_sentence)
{
    for(auto itWord=i_sentence.begin(); itWord!=i_sentence.end(); itWord++)
    {
        /* Extract [DATE] information */
        if(regex_match(*itWord, regex(
            "([t|T][o|O][d|D][a|A][y|Y]"
            "|[t|T][o|O][m|M][o|O][r|R][r|R][o|O][w|W]"
            "|[y|Y][e|E][s|S][t|T][e|E][r|R][d|D][a|A][y|Y]"
            "|[w|W][e|E][e|E][k|K][e|E][n|N][d|D][s|S])")))
        {
            m_Date = (*itWord);
        }

        /* Extract [TIME] information */
        else if(regex_match(*itWord, regex(
            "([0-9][.|:][0-5][0-9][a|A][m|M]"
            "|[0-9][.|:][0-5][0-9][p|P][m|M]"
            "|[1][0-9][.|:][0-5][0-9][a|A][m|M]"
            "|[1][0-9][.|:][0-5][0-9][p|P][m|M]"
            "|[2][0-3][.|:][0-5][0-9][a|A][m|M]"
            "|[2][0-3][.|:][0-5][0-9][p|P][m|M])")))
        {
            m_Time = (*itWord);
        }

        else if(regex_match(*itWord, regex(
            "([0-9][.|:][0-5][0-9]"
            "|[1][0-9][.|:][0-5][0-9]"
            "|[2][0-3][.|:][0-5][0-9])")))
        {
            m_Time = (*itWord);

            if((next(itWord) != i_sentence.end())
                && (regex_match(*next(itWord), regex("([a|A][m|M]|[p|P][m|M])"))))
            {
                m_Time.append(*(next(itWord)));
            }
        }

        /* Extract [PLACE] information */
        else
        {
            if((itWord != i_sentence.begin())
                && (regex_match(*prev(itWord), regex("([i|I][n|N]|[a|A][t|T])"))))
            {
                m_Place = (*itWord);
            }
        }

        /* Deduce intent of asking weather */
        if(regex_match(*itWord, regex(
            "([w|W][e|E][a|A][t|T][h|H][e|E][r|R]"
            "|[r|R][a|A][i|I][n|N]"
            "|[d|D][r|R][y|Y]"
            "|[c|C][l|L][o|O][u|U][d|D]"
            "|[h|H][u|U][m|M][i|I][d|D]"
            "|[s|S][u|U][n|N]"
            "|[s|S][n|N][o|O][w|W]"
            "|[w|W][i|I][n|N][d|D}"
            "|[f|F][o|O][g|G])")))
        {
            m_eTopic = TOPIC_WEATHER;
            m_Point = (*itWord);
        }

        /* Deduce intent of asking fact */
        else if(regex_match(*itWord, regex("([f|F][a|A][c|C][t|T])")))
        {
            m_eTopic = TOPIC_FACT;
            m_Point = (*itWord);
        }

        /* Deduce intent of checking calendar */
        else if((m_Time != "NONE") && (m_eTopic == TOPIC_UNDEFINED))
        {
            m_eTopic = TOPIC_CALENDAR;
        }
    }
}

void IntentRecognizer::ShowAnswer()
{
    switch(m_eTopic)
    {
        case TOPIC_WEATHER:
            cout << "Intent: Get Weather";
            
            if(m_Place != "NONE")
            {
                cout << " " << "City";
            }
            
            if(m_Date != "NONE")
            {
                cout << " " << "Date";
            }
            
            if(m_Time != "NONE")
            {
                cout << " " << "Time";
            }
            
            break;

        case TOPIC_FACT:
            cout << "Intent: Get Fact";
            
            if(m_Place != "NONE")
            {
                cout << " " << "City";
            }

            if(m_Date != "NONE")
            {
                cout << " " << "Date";
            }
            
            if(m_Time != "NONE")
            {
                cout << " " << "Time";
            }
            
            break;

        case TOPIC_CALENDAR:
            cout << "Intent: Check Calendar";
            
            if(m_Place != "NONE")
            {
                cout << " " << "City";
            }
            
            if(m_Date != "NONE")
            {
                cout << " " << "Date";
            }
            
            if(m_Time != "NONE")
            {
                cout << " " << "Time";
            }

            break;

        default:
            break;
    }
}
