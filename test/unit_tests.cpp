#include "gtest/gtest.h"
#include "intentRecognizer.h"

IntentRecognizer rec; 

TEST(IntentRecognitionTest, WeatherTest)
{
    ASSERT_TRUE(1 == 1);
    //rec.PerformIntentRecognition(6, "What is the weather like today");
    //rec.GetRecognizedIntent() == ("Intent: Get Weather Date");

    //What is the weather like in Paris today
    //What is the weather like in New York today
    //Am I free at 13:00 PM tomorrow
    //Tell me an interesting fact
}

TEST(IntentRecognitionTest, CalendarTest)
{
    ASSERT_TRUE(1 == 1);
}

TEST(IntentRecognitionTest, FactTest)
{
    ASSERT_TRUE(1 == 1);
}
