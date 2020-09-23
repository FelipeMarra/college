#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "./readWriteAndSolver/readWriteAndSolver.c"

#include <gtk/gtk.h>

//Functions to time counting
		int timeDiference;
		time_t t_ini, t_end;
		void timeCounting(){
 			t_ini = time(NULL);
		}
		void endTimeCounting(){
			t_end = time(NULL);
			timeDiference = difftime(t_end, t_ini);
			player.currentTimeStamp += timeDiference;
			g_print("TEMPO CONTADO: %d", player.currentTimeStamp);
		}
//temp for passing the difficulty 
int difficulty; 

//---------------------------------------------------------------------
//SOME FUNCTIONS PROTOTYPES
//---------------------------------------------------------------------

G_MODULE_EXPORT void  creat_game_window();
G_MODULE_EXPORT void  player_name_window();
G_MODULE_EXPORT void  loadBestTimesIntoLabel();
G_MODULE_EXPORT void setSudokuValues();
//---------------------------------------------------------------------
// MENU WINDOW
//---------------------------------------------------------------------
//declaring the pointers to the windows and other widgets

GtkWidget *window_main;
GtkWidget *layout_menu;
GtkWidget *btn_randon_load_game;
GtkWidget *btn_best_sudoku_times;
GtkWidget *btn_load_save;
GtkBuilder *builderMenu;

int main(int argc, char *argv[])
{
    
    gtk_init(&argc, &argv); //init GTK


// establish contact with xml code used to adjust widget settings

        //Loading the XML file
    builderMenu = gtk_builder_new_from_file ("View/window_main.glade");
        //Initilizing the window
    window_main = GTK_WIDGET(gtk_builder_get_object(builderMenu, "window_main"));
        //Connecting the sinal to close the window
    g_signal_connect(window_main, "destroy", G_CALLBACK(gtk_main_quit), NULL);
        //Creating the builder stack
    gtk_builder_connect_signals(builderMenu, NULL);
        //building the widgets
    layout_menu = GTK_WIDGET(gtk_builder_get_object(builderMenu, "layout_menu"));
    btn_randon_load_game =  GTK_WIDGET(gtk_builder_get_object(builderMenu, "btn_randon_load_game"));
    btn_load_save =  GTK_WIDGET(gtk_builder_get_object(builderMenu, "btn_load_save"));
    btn_best_sudoku_times =  GTK_WIDGET(gtk_builder_get_object(builderMenu, "btn_best_sudoku_times"));
        //showing everything
    gtk_widget_show(window_main);

    gtk_main();

   return 0;

}

//---------------------------------------------------------------------
// RANDON LOAD GAME WINDOW
//---------------------------------------------------------------------
GtkWidget *randon_load_game_window;
GtkWidget *randon_load_game_layout;
GtkWidget *btn_easy;
GtkWidget *btn_normal;
GtkWidget *btn_hard;
GtkBuilder *builderRandonLoad;

G_MODULE_EXPORT void on_btn_randon_load_game_clicked (GtkButton *load_game){
    g_print ("randon_load_game\n");
     builderRandonLoad = gtk_builder_new_from_file ("View/randon_load_game.glade");
     randon_load_game_window = GTK_WIDGET(gtk_builder_get_object(builderRandonLoad, "randon_load_game_window"));
        //Connecting the sinal to close the window
    g_signal_connect(randon_load_game_window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
        //Creating the builder stack
    gtk_builder_connect_signals(builderRandonLoad, NULL);
        //building the widgets
    randon_load_game_layout = GTK_WIDGET(gtk_builder_get_object(builderRandonLoad, "randon_load_game_layout"));
    btn_easy =  GTK_WIDGET(gtk_builder_get_object(builderRandonLoad, "btn_easy"));
    btn_normal =  GTK_WIDGET(gtk_builder_get_object(builderRandonLoad, "btn_normal"));
    btn_hard =  GTK_WIDGET(gtk_builder_get_object(builderRandonLoad, "btn_hard"));
    
        //showing everything
    gtk_widget_show(randon_load_game_window);

     gtk_main();
}

//***************EASY******************************************************//
G_MODULE_EXPORT void on_btn_easy_clicked (GtkButton *easy){
    g_print ("on_btn_easy_clicked\n");
    //This is used to close the window 
    gtk_widget_hide(randon_load_game_window);
    //puting easy code into int difficulty
    difficulty = 0;
    player_name_window();
}
//***************NORMAL******************************************************//
G_MODULE_EXPORT void on_btn_normal_clicked (GtkButton *normal){
    g_print ("on_btn_normal_clicked\n");
    //This is used to close the window 
    gtk_widget_hide(randon_load_game_window);
     //puting normal code into int difficulty
    difficulty = 1;
    player_name_window();
}
//***************HARD******************************************************//
G_MODULE_EXPORT void on_btn_hard_clicked (GtkButton *hard){
    g_print ("on_btn_hard_clicked\n");
    //This is used to close the window 
    gtk_widget_hide(randon_load_game_window);
     //puting hardcore code into int difficulty
    difficulty = 2;
    player_name_window();
}

//---------------------------------------------------------------------
// LOAD GAME FROM FILE  WINDOW
//---------------------------------------------------------------------
GtkWidget *load_game_from_file_window;
GtkWidget *load_game_from_file_layout;
GtkWidget *btn_file_chooser;
GtkBuilder *builderLoadFile;

//---------------------------------------------------------------------
// LOAD GAME BY NAME WINDOW
//---------------------------------------------------------------------
GtkWidget *load_save_window;
GtkWidget *load_save_layout;
GtkWidget *btn_load_save_ready;
GtkWidget *load_save_entry;
GtkBuilder *builderLoadSaveName;

G_MODULE_EXPORT void on_btn_load_save_clicked (GtkButton *load_game_by_name){
    g_print ("load_game_from_file\n");
     builderLoadSaveName = gtk_builder_new_from_file ("View/load_save_by_name.glade");
     load_save_window = GTK_WIDGET(gtk_builder_get_object(builderLoadSaveName, "load_save_window"));
        //Connecting the sinal to close the window
    g_signal_connect(load_save_window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
        //Creating the builder stack
    gtk_builder_connect_signals(builderLoadSaveName, NULL);
        //building the widgets
    load_save_layout = GTK_WIDGET(gtk_builder_get_object(builderLoadSaveName, "load_save_layout"));
    load_save_entry = GTK_WIDGET(gtk_builder_get_object(builderLoadSaveName, "load_save_entry"));
    btn_load_save_ready =  GTK_WIDGET(gtk_builder_get_object(builderLoadSaveName, "btn_load_save_ready"));
        //showing everything
    gtk_widget_show(load_save_window);

     gtk_main();
}
//************Entry Handler**********************************************
char player_save_name[playerName_Size];
G_MODULE_EXPORT void on_load_save_entry_changed(GtkEntry *entry) {
	strcpy(player_save_name, gtk_entry_get_text(entry));
	g_print("Entry From Save by name: %s\n", player_save_name);
	}
//************Player Ready Clicked***************************************
G_MODULE_EXPORT void on_btn_load_save_ready_clicked (GtkButton *ready){
    gtk_widget_hide(load_save_window);
    g_print ("Final Entry: %s \n", player_save_name);
    //Load Game Save Call
   loadGameSave(player_save_name);
   //Call the game function
    creat_game_window();
}

//---------------------------------------------------------------------
// GAME BEST TIMES
//---------------------------------------------------------------------
GtkWidget *best_sudoku_times_window;
GtkWidget *best_sudoku_times_layout;
GtkWidget *best_sudoku_times_grid;
GtkWidget *grid_player1_time; GtkWidget *grid_player1_name; GtkWidget *grid_player1_dificulty;
GtkWidget *grid_player2_time; GtkWidget *grid_player2_name; GtkWidget *grid_player2_dificulty;
GtkWidget *grid_player3_time; GtkWidget *grid_player3_name; GtkWidget *grid_player3_dificulty;

GtkBuilder *builder_best_sudoku_times;

G_MODULE_EXPORT void on_btn_best_sudoku_times_clicked (GtkButton *sudoku_times){
    g_print ("btn_best_sudoku_times\n");
        //Loading the best times data into the array of the current section
    loadBestTimes();
        //Loading the XML file
    builder_best_sudoku_times = gtk_builder_new_from_file ("View/best_sudoku_times.glade");
        //Initilizing the window
    best_sudoku_times_window = GTK_WIDGET(gtk_builder_get_object(builder_best_sudoku_times, "best_sudoku_times_window"));
        //Connecting the sinal to close the window
    g_signal_connect(best_sudoku_times_window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
        //Creating the builder stack
    gtk_builder_connect_signals(builder_best_sudoku_times, NULL);
        //building the widgets
    best_sudoku_times_layout = GTK_WIDGET(gtk_builder_get_object(builder_best_sudoku_times, "best_sudoku_times_layout"));
    best_sudoku_times_grid = GTK_WIDGET(gtk_builder_get_object(builder_best_sudoku_times, "best_sudoku_times_grid"));
    grid_player1_time = GTK_WIDGET(gtk_builder_get_object(builder_best_sudoku_times, "grid_player1_time"));
    grid_player2_time = GTK_WIDGET(gtk_builder_get_object(builder_best_sudoku_times, "grid_player2_time"));
    grid_player3_time = GTK_WIDGET(gtk_builder_get_object(builder_best_sudoku_times, "grid_player3_time"));
	grid_player1_name = GTK_WIDGET(gtk_builder_get_object(builder_best_sudoku_times, "grid_player1_name"));
	grid_player2_name = GTK_WIDGET(gtk_builder_get_object(builder_best_sudoku_times, "grid_player2_name"));
	grid_player3_name = GTK_WIDGET(gtk_builder_get_object(builder_best_sudoku_times, "grid_player3_name"));
	grid_player1_dificulty = GTK_WIDGET(gtk_builder_get_object(builder_best_sudoku_times, "grid_player1_dificulty"));
	grid_player2_dificulty = GTK_WIDGET(gtk_builder_get_object(builder_best_sudoku_times, "grid_player2_dificulty"));
	grid_player3_dificulty = GTK_WIDGET(gtk_builder_get_object(builder_best_sudoku_times, "grid_player3_dificulty"));
   
        //Loading the best times into the label
        loadBestTimesIntoLabel();
        //showing everything
    gtk_widget_show(best_sudoku_times_window);

     gtk_main();
}

//******************MODIFY THE BEST TIMES DATA********************************
//Puts the dificulty into a string named difficultyTemp
char difficultyTemp[20];
G_MODULE_EXPORT void difficultyStr(int index){
	switch (bestTime[index].difficulty){
	case 0:
		strcpy(difficultyTemp, "easy");
		break;
	case 1:
		strcpy(difficultyTemp, "normal");
		break;
	case 2:
		strcpy(difficultyTemp, "hard");
		break;
	}
} 
G_MODULE_EXPORT void loadBestTimesIntoLabel(){

    char timeTemp[20];
	
    sprintf(timeTemp, "%d seconds", bestTime[0].time);
    gtk_label_set_text(GTK_LABEL(grid_player1_time), (const gchar*) timeTemp);
    gtk_label_set_text(GTK_LABEL(grid_player1_name), (const gchar*) bestTime[0].name);
	difficultyStr(0);
    gtk_label_set_text(GTK_LABEL(grid_player1_dificulty), (const gchar*) difficultyTemp);

    sprintf(timeTemp, "%d seconds", bestTime[1].time);
    gtk_label_set_text(GTK_LABEL(grid_player2_time), (const gchar*) timeTemp);
    gtk_label_set_text(GTK_LABEL(grid_player2_name), (const gchar*) bestTime[1].name);
	difficultyStr(1);
    gtk_label_set_text(GTK_LABEL(grid_player2_dificulty), (const gchar*) difficultyTemp);

    sprintf(timeTemp, "%d seconds", bestTime[2].time);
    gtk_label_set_text(GTK_LABEL(grid_player3_time), (const gchar*) timeTemp);
	gtk_label_set_text(GTK_LABEL(grid_player3_name), (const gchar*) bestTime[2].name);
	difficultyStr(2);
    gtk_label_set_text(GTK_LABEL(grid_player3_dificulty), (const gchar*) difficultyTemp);
}
//---------------------------------------------------------------------
// PLARYER NAME WINDOW
//---------------------------------------------------------------------
GtkWidget *playerWindow;
GtkWidget *player_layout;
GtkWidget *player_entry;
GtkWidget *btn_player_ready;
GtkBuilder *builderPlayer;

G_MODULE_EXPORT void  player_name_window(){
     //Loading the XML file
    builderPlayer = gtk_builder_new_from_file ("View/player.glade");
        //Initilizing the window
    playerWindow = GTK_WIDGET(gtk_builder_get_object(builderPlayer, "player_window"));
        //Connecting the sinal to close the window
    g_signal_connect(playerWindow, "destroy", G_CALLBACK(gtk_main_quit), NULL);
        //Creating the builder stack
    gtk_builder_connect_signals(builderPlayer, NULL);
        //building the widgets
    player_layout = GTK_WIDGET(gtk_builder_get_object(builderPlayer, "player_layout"));
    player_entry = GTK_WIDGET(gtk_builder_get_object(builderPlayer, "player_entry"));
    btn_player_ready = GTK_WIDGET(gtk_builder_get_object(builderPlayer, "btn_player_ready"));
        //showing everything
    gtk_widget_show(playerWindow);

     gtk_main();
}
//************Entry Handler**********************************************
char player_name[playerName_Size];
G_MODULE_EXPORT void on_player_entry_changed(GtkEntry *entry) {
	strcpy(player_name, gtk_entry_get_text(entry));
	g_print("Entry: %s\n", player_name);
	}
//************Player Ready Clicked***************************************
G_MODULE_EXPORT void on_btn_player_ready_clicked (GtkButton *ready){
    gtk_widget_hide(playerWindow);
    g_print ("Final Entry: %s \n", player_name);
    //Create Game matri
    createNewGame(difficulty);
    //Set player name into the struct
    strcpy(player.player_name,player_name);
	//Set currentTimeStamp to 0
	player.currentTimeStamp = 0;
   //Call the game function
    creat_game_window();
}

//---------------------------------------------------------------------
// GAME WINDOW
//---------------------------------------------------------------------
GtkWidget *gameWindow;
GtkWidget *game_layout;
GtkWidget *game_grid;
GtkWidget *label_player_name;
GtkWidget *btn_save_game;
GtkWidget *btn_player_is_done;
GtkBuilder *builderGame;

//deeclaring game cells entrys pointers

//0 line                //1 line                //2 line
GtkWidget *index_00;    GtkWidget *index_10;    GtkWidget *index_20;
GtkWidget *index_01;    GtkWidget *index_11;    GtkWidget *index_21;
GtkWidget *index_02;    GtkWidget *index_12;    GtkWidget *index_22;
GtkWidget *index_03;    GtkWidget *index_13;    GtkWidget *index_23;
GtkWidget *index_04;    GtkWidget *index_14;    GtkWidget *index_24;
GtkWidget *index_05;    GtkWidget *index_15;    GtkWidget *index_25;
GtkWidget *index_06;    GtkWidget *index_16;    GtkWidget *index_26;
GtkWidget *index_07;    GtkWidget *index_17;    GtkWidget *index_27;
GtkWidget *index_08;    GtkWidget *index_18;    GtkWidget *index_28;
//3 line                //4 line                //5 line  
GtkWidget *index_30;    GtkWidget *index_40;    GtkWidget *index_50;
GtkWidget *index_31;    GtkWidget *index_41;    GtkWidget *index_51;
GtkWidget *index_32;    GtkWidget *index_42;    GtkWidget *index_52;
GtkWidget *index_33;    GtkWidget *index_43;    GtkWidget *index_53;
GtkWidget *index_34;    GtkWidget *index_44;    GtkWidget *index_54;
GtkWidget *index_35;    GtkWidget *index_45;    GtkWidget *index_55;
GtkWidget *index_36;    GtkWidget *index_46;    GtkWidget *index_56;
GtkWidget *index_37;    GtkWidget *index_47;    GtkWidget *index_57;
GtkWidget *index_38;    GtkWidget *index_48;    GtkWidget *index_58;

//6 line                //7 line                //8 line  
GtkWidget *index_60;    GtkWidget *index_70;    GtkWidget *index_80;
GtkWidget *index_61;    GtkWidget *index_71;    GtkWidget *index_81;
GtkWidget *index_62;    GtkWidget *index_72;    GtkWidget *index_82;
GtkWidget *index_63;    GtkWidget *index_73;    GtkWidget *index_83;
GtkWidget *index_64;    GtkWidget *index_74;    GtkWidget *index_84;
GtkWidget *index_65;    GtkWidget *index_75;    GtkWidget *index_85;
GtkWidget *index_66;    GtkWidget *index_76;    GtkWidget *index_86;
GtkWidget *index_67;    GtkWidget *index_77;    GtkWidget *index_87;
GtkWidget *index_68;    GtkWidget *index_78;    GtkWidget *index_88;



G_MODULE_EXPORT void  creat_game_window(){
		
	     //Starts time counting
		timeCounting();
         //Loading the XML file
    builderGame = gtk_builder_new_from_file ("View/game.glade");
        //Initilizing the window
    gameWindow = GTK_WIDGET(gtk_builder_get_object(builderGame, "game_window"));
        //Connecting the sinal to close the window
    g_signal_connect(gameWindow, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(gameWindow, "destroy", G_CALLBACK(endTimeCounting), NULL);
	g_signal_connect(gameWindow, "destroy", G_CALLBACK(saveGame), NULL);
        //Creating the builder stack
    gtk_builder_connect_signals(builderGame, NULL);
        //building the widgets
    game_layout = GTK_WIDGET(gtk_builder_get_object(builderGame, "game_layout"));
    label_player_name = GTK_WIDGET(gtk_builder_get_object(builderGame, "label_player_name"));
       //Seting the labe text to the players name
    gtk_label_set_text(GTK_LABEL(label_player_name), (const gchar*) player_name);
    game_grid = GTK_WIDGET(gtk_builder_get_object(builderGame, "game_grid"));
    btn_save_game = GTK_WIDGET(gtk_builder_get_object(builderGame, "btn_save_game"));
    btn_player_is_done = GTK_WIDGET(gtk_builder_get_object(builderGame, "btn_player_is_done"));
        //Makeing GTK see all the gtk entry game cells
		//0 line 
        index_00 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_00"));
        index_01 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_01"));
        index_02 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_02"));
        index_03 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_03"));
        index_04 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_04"));
        index_05 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_05"));
        index_06 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_06"));
        index_07 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_07"));
        index_08 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_08"));
		//1 line 
        index_10 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_10"));
        index_11 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_11"));
        index_12 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_12"));
        index_13 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_13"));
        index_14 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_14"));
        index_15 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_15"));
        index_16 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_16"));
        index_17 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_17"));
        index_18 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_18"));
		//2 line 
        index_20 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_20"));
        index_21 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_21"));
        index_22 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_22"));
        index_23 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_23"));
        index_24 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_24"));
        index_25 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_25"));
        index_26 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_26"));
        index_27 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_27"));
        index_28 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_28"));
		//3 line 
        index_30 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_30"));
        index_31 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_31"));
        index_32 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_32"));
        index_33 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_33"));
        index_34 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_34"));
        index_35 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_35"));
        index_36 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_36"));
        index_37 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_37"));
        index_38 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_38"));
		//4 line 
        index_40 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_40"));
        index_41 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_41"));
        index_42 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_42"));
        index_43 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_43"));
        index_44 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_44"));
        index_45 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_45"));
        index_46 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_46"));
        index_47 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_47"));
        index_48 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_48"));
		//5 line 
        index_50 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_50"));
        index_51 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_51"));
        index_52 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_52"));
        index_53 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_53"));
        index_54 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_54"));
        index_55 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_55"));
        index_56 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_56"));
        index_57 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_57"));
        index_58 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_58"));
		//6 line 
        index_60 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_60"));
        index_61 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_61"));
        index_62 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_62"));
        index_63 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_63"));
        index_64 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_64"));
        index_65 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_65"));
        index_66 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_66"));
        index_67 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_67"));
        index_68 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_68"));
		//7 line 
        index_70 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_70"));
        index_71 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_71"));
        index_72 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_72"));
        index_73 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_73"));
        index_74 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_74"));
        index_75 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_75"));
        index_76 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_76"));
        index_77 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_77"));
        index_78 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_78"));
		//8 line 
        index_80 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_80"));
        index_81 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_81"));
        index_82 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_82"));
        index_83 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_83"));
        index_84 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_84"));
        index_85 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_85"));
        index_86 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_86"));
        index_87 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_87"));
        index_88 = GTK_WIDGET(gtk_builder_get_object(builderGame,"index_88"));
        
	//Function that puts the firts sudoku numbers into the gtk entrys
    	setSudokuValues();
	//creat_game_player.player_board matrix();
	//showing everything
    	gtk_widget_show(gameWindow);

    gtk_main();

}

 //******************game window btns functions****************************************
//SAVE GAME
G_MODULE_EXPORT void on_btn_save_game_clicked (GtkButton *save_game){
    g_print ("GAME SAVED \n");
    saveGame();
}

//SAVE GAME
G_MODULE_EXPORT void on_btn_player_is_done_clicked (GtkButton *is_done){
    //To verify if the sudoku is correct
    if(entire_sudoku_solver(player.player_board) == 'w'){
		GtkWidget *dialog;
		dialog = gtk_message_dialog_new (GTK_WINDOW(gameWindow),
                                 GTK_DIALOG_DESTROY_WITH_PARENT,
                                 GTK_MESSAGE_ERROR,
                                 GTK_BUTTONS_CLOSE,
                                 "Ta erradito");
		gtk_dialog_run (GTK_DIALOG (dialog));
	/* Destroy the dialog when the user responds to it (e.g. clicks a button) */
	g_signal_connect_swapped (dialog, "response", G_CALLBACK (gtk_widget_destroy), dialog);
	
	}
	 
	else if(entire_sudoku_solver(player.player_board) == 'r'){
		GtkWidget *dialog;
		dialog = gtk_message_dialog_new (GTK_WINDOW(gameWindow),
                                 GTK_DIALOG_DESTROY_WITH_PARENT,
                                 GTK_MESSAGE_ERROR,
                                 GTK_BUTTONS_CLOSE,
                                 "GANHOU SEU LINDO");
		gtk_dialog_run (GTK_DIALOG (dialog));
	/* Destroy the dialog when the user responds to it (e.g. clicks a button) */
	g_signal_connect_swapped (dialog, "response", G_CALLBACK (gtk_widget_destroy), dialog);
	strcpy(bestTime[3].name, player.player_name);
    bestTime[3].difficulty = player.difficulty;
    bestTime[3].time = player.currentTimeStamp;
	endTimeCounting();
	
	loadBestTimes(); 
   	threeBestTimes();
	}
    //To compare and store the timestamp if its smaller than the others
	
	saveGame();
	gtk_widget_destroy(gameWindow);
}


//******************gtk entry game cells functions****************************************
//**gtk_label_set_text(GTK_LABEL(label_player_name), (const gchar*) player_name);**********
G_MODULE_EXPORT void setSudokuValues(){
	char value[1];
//0 line:
	//index00
	if (player.player_board[0][0] > 0){
		value[0] = player.player_board[0][0] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_00), (const gchar*) value);
	}
	//index01
	if (player.player_board[0][1] > 0){
		value[0] = player.player_board[0][1] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_01), (const gchar*) value);
	}
	//index02
	if (player.player_board[0][2] > 0){
		value[0] = player.player_board[0][2] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_02), (const gchar*) value);
	}
	//index03
	if (player.player_board[0][3] > 0){
		value[0] = player.player_board[0][3] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_03), (const gchar*) value);
	}
	//index04
	if (player.player_board[0][4] > 0){
		value[0] = player.player_board[0][4] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_04), (const gchar*) value);
	}
	//index05
	if (player.player_board[0][5] > 0){
		value[0] = player.player_board[0][5] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_05), (const gchar*) value);
	}
	//index06
	if (player.player_board[0][6] > 0){
		value[0] = player.player_board[0][6] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_06), (const gchar*) value);
	}
	//index07
	if (player.player_board[0][7] > 0){
		value[0] = player.player_board[0][7] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_07), (const gchar*) value);
	}
	//index08
	if (player.player_board[0][8] > 0){
		value[0] = player.player_board[0][8] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_08), (const gchar*) value);
	}
//1 line:
	//index10
	if (player.player_board[1][0] > 0){
		value[0] = player.player_board[1][0] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_10), (const gchar*) value);
	}
	//index11
	if (player.player_board[1][1] > 0){
		value[0] = player.player_board[1][1] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_11), (const gchar*) value);
	}
	//index12
	if (player.player_board[1][2] > 0){
		value[0] = player.player_board[1][2] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_12), (const gchar*) value);
	}
	//index13
	if (player.player_board[1][3] > 0){
		value[0] = player.player_board[1][3] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_13), (const gchar*) value);
	}
	//index14
	if (player.player_board[1][4] > 0){
		value[0] = player.player_board[1][4] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_14), (const gchar*) value);
	}
	//index15
	if (player.player_board[1][5] > 0){
		value[0] = player.player_board[1][5] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_15), (const gchar*) value);
	}
	//index16
	if (player.player_board[1][6] > 0){
		value[0] = player.player_board[1][6] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_16), (const gchar*) value);
	}
	//index17
	if (player.player_board[1][7] > 0){
		value[0] = player.player_board[1][7] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_17), (const gchar*) value);
	}
	//index18
	if (player.player_board[1][8] > 0){
		value[0] = player.player_board[1][8] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_18), (const gchar*) value);
	}   

//2 line:
	//index20
	if (player.player_board[2][0] > 0){
		value[0] = player.player_board[2][0] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_20), (const gchar*) value);
	}
	//index21
	if (player.player_board[2][1] > 0){
		value[0] = player.player_board[2][1] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_21), (const gchar*) value);
	}
	//index22
	if (player.player_board[2][2] > 0){
		value[0] = player.player_board[2][2] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_22), (const gchar*) value);
	}
	//index23
	if (player.player_board[2][3] > 0){
		value[0] = player.player_board[2][3] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_23), (const gchar*) value);
	}
	//index24
	if (player.player_board[2][4] > 0){
		value[0] = player.player_board[2][4] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_24), (const gchar*) value);
	}
	//index25
	if (player.player_board[2][5] > 0){
		value[0] = player.player_board[2][5] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_25), (const gchar*) value);
	}
	//index26
	if (player.player_board[2][6] > 0){
		value[0] = player.player_board[2][6] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_26), (const gchar*) value);
	}
	//index27
	if (player.player_board[2][7] > 0){
		value[0] = player.player_board[2][7] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_27), (const gchar*) value);
	}
	//index28
	if (player.player_board[2][8] > 0){
		value[0] = player.player_board[2][8] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_28), (const gchar*) value);
	}
//3 line:
	//index30
	if (player.player_board[3][0] > 0){
		value[0] = player.player_board[3][0] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_30), (const gchar*) value);
	}
	//index31
	if (player.player_board[3][1] > 0){
		value[0] = player.player_board[3][1] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_31), (const gchar*) value);
	}
	//index32
	if (player.player_board[3][2] > 0){
		value[0] = player.player_board[3][2] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_32), (const gchar*) value);
	}
	//index33
	if (player.player_board[3][3] > 0){
		value[0] = player.player_board[3][3] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_33), (const gchar*) value);
	}
	//index34
	if (player.player_board[3][4] > 0){
		value[0] = player.player_board[3][4] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_34), (const gchar*) value);
	}
	//index35
	if (player.player_board[3][5] > 0){
		value[0] = player.player_board[3][5] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_35), (const gchar*) value);
	}
	//index36
	if (player.player_board[3][6] > 0){
		value[0] = player.player_board[3][6] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_36), (const gchar*) value);
	}
	//index37
	if (player.player_board[3][7] > 0){
		value[0] = player.player_board[3][7] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_37), (const gchar*) value);
	}
	//index38
	if (player.player_board[3][8] > 0){
		value[0] = player.player_board[3][8] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_38), (const gchar*) value);
	}
//4 line:
	//index40
	if (player.player_board[4][0] > 0){
		value[0] = player.player_board[4][0] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_40), (const gchar*) value);
	}
	//index41
	if (player.player_board[4][1] > 0){
		value[0] = player.player_board[4][1] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_41), (const gchar*) value);
	}
	//index42
	if (player.player_board[4][2] > 0){
		value[0] = player.player_board[4][2] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_42), (const gchar*) value);
	}
	//index43
	if (player.player_board[4][3] > 0){
		value[0] = player.player_board[4][3] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_43), (const gchar*) value);
	}
	//index44
	if (player.player_board[4][4] > 0){
		value[0] = player.player_board[4][4] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_44), (const gchar*) value);
	}
	//index45
	if (player.player_board[4][5] > 0){
		value[0] = player.player_board[4][5] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_45), (const gchar*) value);
	}
	//index46
	if (player.player_board[4][6] > 0){
		value[0] = player.player_board[4][6] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_46), (const gchar*) value);
	}
	//index47
	if (player.player_board[4][7] > 0){
		value[0] = player.player_board[4][7] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_47), (const gchar*) value);
	}
	//index48
	if (player.player_board[4][8] > 0){
		value[0] = player.player_board[4][8] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_48), (const gchar*) value);
	}
//5 line:
	//index50
	if (player.player_board[5][0] > 0){
		value[0] = player.player_board[5][0] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_50), (const gchar*) value);
	}
	//index51
	if (player.player_board[5][1] > 0){
		value[0] = player.player_board[5][1] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_51), (const gchar*) value);
	}
	//index52
	if (player.player_board[5][2] > 0){
		value[0] = player.player_board[5][2] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_52), (const gchar*) value);
	}
	//index53
	if (player.player_board[5][3] > 0){
		value[0] = player.player_board[5][3] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_53), (const gchar*) value);
	}
	//index54
	if (player.player_board[5][4] > 0){
		value[0] = player.player_board[5][4] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_54), (const gchar*) value);
	}
	//index55
	if (player.player_board[5][5] > 0){
		value[0] = player.player_board[5][5] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_55), (const gchar*) value);
	}
	//index56
	if (player.player_board[5][6] > 0){
		value[0] = player.player_board[5][6] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_56), (const gchar*) value);
	}
	//index57
	if (player.player_board[5][7] > 0){
		value[0] = player.player_board[5][7] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_57), (const gchar*) value);
	}
	//index58
	if (player.player_board[5][8] > 0){
		value[0] = player.player_board[5][8] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_58), (const gchar*) value);
	}    

//6 line:
	//index60
	if (player.player_board[6][0] > 0){
		value[0] = player.player_board[6][0] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_60), (const gchar*) value);
	}
	//index61
	if (player.player_board[6][1] > 0){
		value[0] = player.player_board[6][1] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_61), (const gchar*) value);
	}
	//index62
	if (player.player_board[6][2] > 0){
		value[0] = player.player_board[6][2] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_62), (const gchar*) value);
	}
	//index63
	if (player.player_board[6][3] > 0){
		value[0] = player.player_board[6][3] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_63), (const gchar*) value);
	}
	//index64
	if (player.player_board[6][4] > 0){
		value[0] = player.player_board[6][4] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_64), (const gchar*) value);
	}
	//index65
	if (player.player_board[6][5] > 0){
		value[0] = player.player_board[6][5] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_65), (const gchar*) value);
	}
	//index66
	if (player.player_board[6][6] > 0){
		value[0] = player.player_board[6][6] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_66), (const gchar*) value);
	}
	//index67
	if (player.player_board[6][7] > 0){
		value[0] = player.player_board[6][7] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_67), (const gchar*) value);
	}
	//index68
	if (player.player_board[6][8] > 0){
		value[0] = player.player_board[6][8] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_68), (const gchar*) value);
	} 
//7 line:
	//index70
	if (player.player_board[7][0] > 0){
		value[0] = player.player_board[7][0] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_70), (const gchar*) value);
	}
	//index71
	if (player.player_board[7][1] > 0){
		value[0] = player.player_board[7][1] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_71), (const gchar*) value);
	}
	//index72
	if (player.player_board[7][2] > 0){
		value[0] = player.player_board[7][2] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_72), (const gchar*) value);
	}
	//index73
	if (player.player_board[7][3] > 0){
		value[0] = player.player_board[7][3] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_73), (const gchar*) value);
	}
	//index74
	if (player.player_board[7][4] > 0){
		value[0] = player.player_board[7][4] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_74), (const gchar*) value);
	}
	//index75
	if (player.player_board[7][5] > 0){
		value[0] = player.player_board[7][5] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_75), (const gchar*) value);
	}
	//index76
	if (player.player_board[7][6] > 0){
		value[0] = player.player_board[7][6] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_76), (const gchar*) value);
	}
	//index77
	if (player.player_board[7][7] > 0){
		value[0] = player.player_board[7][7] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_77), (const gchar*) value);
	}
	//index78
	if (player.player_board[7][8] > 0){
		value[0] = player.player_board[7][8] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_78), (const gchar*) value);
	}
//8 line:
	//index80
	if (player.player_board[8][0] > 0){
		value[0] = player.player_board[8][0] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_80), (const gchar*) value);
	}
	//index81
	if (player.player_board[8][1] > 0){
		value[0] = player.player_board[8][1] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_81), (const gchar*) value);
	}
	//index82
	if (player.player_board[8][2] > 0){
		value[0] = player.player_board[8][2] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_82), (const gchar*) value);
	}
	//index83
	if (player.player_board[8][3] > 0){
		value[0] = player.player_board[8][3] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_83), (const gchar*) value);
	}
	//index84
	if (player.player_board[8][4] > 0){
		value[0] = player.player_board[8][4] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_84), (const gchar*) value);
	}
	//index85
	if (player.player_board[8][5] > 0){
		value[0] = player.player_board[8][5] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_85), (const gchar*) value);
	}
	//index86
	if (player.player_board[8][6] > 0){
		value[0] = player.player_board[8][6] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_86), (const gchar*) value);
	}
	//index87
	if (player.player_board[8][7] > 0){
		value[0] = player.player_board[8][7] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_87), (const gchar*) value);
	}
	//index88
	if (player.player_board[8][8] > 0){
		value[0] = player.player_board[8][8] + 48;
    	gtk_entry_set_text(GTK_ENTRY(index_88), (const gchar*) value);
	}
} 

//Functions to detect the entry and add the value to the player.player_boardrix
//0 line 
G_MODULE_EXPORT void on_index_00_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[0][0] = (int)temp[0] - 48;
	g_print("Index 00 mod = %d\n", player.player_board[0][0]);
	}
G_MODULE_EXPORT void on_index_01_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[0][1] = (int)temp[0] - 48;
	g_print("Index 01 mod = %d\n", player.player_board[0][1]);
	}
G_MODULE_EXPORT void on_index_02_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[0][2] = (int)temp[0] - 48;
	g_print("Index 02 mod = %d\n", player.player_board[0][2]);
	}
G_MODULE_EXPORT void on_index_03_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[0][3] = (int)temp[0] - 48;
	g_print("Index 03 mod = %d\n", player.player_board[0][3]);
	}
G_MODULE_EXPORT void on_index_04_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[0][4] = (int)temp[0] - 48;
	g_print("Index 04 mod = %d\n", player.player_board[0][4]);
	}
G_MODULE_EXPORT void on_index_05_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[0][5] = (int)temp[0] - 48;
	g_print("Index 05 mod = %d\n", player.player_board[0][5]);
	}
G_MODULE_EXPORT void on_index_06_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[0][6] = (int)temp[0] - 48;
	g_print("Index 06 mod = %d\n", player.player_board[0][6]);
	}
G_MODULE_EXPORT void on_index_07_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[0][7] = (int)temp[0] - 48;
	g_print("Index 07 mod = %d\n", player.player_board[0][7]);
	}
G_MODULE_EXPORT void on_index_08_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[0][8] = (int)temp[0] - 48;
	g_print("Index 08 mod = %d\n", player.player_board[0][8]);
	}


//1 line
G_MODULE_EXPORT void on_index_10_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[1][0] = (int)temp[0] - 48;
	g_print("Index 10 mod = %d\n", player.player_board[1][0]);
	}
G_MODULE_EXPORT void on_index_11_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[1][1] = (int)temp[0] - 48;
	g_print("Index 11 mod = %d\n", player.player_board[1][1]);
	}
G_MODULE_EXPORT void on_index_12_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[1][2] = (int)temp[0] - 48;
	g_print("Index 12 mod = %d\n", player.player_board[1][2]);
	}
G_MODULE_EXPORT void on_index_13_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[1][3] = (int)temp[0] - 48;
	g_print("Index 13 mod = %d\n", player.player_board[1][3]);
	}
G_MODULE_EXPORT void on_index_14_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[1][4] = (int)temp[0] - 48;
	g_print("Index 14 mod = %d\n", player.player_board[1][4]);
	}
G_MODULE_EXPORT void on_index_15_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[1][5] = (int)temp[0] - 48;
	g_print("Index 15 mod = %d\n", player.player_board[1][5]);
	}
G_MODULE_EXPORT void on_index_16_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[1][6] = (int)temp[0] - 48;
	g_print("Index 16 mod = %d\n", player.player_board[1][6]);
	}
G_MODULE_EXPORT void on_index_17_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[1][7] = (int)temp[0] - 48;
	g_print("Index 17 mod = %d\n", player.player_board[1][7]);
	}
G_MODULE_EXPORT void on_index_18_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[1][8] = (int)temp[0] - 48;
	g_print("Index 18 mod = %d\n", player.player_board[1][8]);
	}
//2 line
G_MODULE_EXPORT void on_index_20_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[2][0] = (int)temp[0] - 48;
	g_print("Index 20 mod = %d\n", player.player_board[2][0]);
	}
G_MODULE_EXPORT void on_index_21_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[2][1] = (int)temp[0] - 48;
	g_print("Index 21 mod = %d\n", player.player_board[2][1]);
	}
G_MODULE_EXPORT void on_index_22_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[2][2] = (int)temp[0] - 48;
	g_print("Index 22 mod = %d\n", player.player_board[2][2]);
	}
G_MODULE_EXPORT void on_index_23_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[2][3] = (int)temp[0] - 48;
	g_print("Index 23 mod = %d\n", player.player_board[2][3]);
	}
G_MODULE_EXPORT void on_index_24_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[2][4] = (int)temp[0] - 48;
	g_print("Index 24 mod = %d\n", player.player_board[2][4]);
	}
G_MODULE_EXPORT void on_index_25_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[2][5] = (int)temp[0] - 48;
	g_print("Index 25 mod = %d\n", player.player_board[2][5]);
	}
G_MODULE_EXPORT void on_index_26_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[2][6] = (int)temp[0] - 48;
	g_print("Index 26 mod = %d\n", player.player_board[2][6]);
	}
G_MODULE_EXPORT void on_index_27_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[2][7] = (int)temp[0] - 48;
	g_print("Index 27 mod = %d\n", player.player_board[2][7]);
	}
G_MODULE_EXPORT void on_index_28_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[2][8] = (int)temp[0] - 48;
	g_print("Index 28 mod = %d\n", player.player_board[2][8]);
	}
//3 line
G_MODULE_EXPORT void on_index_30_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[3][0] = (int)temp[0] - 48;
	g_print("Index 30 mod = %d\n", player.player_board[3][0]);
	}
G_MODULE_EXPORT void on_index_31_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[3][1] = (int)temp[0] - 48;
	g_print("Index [3][1]  mod = %d\n", player.player_board[3][1] );
	}
G_MODULE_EXPORT void on_index_32_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[3][2] = (int)temp[0] - 48;
	g_print("Index [3][2]  mod = %d\n", player.player_board[3][2]);
	}
G_MODULE_EXPORT void on_index_33_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[3][3] = (int)temp[0] - 48;
	g_print("Index [3][3]  mod = %d\n", player.player_board[3][3]);
	}
G_MODULE_EXPORT void on_index_34_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[3][4] = (int)temp[0] - 48;
	g_print("Index [3][4]  mod = %d\n", player.player_board[3][4]);
	}
G_MODULE_EXPORT void on_index_35_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[3][5] = (int)temp[0] - 48;
	g_print("Index [3][5]  mod = %d\n", player.player_board[3][5]);
	}
G_MODULE_EXPORT void on_index_36_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[3][6] = (int)temp[0] - 48;
	g_print("Index [3][6]  mod = %d\n", player.player_board[3][6]);
	}
G_MODULE_EXPORT void on_index_37_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[3][7] = (int)temp[0] - 48;
	g_print("Index [3][7]  mod = %d\n", player.player_board[3][7]);
	}
G_MODULE_EXPORT void on_index_38_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[3][8] = (int)temp[0] - 48;
	g_print("Index [3][8]  mod = %d\n", player.player_board[3][8]);
	}
//4 line
G_MODULE_EXPORT void on_index_40_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[4][0] = (int)temp[0] - 48;
	g_print("Index [4][0]  mod = %d\n", player.player_board[4][0]);
	}
G_MODULE_EXPORT void on_index_41_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[4][1] = (int)temp[0] - 48;
	g_print("Index [4][1]  mod = %d\n", player.player_board[4][1]);
	}
G_MODULE_EXPORT void on_index_42_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[4][2] = (int)temp[0] - 48;
	g_print("Index [4][2]  mod = %d\n", player.player_board[4][2]);
	}
G_MODULE_EXPORT void on_index_43_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[4][3] = (int)temp[0] - 48;
	g_print("Index [4][3]  mod = %d\n", player.player_board[4][3]);
	}
G_MODULE_EXPORT void on_index_44_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[4][4] = (int)temp[0] - 48;
	g_print("Index [4][4]  mod = %d\n", player.player_board[4][4]);
	}
G_MODULE_EXPORT void on_index_45_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[4][5] = (int)temp[0] - 48;
	g_print("Index [4][5]  mod = %d\n", player.player_board[4][5]);
	}
G_MODULE_EXPORT void on_index_46_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[4][6] = (int)temp[0] - 48;
	g_print("Index [4][6]  mod = %d\n", player.player_board[4][6]);
	}
G_MODULE_EXPORT void on_index_47_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[4][7] = (int)temp[0] - 48;
	g_print("Index [4][7]  mod = %d\n", player.player_board[4][7]);
	}
G_MODULE_EXPORT void on_index_48_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[4][8] = (int)temp[0] - 48;
	g_print("Index [4][8]  mod = %d\n", player.player_board[4][8]);
	}
//5 line
G_MODULE_EXPORT void on_index_50_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[5][0] = (int)temp[0] - 48;
	g_print("Index [5][0]  mod = %d\n", player.player_board[5][0]);
	}
G_MODULE_EXPORT void on_index_51_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[5][1] = (int)temp[0] - 48;
	g_print("Index [5][1]  mod = %d\n", player.player_board[5][1]);
	}
G_MODULE_EXPORT void on_index_52_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[5][2] = (int)temp[0] - 48;
	g_print("Index [5][2]  mod = %d\n", player.player_board[5][2]);
	}
G_MODULE_EXPORT void on_index_53_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[5][3] = (int)temp[0] - 48;
	g_print("Index [5][3]  mod = %d\n", player.player_board[5][3]);
	}
G_MODULE_EXPORT void on_index_54_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[5][4] = (int)temp[0] - 48;
	g_print("Index [5][4]  mod = %d\n", player.player_board[5][4]);
	}
G_MODULE_EXPORT void on_index_55_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[5][5] = (int)temp[0] - 48;
	g_print("Index [5][5]  mod = %d\n", player.player_board[5][5]);
	}
G_MODULE_EXPORT void on_index_56_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[5][6] = (int)temp[0] - 48;
	g_print("Index [5][6]  mod = %d\n", player.player_board[5][6]);
	}
G_MODULE_EXPORT void on_index_57_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[5][7] = (int)temp[0] - 48;
	g_print("Index [5][7]  mod = %d\n", player.player_board[5][7]);
	}
G_MODULE_EXPORT void on_index_58_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[5][8] = (int)temp[0] - 48;
	g_print("Index [5][8]  mod = %d\n", player.player_board[5][8]);
	}
//6 line
G_MODULE_EXPORT void on_index_60_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[6][0] = (int)temp[0] - 48;
	g_print("Index [6][0]  mod = %d\n", player.player_board[6][0]);
	}
G_MODULE_EXPORT void on_index_61_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[6][1] = (int)temp[0] - 48;
	g_print("Index [6][1]  mod = %d\n", player.player_board[6][1]);
	}
G_MODULE_EXPORT void on_index_62_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[6][2] = (int)temp[0] - 48;
	g_print("Index [6][2]  mod = %d\n", player.player_board[6][2]);
	}
G_MODULE_EXPORT void on_index_63_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[6][3] = (int)temp[0] - 48;
	g_print("Index [6][3]  mod = %d\n", player.player_board[6][3]);
	}
G_MODULE_EXPORT void on_index_64_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[6][4] = (int)temp[0] - 48;
	g_print("Index [6][4]  mod = %d\n", player.player_board[6][4]);
	}
G_MODULE_EXPORT void on_index_65_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[6][5] = (int)temp[0] - 48;
	g_print("Index [6][5]  mod = %d\n", player.player_board[6][5]);
	}
G_MODULE_EXPORT void on_index_66_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[6][6] = (int)temp[0] - 48;
	g_print("Index [6][6]  mod = %d\n", player.player_board[6][6]);
	}
G_MODULE_EXPORT void on_index_67_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[6][7] = (int)temp[0] - 48;
	g_print("Index [6][7]  mod = %d\n", player.player_board[6][7]);
	}
G_MODULE_EXPORT void on_index_68_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[6][8] = (int)temp[0] - 48;
	g_print("Index [6][8]  mod = %d\n", player.player_board[6][8]);
	}
//7 line
G_MODULE_EXPORT void on_index_70_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[7][0] = (int)temp[0] - 48;
	g_print("Index [7][0]  mod = %d\n", player.player_board[7][0]);
	}
G_MODULE_EXPORT void on_index_71_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[7][1] = (int)temp[0] - 48;
	g_print("Index [7][1]  mod = %d\n", player.player_board[7][1]);
	}
G_MODULE_EXPORT void on_index_72_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[7][2] = (int)temp[0] - 48;
	g_print("Index [7][2]  mod = %d\n", player.player_board[7][2]);
	}
G_MODULE_EXPORT void on_index_73_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[7][3] = (int)temp[0] - 48;
	g_print("Index [7][3]  mod = %d\n", player.player_board[7][3]);
	}
G_MODULE_EXPORT void on_index_74_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[7][4] = (int)temp[0] - 48;
	g_print("Index [7][4]  mod = %d\n", player.player_board[7][4]);
	}
G_MODULE_EXPORT void on_index_75_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[7][5] = (int)temp[0] - 48;
	g_print("Index [7][5]  mod = %d\n", player.player_board[7][5]);
	}
G_MODULE_EXPORT void on_index_76_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[7][6] = (int)temp[0] - 48;
	g_print("Index [7][6]  mod = %d\n", player.player_board[7][6]);
	}
G_MODULE_EXPORT void on_index_77_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[7][7] = (int)temp[0] - 48;
	g_print("Index [7][7]  mod = %d\n", player.player_board[7][7]);
	}
G_MODULE_EXPORT void on_index_78_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[7][8] = (int)temp[0] - 48;
	g_print("Index [7][8]  mod = %d\n", player.player_board[7][8]);
	}
//8 line
G_MODULE_EXPORT void on_index_80_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[8][0] = (int)temp[0] - 48;
	g_print("Index [8][0]  mod = %d\n", player.player_board[8][0]);
	}
G_MODULE_EXPORT void on_index_81_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[8][1] = (int)temp[0] - 48;
	g_print("Index [8][1]  mod = %d\n", player.player_board[8][1]);
	}
G_MODULE_EXPORT void on_index_82_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[8][2] = (int)temp[0] - 48;
	g_print("Index [8][2]  mod = %d\n", player.player_board[8][2]);
	}
G_MODULE_EXPORT void on_index_83_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[8][3] = (int)temp[0] - 48;
	g_print("Index [8][3]  mod = %d\n", player.player_board[8][3]);
	}
G_MODULE_EXPORT void on_index_84_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[8][4] = (int)temp[0] - 48;
	g_print("Index [8][4]  mod = %d\n", player.player_board[8][4]);
	}
G_MODULE_EXPORT void on_index_85_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[8][5] = (int)temp[0] - 48;
	g_print("Index [8][5]  mod = %d\n", player.player_board[8][5]);
	}
G_MODULE_EXPORT void on_index_86_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[8][6] = (int)temp[0] - 48;
	g_print("Index [8][6]  mod = %d\n", player.player_board[8][6]);
	}
G_MODULE_EXPORT void on_index_87_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[8][7] = (int)temp[0] - 48;
	g_print("Index [8][7]  mod = %d\n", player.player_board[8][7]);
	}
G_MODULE_EXPORT void on_index_88_changed(GtkEntry *entry) {
    char temp[1];
    strcpy(temp, gtk_entry_get_text(entry));
	player.player_board[8][8] = (int)temp[0] - 48;
	g_print("Index [8][8]  mod = %d\n", player.player_board[8][8]);
	}
