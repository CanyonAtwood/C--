#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// These numbers will represent the location on the board for tic tac toe

char board[3][3] = {{'1', '2', '3'},{'4' ,'5' ,'6'},{'7' ,'8' ,'9'}};

char current_marker;
int current_player;

void drawBoard()
// another representation of the drawboard showing where the slots will go. Remember it looks like this because we start with 0
{
    cout << " " << board[0][0] << "|" << board [0][1] <<"|"<< board[0][2] << endl;
    cout << "----------\n";
    cout << " " << board[1][0] << "|" << board [1][1] <<"|"<< board[1][2] << endl;
    cout << "----------\n";
    cout << " " << board[2][0] << "|" << board [2][1] <<"|"<< board[2][2] << endl;
    cout << "----------\n";

}
bool placeMarker(int slot)
{
    int row = slot /3;
    int col;
    if(slot % 3 == 0)
    {
        row = row- 1;
        col = 2;
    }
    
     else col = (slot % 3) - 1;
     if (board[row][col] != 'X' && board[row][col] !='O') 
     {
        board[row][col] = current_marker;
        return true;
     }
     else return false;

}

int winner()
//this is how we are to determine the winner 
{
    for (int i = 0; i < 3; i++)
    {
        if(board[i][0] == board[i][1] ==board[i][2]) return current_player;
        if(board[0][i] == board[1][i] ==board[2][i]) return current_player;
    
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[1][2]) return current_player;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) return current_player;
    return 0;

}
//taking turns
void swap_player_and_marker()
{
    if(current_marker =='X') current_marker='O';
    else current_marker = 'X';

    if(current_player ==1) current_player = 2;
    else current_player = 1;
}

void game()
{
    cout<<"Player 1, X or O:    ";
    char marker_pl;
    cin >> marker_pl;
    current_player =1;
    current_marker = marker_pl;
    drawBoard();

    int player_won;
    //player wins statements 

    for(int i =0; i<9; i++)
    {

    cout <<"its player"<< current_player<< "'s  turn. Enter the number for where you want to go  : ";
    int slot;
    cin>> slot;


      // again this just shows how we show if a space does exist ex: 100 because we only play on the 1-9 number range representing the slots 
    if(slot <1 || slot>9)
    {
       cout <<" that slot is invalid please be a doll and try another one";
          continue; 
    }
    // showing that the slot requested is already taken and that they need to pick something else
    if(!placeMarker(slot)) 
    {
         cout <<" that slot is already being used try another one";
          continue;
          }
    player_won = winner();

    if(player_won ==1) { cout<<"Player one wins!"; break; }
    if(player_won==2)  { cout<<"Player two wins!"; break;}
    swap_player_and_marker();
    drawBoard();
    }
   


    if (player_won == 0) cout<<"tie game";
}

int main()
{
    srand(time(NULL));
    cout<<(rand() %(10-1+1))+1;
}
