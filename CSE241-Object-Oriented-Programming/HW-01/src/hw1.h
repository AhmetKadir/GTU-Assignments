#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

enum class cell {empty, peg, out};
const cell peg = cell::peg;
const cell out = cell::out;
const cell empty = cell::empty;

vector<vector<cell>> map1();
vector<vector<cell>> map2();
vector<vector<cell>> map3();
vector<vector<cell>> map4();
vector<vector<cell>> map5();
vector<vector<cell>> map6();
void move(vector<vector<cell>> board);
void move6 (vector<vector<cell>> board);
void printmap(vector<vector<cell>> maps);
bool checkInput(string inp);
bool checkMove(int cRow, int cColumn, char cDirection, vector<vector<cell>> cBoard);
bool checkMove6(int cRow, int cColumn, char cDirection, vector<vector<cell>> cBoard);
bool endGame(vector<vector<cell>> eBoard);
bool endGame6(vector<vector<cell>> eBoard);
void computerGame(vector<vector<cell>> board);
void computerGame6(vector<vector<cell>> board);
void getRandomMove(int *row, int *col, char *direc, vector<vector<cell>> board);
void processInput(string userMove,int *col, int *r, char* dir);
void printInputMessage();
void printFinalMessage(int score);
int finalScore(vector<vector<cell>> fBoard);
void printComputerMove(int row, int column, char direction);