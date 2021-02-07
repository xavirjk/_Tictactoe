#ifndef GAME_H
#define GAME_H

#include "ticTacToe_global.h"
#include <QObject>
#include <QJsonArray>
#include <controller/mode_controller.h>
#include <depends/sort.h>
class TICTACTOE_EXPORT Game: public QObject
{
public:
    Game(QObject *parent = nullptr);
    ~Game();
    void initialiseGame(const int index);
    void computerMove();
    void get2DIndex();
    void setPlayer(const QString &player);
    QString player() const;
    QString gameWinner() const;
    void setMoves();
    void searchWinner();
    //void confirmWinner(const int &count,int tempo[]);
    void RefreshGame(int gameMode);
    int getRandom();
    int accessComputerMove();
    int getScores(const QString &player);
    int *accessProgressArray();
    int gameMode();
    QJsonArray getWinningMoves();

private:
    HeapSort *heapsort;
    ModeController *controller;
    static const int rows = 3;
    static const int columns = 3;
    int row, column, index;
    int xWins = 0, oWins = 0;
    QString currentMove = "X", winner = "";
    QString refMove = currentMove;
    QString gameBoard[rows][columns];
    int winningMoves[3];
    QJsonArray winMoves;
    int progressArray[9];
    int progress = 8;
    int temp;
    int mode = 1;

};

#endif // GAME_H
