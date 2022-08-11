#include <iostream>
/*#include <string>*/
#include <vector>
/*#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <fstream>*/
#include "lib.h"

using namespace std;

int PegSolitaire::pegsInBoards = 0;

int main(){
    PegSolitaire p1(1), p2(2), p3(3), p4(4), p5(5);
    int game, run = 1;

    while(run == 1){
        cout << endl << "MAIN MENU" << endl << endl;
        cout << "Total number of pegs in all games: " <<  PegSolitaire::pegsInBoards << endl << endl;
        cout << "Enter the game you want to play (from 1 to 5)" << endl
        << "To compare p1 with p2 enter 6 " << endl
        << "(0 to exit): ";
        cin >> game;
        switch (game){
            case 1:p1.menu();
                    break;
            case 2:p2.menu();
                    break;
            case 3:p3.menu();
                    break;
            case 4:p4.menu();
                    break;
            case 5:p5.menu();
                    break;
            case 6:
                    cout << endl;
                    if(p1.gameHasStarted(p1,p2) == true){
                        if (p1.compare(p2) == true)
                            cout << "1.game has more pegs on the board than  "
                            << " 2.game" << endl;
                        else
                            cout << "2.game"
                            <<" has more pegs on the board than 1.game."
                            <<  endl;
                    }
                    else cerr << "NO ACTIVE GAME FOUND !!" << endl << endl;
                    break;
            case 0:
                    exit(0);
            default: 
                cout << "Wrong Input !" << endl;
                break;
        }
    }
    return 0;
}
