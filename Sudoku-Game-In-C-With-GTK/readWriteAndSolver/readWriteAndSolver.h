#ifndef READWRITEANDSOLVER_H
#define READWRITEANDSOLVER_H

#include <gtk/gtk.h>

#define board_Size 9
#define gamePath_Size 50
#define playerName_Size 50
#define Amountsbest_Times 3

//Main player data.
struct data_player {
    char player_name[playerName_Size];
    int difficulty;
    int currentTimeStamp; 
    char gamePath[gamePath_Size];
    int player_board[board_Size][board_Size];
} player;

//Number of best times.
struct time {
    char name[playerName_Size];
    int difficulty;
    int time;
} bestTime[Amountsbest_Times + 1];

/*The createNewGame function is called when the player presses the New Game Random button.*/
 G_MODULE_EXPORT void createNewGame(int difficulty);

/*The saveGame function is called when the player presses the save button. */
G_MODULE_EXPORT int saveGame(void);

/*The loadNewGame function is called when the player presses the new game button.*/
G_MODULE_EXPORT void loadGameSave(char player_name[playerName_Size]);

//******************VERIFY THE WHOLE SUDOKU**************************
G_MODULE_EXPORT int entire_sudoku_solver( int matrix[board_Size][board_Size]);

//
G_MODULE_EXPORT void threeBestTimes(void);
//
G_MODULE_EXPORT void loadBestTimes(void);

#endif //READANDWRITE_H