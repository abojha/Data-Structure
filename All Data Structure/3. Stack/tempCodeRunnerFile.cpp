#include<iostream>
#include<string.h>
using namespace std;

void *duplicate_delete(char *temp)
{
    int stkptr = -1;
    int i = 0;
    int len = strlen(temp);
    while(i < len)
    {
        if(stkptr == -1 || temp[stkptr] != temp[i])
        {
            stkptr++;
            temp[stkptr] = temp[i];
            i++;
        }
        else
        {
            while(i < len && temp[stkptr] == temp[i])
            {
                i++;
            }
            stkptr--;
        }
    }
    temp[stkptr+1] = '\0';
    cout<<temp<<endl;
}
int main()
{
    char temp[] = "tauuuiiiu";
    duplicate_delete(temp);
    return 0;
}