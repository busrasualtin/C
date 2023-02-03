#include<stdio.h>
#include<stdlib.h>

#define BOARDSIZE 8

enum Cell {empty, pawn, rock, knight, bishop, queen, king};
typedef enum Cell Cell_t;

typedef Cell_t ChessBoard[BOARDSIZE][BOARDSIZE];
typedef int Position[2];
#define POS_X 0
#define POS_Y 1

#define BORDER_CORNER_TOPLEFT 0xC9
#define BORDER_CORNER_TOPRIGHT 0xBB
#define BORDER_CORNER_BOTTOMLEFT 0xC8
#define BORDER_CORNER_BOTTOMRIGHT 0xBC
#define BORDER_ROW 0xCD
#define BORDER_COLUMN 0xBA

#define LABEL_ROW_INITIAL 'A'
#define LABEL_COLUMN_INITIAL '1'

/*
#define BORDER_CORNER_TOPLEFT ' '
#define BORDER_CORNER_TOPRIGHT ' '
#define BORDER_CORNER_BOTTOMLEFT ' '
#define BORDER_CORNER_BOTTOMRIGHT ' '
#define BORDER_ROW ' '
#define BORDER_COLUMN ' '
*/

void print_chessboard_label_row(char initval, int n)
{
	int i;
	for(i=0; i<n; i++) {
		printf("%c", initval+i);
	}
}

void print_chessboard_label_column(char initval, int offset)
{
	printf("%c", initval+offset);
}

void print_chessboard_row(ChessBoard b, char cellchars[], int n, int r)
{
	int i;
	for(i=0; i<n; i++) {
		printf("%c", cellchars[b[r][i]]);
	}
}
void print_chessboard_border_top(int n)
{
	int i;
	printf("%c", BORDER_CORNER_TOPLEFT);
	for(i=0; i<n; i++) {
		printf("%c", BORDER_ROW);
	}
	printf("%c", BORDER_CORNER_TOPRIGHT);
	
}

void print_chessboard_border_column()
{
	printf("%c", BORDER_COLUMN);
}

void print_chessboard_border_bottom(int n)
{
	int i;
	printf("%c", BORDER_CORNER_BOTTOMLEFT);
	for(i=0; i<n; i++) {
		printf("%c", BORDER_ROW);
	}
	printf("%c", BORDER_CORNER_BOTTOMRIGHT);
}

void print_chessboard(ChessBoard b, char cellchars[], int n)
{
	int i;
	printf("  ");
	print_chessboard_label_row(LABEL_ROW_INITIAL, n);
	printf("\n");
	printf(" ");
	print_chessboard_border_top(n);
	printf("\n");
	for(i=0; i<n; i++) {
		print_chessboard_label_column(LABEL_COLUMN_INITIAL, i);
		print_chessboard_border_column();
		print_chessboard_row(b, cellchars, n, i);
		print_chessboard_border_column();
		print_chessboard_label_column(LABEL_COLUMN_INITIAL, i);
		printf("\n");
	}
	printf(" ");
	print_chessboard_border_bottom(n);
	printf("\n");
	printf("  ");
	print_chessboard_label_row(LABEL_ROW_INITIAL, n);
}



int is_pawn_move_pos(Position sp, Position dp)
{
	return (sp[POS_X]==dp[POS_X]) && (abs(sp[POS_Y]-dp[POS_Y])==1);
}

int is_pawn_move(int sr, int sc, int dr, int dc)
{
	return (sc==dc) && (abs(sr-dr)==1);
}

int is_rock_move(int sr, int sc, int dr, int dc)
{
	return ((sc==dc) && (sr!=dr)) || ((sr==dr) && (sc!=dc));
}

int is_knight_move(int sr, int sc, int dr, int dc)
{
	return (abs(sr-dr)==2 && abs(sc-dc)==1) || (abs(sr-dr)==1 && abs(sc-dc)==2);
}

int is_bishop_move(int sr, int sc, int dr, int dc)
{
	return (sr!=dr) && (abs(sr-dr)==abs(sc-dc));
}

int is_king_move(int sr, int sc, int dr, int dc)
{
	return (abs(sr-dr)==1 && abs(sc-dc)<=1) || (abs(sc-dc)==1 && abs(sr-dr)<=1);
}

int is_queen_move(int sr, int sc, int dr, int dc)
{
	return is_bishop_move(sr, sc, dr, dc) || is_rock_move(sr, sc, dr, dc);
}



int main()
{
	ChessBoard b = {{rock,knight,bishop,king,queen,bishop,knight,rock},
	                {pawn,pawn,pawn,pawn,pawn,pawn,pawn,pawn},
	                {empty,empty,empty,empty,empty,empty,empty,empty},
	                {empty,empty,empty,empty,empty,empty,empty,empty},
	                {empty,empty,empty,empty,empty,empty,empty,empty},
	                {empty,empty,empty,empty,empty,empty,empty,empty},
	                {pawn,pawn,pawn,pawn,pawn,pawn,pawn,pawn},
	                {rock,knight,bishop,queen,king,bishop,knight,rock}};
	char cellchars[] = {'.', 'P', 'R', 'N', 'B', 'Q', 'K'};
	char cellchars2[] = {219, 'P', 'R', 'N', 'B', 'Q', 'K'}; //219 is decimal value for 'full-cursor' character. you can also use hexadecimal value 0xDB;
	
	print_chessboard(b, cellchars, BOARDSIZE);
	printf("\n");
	print_chessboard(b, cellchars2, BOARDSIZE);
	printf("\n");
	
	
	
	//enable too look up character values	
/*	unsigned char c;
	for(c=0; c<255; c++) {
		printf("%c - %d - %x\n", c, c, c);
	}
	printf("%c - %d - %x\n", c, c, c);
*/	
	
	return 0;
}

