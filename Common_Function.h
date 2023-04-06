#ifndef COMMON_FUNCTION
#define COMMON_FUNCTION

#include <Windows.h>
#include <SDL.h>
#include <SDL_image.h>
#include<SDL_mixer.h>
#include<SDL_ttf.h>

#include <vector>
#include <cmath>
#include<bits/stdc++.h>
#include<string>
using namespace std;

//Screen
const int SCREEN_WIDTH = 700;
const int SCREEN_HEIGHT = 750;
const int FPS = 80;
const int DELAY_TIME = 1000/FPS;

//plane
const int WIDTH_PLANE = 25;
const int HEIGHT_PLANE = 40;
const int SPEED_PLANE = 4;
const int POS_X_START_PLANE  = SCREEN_WIDTH/2;
const int POS_Y_START_PLANE  = SCREEN_HEIGHT - HEIGHT_PLANE;
const int SPEED_BULLET_MAIN = 5;
const int WIDTH_BULLET_PLANE = 5;
const int HEIGHT_BULLET_PLANE = 8;

//Enemy
const double SPEED_BULLET_ENEMY = 2.5;
const int NUM_ENEMIES = 3;
const double SPEED_ENEMY = 2;

const int  WIDTH_ENEMY = 30;
const int HEIGHT_ENEMY = 15;

const int BULLET_ENEMY_W = 5;
const int BULLET_ENEMY_H = 5;

    int MakeRandValue();
    bool CheckCollision(SDL_Rect object1,SDL_Rect object2);
    string number_to_string(int number);
    string GetHighScoreFromFile(string path);
    void UpdateHighScore(string path, const int &score, string &old_high_score);
    string RatingBaseOnScore(const long currentscore);
    string number_to_string1(int number);

#endif
