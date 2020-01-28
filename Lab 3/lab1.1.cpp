#include <iostream>
#include <string.h>

using namespace std;

void _p(char i);
void _q(char i);
void _r(char i);

char p(char inp);
char q(char inp);
char r(char inp);

void ECLOSER(char i);
void checkString(string inpStr);

string input_string;
char current_state = 'p';

char p(char inp)
{
    if (inp == 'e') current_state = 'N';
    else if (inp == 'a') current_state = 'p';
    else if (inp == 'b') current_state = 'q';
    else if (inp == 'c') current_state = 'r';
    return current_state;
}

char q(char inp)
{
    if (inp == 'e') current_state = 'p';
    else if (inp == 'a') current_state = 'q';
    else if (inp == 'b') current_state = 'r';
    else if (inp == 'c') current_state = 'N';
    return current_state;
}

char r(char inp)
{
    if (inp == 'e') current_state = 'q';
    else if (inp == 'a') current_state = 'r';
    else if (inp == 'b') current_state = 'N';
    else if (inp == 'c') current_state = 'p';
    return current_state;
}

void _p(char i)
{
    cout << 'p';
    if(i == 'e')
    {
        if (p(i) == 'N') return;
        else
        {
            if (p(i) == 'p') _p(i);
            else if (p(i) == 'q') _q(i);
            else if (p(i) == 'r') _r(i);
        }
    }
}

void _q(char i)
{
    cout << 'q';
    if(i == 'e')
    {
        if (q(i) == 'N') return;
        else
        {
            if (q(i) == 'p') _p(i);
            else if (q(i) == 'q') _q(i);
            else if (q(i) == 'r') _r(i);
        }
    }
}

void _r(char i)
{
    cout << 'r';
    if(i == 'e')
    {
        if (r(i) == 'N') return;
        else
        {
            if (r(i) == 'p') _p(i);
            else if (r(i) == 'q') _q(i);
            else if (r(i) == 'r') _r(i);
        }
    }
}

void ECLOSER(char i)
{
    cout << "ECLOSER(" << i << "): ";
    if (i == 'p') _p('e');
    else if (i == 'q') _q('e');
    else if (i == 'r') _r('e');
    cout << endl;
}

void checkString(string inpStr)
{
    int c_a = 0, c_b = 0, c_c = 0;
    for (int i = 0; i < inpStr.length(); i++)
    {
        if (inpStr[i] == 'a') c_a++;
        else if (inpStr[i] == 'b') c_b++;
        else if (inpStr[i] == 'c') c_c++;
    }
    if(c_c == 1 || c_b >= 2) cout << "ACCEPTED" << endl;
    else cout << "REJECTED" << endl;
}

int main()
{
    cout << endl;
    ECLOSER('p');
    ECLOSER('q');
    ECLOSER('r');

    while (1)
    {
        cout << "\nEnter string of length atmost three: ";
        cin >> input_string;
        int s = input_string.length();

        if (s > 3)
        {
            cout << "\nInput String length is greater than 3.\nProgram is Terminating.\n";
            return -1;
        }
        else checkString(input_string);
    }
    
    return 0;
}