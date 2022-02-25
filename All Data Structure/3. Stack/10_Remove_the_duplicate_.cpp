#include<iostream>
#include<string.h>
using namespace std;

void duplicate(char *str)
{
    int stkptr = -1;
    int i = 0;
    int len = strlen(str);
    while(i<len)
    {
        if(str[stkptr] == -1 || str[stkptr]!=str[i])
        {
            stkptr++;
            str[stkptr] = str[i];
            i++;
        }
        else
        {
            while(i<len && str[stkptr]==str[i])
            {
                
                i++;
                stkptr--;
            }
        }
    }
     str[stkptr+1] = '\0';
}
int main()
{
    char expression[] ="mississippi";
    duplicate(expression);
    cout<<expression<<endl;

    
    return 0;
}