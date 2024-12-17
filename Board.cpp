#include "Board.h"
#include<format>
#include<iostream>
using std::cin, std::cout;

Board::Board(int size , int win)//constructor
{
    winningStreak = win;
    board = vector < vector < string> >(size);
    for (int row = 0; row < size; row++) //initalzing board
    {
        vector< string > rowVec(size);
        for (int collum = 0 ; collum < size ; collum++)
        {
            string index = std::format("{}{}", row , collum);
            rowVec.at(collum) = index;
        }
        board.at(row) = rowVec;
    }
}
int Board::insertSymbol(string symbol , int row , int col)//inserting a symbol on the board
{
    if( symbol == "X" )
    {
      if( board.at( row ).at( col ) != "O" )//if the spot isnt already taken
      {
          counterX++;
          board.at( row ).at( col ) = symbol;
          if( counterX == winningStreak && iStreak( board , symbol) )
          {
            cout<< "Congratulations! Player X wins !\n";
            return 0;
          }
      }
      else
      {
        cout<< "Error O already put there! try again.\n";
        return -1;
      }
    }
    else// its a O sybmol
    {
        if( board.at(row).at(col) != "X" )//if the spot isnt already taken
        {
            counterO++;
            board.at(row).at(col) = symbol;
            if( counterO == winningStreak && iStreak( board , symbol ) )//checkimg if it was a winning move
            {
                cout<< "Congratulations! Player 0 wins !\n";
                return 0;
            }
        }
        else
        {
            cout<< "Error X already put there! try again.\n";
            return -1;
        }
    }
    return 0 ;
}

void Board:: print() //printing board
 {
    for (int row = 0; row < board.size(); row++)
    {
        for (int collum = 0; collum < board.size() ; collum++)
        {
            cout << board.at(row).at(collum) << " ";
        }
        cout << std::endl;
    }
 }
bool Board::iStreak(vector < vector < string > >& board , string symbol) const //chekcing of the symbol has a streak
{
    if( iSHorizontalStreak(board , symbol) )//horizontal streak
    {
      return true;
     }
    if( iSDiagonalStreak(board , symbol) )//diagonal streak
    {
        return true;
    }
    return false;
}

bool Board:: iSHorizontalStreak(vector < vector < string > >& board , string symbol) const
{
    int streakCounter {1};
    for( int row = 1 ; row < board.size() - 1 ; row++) //collum streak
    {
        if( board.at( row ).at( 0 ) != symbol && board.at( row - 1 ).at( 0 ) != symbol)
        {
            break;
        }
        streakCounter++;
    }
    if( streakCounter == winningStreak )//row streak
    {
        return true;
    }
    streakCounter = 1 ;
    for( int row = 0 ; row < board.size() - 1 ; row++)
    {
        for( int col = 1 ; col < board.size() - 1 ; col++ )
        {
            if( board.at( row ).at( col ) != symbol && board.at( row  ).at( col - 1 ) != symbol )
            {
                break;
            }
        }
        streakCounter++;
    }
    if( streakCounter == winningStreak )
    {
        return true;
    }
    return false;
}

bool Board:: iSDiagonalStreak(vector < vector < string > >& board , string symbol) const
{
    int streakCounter {1};
    for( int row = 1 ; row < board.size()  ; row++)
    {
        if( board.at( row ).at( row ) != symbol &&  board.at( row - 1 ).at( row - 1 ) != symbol )
        {
            break;
        }
        streakCounter++;
    }
    if( streakCounter == winningStreak )
    {
        return true;
    }
    streakCounter = 1 ;
    for( int row = 0 ; row < board.size() - 1 ; row++)
    {
        for( int col = 3 ; col > 0 ; col-- )
        {
            if( board.at( row ).at( col ) != symbol && board.at( row  ).at( col - 1 ) != symbol )
            {
                break;
            }
        }
        streakCounter++;
    }
    if( streakCounter == winningStreak )
    {
        return true;
    }
    return false;
}