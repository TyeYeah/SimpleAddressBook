#include <iostream>
#include <stdio.h>
#include <windows.h>
#include "MailList.h"
using namespace std;


void Menu()
{
    cout<<endl;
    int a=750;
    Sleep(a);
    cout<<"         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    Sleep(a);
    cout<<"                 Simple";
    Sleep(a);
    cout<<"         Address";
    Sleep(a);
    cout<<"         Book\n";
    cout<<'\n';
    cout<<"         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    Sleep(a-700);
    cout<<"         ~~ 1-------Show All                               ~~\n";
    Sleep(a-700);
    cout<<"         ~~ 2-------Add                                    ~~\n";
    Sleep(a-700);
    cout<<"         ~~ 3-------Build HashTable                        ~~\n";
    Sleep(a-700);
    cout<<"         ~~ 4-------Fuzzy Query                            ~~\n";
    Sleep(a-700);
    cout<<"         ~~ 5-------Query By Name                          ~~\n";
    Sleep(a-700);
    cout<<"         ~~ 6-------Query By Phone                         ~~\n";
    Sleep(a-700);
    cout<<"         ~~ 7-------Delete Record                          ~~\n";
    Sleep(a-700);
    cout<<"         ~~ 0-------Exit                                   ~~\n";
    Sleep(a-700);
    cout<<"         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    Sleep(a-700);
    cout<<"         Help:\n";
    cout<<"         1.After added, choose 3 to build hash table first and then do query\n";
    cout<<"         2.Before doing query by name, set name as hash table's key\n";
    cout<<"         3.Before doing query by phone number, set phone number as hash table's key\n";
}
void Mexit()
{
    int i;
    int a=800;
    for(i=1; i<=4; i++)
        cout<<endl;
    cout<<"          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    Sleep(a-700);
    cout<<"         ~~                                                 ~~\n";
    Sleep(a-700);
    cout<<"         ~~             Simple Address Book                 ~~\n";
    Sleep(a-700);
    cout<<"         ~~                                                 ~~\n";
    Sleep(a-700);
    cout<<"         ~~             Thanks for using                    ~~\n";
    Sleep(a-700);
    cout<<"         ~~                                                 ~~\n";
    Sleep(a-700);
    cout<<"         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}
void Smenu()
{
    cout<<"         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout<<"         ~~ 1-------Show All                               ~~\n";
    cout<<"         ~~ 2-------Add                                    ~~\n";
    cout<<"         ~~ 3-------Build HashTable                        ~~\n";
    cout<<"         ~~ 4-------Fuzzy QUery                            ~~\n";
    cout<<"         ~~ 5-------Query By name                          ~~\n";
    cout<<"         ~~ 6-------Query By Phone                         ~~\n";
    cout<<"         ~~ 7-------Delete Record                          ~~\n";
    cout<<"         ~~ 0-------Exit                                   ~~\n";
    cout<<"         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}
int uMenu()
{
    int a=800;
    cout<<"         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    Sleep(a-700);
    cout<<"                          Start using Address book? \n";
    cout<<"         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n";
    Sleep(a-700);
    cout<<"                             yes  or  no\n";
    cout<<"         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n";

    string ch;
    cin>>ch;
    if(ch=="yes")
    {
        cout<<"Start Editing"<<endl;
        cout<<"~~~Please input function order~~~"<<endl;
        int index;
        cin>>index;
        while(index<0||index>9)
        {
            cout<<"~~~No such order, please retype~~~"<<endl;
            cin>>index;
        }

        switch(index)
        {
        case 1:
            cout<<"Show All: "<<endl;
            return 1;
        case 2:
            cout<<"Add: "<<endl;
            return 2;
        case 3:
            cout<<"Build HashTable: "<<endl;
            return 3;
        case 4:
            cout<<"Fuzzy Query: ";
            return 4;
        case 5:
            cout<<"Query by name: ";
            return 5;
        case 6:
            cout<<"Query by name: ";
            return 6;
        case 7:
            cout<<"Delete Record";
            return 7;
        case 9:
            cout<<"Exit";
            return 9;
        case 8:
            cout<<"Edit Some Record";
            return 8;
        default:
            return 9;
        }
    }
    else
    {
        return 9;
    }
}

