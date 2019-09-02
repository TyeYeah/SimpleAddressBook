#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include "MailList.h"
using namespace std;


void Menu()
{
    cout<<endl;
    float a=0.75;
    sleep(a);
    cout<<"         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    sleep(a);
    cout<<"                 Simple";
    sleep(a);
    cout<<"         Address";
    sleep(a);
    cout<<"         Book\n";
    cout<<'\n';
    cout<<"         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    sleep(a-0.7);
    cout<<"         ~~ 1-------Show All                               ~~\n";
    sleep(a-0.7);
    cout<<"         ~~ 2-------Add                                    ~~\n";
    sleep(a-0.7);
    cout<<"         ~~ 3-------Build HashTable                        ~~\n";
    sleep(a-0.7);
    cout<<"         ~~ 4-------Fuzzy Query                            ~~\n";
    sleep(a-0.7);
    cout<<"         ~~ 5-------Query By Name                          ~~\n";
    sleep(a-0.7);
    cout<<"         ~~ 6-------Query By Phone                         ~~\n";
    sleep(a-0.7);
    cout<<"         ~~ 7-------Delete Record                          ~~\n";
    sleep(a-0.7);
    cout<<"         ~~ 0-------Exit                                   ~~\n";
    sleep(a-0.7);
    cout<<"         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    sleep(a-0.7);
    cout<<"         Help:\n";
    cout<<"         1.After added, choose 3 to build hash table first and then do query\n";
    cout<<"         2.Before doing query by name, set name as hash table's key\n";
    cout<<"         3.Before doing query by phone number, set phone number as hash table's key\n";
}
void Mexit()
{
    int i;
    float a=0.8;
    for(i=1; i<=4; i++)
        cout<<endl;
    cout<<"          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    sleep(a-0.7);
    cout<<"         ~~                                                 ~~\n";
    sleep(a-0.7);
    cout<<"         ~~             Simple Address Book                 ~~\n";
    sleep(a-0.7);
    cout<<"         ~~                                                 ~~\n";
    sleep(a-0.7);
    cout<<"         ~~             Thanks for using                    ~~\n";
    sleep(a-0.7);
    cout<<"         ~~                                                 ~~\n";
    sleep(a-0.7);
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
    float a=0.8;
    cout<<"         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    sleep(a-0.7);
    cout<<"                          Start using Address book? \n";
    cout<<"         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n";
    sleep(a-0.7);
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

