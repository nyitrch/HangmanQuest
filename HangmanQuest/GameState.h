#pragma once
/*
Represents the current state of the game (HQGame).

Either the game is in PLAY, a LOSE, or a WIN to the model.
*/
enum class GameState
{
	PLAY,
	LOSE,
	WIN
};