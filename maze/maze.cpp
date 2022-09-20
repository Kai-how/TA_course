#include <stdio.h>
#include <stdlib.h>
#include <deque>
using namespace std;
#define X -1
int m, n;			// size of the maze, m x n
int **M;			// the maze
int Sx, Sy, Tx, Ty;		// source and destination

typedef struct {
    int x; 
    int y;
    int d;
}STEP;

typedef struct _matrix  
{  
    STEP start;          
    STEP end;             
}MATRIX;

 
static STEP  s_shift[]=  
{  
    {1,0,0},      //向右走
    {0,1,0},      //向下走   
    {-1,0,0},     //向左走  
    {0,-1,0}      //向上走  
};
deque<STEP> my_queue;

// read an m x n maze
void readMaze()
{
	int x, y, Z;
	char c;
	Z = m * n + 1;		// infinity
		
	for (x = 1; x <= m; x++) {	// read the maze row by row
		for (y = 1; y <= n; y++)
			M[x][y] = Z;	// set distance = "infinity"

		scanf("%d", &y);
		while (y) {
			scanf(" %c", &c);
			switch (c) {
			case 'X':	// obstacle
			case 'x':
				M[x][y] = X;	// set distance = -1
				break;
			case 'S':	// source
			case 's':
				Sx = x; Sy = y;
				M[x][y] = -2;
				break;
			case 'T':	// destination
			case 't':
				Tx = x; Ty = y;
				M[x][y] = Z;
				break;
			default:
				fprintf(stderr, "%c: invalid\n", c);
				break;
			}
			scanf("%d", &y);
		}
	}
	for (y = 0; y < n + 2; y++) {	// set top and bottom rows to 'X'
		M[0][y] = X;
		M[m + 1][y] = X;
	}
	for (x = 1; x < m + 1; x++) {	// set left and right columns to 'X'
		M[x][0] = X;
		M[x][n + 1] = X;
	}
}
// print maze
void printMaze(const int d)
{
	int x, y, Z;

	printf("\nThe maze\n");

	Z = m * n + 1;
	for (x = 0; x < m + 2; x++) {
		for (y = 0; y < n + 2; y++) {
			if (M[x][y] == X) {	// obstacle
				printf(" X");
			} else if ((x == Sx) && (y == Sy)) {	// source
				printf(" S");
			} else if ((x == Tx) && (y == Ty)) {	// destination
				printf(" T");
			} else if (M[x][y] < Z) {	// print distance
				printf("%2d", M[x][y]);
			} else {
				printf(" 0");	// empty cell
			}
		}
		putchar('\n');
	}
}/*
int move(MATRIX g_matrix.start,MATRIX g_matrix.end)
{
	if ( (t2.x!=t1.x || t2.y !=t1.y) && M[t2.x][t2.y] != -1 )
		{
			if  ( M[t2.x][t2.y]==0 || M[t2.x][t2.y]> t2.d)
			{
				M[t2.x][t2.y]=t2.d;
				my_queue.push_back(t2);
			}
		}
}*/ 
int SearchDistance(int** M,STEP start,STEP end)
{	
	STEP t1,t2;
	t1=start;
	int i;
	t1.d=0;
	
	my_queue.push_back(t1);
	while ( !my_queue.empty() )
	{
		t1=my_queue.front();
		my_queue.pop_front();
		
		
		t2.d =t1.d +1;
		for (i=0;i<4;i++)
		{
			t2.x=t1.x + s_shift[i].x;
			t2.y=t1.y + s_shift[i].y;
			
			if ( (t2.x!=t1.x || t2.y !=t1.y) && M[t2.x][t2.y] != -1 )
			{
				if  ( M[t2.x][t2.y]==0 || M[t2.x][t2.y]> t2.d)
				{
					M[t2.x][t2.y]=t2.d;
					my_queue.push_back(t2);
				}
			}
		}
	}
	
	return t2.d-1;		
}  


int main()
{
	printf("Input maze size: e.g.(5 4) means 5 rows and 4 columns \n");
	printf("maze size:");
	while (scanf("(%d %d)", &m, &n) != EOF) {
		M = (int **) malloc(sizeof(int *) * (m + 2));
		for (int x = 0; x < m + 2; x++)
			M[x] = (int *) malloc(sizeof(int) * (n + 2));
		readMaze();
		printMaze(0);
		
		
		MATRIX g_matrix=               
		{                      
  	 	 {Sx,Sy},                    
   		 {Tx,Ty}                      
		};
		
		int Max_distance;
		Max_distance = SearchDistance(M,g_matrix.start,g_matrix.end);
		
		printf("\n%Distance from S to T:\n");
		for (int x = 0; x < m + 2; x++) {
			for (int y = 0; y < n + 2; y++)
			 	{
			 		if(M[x][y]==-1){
						printf(" X");
					}
					else if(M[x][y]==Max_distance){
						printf(" T");
					}
					else if(M[x][y]==-2){
						printf(" S");
					}
					else{
						printf(" %d",M[x][y]);
					}
				}
				printf("\n");
			}
		// free memory for the maze
		for (int x = 0; x < m + 2; x++)
			free(M[x]);
		free(M);
	}

}
