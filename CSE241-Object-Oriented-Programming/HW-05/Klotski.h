#ifndef KLOTSKI_H
#define KLOTSKI_H

#include "BoardGame2D.h"
#include <vector>
#include <string>

namespace AkaGames{
    class Klotski : public BoardGame2D{
    public:
        Klotski();

        using BoardGame2D::playUser;
        
        void initialize();
        
        void playUser(string userMove);
        
        void playAuto();

        bool checkInput(string inp);

        bool checkMove(int blockNumber, char direction);

        void swap(int& val1, int& val2);

        void print() const;

        bool endGame() const;

        int boardScore() const;

        vector<vector<int>> getBoard() const;
    private:
        vector<vector<int>> board; /*change vector type*/
    };
}

#endif