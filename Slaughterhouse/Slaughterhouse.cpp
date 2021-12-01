#include <iostream>
#include <ctime>
#include "art.h"
#include "utils.h"

void PromptPlayerStart()
{
    char prompt = '.';
    while (prompt != 'p' && prompt != 'q')
    {
        std::cout << std::endl;
        std::cout << "Do you want to play ? Press (p) to play or (q) to quit" << std::endl;
        std::cin >> prompt;
    }
    if (prompt == 'q')
    {
        abort();
    }
    ClearInput();
}

bool PromptPlayerRetry()
{
    char prompt = '.';
    while (prompt != 'r' && prompt != 'q')
    {
        std::cout << std::endl;
        std::cout << "Give up or Stand up ? Press (r) to retry or (q) to quit" << std::endl;
        std::cin >> prompt;
    }
    if (prompt == 'q')
    {
        abort();
    }
    ClearInput();
    return true;
}

bool PromptPlayerQuit()
{
    char prompt = '.';
    while (prompt != 'q')
    {
        std::cout << std::endl;
        std::cout << "Thanks for playing! Press (q) to quit" << std::endl;
        std::cin >> prompt;
    }
    if (prompt == 'q')
    {
        abort();
    }
    ClearInput();
}

void Introduction()
{
    PrintSkull();
    std::cout << "Welcome to the Slaughterhouse, do not scream for help, you are only wasting your energy and my TIME!" << std::endl;
    std::cout << "If you can figure out the code sequences of these doors, I might let you free, hahahaha" << std::endl;
    std::cout << "Or just rot like the maggot you are!" << std::endl;
    PromptPlayerStart();
}

void PrintLevel(int LevelDifficulty, int MaxLevel)
{
    std::cout << "\x1B[2J\x1B[H";
    PrintLevelNumber(LevelDifficulty);
    if (LevelDifficulty == 1)
    {
        PrintDoor1();
        std::cout << "Here's the first door, I made it easy for you haha";
    }
    else if (LevelDifficulty == MaxLevel)
    {
        PrintDoor3();
        std::cout << "No mortal creature, can understand this sequence!";
    }
    else
    {
        PrintDoor2();
        std::cout << "This will only get harder, just give up already!";
    }
    std::cout << std::endl;
}

void HintPlayer(int CodeSum, int CodeProduct)
{
    PrintTextHint();
    std::cout << "There are 3 numbers in the code" << std::endl;
    std::cout << "- The codes add-up to: " << CodeSum << std::endl;
    std::cout << "- The code multiply to: " << CodeProduct << std::endl;
}

void GetPlayerInput(int* GuessSum, int* GuessProduct)
{
    int GuessA, GuessB, GuessC;

    std::cout << std::endl;
    std::cout << "What will it be ? (To enter your guess type the number with aspace behind it, eg: 1 2 3)" << std::endl;
    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;
    std::cout << "You entered: " << GuessA << GuessB << GuessC << std::endl;
    ClearInput();

    *GuessSum = GuessA + GuessB + GuessC;
    *GuessProduct = GuessA * GuessB * GuessC;
}

void PrintGameOver()
{
    std::cout << "\x1B[2J\x1B[H";
    PrintDeath();
    std::cout << std::endl;
    std::cout << "Another prey falls to the Slaughterhouse!";
    std::cout << std::endl;
}

void End()
{
    std::cout << "\x1B[2J\x1B[H";
    PrintLandscape();
    std::cout << std::endl;
    std::cout << "Well done escaping the Slaughterhouse, very few people do...";
    std::cout << std::endl;
}

void PlayGame()
{
    const int MaxLevel = 3;
    int LevelDifficulty = 1;
    bool GameOver = false;

    while (LevelDifficulty <= MaxLevel && !GameOver)
    {
        PrintLevel(LevelDifficulty, MaxLevel);

        const int CodeA = GenerateCode(LevelDifficulty);
        const int CodeB = GenerateCode(LevelDifficulty);
        const int CodeC = GenerateCode(LevelDifficulty);
        const int CodeSum = CodeA + CodeB + CodeC;
        const int CodeProduct = CodeA * CodeB * CodeC;

        HintPlayer(CodeSum, CodeProduct);

        int GuessSum, GuessProduct;

        GetPlayerInput(&GuessSum, &GuessProduct);

        GameOver = !CheckGuess(CodeSum, CodeProduct, GuessSum, GuessProduct);

        if (!GameOver)
        {
            ++LevelDifficulty;
        }
    }
    if (GameOver)
    {
        PrintGameOver();
        if (PromptPlayerRetry())
        {
            PlayGame();
        }
    }
    else
    {
        End();
        PromptPlayerQuit();
    }
}

int main()
{
    srand(time(NULL));
    Introduction();
    PlayGame();
    return 0;
}