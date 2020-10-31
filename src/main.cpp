#include <iostream>
#include "IntentRecognizer.h"

int main(int argc, char** argv)
{
    if(argc > 1)
    {
        IntentRecognizer::PerformIntentRecognition(argc, argv);
    }

	return 0;
}
