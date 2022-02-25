#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<stack>

using namespace std;

char * duplicate_delete(char *temp)
{
    int stkptr = -1;
    int len = strlen(temp);
    int i = 0;
    while(i<len)
    {
        if(stkptr == -1 || temp[stkptr]!=temp[i])
        {
            stkptr++;
            temp[stkptr] = temp[i];
            i++;
        }
        else
        {
            while(i<len && temp[stkptr] == temp[i])
            i++;
            stkptr--;
            
        }
    }
    temp[stkptr+1] = '\0';
    cout<<temp<<endl;

}


int main()
{

    return 0;
}