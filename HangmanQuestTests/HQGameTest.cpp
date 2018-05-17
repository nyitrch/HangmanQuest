#include "CppUnitTest.h"
#include "../HangmanQuest/HQGame.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HangmanQuestTests
{		
	TEST_CLASS(HQGameUnitTest)
	{
	public:
		
		TEST_METHOD(TestSetWord)
		{
			// Test setWord.
			HQGame game;
			std::string test_string = "hello";
			game.setWord(test_string);
			Assert::AreEqual(test_string, game.getWord());

			test_string = "my favorite color is green and my name is martha";
			game.setWord(test_string);
			Assert::AreEqual(test_string, game.getWord());
			Assert::AreEqual(test_string.size(), game.getWordLength());
		}

		TEST_METHOD(TestGuess)
		{
			HQGame game;
			game.setWord("hello");

			// Test guessing.
			int result = game.guess('a');
			Assert::AreEqual(result, 1); // 1 = not in word.
			result = game.guess('l');
			Assert::AreEqual(result, 0); // 0 = in word.
			result = game.guess('l');
			Assert::AreEqual(result, 2); // 2 = already guessed.

			result = game.guess('?');
			Assert::AreEqual(result, 1); // 1 = not in word.
			result = game.guess(' ');
			Assert::AreEqual(result, 1); // 1 = not in word.
		}

		TEST_METHOD(TestFetchWord)
		{
			HQGame game;

			// Fetch at same time, words are equal.
			game.fetchNewWord();
			std::string test_string1 = game.getWord();
			game.fetchNewWord();
			std::string test_string2 = game.getWord();
			Assert::AreEqual(test_string1, test_string2);

			// Fetched at different times, words should be different.
			
		}

	};
}