#include <iostream> 
#include<fstream> 
#include<cstdio> 
using namespace std;
int main()
{
    FILE *fptr;
    char fileName[30], ch;
    fstream fps, fpt;
    cout << "Enter the Name of File: ";

    gets(fileName);
    fps.open(fileName, fstream::out);
    if (!fps)
    {
        cout << "\nError Occurred while Opening the Source File!";
        return 0;
    }
    fpt.open("tmp.txt", fstream::in);
    if (!fpt)
    {
        cout << "\nError Occurred while Opening/Creating tmp File!";
        return 0;
    }
    while (fpt >> noskipws >> ch)
    {
        ch = ch - 100;
        fps << ch;
    }
    fps.close();
    fpt.close();

    fptr = fopen(fileName, "r");
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
    ch = fgetc(fptr);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = fgetc(fptr);
    }
    fclose(fptr);
    cout << "\nFile '" << fileName << "' Decrypted Successfully!";
    cout << endl;
    return 0;
}
