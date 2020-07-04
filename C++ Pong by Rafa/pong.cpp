#include <iostream>
#include <time.h>
#include <conio.h>
using namespace std;
enum eDir { STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT= 6};

// Here we create the functions for the game,
// Before the int main

class cBall
{
private:
        // the ball coordinates:
    int x,y;
    int originalX, originalY;
        //the direction of the ball:
    eDir direction;
public:
    cBall(int posX, int posY)
    {
         originalX = posX;
         originalY = posY;
         x = posX; y = posY;
         direction = STOP;
    }
    void Reset()
    {
        x = originalX; y = originalY;
        direction = STOP;
    }
    void changeDirection(eDir d){

        direction = d;
    }
    
    //this function makes the directions go random
    void randomDirection()
    {

        // this generates numbers from 1-6 
        // (the 6 things at the top of this code) randomly

        direction = (eDir)((rand() % 6) + 1);
    }

    // this function is to get the current x and y
    inline int getX() { return x; }
    inline int getY() { return y; }
    inline eDir getDirection() { return direction; }
    
    // this is so the ball can move
    void Move(){
        /*
        The coordinates start from the top left
        +y will go DOWN
        -y will go UP
        +x will go RIGHT
        -x will go LEFT
        */
        switch(direction)
        {
            case STOP:
                break;
            case LEFT:
                x--;
                break;
            case RIGHT:
                x++;
                break;
            case UPLEFT:
                x--; y--;
                break;
            case UPRIGHT:
                x++; y--;
                break;
            case DOWNLEFT:
                x--; y++;
                break;
            case DOWNRIGHT:
                x++; y++;
                break;
            default:
                break;

        /*
        There is no UP or DOWN because
        in pong the ball doesn't go
        up or down, it only goes
        left right or diagonal
        */
        }
    }
    friend ostream & operator<<(ostream & o, cBall c)
    {
        o << "Ball [" << c.x << "," << c.y << "][" << c.direction << "]";
        return o;
    }

};

class cPaddle{
    private:
        int x, y;
        int originalX, originalY;
    public:
        cPaddle()
        {
            x = y = 0;
        }
        cPaddle(int posX,int posY) : cPaddle()
        {
            originalX = posX;
            originalY = posY;
            x = posX;
            y = posY;
        }
        inline void Reset() { x = originalX; y = originalY; }
        inline int getX() { return x; }
        inline int getY() { return y; }
        inline void moveUp() { y--; }
        inline void moveDown() { y++; }
        friend ostream & operator<<(ostream & o, cPaddle c)
        {
        o << "Paddle [" << c.x << "," << c.y << "]";
        return o;
        }

};

class cGameManager{
private:
    int width, height;
    int score1, score2;
    char up1, down1, up2, down2;
    bool quit;
    cBall * ball;
    cPaddle *player1;
    cPaddle *player2;
public:
    cGameManager(int w, int h)
    {
        srand(time(NULL));
        quit = false;
        up1 = 'w'; up2 = 'i';
        down1 = 's'; down2 = 'k';
        score1 = score2 = 0;
        width = w; height = h;
        ball = new cBall(w / 2, h / 2);
        player1 = new cPaddle(1, h/2 - 3);
        player2 = new cPaddle(w - 2, h/2 - 3);
        
    }
    ~cGameManager()
    {
        delete ball, player1, player2;
    }
    void ScoreUp(cPaddle * player) 
    {
        if (player == player1)
            score1++;
        else if(player == player2)
            score2++;

        ball->Reset();
        player1->Reset();
        player2->Reset();
    }
    void Draw()
    {
        system("cls");

        //top wall
        for (int i = 0; i < width + 2; i++)
            cout << "\xB2";
        cout << endl;

        for (int i = 0; i < height; i++)
        {
            for (int j = 0 ; j < width; j++)
            {
                int ballx = ball->getX();
                int bally = ball->getY();
                int player1x = player1->getX();
                int player2x = player2->getX();
                int player1y = player1->getY();
                int player2y = player2->getY();

                if (j == 0)
                    cout << "\xB2";

                if (ballx == j && bally == i )
                    cout << "o"; //the ball
                else if(player1x == j && player1y == i)
                    cout << "\xDB"; //player 1
                else if(player2x == j && player2y == i)
                    cout << "\xDB"; //player 2
                
                else if(player1x == j && player1y + 1 == i)
                    cout << "\xDB"; //player 1
                else if(player1x == j && player1y + 2 == i)
                    cout << "\xDB"; //player 1
                else if(player1x == j && player1y + 3 == i)
                    cout << "\xDB"; //player 1
                
                else if(player2x == j && player2y + 1 == i)
                    cout << "\xDB"; //player 2
                else if(player2x == j && player2y + 2 == i)
                    cout << "\xDB"; //player 2
                else if(player2x == j && player2y + 3 == i)
                    cout << "\xDB"; //player 2
                else
                    cout << " ";
                
                if (j == width - 1)
                    cout << "\xB2";


            }
            cout << endl;
        }

        for (int i = 0; i < width + 2; i++)
            cout << "\xB2";
        cout << endl;

        cout << "Score 1 :" << score1  << endl << "Score 2: " << score2 << endl;

        cout << "C++ Pong by Rafa" << endl;

        cout << "Press W and S for Player 1" << endl;

        cout << "Press I and K for Player 2" << endl;

        cout << "I dunno why it's flickering so much" << endl;

        cout << "Press Q to quit game" << endl;


    }
    void Input()
    {
        ball->Move();

        int ballx = ball->getX();
        int bally = ball->getY();
        int player1x = player1->getX();
        int player2x = player2->getX();
        int player1y = player1->getY();
        int player2y = player2->getY();

        if (_kbhit())
        {
            char current = +getch();
            if (current == up1)
                if(player1y > 0)
                    player1->moveUp();
            if (current == up2)
                if(player2y > 0)
                    player2->moveUp();
            if (current == down1)
                if(player1y + 4 < height)
                    player1->moveDown(); 
            if (current == down2)
                if(player2y + 4 < height)
                    player2->moveDown();

            if(ball->getDirection() == STOP)
                ball->randomDirection();

            if (current == 'q')
                quit = true;

        }
    }
    void Logic()
    {
        int ballx = ball->getX();
        int bally = ball->getY();
        int player1x = player1->getX();
        int player2x = player2->getX();
        int player1y = player1->getY();
        int player2y = player2->getY();

        // Left Paddle / player
        // the 4 is the paddle head
        for(int i = 0; i < 4; i ++)
            if(ballx == player1x + 1)
                if (bally == player1y + i)
                    ball->changeDirection((eDir)((rand() % 3) + 4)); // 4 because in eDir, 4 5 and 6 will go right, upright, or downright
        // Right Paddle / player
        for(int i = 0; i < 4; i ++)
            if(ballx == player2x - 1)
                if (bally == player2y + i)
                    ball->changeDirection((eDir)((rand() % 3) +  1)); // 1 because in eDir, 4 5 and 6 will go left, upleft, or downleft
        
        // bottom wall
        if(bally == height - 1)
            ball->changeDirection(ball->getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);
        // top wall
        if(bally == 0)
            ball->changeDirection(ball->getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);
        //right wall  player 1 score
        if(ballx == width - 1)
            ScoreUp(player1);
        //left wall player 2 score
        if(ballx == 0)
            ScoreUp(player2);

    }
    void Run()
    {
        while(!quit)
        {
            Draw();
            Input();
            Logic();
        }
    }
};

int main(){
    cGameManager c(40, 20);
    c.Run();

    return 0;
}