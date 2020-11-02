#include <iostream>
#include "intentRecognizer.h"

int main(int argc, char** argv)
{
    if(argc > 1)
    {
        IntentRecognizer rec;
        std::cout << rec.GetIntent(argc-1, &argv[1]) << std::endl;
    }
}
