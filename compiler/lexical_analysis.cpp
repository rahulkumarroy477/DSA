#include <bits/stdc++.h>
using namespace std;

vector<string> tokenization(string input)
{
    vector<string> ans;
    
}
int main()
{
    FILE *fp;
    string input;
    fp = fopen("test.c", "r");
    char ch;
    while (ch != EOF)
    {
        ch = fgetc(fp);
        // printf("%c",ch);
        input.push_back(ch);
    }
    fclose(fp);
    // cout << input;
    vector<string> tokens = tokenization(input);
    return 0;
}