 #include <iostream>
	#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	int win, maxN, t = 0, p=1, c1 = 0, c2 = 0;
	int n1, n2;
	unsigned int seed = time(0);
	srand(seed);

	while (p == 1)
	{
		cout << "Enter the winning number" << endl;
		cin >> win;
		cout << "enter the max number allowed" << endl;
		cin >> maxN;
		cout << "Your goal is to get " << win << ", and you are allowed to add " << maxN << " at the most each term!" << endl;
		while (t < win)
		{
			cout << "enter a number between 1 and " << maxN << endl;
			cin >> n1;
			while (n1<1 || n1>maxN || n1 > (win - t))
			{
				cout << "invalid input" << endl;
				cout << "enter a number between 1 and " << maxN << endl;
				cin >> n1;
			}
			cout << "you entered" << n1 << endl;
			t += n1;
			cout << "The total is now " << t;
			c1++;
			if (t == win)
				break;
			else
			{
				cout << "Now it's your opponent's term" << endl;
				if (win - t <= maxN)
					n2 = (win - t);
				else
					n2 = (rand() % (maxN - 1 + 1)) + 1;
				cout << "The computer entered" << n2 << endl;
				t += n2;
				cout << "the total is now " << t << endl;
				c2++;
			}
		}
		if (c1 > c2)
			cout << "You won! good job!" << endl;
		else
			cout << "the computer beat you, feel shame!" << endl;
		cout << "press 1 and then enter to play again, or anything else to exit" << endl;
		cin >> p;
		if (p == 1)
		{
			c1 = 0;
			c2 = 0;
			t = 0;
		}
	}
	return 0;
}