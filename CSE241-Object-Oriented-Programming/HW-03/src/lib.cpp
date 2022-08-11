#include <iostream>
#include <string>
#include <vector>
/*#define DEBUG*/
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <fstream>
#include "lib.h"


PegSolitaire::PegSolitaire(int boardTypeVal, int humanGameVal)
:board({0}), boardType(boardTypeVal), humanGame(humanGameVal)
{
    #ifdef DEBUG
    cerr << "Error in constructor1" << endl;
    #endif
}

PegSolitaire::PegSolitaire(int boardTypeVal)
:board({0}), boardType(boardTypeVal), humanGame(0)
{
    #ifdef DEBUG
    cerr << "Error in constructor1" << endl;
    #endif
}

PegSolitaire::PegSolitaire( ) : board({0}), boardType(1), humanGame(0)
{
    #ifdef DEBUG
    cerr << "Error in constructor0" << endl;
    #endif
}

void PegSolitaire::Cell::setCell(cell currentSituation){
    #ifdef DEBUG
    cerr << "Error in setcell" << endl;
    #endif
    situation = currentSituation;
}

void PegSolitaire::Cell::getCell () const {
        string temp;
        if (situation == peg) temp = "peg";
        else if(situation == empty) temp = "empty";
        else if (situation == out) temp = "out";
        cout << "row " << row << endl
        << "column " << column << endl
        << "situation " << temp;
}

bool PegSolitaire::Cell::cellNotEqual(cell compareSituation) const{
    /*#ifdef DEBUG
    cerr << "Error in cellNotequal" << endl;
    #endif*/
    if (situation != compareSituation) return true;
    return false;
}

PegSolitaire::Cell::Cell(int rowValue, int columnValue, cell situationValue)
: row(rowValue), column(columnValue), situation(situationValue)
{}

int PegSolitaire::totalNumberOfPegs(){
    pegsInBoards++;
    return pegsInBoards;
}

int PegSolitaire::totalNumberOfPegsDecrease(){
    pegsInBoards--;
    return pegsInBoards;
}

void PegSolitaire::menu(){
    int run = 1, option;
    string fileName;
    #ifdef DEBUG
    cerr << "Error before pegsinBoards" << endl;
    #endif
    /*pegsInBoards+= numberOfPegs();*/
    while(run == 1)  {
        cout << endl << "GAME MENU" << endl;
        cout << endl << "1-Continue last game" << endl
        << "2-Human game" << endl 
        << "3-Computer game" << endl 
        << "4-Load a new board" << endl
        << "5-Save the board" << endl
        << "6-Statistics" << endl
        << "0-Go back to main menu" << endl << endl
        << "Please enter your choice: ";
        cin >> option;
        switch(option){
            case 1:
                continueLast();
                break;
            case 2:
                newGameHuman();
                break;
            case 3:
                playGame();
                break;
            case 4:
                cout << "Enter the file name you want to load: " ;
                cin >> fileName;
                loadBoard(fileName);
                break;
            case 5:
                cout << "Enter the file name you want to save: " ;
                cin >> fileName;
                saveBoard(fileName);
                break;
            case 6:
                showStatistics();
                break;
            case 0:
                run = 0;
                break;
            default:
                cout << "Wrong entry !" << endl;
                break;
        }
    }
}

void PegSolitaire::createMap(){
    #ifdef DEBUG
    cerr << "Error in createmap" << endl;
    #endif
    vector<vector<cell>> map;
    board.clear();
    int xsize, ysize;
    switch(boardType){
        case 1:
            map = map1();
            break;
        case 2:
            map = map2();
            break;
        case 3:
            map = map3();
            break;
        case 4:
            map = map4();
            break;
        case 5:
            map = map5();
            break;
    }
    xsize = map.size();
    ysize = map[0].size();
    for(auto i=0; i<xsize ; i++){
        board.push_back(vector<Cell>());
        for(decltype(i) j=0; j< ysize; j++){
            switch(map[i][j]){
                case peg:
                    board[i].push_back(Cell(i,j,peg));
                    totalNumberOfPegs();
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

vector<vector<cell>> PegSolitaire::map1(){            
    vector<vector<cell>> mymap1{
        {out, out, peg, peg, peg, out, out},
        {out, peg, peg, peg, peg, peg, out},
        {peg, peg, peg, empty, peg, peg, peg},
        {peg, peg, peg, peg, peg, peg, peg},
        {peg, peg, peg, peg, peg, peg, peg},
        {out, peg, peg, peg, peg, peg, out},
        {out, out, peg, peg, peg, out, out}
    };
    return mymap1;
}

vector<vector<cell>> PegSolitaire::map2(){
    vector<vector<cell>> mymap2{
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
    return mymap2;
}

vector<vector<cell>> PegSolitaire::map3(){
    vector<vector<cell>> mymap3{
        {out, out, peg, peg, peg, out, out, out},
        {out, out, peg, peg, peg, out, out, out},
        {out, out, peg, peg, peg, out, out, out},
        {peg, peg, peg, peg, peg, peg, peg, peg},
        {peg, peg, peg, empty, peg, peg, peg, peg},
        {peg, peg, peg, peg, peg, peg, peg, peg},
        {out, out, peg, peg, peg, out, out, out},
        {out, out, peg, peg, peg, out, out, out}
    };
    return mymap3;
}
vector<vector<cell>> PegSolitaire::map4(){
    
    vector<vector<cell>> mymap4{
        {out, out, peg, peg, peg, out, out},
        {out, out, peg, peg, peg, out, out},
        {peg, peg, peg, peg, peg, peg, peg},
        {peg, peg, peg, empty, peg, peg, peg},
        {peg, peg, peg, peg, peg, peg, peg},
        {out, out, peg, peg, peg, out, out},
        {out, out, peg, peg, peg, out, out}
    };
    return mymap4;
}

vector<vector<cell>> PegSolitaire::map5(){
    
    vector<vector<cell>> mymap5{
        {out, out, out, out, peg, out, out, out, out},
        {out, out, out, peg, peg, peg, out, out, out},
        {out, out, peg, peg, peg, peg, peg, out, out},
        {out, peg, peg, peg, peg, peg, peg, peg, out},
        {peg, peg, peg, peg, empty, peg, peg, peg, peg},
        {out, peg, peg, peg, peg, peg, peg, peg, out},
        {out, out, peg, peg, peg, peg, peg, out, out},
        {out, out, out, peg, peg, peg, out, out, out},
        {out, out, out, out, peg, out, out, out, out}
    };

    return mymap5;
}
bool PegSolitaire::checkBoardType(int tboardType){
    if (tboardType < 1 || tboardType > 5){
        cerr << endl << "COULD NOT FIND THE BOARD" << endl
        << "TRY AGAIN !";
        return false;
    }
    return true;
}

void PegSolitaire::playGame(){
    int score;
    cout << "Please enter the board type: ";
    cin >> boardType;
    if (checkBoardType(boardType) == false) return;
    createMap();
    #ifdef DEBUG
    cerr << "Error in playGame3" << endl;
    #endif
    humanGame = 0;
    displayCurrentBoard();
    while (endGame() == false){
        /*random values*/
        play();
        if(endGame() == true){                                             /*Checks if the game is over or not*/
            cout << "The game is over!" << endl;       
            score = finalScore();
            cout << "Your final score is "<< score << endl << endl;
            if (score == 1) cout << "1 is the best score ! " << endl << "Congratulations" << endl;
            askForSaving();
        }
    }
}

void PegSolitaire::play(){
    /*Plays automatically*/
    int trow, tcolumn, running = 1,rDirec;
    string answer, fileName;
    char direction;
    int xsize = board.size();
    int ysize = board[0].size();
    if (xsize <= 0) {
        cerr << endl << "Something is wrong!" << endl;
        return;
    }
    /*It changes random values for every run*/
    srand(time(NULL));                                                          
    while(running == 1){
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
            running = 0;
            board [trow][tcolumn].setCell(empty);
            totalNumberOfPegsDecrease();
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
            this_thread::sleep_for(std::chrono::milliseconds(500));                     /*For delay (5 seconds)*/
            printComputerMove(trow, tcolumn, direction);
            displayCurrentBoard();
            cout << endl;
        }
    }
}
void PegSolitaire::continueLast(){
    int xsize = board.size();
    if (xsize == 0) { 
        cout << endl << "COULD NOT THE FIND THE GAME !" << endl;
        return;
    }
    play(boardType);
}

void PegSolitaire::newGameHuman(){
    int xsize = board.size(), userContinue, tboardType;
    cout << "Please enter the board type: ";
    cin >> tboardType;
    if (checkBoardType(tboardType) == false) return;
    boardType = tboardType;
    if (xsize == 0) createMap();
    else{
        cout << "There is an unfinished game already" << endl
        << "Do you want to start a new game(1) or continue the last game(2): ";
        cin >> userContinue;
        if (userContinue == 1) createMap();
        else if (userContinue == 2);
        else cerr << "Wrong input" << endl
        << "continues the game" << endl;
    } 
    play(boardType);
}
void PegSolitaire::play(int tboardType){
    /*User plays*/
    string userMove, fileName;                                       
    int trow, tcolumn, running = 1 /*, humanGame = 1, type6 = 0*/, score;
    char direction;
    humanGame = 1;
    boardType = tboardType;
    #ifdef DEBUG
    cout << "Board type is " << tboardType << endl;
    cout << "class board type is " << boardType << endl;
    #endif
    displayCurrentBoard();
    #ifdef DEBUG
    cerr << "Error in playboardt1" << endl;
    #endif
    while(running == 1){
        if(endGame() == true){                              /*Checks if the game is over*/          
            cout << "The game is over!" << endl;                
            score = finalScore();
            cout << "Your final score is "<< score << endl;
            if (score == 1) cout << "1 is the best score ! " << endl << "Congratulations";
            running = 0;              
        }
        cout << "Please enter your move(Ex: B4-R)" << endl 
        << "(Enter 0000 to exit the game): ";                    
        cin >> userMove;
        if (userMove != "0000"){
            if (userMove.compare("LOAD") == 0){                             /*LOAD command*/
                cin >> fileName;
                loadBoard(fileName);
                exit(0);
            }
            if (userMove.compare("SAVE") == 0){                  
                cin >> fileName;
                saveBoard(fileName);
            }
            tcolumn = userMove[0] - 65;                                      /*Takes the char and turns into a integer to fit in the map*/
            trow = userMove[1] - '1';                    
            direction = userMove[3];
            if (checkInput(userMove) == false) cerr << "Invalid Input!" << endl;                          
            else if(checkMove(trow, tcolumn, direction) == false) cerr << "Invalid Move!" << endl;
            else{    
                board [trow][tcolumn].setCell(empty);
                totalNumberOfPegsDecrease();
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
                displayCurrentBoard();
                cout << endl;
            }
        }
        else running = 0;
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
    #ifdef DEBUG
    cerr << "Check Move 1" << endl;
    #endif
    if (board [cRow][cColumn].cellNotEqual(peg)) return false;
    switch (cDirection){                                                                    /*Checks if it is inside the borders*/
        case 'R':
            #ifdef DEBUG
            cerr << "Check Move 2" << endl;
            #endif
            if (cColumn + 2 > (ysize - 1)) return false;
            if (board[cRow][cColumn + 1].cellNotEqual(peg)) return false;
            if (board[cRow][cColumn + 2].cellNotEqual(empty)) return false;
            break;
        case 'L':
            #ifdef DEBUG
            cerr << "Check Move 3" << endl;
            #endif
            if (cColumn -2 < 0) return false;
            if (board[cRow][cColumn - 1].cellNotEqual(peg)) return false;
            if (board[cRow][cColumn - 2].cellNotEqual(empty)) return false;
            break;
        case 'U':
            #ifdef DEBUG
            cerr << "Check Move 4" << endl;
            #endif
            if (cRow -2 < 0 ) return false;
            if (board[cRow - 1][cColumn].cellNotEqual(peg)) return false;
            if (board[cRow - 2][cColumn].cellNotEqual(empty)) return false;
            break;
        case 'D':
            #ifdef DEBUG
            cerr << "Check Move 5" << endl;
            #endif
            if (cRow + 2 > (xsize - 1)) return false;
            if (board[cRow + 1][cColumn].cellNotEqual(peg)) return false;
            if (board[cRow + 2][cColumn].cellNotEqual(empty)) return false;
            break;
    }
    return true;
}

bool PegSolitaire::endGame(){                                           /*Function to check if the game is over or not*/
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

void PegSolitaire::askForSaving(){
    string fileName;
    int answer, control;
    do{
        cout << "1- Save the game" << endl 
        << "2- Go back to the menu" << endl
        << "Please enter your choice: ";
        cin >> answer;
        switch (answer){
            case 1:
                cout << "Please enter the name of the file you want to save: ";
                cin >> fileName;
                /*saveBoard(fileName, humanGame);*/
                control = 0;
                break;
            case 2:
                cout << "Going back to the menu..." << endl << endl;
                control = 0;
                break;
            default: 
                control = 1;
                cerr << "Wrong input" << endl;
        }
    }while (control == 1);
}

void PegSolitaire::displayCurrentBoard() const {
    /*Function to print boards*/
    #ifdef DEBUG
    cerr << "Error display1" << endl;
    #endif
    int xsize = board.size();
     #ifdef DEBUG
    cerr << "Error display2" << endl;
    #endif
    int ysize = board[0].size();
     #ifdef DEBUG
    cerr << "Error display3" << endl;
    #endif
    int control = 1,counter = 0;
   
    string label= "abcdefghijklmnopqr";                             /*Saves letters inside a string*/
    cout << endl;
    for (auto i=0; i < xsize; i++){
        if (counter != 0) cout << counter << " ";                   /*Prints numbers in the map.*/
        counter++;
        #ifdef DEBUG
        cerr << "Error display3" << endl;
        #endif
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
        #ifdef DEBUG
        cerr << "Error display4" << endl;
        #endif
        
    }
}

int PegSolitaire::numberOfPegs(){
    int xsize = board.size(), ysize= board[0].size(), pegsInThisBoard = 0;
    if (xsize == 0) return 0;
    for (int i = 0 ; i< xsize ; i++)
        for(int j=0; j< ysize ; j++)   
            if (board[i][j].cellEqual(peg))   
                pegsInThisBoard += 1;
    return pegsInThisBoard;
}

int PegSolitaire::numberOfEmpty(){
    int xsize = board.size(), ysize= board[0].size(), emptyCells = 0;
    if (xsize == 0) return 0;
    for (int i=0 ; i< xsize ; i++)
        for(int j=0; j< ysize ; j++)   
            if (board[i][j].cellEqual(empty))   
                emptyCells += 1;
    return emptyCells;
}

int PegSolitaire::numberOfPegsTaken(){
    /*It assumes that every board starts with 1 empty cell,
    then, if we take out 1 from total number of empty cells, 
    we reach the total number of pegs taken.
     */
    int xsize = board.size();
    if (xsize == 0) return 0;
    return numberOfEmpty() - 1;
}

void PegSolitaire::showStatistics(){
    int xsize = board.size();
    cout << endl;
    if(xsize == 0){
        cerr << "NO ACTIVE GAME FOUND !!" << endl;
        return;
    }
    cout << "Number of pegs in the board: " << numberOfPegs() << endl
    << "Number of empty cells in the board: " << numberOfEmpty() << endl
    << "Number of pegs taken: " << numberOfPegsTaken() << endl;
    this_thread::sleep_for(std::chrono::milliseconds(500));
}

bool PegSolitaire::compare(PegSolitaire& other){
    int mypegs = numberOfPegs();
    int otherpegs = other.numberOfPegs();
    if (mypegs > otherpegs) return true;
    return false;
}

bool PegSolitaire::gameHasStarted(const PegSolitaire& object1, const PegSolitaire& object2){
    int xsize = object1.board.size();
    int ksize = object2.board.size();
    if (xsize > 0 && ksize > 0) return true;
    return false;
}

bool PegSolitaire::gameHasStarted(){
    int xsize = board.size();
    if (xsize > 0) return true;
    return false;
}


void PegSolitaire::loadBoard(string fileName){
    ifstream myFile;
    string line;
    int i=0, j=0, sizeofLine=0, run = 1, fileControl = 1, score;
    while(run == 1){
        /*If filename is not valid, or does not have the game, asks for it again.*/
        if (fileControl == 0){                                          
            cout << "Enter the file name again: ";
            cin >> fileName;
        }
        cout << "File " << fileName << " is opening" << endl;
        myFile.open(fileName);
        if(myFile.is_open()){
            board.clear();
            while(getline(myFile, line)){
                /*when it sees the word "end", it starts to take informations about the board and the game*/
                if (line.compare("end") == 0){                       
                    getline(myFile, line);
                    if(line.compare("Human") == 0) humanGame = 1;
                    else humanGame= 0;
                    run = 0;                    
                }
                /*It takes the board into a vector from txt file.*/
                else {board.push_back(vector<Cell>());                    
                    sizeofLine = line.size();
                    for(j=0; j< sizeofLine; j++){
                        switch (line[j]){
                            case 'P':
                                totalNumberOfPegs();
                                board[i].push_back(Cell(i,j,peg));
                                break;
                            case '-':
                                board[i].push_back(Cell(i,j,out));
                                break;
                            case '.':
                                board[i].push_back(Cell(i,j,empty));
                                break;
                        }
                    }
                }
                i++;
            }
            myFile.close();
        }
        else{
            cerr << "Could not open the file !" << endl;
            fileControl = 0;
            run = 1;
        }
    }
    cout << "File has been loaded succesfully !" << endl << endl;
        if (humanGame == 0) {
            displayCurrentBoard();
            while (endGame() == false){
            /*random values*/
                play();
                if(endGame() == true){                                             /*Checks if the game is over or not*/
                    cout << "The game is over!" << endl;       
                    score = finalScore();
                    cout << "Your final score is "<< score << endl << endl;
                    if (score == 1) cout << "1 is the best score ! " << endl << "Congratulations" << endl;
                    askForSaving();
                }
            }
        }
        else play(1);
}

void PegSolitaire::saveBoard(string fileName){
    /*Function to save a board into a txt file*/
    if (gameHasStarted() == false) return;
    int xsize = board.size(), ysize = board[0].size();
    ofstream myFile;
    myFile.open(fileName);
    if(myFile.is_open()){
        for(auto i=0; i< xsize; i++){
            for(decltype (i) j=0; j< ysize; j++){
                if(board[i][j].cellEqual(peg))
                    myFile << "P";
                else if (board[i][j].cellEqual(empty))
                    myFile << ".";
                else if (board[i][j].cellEqual(out)) 
                    myFile << "-";
            }
        myFile << endl;
        }
        myFile << "end" << endl;
        if (humanGame == 1) myFile << "Human" << endl;
        else myFile << "Computer" << endl;
        /*myFile << numberOfPegs() << endl
        << numberOfEmpty() << endl
        << numberOfPegsTaken() << endl;*/

        myFile.close();
        cout << endl << "The game saved succesfully" << endl << endl;
    }
}

void PegSolitaire::printComputerMove(int cRow, int cColumn, char direction){        /*It prints computer`s moves*/
    char c = cColumn+65;
    int r = cRow+1;
    cout << c << r << '-' << direction << " played"<< endl;
}

int PegSolitaire::finalScore(){                    /*Function to calculate final score*/
    int final = 0;                                              /*Calculates pegs in the board*/
    int xsize = board.size();
    int ysize = board[0].size();
    for(int i=0; i<xsize; i++){
        for(int j=0; j<ysize; j++){
            if (board[i][j].cellEqual(peg)) final++;
        }
    }
    return final;
}