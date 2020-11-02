#pragma once

#include <vector>

using namespace std;

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

    string GetIntent(const int i_numberWords, char** i_sentence);

private:
    /* Register for Keywords */
    eTopic m_eTopic;
    string m_Point;
    string m_Place;
    string m_Date;
    string m_Time; // [HH.MM]<AM|PM>

    void RegisterKeywords(const vector<string>& i_sentence);
    string DeduceIntent();
};
