#include "CppUnitTest.h"
#include "../HangmanQuest/HQGame.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HangmanQuestTests
{		
	TEST_CLASS(HQGameUnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod)
		{
			// Test setWord.
			HQGame game;
			std::string test_string = "hello";

			game.setWord(test_string);

			Assert::AreEqual(test_string, game.getWord());
			
		}

	};
}