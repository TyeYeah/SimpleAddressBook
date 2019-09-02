#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "MailList.h"
string fpath="D://";    //file path
string intype;  //input file's format

void readFile(StringHash &maillist)     //read file/ import data
{
    cout<<"Please specify the file path(the format should be TXT or CSV): ";          //specify the file path
    cin>>fpath;
    cout<<endl;
    string s;   //temporary save one record
    string name;
    int age;
    string phoneNumber;//temporary save a item in one record
    string sex;
    string className;
    int a=fpath.length()-4;
    GetFormat(a);
    while(1)
    {
        if(intype==".txt"||intype==".TXT"||intype==".txT"||intype==".tXt"
                ||intype==".txT"||intype==".Txt"||intype==".TxT"||intype==".TXt"
                ||intype==".CSV"||intype==".csv"||intype==".cSv"||intype==".csV"
                ||intype==".Csv"||intype==".CSv"||intype==".cSV"||intype==".CsV")
            break;
        else
        {
            cout<<"Wrong file format! Retype the file path please: ";
            cin>>fpath;
            cout<<endl;
            a=fpath.length()-4;
            GetFormat(a);
        }
    }

    ifstream infile;
    infile.open(fpath.data());   //Link file stream obj with file
    while(!infile.is_open())   //if failed reset path
    {
        cout<<"Wrong Path! Retype the file path please: ";
        cin>>fpath;                //reset path
        infile.open(fpath.data()); // try to open
        cout<<endl;
        a=fpath.length()-4;
        GetFormat(a);
        while(1)
        {
            if(intype==".txt"||intype==".TXT"||intype==".txT"||intype==".tXt"
                    ||intype==".txT"||intype==".Txt"||intype==".TxT"||intype==".TXt"
                    ||intype==".CSV"||intype==".csv"||intype==".cSv"||intype==".csV"
                    ||intype==".Csv"||intype==".CSv"||intype==".cSV"||intype==".CsV")
                break;
            else
            {
                cout<<"Wrong Path! Retype the file path please: ";
                cin>>fpath;
                cout<<endl;
                a=fpath.length()-4;
                GetFormat(a);
            }
        }
    }

    while(1)
    {
        cout<<"Choose one key to set"<<endl;
        cout<<"N:name  P:phoneNumber"<<endl;
        cin>>maillist.type;
        if(maillist.type=="N"||maillist.type=="n"||maillist.type=="name")//choose hash key
        {
            maillist.type="name";
            cout<<"abcd"<<endl;
            break;
        }
        else if(maillist.type=="P"||maillist.type=="p"||maillist.type=="phone")
        {
            cout<<endl;
            maillist.type="phone";
            cout<<"succeed"<<endl;
            break;
        }
        else
            cout<<"Wrong typing! Please retype it"<<endl<<endl;


    }

    if(intype==".txt"||intype==".TXT"||intype==".txT"||intype==".tXt"
            ||intype==".txT"||intype==".Txt"||intype==".TxT"||intype==".TXt")

    {

        while(getline(infile,s))
        {
            if(s!="")
            {
                istringstream is(s);
                is>>name>>age>>phoneNumber>>sex>>className;      //assign values to one record
                if(name.find("name")==name.npos)
                {
                    Record rec(name,age,phoneNumber,sex,className);  //Instantiate this record
                    RecordNode* node=new RecordNode(rec);       //Instantiate this node
                    maillist.add(*node,maillist.type);
                }
            }

        }
    }
    if(intype==".CSV"||intype==".csv"||intype==".cSv"||intype==".csV"
            ||intype==".Csv"||intype==".CSv"||intype==".cSV"||intype==".CsV")
    {
        while(getline(infile,s))
        {
            if(s!="")
            {
                size_t b=0;
                size_t c[4];
                int i=0;
                string a_age;
                for(int j=0; j<4; j++)
                {
                    b=s.find(',',b);
                    c[j]=b;
                    b++;
                }
                i=c[0];
                name=s.substr(0,i);
                i++;
                if (name.find("name")!=name.npos)
                    continue;
                int h=c[1]-c[0]-1;
                a_age=s.substr(i,h);
                istringstream i_age(a_age);
                i_age>>age;
                i=c[1]+1;
                h=c[2]-c[1]-1;
                phoneNumber=s.substr(i,h);
                i=c[2]+1;
                h=c[3]-c[2]-1;
                sex=s.substr(i,h);
                i=c[3]+1;
                className=s.substr(i);
            }
            Record rec(name,age,phoneNumber,sex,className);  //Instantiate this record
            RecordNode* node=new RecordNode(rec);       //Instantiate this node
            maillist.add(*node,maillist.type);
        }
    }
    infile.close();             //close file in stream
}

void writeFile(StringHash &maillist)  //export data
{
    int pos;
    string x;
    while(1)
    {
        cout<<"Set path(or \"no\" to use default)"<<endl;
        cout<<"   Y: yes     N: no"<<endl;
        cin>>x;
        if(x=="N"||x=="n"||x=="no"||x=="No"||x=="NO")
            break;
        if(x=="Y"||x=="y"||x=="yes"||x=="Yes"||x=="YES")
        {
            cout<<endl;
            cout<<"Please set path: ";
            cin>>fpath;
            cout<<endl;
            pos=fpath.length()-4;
            GetFormat(pos);
            while(1)
            {
                if(intype==".txt"||intype==".TXT"||intype==".txT"||intype==".tXt"
                        ||intype==".txT"||intype==".Txt"||intype==".TxT"||intype==".TXt"
                        ||intype==".CSV"||intype==".csv"||intype==".cSv"||intype==".csV"
                        ||intype==".Csv"||intype==".CSv"||intype==".cSV"||intype==".CsV")
                    break;
                else
                {
                    cout<<"Wrong file format! Retype the file path please: ";
                    cin>>fpath;
                    cout<<endl;
                    pos=fpath.length()-4;
                    GetFormat(pos);
                }
            }
            break;
        }
        else
        {
            cout<<"Wrong typing! Please choose again: "<<endl<<endl;
        }
    }

    ofstream oufile;

    oufile.open(fpath.data(),ios::trunc|ios::out);
    while(!oufile.is_open())
    {
        cout<<"Wrong file Path! Retype the file path please: ";
        cin>>fpath;                //reset path
        pos=fpath.length()-4;
        GetFormat(pos);
        while(1)
        {
            if(intype==".txt"||intype==".TXT"||intype==".txT"||intype==".tXt"
                    ||intype==".txT"||intype==".Txt"||intype==".TxT"||intype==".TXt"
                    ||intype==".CSV"||intype==".csv"||intype==".cSv"||intype==".csV"
                    ||intype==".Csv"||intype==".CSv"||intype==".cSV"||intype==".CsV")
                break;
            else
            {
                cout<<"Wrong file format! Retype the file path please: ";
                cin>>fpath;
                cout<<endl;
                pos=fpath.length()-4;
                GetFormat(pos);
            }
        }
        oufile.open(fpath.data(),ios::trunc|ios::out); // try to open specify path file
        cout<<endl;
    }

    if(intype==".CSV"||intype==".csv"||intype==".cSv"||intype==".csV"
            ||intype==".Csv"||intype==".CSv"||intype==".cSV"||intype==".CsV")
    {
        oufile<<"Name"<<","<<"Age"<<","<<"Phone Number"<<","<<"Sex"<<","<<"Class"<<endl;
        for(int i=0; i<100; i++)
        {
            if(maillist.a[i]!=NULL)
            {
                oufile<<maillist.a[i]->r.name<<","<<maillist.a[i]->r.age<<","<<maillist.a[i]->r.phoneNumber
                      <<","<<maillist.a[i]->r.sex<<","<<maillist.a[i]->r.className<<endl;
            }
            else
                continue;
            RecordNode*p=maillist.a[i];
            while(p->next!=NULL)
            {
                p=p->next;
                oufile<<p->r.name<<","<<p->r.age<<","<<p->r.phoneNumber<<","<<p->r.sex<<","<<p->r.className<<endl;
            }
        }

        oufile.close();
    }

    if(intype==".txt"||intype==".TXT"||intype==".txT"||intype==".tXt"
            ||intype==".txT"||intype==".Txt"||intype==".TxT"||intype==".TXt")
    {
        oufile<<"Name"<<"\t"<<"Age"<<"\t"<<"Phone Number"<<"\t"<<"Sex"<<"\t"<<"Class"<<endl;
        for(int i=0; i<100; i++)
        {
            if(maillist.a[i]!=NULL)
            {
                oufile<<maillist.a[i]->r<<endl;
            }
            else
                continue;
            RecordNode*p=maillist.a[i];
            while(p->next!=NULL)
            {
                p=p->next;
                oufile<<p->r<<endl;
            }
        }
        oufile.close();
    }
}

void Print(const StringHash&maillist)  //Traversal output
{
    cout<<"Name"<<"\t"<<"Age"<<"\t"<<"Phone Number"<<"\t"<<"Sex"<<"\t"<<"Class"<<endl;
    for(int i=0; i<100; i++)
    {
        if(maillist.a[i]!=NULL)
        {
            cout<<maillist.a[i]->r<<endl;
        }
        else
            continue;
        RecordNode*p=maillist.a[i];
        while(p->next!=NULL)
        {
            p=p->next;
            cout<<p->r<<endl;
        }
    }
}

void GetFormat(int pos)
{
    if(pos>0)
    {
        intype=fpath.substr (pos);
    }
    else
    {
        while(pos<=0)
        {
            cout<<"Wrong file format! Retype the file path please: ";
            cin>>fpath;
            cout<<endl;
            pos=fpath.length()-4;
        }
        intype=fpath.substr (pos);
    }
}


