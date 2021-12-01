#ifndef SLAUGHTERHOUSE_UTILS_H
#define SLAUGHTERHOUSE_UTILS_H
#include <stdbool.h>

int GenerateCode(int LevelDifficulty);
void ClearInput();
bool CheckGuess(int CodeSum, int CodeProduct, int GuessSum, int GuessProduct);

#endif //SLAUGHTERHOUSE_UTILS_H