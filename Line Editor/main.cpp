#include <iostream>

using namespace std;

int main()
{
    cout << "Fuck you!" << endl;
    return 0;
}
/*
EDIT testfile // This is typed at the command prompt
1> The first line // The prompt “1>” is provided by the line editor
2> // prompt updated to show current line number, user enters empty line
3> And another line
4> I 3
3> The second line
4> One more line
5> L
1> The first line
2>
3> The second line
4> One more line
5> And another line // This is now line 5, not 3;
5> D 2 // line 5, since L was issued from line 5;

4> L // line 4, since one line was deleted;
1> The first line
2> The second line // this and the following lines
3> One more line // now have new numbers;
4> And another line
4> E
2. Submission
*/
