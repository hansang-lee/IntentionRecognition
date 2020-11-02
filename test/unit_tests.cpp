#include "gtest/gtest.h"
#include "intentRecognizer.h"

IntentRecognizer rec; 

TEST(IntentRecognitionTest, WeatherTest)
{
    /* Basic */
    EXPECT_EQ(rec.GetIntent("What is the weather like today?"), "Intent: Get Weather");
    EXPECT_EQ(rec.GetIntent("What is the weather like in Paris today?"), "Intent: Get Weather City");
    EXPECT_EQ(rec.GetIntent("What is the weather like in New York today?"), "Intent: Get Weather City");

    /* Advanced */
    EXPECT_EQ(rec.GetIntent("Will it rain tomorrow in Paris?"), "Intent: Get Weather City");
    EXPECT_EQ(rec.GetIntent("Is it sunny, should I take sunglasses?"), "Intent: Get Weather");
    EXPECT_EQ(rec.GetIntent("Is it snowing in New York?"), "Intent: Get Weather City");
}

TEST(IntentRecognitionTest, CalendarTest)
{
    /* Basic */
    EXPECT_EQ(rec.GetIntent("Tell me an interesting fact."), "Intent: Get Fact");

    /* Advanced */
    EXPECT_EQ(rec.GetIntent("I need some fun facts"), "Intent: Get Fact");
    EXPECT_EQ(rec.GetIntent("Do you have any important fact to tell me?"), "Intent: Get Fact");
    EXPECT_EQ(rec.GetIntent("Do you know for a fact that he is in London?"), "Intent: Get Fact");
}

TEST(IntentRecognitionTest, FactTest)
{
    /* Basic */
    EXPECT_EQ(rec.GetIntent("Am I free at 13:00PM tomorrow?"), "Intent: Check Calendar");

    /* Advanced */
    EXPECT_EQ(rec.GetIntent("Do I have an appointment at 13:00pm tomorrow?"), "Intent: Check Calendar");
    EXPECT_EQ(rec.GetIntent("What time did I attend the party yesterday?"), "Intent: Check Calendar");
    EXPECT_EQ(rec.GetIntent("Can I meet someone at 11.45 AM on Friday in the city center?"), "Intent: Check Calendar");
}
