#pragma once

#include<vector>
#include<string>
using std::vector, std::string ;

class Board
{
private:
    int winningStreak = 0;
    int counterX = 0;
    int counterO = 0 ;

public:
    vector < vector < string > > board;
    Board( int size , int win );
    int insertSymbol( string symbol , int row , int col );
    void print();
    bool iStreak(vector < vector < string > >& board , string symbol) const;
    bool iSHorizontalStreak(vector < vector < string > >& board, string symbol) const;
    bool iSDiagonalStreak(vector < vector < string > >& board ,string symbol) const;

};



