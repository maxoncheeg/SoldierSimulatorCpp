#pragma once


struct FightResult {
	bool isVictory = false;
	int woundedAmount = 0;
	int diedAmount = 0;

	FightResult() = default;
};