#pragma once
class HQView
{
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

