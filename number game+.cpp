#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//take term, enter number within range
int play(int win, int maxN, int t, int n1, int c1)
{
    cout << "enter a number between 1 and " << maxN << endl;
    cin >> n1;
    //validate num entered
    while (n1<1 || n1>maxN || n1 > (win - t))
    {
        cout << "invalid input" << endl;
        cout << "enter a number between 1 and " << maxN << endl;
        cin >> n1;
    }
    cout << "you entered" << n1 << endl;
    t += n1;
    cout << "the total is now " << t << endl;
    return t;
}

//computer's term, win if possible
int opp(int ai, int win, int maxN, int t, int n2)
{
    for (int c = 0; c < ai; c++)
    {
        if (ai == 1)
            cout << "Now it's your opponent's term" << endl;
        else
            cout << "Now it's opponent " << c + 1 << "'s term" << endl;
        //if can win
        if (win - t <= maxN)
        {
            //calc winning move
            n2 = (win - t);
            //for loop stop after this time
            c = (ai - 1);
        }
        else
            //use randum num
            n2 = (rand() % (maxN - 1 + 1)) + 1;
        cout << "The number entered is " << n2 << endl;
        t += n2;
        cout << "the total is now " << t << endl;
    }
    return t;
}

int main()
{
    int ai = 0, win = 0, maxN = 0;
    int n1 = 0, n2 = 0, t = 0, c1 = 0, again;
    unsigned int seed = time(0);
    srand(seed);

    //set the number of opponents, winning number, and max number allowed
    cout << "How many opponents do you want?" << endl;
    cin >> ai;
    cout << "Enter the winning number" << endl;
    cin >> win;
    cout << "enter the max number allowed" << endl;
    cin >> maxN;
    cout << "Your goal is to get " << win << ", and you are allowed to add " << maxN << " at the most each term!" << endl;

    //play till one wins
    while (t < win)
    {
        t=play(win, maxN, t, n1, c1);
        if (t == win)
        {
            c1 = 1;
            break;
        }
        else
            t=opp(ai, win, maxN, t, n2);
    }
    if (c1 == 1)
        cout << "You won! good job!" << endl;
    else
        cout << "the computer beat you, feel shame!" << endl;

    //reset vals to 0
    c1 = 0, t = 0, win = 0;
    //ask play again?
    cout << "do you want to play again?" << endl << "press 1 then enter to continue." << endl;
    cin >> again;
    if (again == 1)
        main();
    return 0;
}