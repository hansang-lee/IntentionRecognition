#include <iostream>
#include "intentRecognizer.h"

int main(int argc, char** argv)
{
    if(argc > 1)
    {
        IntentRecognizer ir;
        ir.PerformIntentRecognition(argc-1, &argv[1]);
    }
}
