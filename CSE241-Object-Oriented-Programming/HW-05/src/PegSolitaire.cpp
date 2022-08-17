
/*#define DEBUG*/

#include "PegSolitaire.h"

using namespace std;

namespace AkaGames{
PegSolitaire::Cell::Cell(int rowValue, int columnValue, cell situationValue)
: row(rowValue), column(columnValue), situation(situationValue)
{}

void PegSolitaire::Cell::setCell(cell currentSituation){
    situation = currentSituation;
}

bool PegSolitaire::Cell::cellEqual(cell compareSituation) const{ 
    if (situation == compareSituation) return true;
    return false;
}

bool PegSolitaire::Cell::cellNotEqual(cell compareSituation) const{
    if (situation != compareSituation) return true;
    return false;
}

PegSolitaire::PegSolitaire():
board({0})
{
    initialize();
}

void PegSolitaire::initialize(){
    vector<vector<cell>> freshBoard{
    {out, out, out, peg, peg, peg, out, out, out},
    {out, out, out, peg, peg, peg, out, out, out},
    {out, out, out, peg, peg, peg, out, out, out},
    {peg, peg, peg, peg, peg, peg, peg, peg, peg},
    {peg, peg, peg, peg, empty, peg, peg, peg, peg},
    {peg, peg, peg, peg, peg, peg, peg, peg, peg},
    {out, out, out, peg, peg, peg, out, out, out},
    {out, out, out, peg, peg, peg, out, out, out},
    {out, out, out, peg, peg, peg, out, out, out}
    };
 
    board.clear();
    int xsize, ysize;
    
    xsize = freshBoard.size();
    ysize = freshBoard[0].size();
    for(auto i=0; i<xsize ; i++){
        board.push_back(vector<Cell>());
        for(decltype(i) j=0; j< ysize; j++){
            switch(freshBoard[i][j]){
                case peg:
                    board[i].push_back(Cell(i,j,peg));
                    break;
                case out:
                    board[i].push_back(Cell(i,j,out));
                    break;
                case empty:
                    board[i].push_back(Cell(i,j,empty));
                    break;
            }
        }
    }
}
    
void PegSolitaire::playUser(string userMove){
    int trow, tcolumn;
    char direction;
    if (userMove != "0000"){
        tcolumn = userMove[0] - 65;                                      /*Takes the char and turns into a integer to fit in the map*/
        trow = userMove[1] - '1';                    
        direction = userMove[3];
        if (checkInput(userMove) == false) cerr << "\n!!!!! Invalid Input !!!!!" << endl;                          
        else if(checkMove(trow, tcolumn, direction) == false) cerr << "\n!!!!! Invalid Move !!!!!" << endl;
        else{    
            board [trow][tcolumn].setCell(empty);
            switch(direction){                                          /*Movement according to direction.*/
                case 'R':
                    board [trow][tcolumn+1].setCell(empty);
                    board [trow][tcolumn+2].setCell(peg);
                    break;
                case 'L':
                    board [trow][tcolumn-1].setCell(empty);
                    board [trow][tcolumn-2].setCell(peg);
                    break;
                case 'U':
                    board [trow-1][tcolumn].setCell(empty);
                    board [trow-2][tcolumn].setCell(peg);
                    break;
                case 'D':
                    board [trow+1][tcolumn].setCell(empty);
                    board [trow+2][tcolumn].setCell(peg);
                    break;
                default:
                    cout << "Wrong entry !" << endl;
                    break;    
            }
            cout << endl;
        }
    }
}

bool PegSolitaire::playAuto(){
        /*Plays automatically*/
    int trow, tcolumn, rDirec;
    string answer, fileName;
    char direction;
    int xsize = board.size();
    int ysize = board[0].size();

    if (xsize <= 0) {
        cerr << endl << "Something is wrong!" << endl;
        return false;
    }

    /*Generates random values and get a random move*/
    trow = rand() % xsize;                      
    tcolumn = rand() % ysize;
    rDirec = rand() % 4;
    switch(rDirec){
        case 0 :
            direction = 'R';
            break;
        case 1 :
            direction = 'L';
            break;
        case 2 :
            direction = 'U';
            break;
        case 3 :
            direction = 'D';
            break;
        default :
            cerr << "ERROR !" ;
            exit(1);
    }

    /*After generating a random move, it checks if the move is valid or not.
    If move is not valid, generates a new move and tries again
    If move is valid, then makes the move.*/

    if(checkMove(trow, tcolumn, direction) == true){           
        board [trow][tcolumn].setCell(empty);
        switch(direction){
            case 'R':
                board [trow][tcolumn+1].setCell(empty);
                board [trow][tcolumn+2].setCell(peg);
                break;
            case 'L':
                board [trow][tcolumn-1].setCell(empty);
                board [trow][tcolumn-2].setCell(peg);
                break;
            case 'U':
                board [trow-1][tcolumn].setCell(empty);
                board [trow-2][tcolumn].setCell(peg);
                break;
            case 'D':
                board [trow+1][tcolumn].setCell(empty);
                board [trow+2][tcolumn].setCell(peg);
                break;
            default:
                cerr << "ERROR !" ;
                exit(1);
                break;    
            }
        return true;
    }
    else{
        return false;
    }
    
}

bool PegSolitaire::checkInput(string inp){                                                        /*Function to check input if it is appropriate*/
    if (inp[1] > '0' && inp[1] <= '9');
    else return false;
    if (inp[0] >= 'A' && inp[0]<= 'P');
    else return false;
    if (inp[3] == 'R' || inp[3] == 'L' || inp[3] == 'U' || inp[3] == 'D');
    else return false;
    return true;
}

bool PegSolitaire::checkMove(int cRow, int cColumn, char cDirection){        /*Checks move if it is invalid or not.*/
    int xsize = board.size();
    int ysize = board[0].size();

    if (cRow > xsize-1 || cRow < 0) return false;
    if (cColumn > ysize - 1 || cColumn < 0) return false;

    if (board [cRow][cColumn].cellNotEqual(peg)) return false;
    switch (cDirection){                                                       /*Checks if it is inside the borders*/
        case 'R':
            if (cColumn + 2 > (ysize - 1)) return false;
            if (board[cRow][cColumn + 1].cellNotEqual(peg)) return false;
            if (board[cRow][cColumn + 2].cellNotEqual(empty)) return false;
            break;
        case 'L':
            if (cColumn -2 < 0) return false;
            if (board[cRow][cColumn - 1].cellNotEqual(peg)) return false;
            if (board[cRow][cColumn - 2].cellNotEqual(empty)) return false;
            break;
        case 'U':
            if (cRow -2 < 0 ) return false;
            if (board[cRow - 1][cColumn].cellNotEqual(peg)) return false;
            if (board[cRow - 2][cColumn].cellNotEqual(empty)) return false;
            break;
        case 'D':

            if (cRow + 2 > (xsize - 1)) return false;
            if (board[cRow + 1][cColumn].cellNotEqual(peg)) return false;
            if (board[cRow + 2][cColumn].cellNotEqual(empty)) return false;
            break;
    }
    return true;
}

void PegSolitaire::print() const {
    /*Function to print boards*/

    int xsize = board.size();
    int ysize = board[0].size();
    int control = 1,counter = 0;
    string label= "abcdefghijklmnopqr";                             /*Saves letters inside a string*/
    
    cout << endl;
    
    for (auto i=0; i < xsize; i++){
        if (counter != 0) cout << counter << " ";                   /*Prints numbers in the map.*/
        counter++;

        if (i==0 && control == 1) {
            cout << "  ";
            for(int k=0 ; k< ysize; k++) cout << label[k] << " ";    /*Prints letters in the map.*/
                
            control = 0;
            i--;
        }
        else{
            for(decltype(i) j=0; j < ysize; j++){    /*Prints pegs and empty areas, and prints out of the board*/
                if(board[i][j].cellEqual(out))          cout << ' ' ; 
                else if (board[i][j].cellEqual(peg))    cout << 'P';
                else if (board[i][j].cellEqual(empty))  cout << '.';
                cout << " ";
            }
        }
        cout << endl;  
    }
}

bool PegSolitaire::endGame() const{                                           /*Function to check if the game is over or not*/
    /*Checks every cell in the board.
    If the cell has peg on it, and there is a peg beside the cell and there is a empty cell beside it, movement is possible.
    So the game continues.
    If there is no cell satisfies this conditions, game is over.*/
    int xsize = board.size();
    int ysize = board[0].size();
    for(int i=0 ; i<xsize; i++){
        for(int j=0 ; j<ysize; j++){
            if(board[i][j].cellEqual(peg)){
                if(j < ysize -2  && board[i][j+1].cellEqual(peg) && board[i][j+2].cellEqual(empty)) return false;
                if(j > 1 && board[i][j-1].cellEqual(peg) && board[i][j-2].cellEqual(empty)) return false;
                if(i < xsize-2 && board[i+1][j].cellEqual(peg) && board[i+2][j].cellEqual(empty)) return false;
                if(i > 1 && board[i-1][j].cellEqual(peg) && board[i-2][j].cellEqual(empty)) return false;
            }
        }
    }
    return true;
}

int PegSolitaire::boardScore() const{
    int final = 0;                                              /*Calculates pegs in the board*/
    int xsize = board.size();
    int ysize = board[0].size();
    for(int i=0; i<xsize; i++){
        for(int j=0; j<ysize; j++){
            if (board[i][j].cellEqual(peg)) final++;
        }
    }
    if (final == 1) cout << "1 is the best score ! " << endl << "Congratulations" << endl;
    return final;
}

vector<vector<PegSolitaire::Cell>> PegSolitaire::getBoard() const{
    return board;
}

void PegSolitaire::printMovementRules() const{
	cout << "\nPlease enter your move" << endl;         /*Takes a string from user*/
    cout << "---Correct input type: B4-R---\n";
    cout << "---Upper letters only---\n";
    cout << "---This moves the peg at B4 towards right to eliminate the peg at C4---\n";
    cout << "---Use L for left, R for right, U for up, and D for down.---\n"; 
	}


}