using namespace std;


enum class cell {empty, peg, out};
const cell peg = cell::peg;
const cell out = cell::out;
const cell empty = cell::empty;

class PegSolitaire
{
public: 
    class Cell
    {
    public:
        Cell (int rowValue, int columnValue, cell situationValue);
        void setCell(cell currentSituation);
        bool cellEqual(cell compareSituation) const{ 
            if (situation == compareSituation) return true;
            return false;
        }
        bool cellNotEqual(cell compareSituation) const ;
        void getCell () const;
    private: 
        int row;
        int column;
        cell situation;
    };

    PegSolitaire (int boardTypeVal, int humanGameVal);
    PegSolitaire (int boardTypeVal);
    PegSolitaire ();
    void loadBoard(string fileName);
    void saveBoard(string fileName);
    int numberOfPegs();
    int numberOfEmpty(); 
    int numberOfPegsTaken();
    void showStatistics();
    void displayCurrentBoard() const;
    void continueLast();
    void newGameHuman();
    void play();//auto play
    void play(int boardType);//user play
    bool checkBoardType(int tboardType);
    bool checkInput(string inp);
    bool checkMove(int cRow, int cColumn, char cDirection);
    bool endGame();
    void askForSaving();
    void playGame(); /*first ask board type then autoplay*/
    static int totalNumberOfPegs();
    static int totalNumberOfPegsDecrease();
    bool compare(PegSolitaire& other);
    bool gameHasStarted();
    void printComputerMove(int row, int column, char direction);
    void menu();
    void createMap();
    vector<vector<cell>> map1();
    vector<vector<cell>> map2();
    vector<vector<cell>> map3();
    vector<vector<cell>> map4();
    vector<vector<cell>> map5();
    int finalScore();
    void printFinalMessage(int score);
    static int pegsInBoards;

private: 
    vector<vector<Cell>> board;
    int boardType;
    int humanGame;
};


