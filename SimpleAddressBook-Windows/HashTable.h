#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Record
{
public:
    string name;
    int age;
    string phoneNumber;
    string sex;
    string className;
    Record(string nname,int aage,string pphoneNumber,string ssex,string cclassName);
    Record();

    Record(Record& n);

    Record& operator= (Record& r);
    friend ostream& operator <<(ostream&os,const Record& r);
};
class RecordNode
{
public:
    Record r;
    RecordNode* next=NULL;
    RecordNode(Record rr,RecordNode* rd=NULL);
    RecordNode();

    RecordNode(RecordNode& n);

    RecordNode& operator= (RecordNode& rrr);

};

long ELFHash(string str);//Hash function

char* trans(string src);//transfer string to char*

class StringHash
{
public:
    RecordNode* a[100];
    string type;
    StringHash(string t="");

    int getPos(string ss);

    void add(RecordNode& newr,string type);

    RecordNode* Search(string nname,string pphone,int i,string type);

    RecordNode*SSearch(string str,string type="");//Fuzzy Query

    bool del(string name,string phone,string type);
    // bool Set(RecordNode& oldr,RecordNode& newr,string type);

};
