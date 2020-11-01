#include <iostream>
#include <string>
#include <regex>
#include "IntentRecognizer.h"

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
    /* Convert [char*] to [string] and save in a vector */
    vector<string> words;
    for(int i=1; i<i_numberWords; i++)
    {
        words.push_back(string(i_sentence[i]));
    }

    /* Classify the type of the given sentence */
    eSentenceType sentenceType = ClassifySentenceType(words);

    /* Extract Keywords */
    GetKeywords(words);

    /* Deduce Intent */
    if((sentenceType != TYPE_UNDEFINED) && (sentenceType != TYPE_NON_QUESTION))
    {
        DeduceIntent();
    }
}

eSentenceType IntentRecognizer::ClassifySentenceType(const vector<string>& i_sentence)
{
    string strFirstWord = i_sentence.front();

    if(regex_match(strFirstWord, regex("[w|W][h|H][a|A][t|T](.*)")))
    {
        return eSentenceType::TYPE_QUESTION_WHAT;
    }

    else if(regex_match(strFirstWord, regex("[w|W][h|H][e|E][n|N](.*)")))
    {
        return eSentenceType::TYPE_QUESTION_WHEN;
    }

    else if(regex_match(strFirstWord, regex("[w|W][h|H][e|E][r|R][e|E](.*)")))
    {
        return eSentenceType::TYPE_QUESTION_WHERE;
    }

    else if(regex_match(strFirstWord, regex("[w|W][h|H][y|Y](.*)")))
    {
        return eSentenceType::TYPE_QUESTION_WHY;
    }

    else if(regex_match(strFirstWord, regex("[w|W][h|H][o|O](.*)")))
    {
        return eSentenceType::TYPE_QUESTION_WHO;
    }

    else if(regex_match(strFirstWord, regex("[w|W][h|H][i|I][c|C][h|H](.*)")))
    {
        return eSentenceType::TYPE_QUESTION_WHICH;
    }

    else if(regex_match(strFirstWord, regex("[h|H][o|O][w|W](.*)")))
    {
        return eSentenceType::TYPE_QUESTION_HOW;
    }

    else if(regex_match(strFirstWord, 
        regex("([a|A][m|M]"
            "|[i|I][s|S]"
            "|[a|A][r|R][e|E]"
            "|[w|W][a|A][s|S]"
            "|[w|W][e|E][r|R][e|E])")))
    {
        return eSentenceType::TYPE_QUESTION_BE;
    }

    else if(regex_match(strFirstWord,
        regex("([c|C][a|A][n|N]"
            "|[m|M][a|A][y|Y]"
            "|[w|W][i|I][l|L][l|L])")))
    {
        return eSentenceType::TYPE_QUESTION_AUXILIARY;
    }

    else if(regex_match(strFirstWord,
        regex("([d|D][o|O]"
            "|[d|D][o|O][e|E][s|S]"
            "|[d|D][i|I][d|D])")))
    {
        return eSentenceType::TYPE_QUESTION_GENERAL;
    }

    std::cout << "NON_QUESTION";
    return eSentenceType::TYPE_NON_QUESTION;
}

void IntentRecognizer::GetKeywords(const vector<string>& i_sentence)
{
    for(auto itWord=next(i_sentence.begin()); itWord!=i_sentence.end(); itWord++)
    {
        /* Extract WEATHER information */
        if(regex_match(*itWord,
            regex("([w|W][e|E][a|A][t|T][h|H][e|E][r|R]"
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

        /* Extract DATE information */
        else if(regex_match(*itWord,
            regex("([t|T][o|O][d|D][a|A][y|Y]"
            "|[t|T][o|O][m|M][o|O][r|R][r|R][o|O][w|W]"
            "|[y|Y][e|E][s|S][t|T][e|E][r|R][d|D][a|A][y|Y]"
            "|[w|W][e|E][e|E][k|K][e|E][n|N][d|D][s|S])")))
        {
            m_Date = (*itWord);
        }

        /* Extract TIME information */
        else if(regex_match(*itWord, 
            regex("([0-9][.|:][0-5][0-9][a|A][m|M]"
            "|[0-9][.|:][0-5][0-9][p|P][m|M]"
            "|[1][0-9][.|:][0-5][0-9][a|A][m|M]"
            "|[1][0-9][.|:][0-5][0-9][p|P][m|M]"
            "|[2][0-3][.|:][0-5][0-9][a|A][m|M]"
            "|[2][0-3][.|:][0-5][0-9][p|P][m|M])")))
        {
            m_Time = (*itWord);
        }

        else if(regex_match(*itWord, 
            regex("([0-9][.|:][0-5][0-9]"
            "|[1][0-9][.|:][0-5][0-9]"
            "|[2][0-3][.|:][0-5][0-9])")))
        {
            m_Time = (*itWord);

            if(regex_match(*next(itWord),
                regex("([a|A][m|M]|[p|P][m|M])")))
            {
                m_Time.append(*(next(itWord)));
            }
        }

        /* Extract PLACE information */
        else
        {
            if(itWord == i_sentence.begin())
            {
                continue;
            }

            if(regex_match(*prev(itWord), regex("([i|I][n|N]|[a|A][t|T])")))
            {
                m_Place = (*itWord);
            }
        }
    }
}

void IntentRecognizer::DeduceIntent()
{
    switch(m_eTopic)
    {
        case TOPIC_WEATHER:
            cout << "Intent: Get Weather";
            PrintExtractedKeywords();
            break;

        case TOPIC_SCHEDULE:
            break;

        case TOPIC_FACT:
            break;

        default:
            break;
    }
}

void IntentRecognizer::PrintExtractedKeywords()
{
    cout << "(";

    if(m_Point != "NONE")
    {
        cout << m_Point;
    }
    
    if(m_Date != "NONE")
    {
        cout << " " << m_Date;
    }
    
    if(m_Time != "NONE")
    {
        cout << " " << m_Time;
    }

    if(m_Place != "NONE")
    {
        cout << " " << m_Place;
    }

    cout << ")";
}
