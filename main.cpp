#include <iostream>
#include <string.h>
#include "functii.h"

using namespace std;

int main()
{
    stiva s;
    stiva2 s2;
    init(s);
    init2(s2);
    char expresie[20] = "2+3*4-5";

    int index, index_modi;
    for (index = 0; index < strlen(expresie); index++)
    {
        if (isdigit(expresie[index]))
        {
            updateExpresie(expresie[index]);
        }
        else
        {
            updateStack2(s2, expresie[index]);
        }
    }

    while (!isEmpty2(s2))
    {
        updateExpresie(top2(s2));
        pop2(s2);
    }

    for (int i = 0; i < strlen(exprModi); ++i)
        cout << exprModi[i];

    cout << endl;

    char prefix[20] = "";
    strcpy(prefix, exprModi);
    // char prefix[20]= "234*+5-";

    for (index = 0; index < strlen(prefix); index++)
    {
        if (isdigit(prefix[index]))
        {
            updateStack(s, prefix[index]);
        }
        else
        {
            updateExpresie2(s, prefix[index]);
        }
    }

    string rezultat = top(s);

    cout << rezultat;
    pop(s);
    
    cout<<endl;

    cout<<evaluarePrefix(s,rezultat);


    return 0;
}