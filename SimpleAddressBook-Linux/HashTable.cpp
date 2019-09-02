#include <stdlib.h>
#include "HashTable.h"
using namespace std;

Record::Record(string nname,int aage,string pphoneNumber,string ssex,string cclassName)
{
    name=nname;
    age=aage;
    phoneNumber=pphoneNumber;
    sex=ssex;
    className=cclassName;
}
Record::Record()
{
    name="a";
    age=0;
    phoneNumber="1";
    sex="";
    className="";
}
Record::Record(Record& n)
{
    name=n.name;
    age=n.age;
    phoneNumber=n.phoneNumber;
    sex=n.sex;
    className=n.className;
}

Record& Record::operator= (Record& r)
{
    name=r.name;
    age=r.age;
    phoneNumber=r.phoneNumber;
    sex=r.sex;
    className=r.className;
    return *this;
}
ostream& operator <<(ostream&os,const Record& r)
{
    os<<r.name<<"\t"<<r.age<<"\t"<<r.phoneNumber<<"\t"<<r.sex<<"\t"<<r.className;
    return os;
}


RecordNode::RecordNode(Record rr,RecordNode* rd)
{
    r=rr;
    next=rd;
}
RecordNode::RecordNode()
{
    next=NULL;
}
RecordNode::RecordNode(RecordNode& n)
{
    r.name=n.r.name;
    r.age=n.r.age;
    r.phoneNumber=n.r.phoneNumber;
    r.sex=n.r.sex;
    r.className=n.r.className;
    next=NULL;
}
RecordNode& RecordNode::operator= (RecordNode& rrr)
{
    r.name=rrr.r.name;
    r.age=rrr.r.age;
    r.phoneNumber=rrr.r.phoneNumber;
    r.sex=rrr.r.sex;
    r.className=rrr.r.className;
    return *this;
}


long ELFHash(string str)//Hash function
{
    long hash = 0;
    long x    = 0;
    for(int i = 0; i < (signed)str.length(); i++)
    {
        hash = (hash << 4) + str[i];
        if((x = hash & 0xF0000000L) != 0)
        {
            hash ^= (x >> 24);
        }
        hash &= ~x;
    }
    return hash;
}



StringHash::StringHash(string t)
{
    type=t;
    for(int i=0; i<100; i++)
        a[i]=NULL;
}
int StringHash::getPos(string ss)//get position
{
    int nn=ELFHash(ss);
    int nnn=nn%100;
    return nnn;
}

void StringHash::add(RecordNode& newr,string type)
{
    if(type=="name")//add by name
    {
        if(a[getPos(newr.r.name)]!=NULL)
        {
            RecordNode* head;
            RecordNode* pre=a[getPos(newr.r.name)];
            for(head=a[getPos(newr.r.name)]->next; head!=NULL; head=head->next)
            {
                pre=pre->next;
            }
            pre->next=&newr;
        }
        else
            a[getPos(newr.r.name)]=&newr;
    }
    else if(type=="phone")//add by phone
    {
        if(a[getPos(newr.r.phoneNumber)]!=NULL)
        {
            RecordNode* head;
            RecordNode* pre=a[getPos(newr.r.phoneNumber)];
            for(head=a[getPos(newr.r.phoneNumber)]->next; head!=NULL; head=head->next)
            {
                pre=pre->next;
            }
            pre->next=&newr;
        }
        else
            a[getPos(newr.r.phoneNumber)]=&newr;
    }


}

RecordNode* StringHash::Search(string nname,string pphone,int i,string type)
{
    if(type=="name")//query by name
    {
        if(i==0)//query by name and phone
        {
            RecordNode* head;
            for(head=a[getPos(nname)]; head!=NULL; head=head->next)
            {
                if(head->r.name==nname&&head->r.phoneNumber==pphone)
                {
                    RecordNode* hh=new RecordNode(*head);
                    //  cout<<head->r<<endl;
                    return hh;
                }
            }
            return NULL;

        }

        else if (i==1)//query by name, and return first record
        {
            RecordNode* head;
            queue<RecordNode*> qqq;
            RecordNode* h=NULL;
            for(head=a[getPos(nname)]; head!=NULL; head=head->next)
            {
                if(head->r.name==nname)
                {
                    RecordNode* hh=new RecordNode(*head);
                    qqq.push(hh);//stack records with same name
                }

            }
            if(!qqq.empty())
            {
                h=qqq.front();
                //qqq.pop();
                for(RecordNode* head=h; !qqq.empty(); head=head->next)
                {
                    qqq.pop();
                    if(qqq.empty())
                        return h;
                    else
                        head->next=qqq.front();
                    //print phone with same name

                    // cout<<head->r<<endl;
                }

            }
            return h;
        }
        return NULL;
    }
    else if(type=="phone")//query by phone
    {
        if(i==0)
        {
            RecordNode* head;
            for(head=a[getPos(pphone)]; head!=NULL; head=head->next)
            {
                if(head->r.name==nname&&head->r.phoneNumber==pphone)
                {
                    RecordNode* hh=new RecordNode(*head);
                    //cout<<head->r<<endl;
                    return hh;
                }
            }
            return NULL;

        }
        else if(i==1)
        {
            RecordNode* head;
            queue<RecordNode*> qqq;
            RecordNode* h=NULL;
            for(head=a[getPos(pphone)]; head!=NULL; head=head->next)
            {
                if(head->r.phoneNumber==pphone)
                {
                    RecordNode* hh=new RecordNode(*head);
                    qqq.push(hh);
                }

            }
            if(!qqq.empty())
            {
                h=qqq.front();
                //qqq.pop();
                for(RecordNode* head=h; !qqq.empty(); head=head->next)
                {
                    qqq.pop();
                    if(qqq.empty())
                        return h;
                    else
                        head->next=qqq.front();
                    //cout<<head->r<<endl;
                }

            }
            return h;
        }

        return NULL;
    }
    return NULL;
}



bool StringHash::del(string name,string phone,string type)
{

    if(type=="name")
    {
        RecordNode* pre=a[getPos(name)];
        for(RecordNode* head=a[getPos(name)]; head!=NULL;)
        {
            if(pre==head&&name==head->r.name&&phone==head->r.phoneNumber)
            {
                a[getPos(name)]=a[getPos(name)]->next;
                return true;
            }
            else if(name==head->r.name&&phone==head->r.phoneNumber)
            {
                pre->next=head->next;
                return true;//free(head);
            }
            pre=head;
            head=head->next;
        }


    }
    else if(type=="phone")
    {

        RecordNode* pre=a[getPos(phone)];
        for(RecordNode* head=a[getPos(phone)]; head!=NULL;)
        {
            if(pre==head&&phone==head->r.phoneNumber&&name==head->r.name)
            {
                a[getPos(phone)]=a[getPos(phone)]->next;
                return true;
            }
            else if(phone==head->r.phoneNumber&&name==head->r.name)
            {
                pre->next=head->next;
                return true;//free(head);
            }
            pre=head;
            head=head->next;
        }


    }

    return false;
}
/*bool StringHash::Set(RecordNode& oldr,RecordNode& newr,string type)//modify on class to another existed one

RecordNode* nnn=new RecordNode(newr);
    del(oldr.r.name,oldr.r.phoneNumber,type);
    add(*nnn,type);
    return true;
}*/

char* trans(string src)//transfer string to char*
{
    char *dst = new char[255];
    int i;
    for(i=0; i<=(signed)src.length(); i++)
        dst[i]=src[i];
    dst[i] = '\0';
    return dst;
}


RecordNode* StringHash::SSearch(string str,string type)//Fuzzy Query
{
    queue<RecordNode*> qqq;
    RecordNode* h=NULL;
    if(type=="")
    {
        for(int i=0; i<100; i++)
        {
            if(a[i]!=NULL)
            {
                //
                if(a[i]->r.name.find(str)!=string::npos||a[i]->r.sex.find(str)!=string::npos||a[i]->r.phoneNumber.find(str)!=string::npos||a[i]->r.className.find(str)!=string::npos)
                {
                    RecordNode* hh=new RecordNode(*a[i]);
                    qqq.push(hh);
                }
            }
            else
                continue;
            RecordNode*p=a[i];
            // cout<<p->r<<endl;
            while(p->next!=NULL)
            {
                p=p->next;
                if(p->r.name.find(str)!=string::npos||p->r.sex.find(str)!=string::npos||p->r.phoneNumber.find(str)!=string::npos||p->r.className.find(str)!=string::npos)
                {
                    RecordNode* hh=new RecordNode(*p);
                    qqq.push(hh);
                }
            }
        }




    }
    else if(type=="name")
    {
        for(int i=0; i<100; i++)
        {
            if(a[i]!=NULL)
            {
                //
                if(a[i]->r.name.find(str)!=string::npos)
                {
                    RecordNode* hh=new RecordNode(*a[i]);
                    qqq.push(hh);
                }
            }

            else
                continue;
            RecordNode*p=a[i];
            while(p->next!=NULL)
            {
                p=p->next;
                //
                if(p->r.name.find(str)!=string::npos)
                {
                    RecordNode* hh=new RecordNode(*p);
                    qqq.push(hh);
                }
            }
        }

    }
    else if(type=="age")
    {
        for(int i=0; i<100; i++)
        {
            if(a[i]!=NULL)
            {
                //
                if(atoi(trans(str))==a[i]->r.age)
                {
                    RecordNode* hh=new RecordNode(*a[i]);
                    qqq.push(hh);
                }
            }

            else
                continue;
            RecordNode*p=a[i];
            while(p->next!=NULL)
            {
                p=p->next;
                //
                if(atoi(trans(str))==p->r.age)
                {
                    RecordNode* hh=new RecordNode(*p);
                    qqq.push(hh);
                }
            }
        }


    }
    else if(type=="phone")
    {
        for(int i=0; i<100; i++)
        {
            if(a[i]!=NULL)
            {
                //
                if(a[i]->r.phoneNumber.find(str)!=string::npos)
                {
                    RecordNode* hh=new RecordNode(*a[i]);
                    qqq.push(hh);
                }
            }

            else
                continue;
            RecordNode*p=a[i];
            while(p->next!=NULL)
            {
                p=p->next;
                //
                if(p->r.phoneNumber.find(str)!=string::npos)
                {
                    RecordNode* hh=new RecordNode(*p);
                    qqq.push(hh);
                }
            }
        }



    }
    else if(type=="sex")
    {
        for(int i=0; i<100; i++)
        {
            if(a[i]!=NULL)
            {
                //
                if(a[i]->r.sex.find(str)!=string::npos)
                {
                    RecordNode* hh=new RecordNode(*a[i]);
                    qqq.push(hh);
                }
            }

            else
                continue;
            RecordNode*p=a[i];
            while(p->next!=NULL)
            {
                p=p->next;
                //
                if(p->r.sex.find(str)!=string::npos)
                {
                    RecordNode* hh=new RecordNode(*p);
                    qqq.push(hh);
                }
            }

        }


    }
    else if(type=="class")
    {
        for(int i=0; i<100; i++)
        {
            if(a[i]!=NULL)
            {
                //
                if(a[i]->r.className.find(str)!=string::npos)
                {
                    RecordNode* hh=new RecordNode(*a[i]);
                    qqq.push(hh);
                }
            }

            else
                continue;
            RecordNode*p=a[i];
            while(p->next!=NULL)
            {
                p=p->next;
                //
                if(p->r.className.find(str)!=string::npos)
                {
                    RecordNode* hh=new RecordNode(*p);
                    qqq.push(hh);
                }
            }
        }


    }
    if(!qqq.empty())
    {
        h=qqq.front();
        //qqq.pop();
        for(RecordNode* head=h; !qqq.empty(); head=head->next)
        {
            qqq.pop();
            if(qqq.empty())
                return h;
            else
                head->next=qqq.front();
        }

    }
    return h;
}
