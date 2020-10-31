#pragma once

#include <vector>

using namespace std;

enum eSentenceType
{
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

class IntentRecognizer
{
public:
	IntentRecognizer();
	~IntentRecognizer();

    static void PerformIntentRecognition(const int i_numberWords, char** i_sentence);

private:
    static eSentenceType ClassifySentenceType(const vector<string>& i_words);
};
