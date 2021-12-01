#include <iostream>
#include <ctime>
#include "utils.h"

int GenerateCode(int LevelDifficulty)
{
    return rand() % LevelDifficulty + LevelDifficulty;
}

void ClearInput()
{
    std::cin.clear();
    std::cin.ignore();
}

bool CheckGuess(int CodeSum, int CodeProduct, int GuessSum, int GuessProduct)
{
    return CodeSum == GuessSum && CodeProduct == GuessProduct;
}
