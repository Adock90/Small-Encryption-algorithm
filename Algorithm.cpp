#include <iostream>
#include <random>
#include <string>
#include <algorithm>
// ignore for monitoring keyboard
#include <conio.h>

using namespace std;

// encryption algorithm
string Alg(const string &str)
{
    string AlphaNUMANDDASH = "adcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVXYZ1234567890¬!'@£$%^&*()_-+={}[]:;~#/?>.<,|";
    string Cipher = str;
    int C = Cipher.length();
    int ChoiceNum = AlphaNUMANDDASH.length();
    reverse(Cipher.begin(), Cipher.end());
    string fin = "";
    for (int j = 0; j < 100; j++)
    {
        int numS = rand() % (100 - 100 + 1) + 100;
        char sCH = AlphaNUMANDDASH[numS];
        fin[j] = sCH;
    }
    for (int i = 0; i < C; i++)
    {
        int NumChoice = rand() % (ChoiceNum - 0 + 1) + 0;
        int plusNum = rand() % (75 - 75 + 1) + 75;
        char Choice = AlphaNUMANDDASH[NumChoice];
        Cipher[i] = Choice + plusNum;
    }
    return Cipher + fin;
}

// example
int main()
{
    while (true)
    {
        // checks if key pressed
        if (kbhit)
        {
            char ch = getch();
            if ((int)ch == 27)
            {
                cout << "Bye";
                break;
            }
        }
        string input;
        cout << "Enter String\n";
        cin >> input;
        string Encrypt = Alg(input);
        cout << Encrypt << "\n";
    }
}