#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#define PHI "\u03C6"
#define EPSILON "\u03B5"

int states;
int symbols;
int table[100][100];

string findRE(int n, int state1, int state2, string re = "")
{
    if(n == 0)
    {
        ostringstream str1;

        if(state2 == table[state1][1])
        {
            if(state1 == state2)
                re = re + EPSILON + " + ";
            str1 << table[0][1];
            re += str1.str();
        }
        if(state2 == table[state1][2])
        {
            if(state1 == state2)
                if(re == "")
                    re = re + EPSILON + " + ";
                else 
                    re += " + ";
            str1 << table[0][2];
            re += str1.str();
        }
        if(re == "")
        {
            if(state1 == state2)
                re += EPSILON;
            else
                re += PHI;
        }
        return re;
    }
    else
    {
        return findRE( n - 1, state1, state2 ) + " + " + findRE( n - 1, state1, n ) + "(" + findRE ( n - 1, n, n ) + ")*" + findRE( n - 1, n, state2);
    }
}

void RE(int n, int states)
{
    cout << "TABLE: R" << n << endl;
    for(int i = 1; i <= states; i++)
    {
        for(int j = 1; j <= states; j++)
        {
            cout << "R_" << i << j << "(" << n << "): " << findRE( n, i, j ) << endl;
        }
    }
    cout << endl;
}

int main()
{

    // cout << "Number of states: ";
    cin >> states;
    // cout << "Number of symbols: ";
    cin >> symbols;

    for(int i = 0; i <= states; i++)
    {
        for(int j = 0; j <= symbols; j++)
        {
            cin >> table[i][j];
        }
    }

    RE(0, states);
    RE(1, states);
    RE(2, states);

    return 0;
}