 #include "./readWriteAndSolver.h"
 #include <gtk/gtk.h>

G_MODULE_EXPORT int entire_sudoku_solver( int matrix[9][9]);
G_MODULE_EXPORT void createNewGame(int difficulty);
G_MODULE_EXPORT int saveGame(void);
G_MODULE_EXPORT void loadGameSave(char player_name[playerName_Size]);
G_MODULE_EXPORT void threeBestTimes(void);
G_MODULE_EXPORT void loadBestTimes(void);

G_MODULE_EXPORT int entire_sudoku_solver( int matrix[9][9]) {
	int i, i2, i3;
	char right_or_wrong='r';
	
		/* Analyse if exists equal numbers in each column */
	
	for(i=0; i<8; i++) {
		for(i2=i+1; i2<9;i2 ++) { 
			if (matrix[i][0] == matrix[i2][0])
				right_or_wrong='w';
		}
	}
	
	for(i=0; i<8; i++) {
		for(i2=i+1; i2<9;i2 ++) { 
			if (matrix[i][1] == matrix[i2][1])
				right_or_wrong='w';
		}
	}

	for(i=0; i<8; i++) {
		for(i2=i+1; i2<9;i2 ++) { 
			if (matrix[i][2] == matrix[i2][2])
				right_or_wrong='w';
		}
	}

	for(i=0; i<8; i++) {
		for(i2=i+1; i2<9;i2 ++) { 
			if (matrix[i][3] == matrix[i2][3])
				right_or_wrong='w';
		}
	}	

	for(i=0; i<8; i++) {
		for(i2=i+1; i2<9;i2 ++) { 
			if (matrix[i][4] == matrix[i2][4])
				right_or_wrong='w';
		}
	}	

	for(i=0; i<8; i++) {
		for(i2=i+1; i2<9;i2 ++) { 
			if (matrix[i][5] == matrix[i2][5])
				right_or_wrong='w';
		}
	}	

	for(i=0; i<8; i++) {
		for(i2=i+1; i2<9;i2 ++) { 
			if (matrix[i][6] == matrix[i2][6])
				right_or_wrong='w';
		}
	}	

	for(i=0; i<8; i++) {
		for(i2=i+1; i2<9;i2 ++) { 
			if (matrix[i][7] == matrix[i2][7])
				right_or_wrong='w';
		}
	}	

	for(i=0; i<8; i++) {
		for(i2=i+1; i2<9;i2 ++) { 
			if (matrix[i][8] == matrix[i2][8])
				right_or_wrong='w';
		}
	}

		/* Analyse if exists equal numbers in each line */

	for(i=0; i<8; i++) {
		for(i2=i+1; i2<9;i2 ++) { 
			if (matrix[0][i] == matrix[0][i2])
				right_or_wrong='w';
		}
	}
	
	for(i=0; i<8; i++) {
		for(i2=i+1; i2<9;i2 ++) { 
			if (matrix[1][i] == matrix[1][i2])
				right_or_wrong='w';
		}
	}

	for(i=0; i<8; i++) {
		for(i2=i+1; i2<9;i2 ++) { 
			if (matrix[2][i] == matrix[2][i2])
				right_or_wrong='w';
		}
	}

	for(i=0; i<8; i++) {
		for(i2=i+1; i2<9;i2 ++) { 
			if (matrix[3][i] == matrix[3][i2])
				right_or_wrong='w';
		}
	}	

	for(i=0; i<8; i++) {
		for(i2=i+1; i2<9;i2 ++) { 
			if (matrix[4][i] == matrix[4][i2])
				right_or_wrong='w';
		}
	}	

	for(i=0; i<8; i++) {
		for(i2=i+1; i2<9;i2 ++) { 
			if (matrix[5][i] == matrix[5][i2])
				right_or_wrong='w';
		}
	}	

	for(i=0; i<8; i++) {
		for(i2=i+1; i2<9;i2 ++) { 
			if (matrix[6][i] == matrix[6][i2])
				right_or_wrong='w';
		}
	}	

	for(i=0; i<8; i++) {
		for(i2=i+1; i2<9;i2 ++) { 
			if (matrix[7][i] == matrix[7][i2])
				right_or_wrong='w';
		}
	}	

	for(i=0; i<8; i++) {
		for(i2=i+1; i2<9;i2 ++) { 
			if (matrix[8][i] == matrix[8][i2])
				right_or_wrong='w';
		}
	}
	

		/*Analyse if exists equal elements in the first 3x3 cell */

	for(i=1; i<3; i++) {
		for(i2=0; i2<3; i2++) {
			if(matrix[0][0] == matrix[i][i2])
				right_or_wrong='w';			
			for(i3=1; i3<3;i3++){
				if(matrix[0][0] == matrix[0][i3])
				right_or_wrong='w';			
			}
		}
	}
	
	for(i=1; i<3; i++) {
		for(i2=0; i2<3; i2++) {
			if(matrix[0][1] == matrix[i][i2])
				right_or_wrong='w';			
			for(i3=2; i3<3;i3++){
				if(matrix[0][1] == matrix[0][i3])
					right_or_wrong='w';			
			}
		}
	}

	for(i=1; i<3; i++) {
		for(i2=0; i2<3; i2++) {
			if(matrix[0][2] == matrix[i][i2])
				right_or_wrong='w';
			
		}
	}

	for(i=2; i<3; i++) {
		for(i2=0; i2<3; i2++) {
			if(matrix[1][0] == matrix[i][i2])
				right_or_wrong='w';
			
			for(i3=1; i3<3;i3++){
				if(matrix[1][0] == matrix[1][i3])
					right_or_wrong='w';
			}
		}
	}

	for(i=2; i<3; i++) {
		for(i2=0; i2<3; i2++) {
			if(matrix[1][1] == matrix[i][i2])
				right_or_wrong='w';
			
			for(i3=2; i3<3;i3++){
				if(matrix[1][1] == matrix[1][i3])
					right_or_wrong='w';
			}
		}
	}

	for(i=2; i<3; i++) {
		for(i2=0; i2<3; i2++) {
			if(matrix[1][2] == matrix[i][i2])
				right_or_wrong='w';
			
		}
	}

	for(i=2; i<3; i++) {
		for(i2=1; i2<3; i2++) {
			if(matrix[2][0] == matrix[i][i2])
				right_or_wrong='w';
			
		}
	}

	for(i=2; i<3; i++) {
		for(i2=2; i2<3; i2++) {
			if(matrix[2][1] == matrix[i][i2])
				right_or_wrong='w';
			
		}
	}

		/*Analyse if exists equal elements in the second 3x3 cell */

	for(i=1; i<3; i++) {
		for(i2=3; i2<6; i2++) {
			if(matrix[0][3] == matrix[i][i2])
				right_or_wrong='w';
			
			for(i3=4; i3<6;i3++){
				if(matrix[0][3] == matrix[0][i3])
					right_or_wrong='w';
			}
		}
	}
	
	for(i=1; i<3; i++) {
		for(i2=3; i2<6; i2++) {
			if(matrix[0][4] == matrix[i][i2])
				right_or_wrong='w';
			
			for(i3=5; i3<6;i3++){
				if(matrix[0][4] == matrix[0][i3])
					right_or_wrong='w';
			}
		}
	}

	for(i=1; i<3; i++) {
		for(i2=3; i2<6; i2++) {
			if(matrix[0][5] == matrix[i][i2])
				right_or_wrong='w';
			
		}
	}

	for(i=2; i<3; i++) {
		for(i2=3; i2<6; i2++) {
			if(matrix[1][3] == matrix[i][i2])
				right_or_wrong='w';
			
			for(i3=4; i3<6;i3++){
				if(matrix[1][3] == matrix[1][i3])
					right_or_wrong='w';
			}
		}
	}

	for(i=2; i<3; i++) {
		for(i2=3; i2<6; i2++) {
			if(matrix[1][4] == matrix[i][i2])
				right_or_wrong='w';
			
			for(i3=5; i3<6;i3++){
				if(matrix[1][4] == matrix[1][i3])
					right_or_wrong='w';
			}
		}
	}

	for(i=2; i<3; i++) {
		for(i2=3; i2<6; i2++) {
			if(matrix[1][5] == matrix[i][i2])
				right_or_wrong='w';
			
		}
	}

	for(i=2; i<3; i++) {
		for(i2=4; i2<6; i2++) {
			if(matrix[2][3] == matrix[i][i2])
				right_or_wrong='w';
			
		}
	}

	for(i=2; i<3; i++) {
		for(i2=5; i2<6; i2++) {
			if(matrix[2][4] == matrix[i][i2])
				right_or_wrong='w';
			
		}
	}

		/*Analyse if exists equal elements in the third 3x3 cell */

	for(i=1; i<3; i++) {
		for(i2=6; i2<9; i2++) {
			if(matrix[0][6] == matrix[i][i2])
				right_or_wrong='w';
			
			for(i3=7; i3<9;i3++){
				if(matrix[0][6] == matrix[0][i3])
					right_or_wrong='w';
			}
		}
	}
	
	for(i=1; i<3; i++) {
		for(i2=6; i2<9; i2++) {
			if(matrix[0][7] == matrix[i][i2])
				right_or_wrong='w';
			
			for(i3=8; i3<9;i3++){
				if(matrix[0][7] == matrix[0][i3])
					right_or_wrong='w';
			}
		}
	}

	for(i=1; i<3; i++) {
		for(i2=6; i2<9; i2++) {
			if(matrix[0][8] == matrix[i][i2])
				right_or_wrong='w';
			
		}
	}

	for(i=2; i<3; i++) {
		for(i2=6; i2<9; i2++) {
			if(matrix[1][6] == matrix[i][i2])
				right_or_wrong='w';
			
			for(i3=7; i3<9;i3++){
				if(matrix[1][6] == matrix[1][i3])
					right_or_wrong='w';
			}
		}
	}

	for(i=2; i<3; i++) {
		for(i2=6; i2<9; i2++) {
			if(matrix[1][7] == matrix[i][i2])
				right_or_wrong='w';
			
			for(i3=8; i3<9;i3++){
				if(matrix[1][7] == matrix[1][i3])
					right_or_wrong='w';
			}
		}
	}

	for(i=2; i<3; i++) {
		for(i2=6; i2<9; i2++) {
			if(matrix[1][8] == matrix[i][i2])
				right_or_wrong='w';
			
		}
	}

	for(i=2; i<3; i++) {
		for(i2=7; i2<9; i2++) {
			if(matrix[2][6] == matrix[i][i2])
				right_or_wrong='w';
			
		}
	}

	for(i=2; i<3; i++) {
		for(i2=8; i2<9; i2++) {
			if(matrix[2][7] == matrix[i][i2])
				right_or_wrong='w';
			
		}
	}
		/*Analyse if exists equal elements in the fourth 3x3 cell */

	for(i=4; i<6; i++) {
		for(i2=0; i2<3; i2++) {
			if(matrix[3][0] == matrix[i][i2])
				right_or_wrong='w';
			
			for(i3=1; i3<3;i3++){
				if(matrix[3][0] == matrix[3][i3])
					right_or_wrong='w';
			}
		}
	}
	
	for(i=4; i<6; i++) {
		for(i2=0; i2<3; i2++) {
			if(matrix[3][1] == matrix[i][i2])
				right_or_wrong='w';
			
			for(i3=2; i3<3;i3++){
				if(matrix[3][1] == matrix[3][i3])
					right_or_wrong='w';
			}
		}
	}

	for(i=4; i<6; i++) {
		for(i2=0; i2<3; i2++) {
			if(matrix[3][2] == matrix[i][i2])
				right_or_wrong='w';
			
		}
	}

	for(i=5; i<6; i++) {
		for(i2=0; i2<3; i2++) {
			if(matrix[4][0] == matrix[i][i2])
				right_or_wrong='w';
			
			for(i3=1; i3<3;i3++){
				if(matrix[4][0] == matrix[4][i3])
					right_or_wrong='w';
			}
		}
	}

	for(i=5; i<6; i++) {
		for(i2=0; i2<3; i2++) {
			if(matrix[4][1] == matrix[i][i2])
				right_or_wrong='w';
			
			for(i3=2; i3<3;i3++){
				if(matrix[4][1] == matrix[4][i3])
					right_or_wrong='w';
			}
		}
	}

	for(i=5; i<6; i++) {
		for(i2=0; i2<3; i2++) {
			if(matrix[4][2] == matrix[i][i2])
				right_or_wrong='w';
			
		}
	}

	for(i=5; i<6; i++) {
		for(i2=1; i2<3; i2++) {
			if(matrix[5][0] == matrix[i][i2])
				right_or_wrong='w';
			
		}
	}

	for(i=5; i<6; i++) {
		for(i2=2; i2<3; i2++) {
			if(matrix[5][1] == matrix[i][i2])
				right_or_wrong='w';
			
		}
	}


		/*Analyse if exists equal elements in the fifth 3x3 cell */

	for(i=4; i<6; i++) {
		for(i2=3; i2<6; i2++) {
			if(matrix[3][3] == matrix[i][i2])
				right_or_wrong='w';
			
			for(i3=4; i3<6;i3++){
				if(matrix[3][3] == matrix[3][i3])
					right_or_wrong='w';
			}
		}
	}
	
	for(i=4; i<6; i++) {
		for(i2=3; i2<6; i2++) {
			if(matrix[3][4] == matrix[i][i2])
				right_or_wrong='w';
			
			for(i3=5; i3<6;i3++){
				if(matrix[3][4] == matrix[3][i3])
					right_or_wrong='w';
			}
		}
	}

	for(i=4; i<6; i++) {
		for(i2=3; i2<6; i2++) {
			if(matrix[3][5] == matrix[i][i2])
				right_or_wrong='w';
			
		}
	}

	for(i=5; i<6; i++) {
		for(i2=3; i2<6; i2++) {
			if(matrix[4][3] == matrix[i][i2])
				right_or_wrong='w';
			
			for(i3=4; i3<6;i3++){
				if(matrix[4][3] == matrix[4][i3])
					right_or_wrong='w';
			}
		}
	}

	for(i=5; i<6; i++) {
		for(i2=3; i2<6; i2++) {
			if(matrix[4][4] == matrix[i][i2])
				right_or_wrong='w';
			
			for(i3=5; i3<6;i3++){
				if(matrix[4][4] == matrix[4][i3])
					right_or_wrong='w';
			}
		}
	}

	for(i=5; i<6; i++) {
		for(i2=3; i2<6; i2++) {
			if(matrix[4][5] == matrix[i][i2])
				right_or_wrong='w';
			
		}
	}

	for(i=5; i<6; i++) {
		for(i2=4; i2<6; i2++) {
			if(matrix[5][3] == matrix[i][i2])
				right_or_wrong='w';
			
		}
	}

	for(i=5; i<6; i++) {
		for(i2=5; i2<6; i2++) {
			if(matrix[5][4] == matrix[i][i2])
				right_or_wrong='w';
			
		}
	}

		/*Analyse if exists equal elements in the sixth 3x3 cell */

	for(i=4; i<6; i++) {
		for(i2=6; i2<9; i2++) {
			if(matrix[3][6] == matrix[i][i2])
				right_or_wrong='w';
			
			for(i3=7; i3<9;i3++){
				if(matrix[3][6] == matrix[3][i3])
					right_or_wrong='w';
			}
		}
	}
	
	for(i=4; i<6; i++) {
		for(i2=6; i2<9; i2++) {
			if(matrix[3][7] == matrix[i][i2])
				right_or_wrong='w';
			
			for(i3=8; i3<9;i3++){
				if(matrix[3][7] == matrix[3][i3])
					right_or_wrong='w';
			}
		}
	}

	for(i=4; i<6; i++) {
		for(i2=9; i2<9; i2++) {
			if(matrix[3][8] == matrix[i][i2])
				right_or_wrong='w';
			
		}
	}

	for(i=5; i<6; i++) {
		for(i2=6; i2<9; i2++) {
			if(matrix[4][6] == matrix[i][i2])
				right_or_wrong='w';
			
			for(i3=7; i3<9;i3++){
				if(matrix[4][6] == matrix[4][i3])
					right_or_wrong='w';
			}
		}
	}

	for(i=5; i<6; i++) {
		for(i2=6; i2<9; i2++) {
			if(matrix[4][7] == matrix[i][i2])
				right_or_wrong='w';
			
			for(i3=8; i3<9;i3++){
				if(matrix[4][7] == matrix[4][i3])
					right_or_wrong='w';
			}
		}
	}

	for(i=5; i<6; i++) {
		for(i2=6; i2<9; i2++) {
			if(matrix[4][8] == matrix[i][i2])
				right_or_wrong='w';
			
		}
	}

	for(i=5; i<6; i++) {
		for(i2=7; i2<9; i2++) {
			if(matrix[5][6] == matrix[i][i2])
				right_or_wrong='w';
			
		}
	}

	for(i=5; i<6; i++) {
		for(i2=8; i2<9; i2++) {
			if(matrix[5][7] == matrix[i][i2])
				right_or_wrong='w';
			
		}
	}


		/*Analyse if exists equal elements in the seventh 3x3 cell */

	for(i=7; i<9; i++) {
		for(i2=0; i2<3; i2++) {
			if(matrix[6][0] == matrix[i][i2])
				right_or_wrong='w';
			
			for(i3=1; i3<3;i3++){
				if(matrix[6][0] == matrix[6][i3])
					right_or_wrong='w';
			}
		}
	}
	
	for(i=7; i<9; i++) {
		for(i2=0; i2<3; i2++) {
			if(matrix[6][1] == matrix[i][i2])
				right_or_wrong='w';
			
			for(i3=2; i3<3;i3++){
				if(matrix[6][1] == matrix[6][i3])
					right_or_wrong='w';
			}
		}
	}

	for(i=7; i<9; i++) {
		for(i2=0; i2<3; i2++) {
			if(matrix[6][2] == matrix[i][i2])
				right_or_wrong='w';
			
		}
	}

	for(i=8; i<9; i++) {
		for(i2=0; i2<3; i2++) {
			if(matrix[7][0] == matrix[i][i2])
				right_or_wrong='w';
			
			for(i3=1; i3<3;i3++){
				if(matrix[7][0] == matrix[7][i3])
					right_or_wrong='w';
			}
		}
	}

	for(i=8; i<9; i++) {
		for(i2=0; i2<3; i2++) {
			if(matrix[7][1] == matrix[i][i2])
				right_or_wrong='w';
			
			for(i3=2; i3<3;i3++){
				if(matrix[7][1] == matrix[7][i3])
					right_or_wrong='w';
			}
		}
	}

	for(i=8; i<9; i++) {
		for(i2=0; i2<3; i2++) {
			if(matrix[7][2] == matrix[i][i2])
				right_or_wrong='w';
			
		}
	}

	for(i=8; i<9; i++) {
		for(i2=1; i2<3; i2++) {
			if(matrix[8][0] == matrix[i][i2])
				right_or_wrong='w';
			
		}
	}

	for(i=8; i<9; i++) {
		for(i2=2; i2<3; i2++) {
			if(matrix[8][1] == matrix[i][i2])
				right_or_wrong='w';
			
		}
	}


		/*Analyse if exists equal elements in the eighth 3x3 cell */

	for(i=7; i<9; i++) {
		for(i2=3; i2<6; i2++) {
			if(matrix[6][3] == matrix[i][i2])
				right_or_wrong='w';
			
			for(i3=4; i3<6;i3++){
				if(matrix[6][3] == matrix[6][i3])
					right_or_wrong='w';
			}
		}
	}
	
	for(i=7; i<9; i++) {
		for(i2=3; i2<6; i2++) {
			if(matrix[6][4] == matrix[i][i2])
				right_or_wrong='w';
			
			for(i3=5; i3<6;i3++){
				if(matrix[6][4] == matrix[6][i3])
					right_or_wrong='w';
			}
		}
	}

	for(i=7; i<9; i++) {
		for(i2=3; i2<6; i2++) {
			if(matrix[6][5] == matrix[i][i2])
				right_or_wrong='w';
			
		}
	}

	for(i=8; i<9; i++) {
		for(i2=3; i2<6; i2++) {
			if(matrix[7][3] == matrix[i][i2])
				right_or_wrong='w';
			
			for(i3=4; i3<6;i3++){
				if(matrix[7][3] == matrix[7][i3])
					right_or_wrong='w';
			}
		}
	}

	for(i=8; i<9; i++) {
		for(i2=3; i2<6; i2++) {
			if(matrix[7][4] == matrix[i][i2])
				right_or_wrong='w';
			
			for(i3=5; i3<6;i3++){
				if(matrix[7][4] == matrix[7][i3])
					right_or_wrong='w';
			}
		}
	}

	for(i=8; i<9; i++) {
		for(i2=3; i2<6; i2++) {
			if(matrix[7][5] == matrix[i][i2])
				right_or_wrong='w';
			
		}
	}

	for(i=8; i<9; i++) {
		for(i2=4; i2<6; i2++) {
			if(matrix[8][3] == matrix[i][i2])
				right_or_wrong='w';
			
		}
	}

	for(i=8; i<9; i++) {
		for(i2=5; i2<6; i2++) {
			if(matrix[8][4] == matrix[i][i2])
				right_or_wrong='w';
			
		}
	}

		/*Analyse if exists equal elements in the nineth 3x3 cell */

	for(i=7; i<9; i++) {
		for(i2=6; i2<9; i2++) {
			if(matrix[6][6] == matrix[i][i2])
				right_or_wrong='w';
			
			for(i3=7; i3<9;i3++){
				if(matrix[6][6] == matrix[6][i3])
					right_or_wrong='w';
			}
		}
	}
	
	for(i=7; i<9; i++) {
		for(i2=6; i2<9; i2++) {
			if(matrix[6][7] == matrix[i][i2])
				right_or_wrong='w';
			
			for(i3=8; i3<9;i3++){
				if(matrix[6][7] == matrix[6][i3])
					right_or_wrong='w';
			}
		}
	}

	for(i=7; i<9; i++) {
		for(i2=9; i2<9; i2++) {
			if(matrix[6][8] == matrix[i][i2])
				right_or_wrong='w';
			
		}
	}

	for(i=8; i<9; i++) {
		for(i2=6; i2<9; i2++) {
			if(matrix[7][6] == matrix[i][i2])
				right_or_wrong='w';
			
			for(i3=7; i3<9;i3++){
				if(matrix[7][6] == matrix[7][i3])
					right_or_wrong='w';
			}
		}
	}

	for(i=8; i<9; i++) {
		for(i2=6; i2<9; i2++) {
			if(matrix[7][7] == matrix[i][i2])
				right_or_wrong='w';
			
			for(i3=8; i3<9;i3++){
				if(matrix[7][7] == matrix[7][i3])
					right_or_wrong='w';
			}
		}
	}

	for(i=8; i<9; i++) {
		for(i2=6; i2<9; i2++) {
			if(matrix[7][8] == matrix[i][i2])
				right_or_wrong='w';
			
		}
	}

	for(i=8; i<9; i++) {
		for(i2=7; i2<9; i2++) {
			if(matrix[8][6] == matrix[i][i2])
				right_or_wrong='w';
			
		}
	}

	for(i=8; i<9; i++) {
		for(i2=8; i2<9; i2++) {
			if(matrix[8][7] == matrix[i][i2])
				right_or_wrong='w';
			
		}
	}
	
	
	return right_or_wrong;
}

 G_MODULE_EXPORT void createNewGame(int difficulty){
    FILE *board;
    char local[20];

    //Generate a random number to choose the game.
    srand(time(NULL));
    int randomNum = rand() % 6;
    
    //A board is selected randomly according to the difficulty chosen.
    switch (difficulty){
        case 0:
            sprintf(local,"level\\easy\\%d.txt", randomNum);
            board = fopen(local, "r");
            break;

        case 1:
            sprintf(local,"level\\normal\\%d.txt", randomNum);
            board = fopen(local, "r");
            break;

        case 2:
            sprintf(local,"level\\hard\\%d.txt", randomNum);
            board = fopen(local, "r");
            break;
    }

    //Saved player board is read and saved in the localuct data_player player.
    for(int i = 0; i < board_Size; i++) {
        for(int j = 0; j < board_Size; j++){
            fscanf(board, "%d ", &player.player_board[i][j]);
        }
    }
 
    fclose(board);

}

G_MODULE_EXPORT int saveGame(void){

    char save_name[playerName_Size];
    sprintf(save_name,"saves\\%s.txt", player.player_name);

    //The pointer points to the folder where the files saved from the player are located.
    FILE *board;
    board = fopen(save_name, "w");
    if(board == NULL){
        g_print("Erro na Abertura do arquivo.");
        exit(1);
    }


    //The data of the localuct are read and saved in the save folder.
    fprintf(board, "%s", player.player_name);
    fprintf(board, "\n");
    fprintf(board, "%d", player.difficulty);
    fprintf(board, "\n");
    fprintf(board, "%d", player.currentTimeStamp);
    fprintf(board, "\n");

    //The data of the player board are read and saved in the save folder.
    for(int i = 0; i < board_Size; i++) {
	    for(int j = 0; j < board_Size; j++){
		    fprintf(board, "%d ", player.player_board[i][j]);
        }  
        fprintf(board, "\n");
    }   

    fclose(board);

    return 0;
}

G_MODULE_EXPORT void loadGameSave(char player_name[playerName_Size]){

    char loadGame_name[playerName_Size + 12];

    //The pointer points to the folder where the files saved from the player are located.
    FILE *board;
    sprintf(loadGame_name,"saves\\%s.txt", player_name);
    board = fopen(loadGame_name, "r");
    if(board == NULL){
        printf("Erro na Abertura do arquivo.");
        exit(1);
    }


    //Saved player data is read and saved in the localuct data_player player.
    fscanf(board, "%s %d %d", &player.player_name, &player.difficulty, &player.currentTimeStamp);

    //Saved player board is read and saved in the localuct data_player player.
    for(int i = 0; i < board_Size; i++) {
	    for(int j = 0; j < board_Size; j++){
		    fscanf(board, "%d ", &player.player_board[i][j]);
        }
    }

    fclose(board);
}

G_MODULE_EXPORT void threeBestTimes(void){
    
    
    FILE *board;
    char local[30];

	strcpy(player.player_name, bestTime[3].name);
	bestTime[3].difficulty = player.difficulty;
	bestTime[3].time = player.currentTimeStamp;

    //Organizing vector bestTime in ascending order
    for (int j = 0; j < Amountsbest_Times * Amountsbest_Times; j++){
        for (int i = 0; i < Amountsbest_Times; i++){
            if (bestTime[i + 1].time < bestTime[i].time){
                char name[playerName_Size];
                int difficulty;
                int time;

                strcpy(name, bestTime[i].name);
                difficulty = bestTime[i].difficulty;
                time = bestTime[i].time;

                strcpy(bestTime[i].name, bestTime[i + 1].name);
                bestTime[i].difficulty = bestTime[i + 1].difficulty;
                bestTime[i].time = bestTime[i + 1].time;

                strcpy(bestTime[i + 1].name, name);
                bestTime[i + 1].difficulty = difficulty;
                bestTime[i + 1].time = time;
            }
        }    
    }

    for (int i = 0; i < Amountsbest_Times; i++){
        sprintf(local, "bestTime\\%d.txt", i);
        board = fopen(local, "w");
        if(board == NULL){
            printf("Erro na Abertura do arquivo.");
            exit(1);
        }
		//Saving the first 3 positions of the vector
        fprintf(board, "%s \n%d \n%d", bestTime[i].name, bestTime[i].difficulty, bestTime[i].time);
    }
	fclose(board);


}

G_MODULE_EXPORT void loadBestTimes(void){
    FILE *board;
    char local[30];

    for (int i = 0; i < Amountsbest_Times; i++){
        
        sprintf(local, "bestTime\\%d.txt", i);
        board = fopen(local, "r");
        if(board == NULL){
            printf("Erro na Abertura do arquivo.");
            exit(1);
        }
		//Saves the data of the files in the bestTime vector
        fscanf(board, "%s %d %d", &bestTime[i].name, &bestTime[i].difficulty, &bestTime[i].time);
    

        fclose(board);
    }

    //Organizing vector bestTime in ascending order - except the last position
    for (int j = 0; j < Amountsbest_Times * Amountsbest_Times; j++){
        for (int i = 0; i < Amountsbest_Times - 1; i++){
            if (bestTime[i + 1].time < bestTime[i].time){
                char name[playerName_Size];
                int difficulty;
                int time;

                strcpy(name, bestTime[i].name);
                difficulty = bestTime[i].difficulty;
                time = bestTime[i].time;

                strcpy(bestTime[i].name, bestTime[i + 1].name);
                bestTime[i].difficulty = bestTime[i + 1].difficulty;
                bestTime[i].time = bestTime[i + 1].time;

                strcpy(bestTime[i + 1].name, name);
                bestTime[i + 1].difficulty = difficulty;
                bestTime[i + 1].time = time;
            }
        }    
    }

}