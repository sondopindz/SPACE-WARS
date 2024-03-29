#include "Common_Function.h"

int MakeRandValue()
{
    //srand(time(NULL));
    int rand_x = 50 + rand()%(SCREEN_WIDTH - 70);
    return rand_x;
}

bool CheckCollision(SDL_Rect object1,SDL_Rect object2)
{
    if(object1.x + object1.w >= object2.x && object2.x + object2.w >= object1.x && object1.y + object1.h >= object2.y && object2.y + object2.h >= object1.y)
    {
        return true;
    }
    return false;
}

string number_to_string(int number)
{
    stringstream ss;
    ss << setw(6) << setfill('0') << number;
    string val_score;
    ss >> val_score;
    return val_score;
}

string number_to_string1(int number)
{
    string str = "";
    if(number == 0) return "0";
    while(number > 0)
    {
        str = char(number % 10 + 48) + str;
        number /= 10;
    }
    return str;
}

string GetHighScoreFromFile(string path)
{
	fstream HighScoreFile;
	string highscore;

	HighScoreFile.open(path.c_str(),ios::in);
	HighScoreFile >> highscore;

	return highscore;
}

void UpdateHighScore(string path, const int &score, string &old_high_score)
{
	int oldHighScore = 0;
	fstream HighScoreFile;
	string newHighScore;
	stringstream ConvertToInt(old_high_score);

	HighScoreFile.open(path.c_str(), ios::out);

	ConvertToInt >> oldHighScore;
	if (score>oldHighScore)
	{
		oldHighScore = score;
	}
	newHighScore = number_to_string(oldHighScore);
	old_high_score = newHighScore;
	HighScoreFile << newHighScore;
}

string RatingBaseOnScore(const long currentscore)
{
    string rating;
    if(currentscore >= 0 && currentscore < 2000)
    {
        rating = 'F';
    }
    else if(currentscore >= 2000 && currentscore < 4000)
    {
        rating = 'D';
    }
    else if(currentscore >= 4000 && currentscore < 6000)
    {
        rating = 'C';
    }
    else if(currentscore >= 4000 && currentscore < 6000)
    {
        rating = 'B';
    }
    else if(currentscore >= 6000 && currentscore < 8000)
    {
        rating = 'A';
    }
    else if(currentscore >= 8000)
    {
        rating = 'S';
    }
    return rating;
}
