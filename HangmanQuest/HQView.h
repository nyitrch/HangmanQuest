#pragma once
class HQView
{
private:

	enum GameState
	{
		MAIN_MENU,
		ENTER_WORD,
		GAME,
		HELP
	};

	GameState game_state;

public:
	HQView();
	~HQView();

	void update();

	void onGuessButtonPress();

	int displayGame();
	void displayWord();
	void displayHangman();
	void displayHits();
	void displayMisses();
};

