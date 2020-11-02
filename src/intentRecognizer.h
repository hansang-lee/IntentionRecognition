#pragma once

#include <string>

using namespace std;

class IntentRecognizer
{
public:
	IntentRecognizer();
	~IntentRecognizer();

    string GetIntent(const int i_countWords, char** i_words);
    string GetIntent(const string i_sentence);

private:
    /* Register for Keywords */
    string m_Weather;
    string m_Fact;
    string m_Time;
    string m_Date;
    string m_Place;

    string Convert2DCharArrayToString(const int i_count, char** i_array);
    void RegisterKeywords(const string i_sentence);
};
