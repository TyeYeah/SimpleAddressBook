#include <iostream>
#include "MailList.h"
#include "Interface.h"
using namespace std;

int main()
{
    StringHash a;//use "name" as key
    StringHash b;//use "phone" as key
    string type;
    string name;
    string phone;
    string str;//string used in fuzzy query
    int text;//function flag
    int i;
    Menu();
    text=uMenu();
    while(1)
    {

        if(text==1)
        {
            Print(a);
        }
        if(text==2)
        {
            cout<<"Choose to add record according to :name or phone? "<<endl;
            cin>>type;
            if(type=="name")
            {
                cout<<"Please input name, age, phone number, sex and class name: ";
                RecordNode* temp1=new RecordNode();
                cin>>temp1->r.name;
                cin>>temp1->r.age;
                cin>>temp1->r.phoneNumber;
                cin>>temp1->r.sex;
                cin>>temp1->r.className;
                a.add(*temp1,type);
                cout<<endl;
                cout<<"Successfully added"<<endl;

            }
            if(type=="phone")
            {
                RecordNode* temp2=new RecordNode();
                cout<<"Please input name, age, phone number, sex and class name: ";
                cin>>temp2->r.name;
                cin>>temp2->r.age;
                cin>>temp2->r.phoneNumber;
                cin>>temp2->r.sex;
                cin>>temp2->r.className;
                b.add(*temp2,type);
                cout<<endl;
                cout<<"Successfully added"<<endl;
            }
        }
        if(text==3)
        {
            readFile(a);
            readFile(b);
            cout<<"Address book successfully built"<<endl;
        }

        if(text==4)
        {
            cout<<"Please input strings you want to match and which part to match with, like: 20 age ;"<<endl;
            cout<<"Please input string: ";
            cin>>str;
            cout<<"Please input which part: ";
            cin>>type;

            for(RecordNode* rr=a.SSearch(str,type); rr!=NULL; rr=rr->next)
            {
                cout<<rr->r<<endl;
            }
            cout<<endl;

        }
        if(text==5)
        {
            type="name";
            i=1;
            cout<<"Please input name you want to search: ";
            cin>>name;
            phone="";

            for(RecordNode* rr=a.Search(name,phone,i,type); rr!=NULL; rr=rr->next)
            {
                cout<<rr->r<<endl;
            }

        }
        if(text==6)
        {
            type="phone";
            i=1;
            cout<<"Please input he/her phone number: ";
            cin>>phone;
            name="";

            for(RecordNode* rr=b.Search(name,phone,i,type); rr!=NULL; rr=rr->next)
            {
                cout<<rr->r<<endl;
            }
        }
        if(text==7)
        {
            cout<<"Please input name and phone number: ";
            cin>>name;
            cin>>phone;
            type="name";
            a.del(name,phone,type);
            type="phone";
            b.del(name,phone,type);
            cout<<"Successfully deleted"<<endl;
        }
        if(text==8)
        {
            cout<<"Please input name and phone number: ";
            cin>>name;
            cin>>phone;
            cout<<"Please input name, age, phone number, sex and class name: "<<endl;
            RecordNode* newr=new RecordNode();
            cin>>newr->r.name>>newr->r.age>>newr->r.phoneNumber>>newr->r.sex>>newr->r.className;
            type="name";
            //RecordNode* r1=a.Search(name,phone,0,type);
            //a.Set(*r1,*newr,type);
            a.del(name,phone,type);
            a.add(*newr,type);
            type="phone";
            //RecordNode* r2=a.Search(name,phone,0,type);
            //b.Set(*r2,*newr,type);
            b.del(name,phone,type);
            b.add(*newr,type);

        }
        if(text==9)
        {
            cout<<"save all you edited this time? y or n: "<<endl;
            char t;
            cin>>t;
            if(t=='y')
            {
                writeFile(a);
                writeFile(b);
                Mexit();
                break;
            }
            if(t=='n')
            {
                Mexit();
            }
            break;
        }
        Smenu();
        //cout<<"~~~Please input function order~~~"<<endl;
        cin>>text;
    }
    return 0;
}
