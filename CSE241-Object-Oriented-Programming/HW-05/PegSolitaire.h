#ifndef PEGSOLITAIRE_H
#define PEGSOLITAIRE_H

#include "BoardGame2D.h"
#include <vector>
#include <string>

namespace AkaGames{
    enum class cell {empty, peg, out};
    const cell peg = cell::peg;
    const cell out = cell::out;
    const cell empty = cell::empty;
    
    class PegSolitaire : public BoardGame2D{
    public:
        class Cell {
        public:
            Cell (int rowValue, int columnValue, cell situationValue);
            void setCell(cell currentSituation);
            bool cellEqual(cell compareSituation) const;
            bool cellNotEqual(cell compareSituation) const ;
            void getCell () const;
        private: 
            int row;
            int column;
            cell situation;
        };
        
        PegSolitaire();

        using BoardGame2D::playUser;
        
        void initialize();
        
        void playUser(string userMove);
        
        void playAuto();

        bool checkInput(string inp);

        bool checkMove(int cRow, int cColumn, char cDirection);

        void print() const;

        bool endGame() const;

        int boardScore() const;

        vector<vector<Cell>> getBoard() const;
    private:
        vector<vector<Cell>> board;
    };
}

#endif