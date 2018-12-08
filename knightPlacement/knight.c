#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Display the board.
 */
void print_board(char b[][8])
{
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            printf("%c ", b[row][col]);
        }
        printf("\n");
    }
}

/*
 * Initialize the board to be all underscores.
 */
void init_board(char b[][8])
{
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            b[row][col] = '_';
        }
    }
}

/*
 * Get a move from the user.
 *
 *   2   3
 * q       e
 *     K
 * a       d
 *   z   x
 *
 */
char get_move()
{
    char m;
    int valid = 0;
    do
    {
        printf("What's your move? ");
        scanf(" %c", &m);
        if (m != '2' && m != '3' && m != 'e' && m != 'd' &&
            m != 'x' && m != 'z' && m != 'a' && m != 'q')
        {
            printf("Moves are 2, 3, e, d, x, z, a, q\n");
        }
        else
        {
            valid = 1;
        }
    } while (! valid);
    
    return m;
}

int move_knight(int *kx, int *ky, char move)
{
    int savedX = *kx;
    int savedY = *ky;
    
    switch (move)
    {
        case 'q':
            *kx -= 2;
            *ky -= 1;
            break;

        case '2':
            *kx -= 1;
            *ky -= 2;
            break;
            
        case '3':
            *kx += 1;
            *ky -= 2;
            break;
            
        case 'e':
            *kx += 2;
            *ky -= 1;
            break;
            
        case 'd':
            *kx += 2;
            *ky += 1;
            break;
            
        case 'x':
            *kx += 1;
            *ky += 2;
            break;
            
        case 'z':
            *kx -= 1;
            *ky += 2;
            break;
            
        case 'a':
            *kx -= 2;
            *ky += 1;
            break;
    }
    
    if (*kx > 7 || *kx < 0 || *ky > 7 || *ky < 0)
    {
        *kx = savedX;
        *ky = savedY;
        return 0;
    }
    else 
        return 1;
}
/*
 * The function is passed the knight's x and y location, 
 * plus the user's move (from get_move()).
 * The move will be one of 2, 3, e, d, x, z, a, q.
 * The function should change the x and y location based
 * on the direction the user selected.
 * The function returns 1 (true) if the move was valid.
 * Returns 0 if the move would cause the knight to move
 * off the board. If the move is invalid, the knight's
 * position does not change.
 *
 * Write your move_knight function here.
 */


int main()
{
    char board[8][8];
    int kx = 1, ky = 7;   // Starting location for knight
    
    srand(time(NULL));    // Seed the random number generator
    
    int tx, ty;           // Target location
    
    do
    {
        tx = rand() % 8;  // Pick random target
        ty = rand() % 8;
    } while (tx == kx && ty == ky);
    
    init_board(board);
    board[ty][tx] = 'G';    // Place goal and knight
    board[ky][kx] = 'K';
    
    print_board(board);
    
    int moves = 0;
    
    while (tx != kx || ty != ky)
    {
        char move = get_move();
        board[ky][kx] = '_';
        int ret = move_knight(&kx, &ky, move);
        board[ky][kx] = 'K';
        if (!ret)
        {
            printf("Invalid move.\n");
        }
        else
        {
            print_board(board);
            moves++;
        }
    }
    printf("You won in %d moves!\n", moves);
}