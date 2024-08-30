#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <conio.h>
#include <time.h>
#include <fstream>
#include <stdio.h>
#include <cmath>
#include <windows.h>

using namespace std;

struct user
{
    string name;
};

struct Location
{
    int* x;
    int* y;
};


int arr [4][4];
int score = 0;
user N1;

bool ending()
{
    // There is a zero
    for (int x = 0; x < 4; x++){
        for (int y = 0; y < 4; y++){
            if (arr[x][y] == 0)
                return false;
        }
    }

    // can move up
    for(int y = 0;y < 4;y++){
        for(int x = 0; x < 3; x++){
            if (arr[x][y] == arr[x+1][y]){
                return false;
            }
        }
    }

    // can move down
    for(int y = 0;y < 4;y++){
        for(int x = 3;x > 0;x--){
            if (arr[x][y] == arr[x-1][y]){
                return false;
            }
        }
    }

    // can move right
    for(int x = 0; x < 4; x++){
        for(int y = 3; y > 0;y--){
            if (arr[x][y] == arr[x][y-1]){
                return false;
            }
        }
    }

    // can move left
    for(int x = 0;x < 4;x++){
        for(int y = 0;y < 3;y++){
            if (arr[x][y] == arr[x][y+1]){
                return false;
            }
        }
    }

    return true;
}

void randomIndex()
{
    int randI, randJ;
    int randResult, RanIndex;

    /*This is our function that does our random stuff. like gettting random numbers betweeen 2 & 4 with unequal probability, choosing
    random elements of our array etc...*/

    RanIndex = rand() % 4;

    if(RanIndex == 0)
    {
        randResult = 4;
    }

    else
        randResult = 2;

    int counter = 0; // number of zeros

    for(int i = 0;i < 4;i++){
        for(int j = 0;j < 4;j++){
            if(arr[i][j] == 0)
            {
                counter ++;
            }
        }
    }

    //putting the elements of the array as zeros in order two avoid random numbers.

    if(counter == 0)
        return;

    Location loc;
    loc.x = new int[counter];
    loc.y = new int[counter];

    /*حلقه صفر کننده درایه ها
    */
    int c = 0;
    for(int i = 0;i < 4;i++){
        for(int j = 0;j < 4;j++){
            if(arr[i][j] == 0)
            {
                loc.x[c] = i;
                loc.y[c] = j;
                c++;
            }
        }
    }

    int randLoc = rand() % counter;

    //choosing random elements of the array.

    arr[loc.x[randLoc]][loc.y[randLoc]] = randResult;
}

//function for moving left.

void left()
{
    for(int x = 0;x < 4;x++){
        for(int k = 0;k < 3;k++){
            for(int y = 0;y < 3;y++){
                if(arr[x][y + 1] != 0 && arr[x][y] == 0)
                {
                    arr[x][y] = arr[x][y + 1];
                    arr[x][y + 1] = 0;
                }
            }
        }

        int y=0;
		if((arr[x][y] == arr[x][y+1]) && (arr[x][y] != 0))
		{
			arr[x][y] = (2*arr[x][y]);
            score += arr[x][y];
			arr[x][y+1] = arr[x][y+2];
			arr[x][y+2] = arr[x][y+3];
			arr[x][y+3] = 0;
		}
		y=1;
		if((arr[x][y] == arr[x][y+1]) && (arr[x][y] != 0))
		{
			arr[x][y] = (2*arr[x][y]);
            score += arr[x][y];
			arr[x][y+1] = arr[x][y+2];
			arr[x][y+2] = 0;
		}
		y=2;
		if((arr[x][y] == arr[x][y+1]) && (arr[x][y] != 0))
		{
			arr[x][y] = (2*arr[x][y]);
            score += arr[x][y];
			arr[x][y+1] = 0;
		}
    }

    cout << "score :" << score;
}

//function for moving right.

void right()
{
    for(int x = 0;x < 4;x++){
        for(int k = 0;k < 3;k++){
            for(int y = 3; y > 0;y--){
                if(arr[x][y - 1] != 0 && arr[x][y] == 0)
                {
                    arr[x][y] = arr[x][y - 1];
                    arr[x][y - 1] = 0;
                }
            }
        }
        
        int y=3;
		if((arr[x][y] == arr[x][y-1]) && (arr[x][y] != 0))
		{
			arr[x][y] = (2*arr[x][y]);
            score += arr[x][y];
			arr[x][y-1] = arr[x][y-2];
			arr[x][y-2] = arr[x][y-3];
			arr[x][y-3] = 0;
		}
		y=2;
		if((arr[x][y] == arr[x][y-1])&&(arr[x][y] != 0))
		{
			arr[x][y] = (2*arr[x][y]);
            score += arr[x][y];
			arr[x][y-1] = arr[x][y-2];
			arr[x][y-2] = 0;
		}
		y=1;
		if((arr[x][y] == arr[x][y-1]) && (arr[x][y] != 0))
		{
		    arr[x][y] = (2*arr[x][y]);
            score += arr[x][y];
		    arr[x][y-1] = 0;
		}
    }
    cout << "score :" << score;

}

//function for moving up.

void up()
{
    for(int y = 0;y < 4;y++){
        for(int k = 0; k < 3;k++){
            for(int x = 0; x < 3; x++){
                if(arr[x + 1][y] != 0 && arr[x][y] == 0)
                {
                    arr[x][y] = arr[x + 1][y];
                    arr[x + 1][y] = 0;
                }
            }
        }

        int x=0;
		if(arr[x][y] == arr[x+1][y] && arr[x][y] != 0)
		{
			arr[x][y] = (2*arr[x][y]);
            score += arr[x][y];
			arr[x+1][y] = arr[x+2][y];
			arr[x+2][y] = arr[x+3][y];
			arr[x+3][y] = 0;
		}
		x=1;
		if(arr[x][y]==arr[x+1][y] && arr[x][y] != 0)
		{
			arr[x][y] = (2*arr[x][y]);
            score += arr[x][y];
			arr[x+1][y] = arr[x+2][y];
			arr[x+2][y] = 0;
		}
		x=2;
		if(arr[x][y] == arr[x+1][y] && arr[x][y] != 0)
		{
			arr[x][y] = (2*arr[x][y]);
            score += arr[x][y];
			arr[x+1][y] = 0;
		}
    }
    cout << "score :" << score;
}

// function for moving down 

void down()
{
    for(int y = 0;y < 4;y++){
        for(int k = 0;k < 3;k++){
            for(int x = 3;x > 0;x--){
                if(arr[x - 1][y] != 0 && arr[x][y] == 0)
                {
                    arr[x][y] = arr[x - 1][y];
                    arr[x - 1][y] = 0;
                }
            }
        }

        int x=3;
		if((arr[x][y] == arr[x-1][y]) && (arr[x][y] != 0))
		{
			arr[x][y] = (2*arr[x][y]);
            score += arr[x][y];
			arr[x-1][y] = arr[x-2][y];
			arr[x-2][y] = arr[x-3][y];
			arr[x-3][y] = 0;
		}
		x=2;
		if((arr[x][y] == arr[x-1][y]) && (arr[x][y] != 0))
		{
			arr[x][y] = (2*arr[x][y]);
            score += arr[x][y];
			arr[x-1][y] = arr[x-2][y];
			arr[x-2][y] = 0;
		}
		x=1;
		if((arr[x][y] == arr[x-1][y])&&(arr[x][y]!=0))
		{
			arr[x][y] = (2*arr[x][y]);
            score += arr[x][y];
			arr[x-1][y] = 0;
		}
    }
    cout << "score :" << score;
}

int intLen(int n){
    int len = 0;
    while (n > 0)
    {
        n /= 10;
        len++;
    }
    
    return len;
}

// showing unicodes of the game.for better view of the 4 * 4 chart.

void show()
{
    randomIndex();
    cout << "Score: " << score << endl;

    cout << "\u250F";
    for (int i = 0; i < 30; i++)
        cout << "\u2501";
    cout << "\u2513" << endl;

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (arr[i][j] == 0)
                cout << "\u2503" << "      " << "\u2503";
                
            else{
                cout << "\u2503";
                int len = intLen(arr[i][j]);
                for (int i = 0; i < (6 - len)/2; i++)
                    cout << " ";
                cout << arr[i][j];
                for (int i = 0; i < ceil((double)((6 - len)/2.0)); i++)
                    cout << " ";
                cout << "\u2503";
            }

        }
        if (i < 3){
            cout << endl << "\u2523";
            for (int i = 0; i < 6; i++)
                cout << "\u2501";
            cout << "\u252B";

            cout << "\u2523";
            for (int i = 0; i < 6; i++)
                cout << "\u2501";
            cout << "\u252B";

            cout << "\u2523";
            for (int i = 0; i < 6; i++)
                cout << "\u2501";
            cout << "\u252B";

            cout << "\u2523";
            for (int i = 0; i < 6; i++)
                cout << "\u2501";
            cout << "\u252B";
        }
        cout << endl;
    }

    cout << "\u2517";
    for (int i = 0; i < 30; i++)
        cout << "\u2501";
    cout << "\u251B" << endl;
    return;
}

// the Leaderboard menu. showing the scores.

void LeaderBoard(int a)
{
    if(score == 0)
    {
        cout << "No One has played yet" << endl;
    }

    ofstream MyWriteFile("filename.txt");

    MyWriteFile << N1.name << " " << score << endl;
    
    MyWriteFile.close();

    string myText;

  // Read from the text file
    ifstream MyReadFile("filename.txt");

  // Use a while loop together with the getline() function to read the file line by line
    while (getline (MyReadFile, myText)) {
    // Output the text from the file
    cout << myText;
    }

    // Close the file
    MyReadFile.close();
}


void newGame(int a)
{
    /*here, we have an array which is defined globally, and we set all the indexes as zeros*/
    for(int i = 0;i < 4;i++){
        for(int j = 0;j < 4;j++){
            arr[i][j] = 0;
        }
    }
    randomIndex();
    /*here we ask our users to enter their names to save them in a file*/
        
    cout << "Enter your name please." << endl;

    cin >> N1.name;

    //here we colorize the game.

    while(true)
    {
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        cout << "Enter the number of the color you want the game to be" << endl;

        cout << "1: Pink" << endl;
        cout << "2: Yellow" << endl;
        cout << "3: Blue" << endl;
        cout << "4: Red" << endl;
        cout << "5: Green" << endl;

        int a;
        cin >> a;

        if(a == 1)
        {
            SetConsoleTextAttribute(h,13);
            cout << arr[4][4];
            break;
        }

        if(a == 2)
        {
            SetConsoleTextAttribute(h,14);
            cout << arr[4][4];
            break;
        }

        if(a == 3)
        {
            SetConsoleTextAttribute(h,9);
            cout << arr[4][4];
            break;
        }

        if(a == 4)
        {
            SetConsoleTextAttribute(h,4);
            cout << arr[4][4];
            break;
        }

        if(a == 5)
        {
            SetConsoleTextAttribute(h,10);
            cout << arr[4][4];
            break;
        }
    }

    // getting input from user "wasd" using getch function.

    while (true)
    {
        system("cls");
        show();
        
        char harekat = _getch();

        if(harekat == 'a')
            left();

        else if(harekat == 's')
            down();

        else if(harekat == 'd')
            right();

        else if(harekat == 'w')
            up();  

        //ifs and functions related to winning or losing.

        if(score >= 2048)
        {
            cout << "You won" << endl;
            return;
        }

        else
        {
            if(ending()){
                cout << endl << "Game Over!" << endl;
                return; 
            }
        }         
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    /*here we ask the user to select in menu*/
    while(true){
        cout << "Welcome,please select the number of menu" << endl;
        cout << "1: New Game" <<endl;
        cout << "2: Leaderboard" <<endl;
        cout << "3: Exit" << endl;

        int a;
        cin >> a;

        if(a == 1)
            newGame(a);
        if(a == 2)
            LeaderBoard(a);
        if(a == 3)
            break;
    }
    return 0;
}