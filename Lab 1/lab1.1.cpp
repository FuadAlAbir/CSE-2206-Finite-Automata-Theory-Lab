#include <iostream>

using namespace std;

string input_string;
string current_state = "q0";

char q0(char inp)
{
    if(inp == '0')
    {
        current_state = "q1";
    }
    else
    {
        current_state = "q0";
    }
    return current_state[1];
}

char q1(char inp)
{
    if(inp == '0')
    {
        current_state = "q1";
    }
    else
    {
        current_state = "q2";
    }
    return current_state[1];
}
char q2(char inp)
{
    if(inp == '0')
    {
        current_state = "q1";
    }
    else
    {
        current_state = "q3";
    }
    return current_state[1];
}
char q3(char inp)
{
    if(inp == '0')
    {
        current_state = "q3";
    }
    else
    {
        current_state = "q3";
    }
    return current_state[1];
}

void checkString(string inpStr)
{
    current_state = "q0";
    cout << "Initial State: " << current_state << endl;

    for(int i = 0; i < inpStr.size(); i++)
    {
        cout << "Input Char: " << inpStr[i] << " ";
        int state = current_state[1] - 48;
        cout << "\tCurrent State: " << current_state;
        switch(state)
        {
            case 0: q0(inpStr[i]); break;
            case 1: q1(inpStr[i]); break;
            case 2: q2(inpStr[i]); break;
            case 3: q3(inpStr[i]); break;
        }
        cout << "\tOutput State: " << current_state << endl;
    }
}
int main()
{
    cout << "Input String: ";
    cin >> input_string;
    int flag = 0;

    /************************* Brute force ****************************/
    /*
    for(int i = 0; i < input_string.size(); i++)
    {
        if(input_string[i] == '0' && input_string[i + 1] == '1' && input_string[i + 2] == '1')
        {
            cout << "Accepted" << endl;
            flag = 1;
            break;
        }

    }
    if(flag == 0) cout << "Rejected" << endl;
    */

    /*********************** Transition Table **************************/
    cout << "\n\t|\t0\t|\t1\n----------------------------------------\n";
    cout << "->q0\t|\tq"<< q0('0') <<"\t|\tq" << q0('1') << "\n  q1\t|\tq" << q1('0') << "\t|\tq" << q1('1') << "\n  q2\t|\tq" << q2('0') << "\t|\tq" << q2('1')
         <<"\n *q3\t|\tq" << q3('0') << "\t|\tq" << q3('1') <<"\n\n";

    checkString(input_string);

    if(current_state == "q3") cout << "Accepting State: " << current_state << endl;
    else  cout << "Rejecting State: " << current_state << endl;
}
