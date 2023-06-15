#include <iostream>
#include <cstdlib>
#include <ctime>
#include<vector>
using namespace std;
int main ()
{
  srand (static_cast < unsigned int >(time (0)));
  int opponentwkt = rand () % 7 + 3;
  int targetRuns = rand () % 51 + 90;	// Generate a random target between 90 and 140
  int totalRuns = 0;
  int overs = 0;
  bool flag = false;
  int i = 0;
  string player[11] =
    { "S. Dhawan", "R. Sharma", "G. Gambhir", "V. Sehwag", "S. Tendulkar",
"V. Kohli", "S. Raina", "Y. Singh", "M.s. dhoni", "H. Singh", "Z. Khan" };
  cout << "Welcome to Cricket T6 -- By Prem Dayal" << endl;
  if (opponentwkt < 10)
    cout << "Target: " << targetRuns << "/" << opponentwkt <<
      " runs in 6 overs" << endl;
  else
    cout << "Target: " << targetRuns << "/" << opponentwkt <<
      " runs in 5.4 overs" << endl;
  int is = 0;
  // Game loop
  int wicket = 0;
  int ball = 0;
  int pb = 0;
  int balls = 36;
  // int j=0,k=0;

  while (ball < balls)
    {
      int currentRuns = rand () % 7;	// Generate a random runs between 0 and 6

      cout << "Enter your guess for the runs (0-6): ";
      int guess;
      cin >> guess;
      if (guess >= 7)
	{
	  ball++;
	  cout << ball / 6 << "." << (ball %
				      6) << " will considered as a dot ball"
	    << endl << "Please enter any number between (0-6)!" << endl;
	}
      else
	{
	  cout << "Bowler's delivery: " << currentRuns << " runs" << endl;
	  pb++;
	  ball++;
	  if (guess == currentRuns)
	    {
	      wicket++;
	      cout << player[i] << " out!" << endl;
	      cout << player[i] << " scored " << is << " runs in " << pb <<
		" balls" << endl;
	      i++;
	      cout << "IND: " << totalRuns << "/" << wicket << "    overs: "
		<< ball / 6 << "." << (ball % 6) << endl;
	      is = 0;
	      pb = 0;
	      if (wicket == 10)
		break;
	    }
	  else
	    {
	      totalRuns += currentRuns;
	      is += currentRuns;
	      cout << player[i] << " scored " << is << " runs in " << pb <<
		" balls" << endl;
	      cout << "IND: " << totalRuns << "/" << wicket << "    overs: "
		<< ball / 6 << "." << (ball % 6) << endl;
	      if (totalRuns > targetRuns)
		{
		  flag = true;
		  break;
		}
	    }
	}
    }

  cout << "Game over!" << endl;
  cout << "Total runs scored: " << totalRuns << endl;

  if (flag)
    {
      int runsDifference = totalRuns - targetRuns;
      cout << "Congratulations! INDIA won by " << 10 -
	wicket << " wickets." << endl;
    }
  else if (totalRuns == targetRuns)
    {
      cout << "It's a tie!" << endl;
    }
  else
    {
      int runsDifference = targetRuns - totalRuns;
      cout << "Sorry! INDIA lost by " << runsDifference << " runs." << endl;
    }
  return 0;
}
