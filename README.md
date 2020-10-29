# Coding Assignment (Embedded Intent Recognizer)

Build a simple small intent recognition command line tool.
The idea is to be able to ask a set of predefined questions and accurately recognize the intent of the user. The predefined intents are the following:

* What is the weather like today? => Prints (Intent: Get Weather)
* What is the weather like in Paris today? => Prints (Intent: Get Weather City)
* What is the weather like in New York today? => Prints (Intent: Get Weather City)
* Am I free at 13:00 PM tomorrow? ==> Prints (Intent: Check calendar)
* Tell me an interesting fact. => Prints (Intent: Get Fact)

### Evaluation Criteria
We want to see passion for software development and have a conversation around your code. The minimum criteria are set under the __Basic__ section and are enough for us to discuss your code with you. The __Advanced__ section is not mandatory but it allows us to understand how you would work in the team. Finally the __Very Advanced__ is open ended and if you have time and interest, you can do as much as you want (as long as the __Basic__ criteria have been fulfilled)

### Basic:
* The use cases above have to work.
  * String matching and regular expressions could be an easy way to get it to work.
* The project has to be buildable with CMake (using C++17):
* The commands: `mkdir build && cd build && cmake ..  && make` must build the application
* The project is developed using git and pushed to <https://github.com/.> (sending a compressed git project per email would also be okay).
  * We should be able to clone and build it (using the commands above).

### Advanced:
* The project has unit tests (Catch2, Google Test, or any other framework).
* The commit messages in the project are atomic and understandable.

### Very Advanced:
* Handle different semantic variations (i.e. Do I have an appointment at 13:00pm tomorrow? => Prints Check Calendar. Will it rain tomorrow in Paris? => Prints Get Weather).
