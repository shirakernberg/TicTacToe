#include "Board.h"
#include<iostream>
using std::cin, std::cout;
int rowStreak(Board &game)
{
    int sum {0};
    sum += game.insertSymbol("X" , 0 , 0 );
    sum += game.insertSymbol("X" , 0 , 1 );
    sum += game.insertSymbol("X" , 0 , 2 );
    sum += game.insertSymbol("X" , 0 , 3 );
    return sum;
}
int colStreak(Board &game)
{
    int sum {0};
    sum += game.insertSymbol("X" , 0 , 0 );
    sum += game.insertSymbol("X" , 1 , 0 );
    sum += game.insertSymbol("X" , 2 , 0 );
    sum += game.insertSymbol("X" , 3 , 0 );
    return sum;
}
int upwardsDaigonalStreak(Board &game)
{
    int sum {0};
    sum += game.insertSymbol("X" , 0 , 3 );
    sum += game.insertSymbol("X" , 2 , 1 );
    sum += game.insertSymbol("X" , 1 , 2 );
    sum += game.insertSymbol("X" , 3 , 0 );
    return sum;
}
int downwardsDaigonalStreak(Board &game)
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

    Board game1(4 , 4);
    game1.print();
    if (rowStreak(game1) < 0 )
    {
        return -1;
    }
    game1.print();
    Board game2(4 , 4);
    if (colStreak(game2) < 0 )
    {
        return -1;
    }
    game2.print();
    Board game3(4 , 4);
    if (upwardsDaigonalStreak(game3) < 0)
    {
        return -1;
    }
    game3.print();
    Board game4(4 , 4);
    if (downwardsDaigonalStreak(game4) < 0)
    {
        return -1;
    }
    game4.print();
    return 0;
}