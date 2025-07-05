#include <stdio.h>
#include <string.h>

int main()
{
    char s[1000];
    scanf("%s", s);
    printf("%d\n",longest_valid(s));
    return 0;
}

int longest_valid(const char* s)
{
    int left = 0; // close )
    int right = 0; // open (
    int max_len = 0; // max valid lenght
    int n = strlen(s);

    //left to right
    for (int i =0; i< n; i++)
    {
        if (s[i] == '(') left++;
        else right++;
        if (left == right)
        {
          int len = 2*right;
          if (len > max_len) 
          {max_len = len;}
        } 
        else if (right>left)
        {    
            //invalid
            left = 0;
            right = 0;
        }
    }

    // right to left
    left = 0;
    right = 0;
    for (int i = n - 1; i >=0; i--)
    {
        if (s[i] == ')') right++;
        else left++;
        if (left == right)
        {
            int len = 2*left;
            if (len > max_len) 
            {max_len = len;}
        } 
        else if (left > right)
        {
            //invalid
            left = 0;
            right = 0;
        }
    }
    return max_len;
}
