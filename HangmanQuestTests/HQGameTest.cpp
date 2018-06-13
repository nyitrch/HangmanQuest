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
		
			game.guess('a');
			std::set<char> hits = game.getHits();
			std::set<char> misses = game.getMisses();
			Assert::AreEqual(hits.count('a'), (size_t)0); // a not in hits.
			Assert::AreEqual(misses.count('a'), (size_t)1); // a in misses.

			game.guess('l');
			hits = game.getHits();
			misses = game.getMisses();
			Assert::AreEqual(hits.count('l'), (size_t)1); // l in hits.
			Assert::AreEqual(misses.count('l'), (size_t)0); // l not in misses.

			// Reguessing same letter should not change counts.
			game.guess('l');
			hits = game.getHits();
			misses = game.getMisses();
			Assert::AreEqual(hits.count('l'), (size_t)1); // l in hits.
			Assert::AreEqual(misses.count('l'), (size_t)0); // l not in misses.

			game.guess('?');
			hits = game.getHits();
			misses = game.getMisses();
			Assert::AreEqual(hits.count('?'), (size_t)0); // ? not in hits.
			Assert::AreEqual(misses.count('?'), (size_t)0); // ? not in misses.

			game.guess(' ');
			hits = game.getHits();
			misses = game.getMisses();
			Assert::AreEqual(hits.count(' '), (size_t)0); // ' ' not in hits.
			Assert::AreEqual(misses.count(' '), (size_t)0); // ' ' not in misses.
		}

		TEST_METHOD(TestFetchWord)
		{
			HQGame game;

			// Fetch two words, should be different.
			game.getRandomWord();
			std::string test_string1 = game.getWord();
			game.getRandomWord();
			std::string test_string2 = game.getWord();
			Assert::AreNotEqual(test_string1, test_string2);
		}

	};
}