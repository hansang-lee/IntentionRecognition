#include <iostream>
#include <string>
#include <regex>
#include "IntentRecognizer.h"

using namespace std;

IntentRecognizer::IntentRecognizer()
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

    /* @TO_DO:  */
    switch(sentenceType)
    {
        case TYPE_QUESTION_WHAT:
            cout << "QUESTION_WHAT";
            break;

        case TYPE_QUESTION_WHEN:
            cout << "QUESTION_WHEN";
            break;

        case TYPE_QUESTION_WHERE:
            cout << "QUESTION_WHERE";
            break;

        case TYPE_QUESTION_WHY:
            cout << "QUESTION_WHY";
            break;

        case TYPE_QUESTION_WHO:
            cout << "QUESTION_WHO";
            break;

        case TYPE_QUESTION_WHICH:
            cout << "QUESTION_WHICH";
            break;

        case TYPE_QUESTION_HOW:
            cout << "QUESTION_HOW";
            break;

        case TYPE_QUESTION_BE:
            cout << "QUESTION_BE";
            break;

        case TYPE_QUESTION_AUXILIARY:
            cout << "QUESTION_AUXILIARY";
            break;

        case TYPE_QUESTION_GENERAL:
            cout << "QUESTION_GENERAL";
            break;

        case TYPE_NON_QUESTION:
            cout << "NON_QUESTION";
            break;

        default:
            cout << "";
            break;
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
            "|[w|W][e|E][r|R][e|E])(.*)")))
    {
        return eSentenceType::TYPE_QUESTION_BE;
    }

    else if(regex_match(strFirstWord,
        regex("[c|C][a|A][n|N]"
            "|[m|M][a|A][y|Y]"
            "|[w|W][i|I][l|L][l|L](.*)")))
    {
        return eSentenceType::TYPE_QUESTION_AUXILIARY;
    }

    else if(regex_match(strFirstWord,
        regex("[d|D][o|O]"
            "|[d|D][o|O][e|E][s|S]"
            "|[d|D][i|I][d|D](.*)")))
    {
        return eSentenceType::TYPE_QUESTION_GENERAL;
    }

    std::cout << "NON_QUESTION";
    return eSentenceType::TYPE_NON_QUESTION;
}
