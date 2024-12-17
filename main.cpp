#include "Board.h"
#include<iostream>
using std::cin, std::cout;
int rowStreak(Board game)
{
    int sum {0};
    sum += game.insertSymbol("X" , 0 , 0 );
    sum += game.insertSymbol("X" , 0 , 1 );
    sum += game.insertSymbol("X" , 0 , 2 );
    sum += game.insertSymbol("X" , 0 , 3 );
    return sum;
}
int colStreak(Board game)
{
    int sum {0};
    sum += game.insertSymbol("X" , 1 , 0 );
    sum += game.insertSymbol("X" , 2 , 0 );
    sum += game.insertSymbol("X" , 3 , 0 );
    sum += game.insertSymbol("X" , 4 , 0 );
    return sum;
}
int upwardsDaigonalStreak(Board game)
{
    int sum {0};
    sum += game.insertSymbol("X" , 0 , 3 );
    sum += game.insertSymbol("X" , 2 , 1 );
    sum += game.insertSymbol("X" , 1 , 2 );
    sum += game.insertSymbol("X" , 3 , 0 );
    return sum;
}
int downwardsDaigonalStreak(Board game)
{
    int sum {0};
    sum += game.insertSymbol("X" , 0 , 0 );
    sum += game.insertSymbol("X" , 1 , 1 );
    sum += game.insertSymbol("X" , 2 , 2 );
    sum += game.insertSymbol("X" , 3 , 3 );
    return sum;
}
int main()
{

    Board game(4 , 4);
    game.print();
    for( int i = 0 ; i < 16 ; i++ )
    {
        if (rowStreak(game) < 0 )
        {
            return -1;
        }

        game.print();
        if (colStreak(game) < 0 )
        {
            return -1;
        }
        game.print();
        if (upwardsDaigonalStreak(game) < 0)
        {
            return -1;
        }
        game.print();
        if (downwardsDaigonalStreak(game) < 0)
        {
            return -1;
        }
        game.print();
    }
    return 0;
}