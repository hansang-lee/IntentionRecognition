#pragma once

#include <vector>

using namespace std;

enum eSentenceType
{
    TYPE_UNDEFINED,
    TYPE_QUESTION_WHAT,
    TYPE_QUESTION_WHEN, 
    TYPE_QUESTION_WHERE,
    TYPE_QUESTION_WHY,
    TYPE_QUESTION_WHO,
    TYPE_QUESTION_WHICH,
    TYPE_QUESTION_HOW,
    TYPE_QUESTION_BE,
    TYPE_QUESTION_AUXILIARY,
    TYPE_QUESTION_GENERAL,
    TYPE_NON_QUESTION
};

enum eTopic
{
    TOPIC_UNDEFINED,
    TOPIC_WEATHER,
    TOPIC_FACT,
    TOPIC_CALENDAR
};

class IntentRecognizer
{
public:
	IntentRecognizer();
	~IntentRecognizer();

    void PerformIntentRecognition(const int i_numberWords, char** i_sentence);

private:
    /* Register for SentenceType */
    eSentenceType m_eSentenceType;
    
    /* Register for Keywords */
    eTopic m_eTopic;
    string m_Point;
    string m_Place;
    string m_Date;
    string m_Time; //[HH.MM]<AM|PM>

    eSentenceType ClassifySentenceType(const vector<string>& i_sentence);
    void DeduceIntent(const vector<string>& i_sentence);
    void ShowAnswer();

    void PrintExtractedKeywords();
};
