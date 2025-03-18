#include <iostream>
#include <string>
#include <vector>
#include <map>;

using namespace std;

class Worker
{
    public:
    Worker(string name, int Salary)
    {
        this->m_Name = name;
        this->m_Salary = Salary;
    }
    string m_Name;
    int m_Salary;
};

void CreatWorker(vector<Worker>&vWK)
{
    string NameSeed = "ABCDEFGHIJ";
    for (int i = 0; i < 10; i++)
    {
        string Name = "员工";
        Name += NameSeed[i];
        int sal = rand()  % 10000 + 10000;
        Worker wk(Name, sal);
        vWK.push_back(wk);
    }
}

void SetGroup(vector<Worker> &v, multimap<int, Worker> &m)
{
    for(vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
    {
        //cout << it->m_Name << " " << it->m_Salary << endl;
        int PartID = rand() % 3;
        m.insert(make_pair(PartID, *it));
    }
}

void ShowWorker(multimap<int, Worker> &m)
{
    multimap<int, Worker> :: iterator pos = m.find(0);
    int num = m.count(0);
    int index = 0;
    for(;pos != m.end() && index < num; pos++, index++)
    {
        cout << pos->second.m_Name << " " << pos->second.m_Salary << endl;
    }
}

int main()
{
    vector<Worker> vWk;
    CreatWorker(vWk);
    multimap<int, Worker> mWk;
    SetGroup(vWk, mWk);
    ShowWorker(mWk);
}