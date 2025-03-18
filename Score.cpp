#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>

using namespace std;

class Person
{
public:
    Person(string name, int score)
    {
        this->m_Name = name;
        this->m_Score = score;
    }
    int m_Score;
    string m_Name;
};

void CreatPerson(vector<Person> &v)
{
    string NameSeed = "ABCDE";
    for (int i = 0; i < 5; i++)
    {
        string Name = "选手";
        Name += NameSeed[i];
        Person p(Name, 0);
        v.push_back(p);

    }
}

void SetScore(vector<Person> &v)
{
    for(vector<Person> :: iterator it = v.begin(); it != v.end(); it++)
    {
        deque<int> d;
        for(int i = 0; i < 10; i++)
        {
            int score = (rand() % 41) + 60; //取值范围是60-100
            d.push_back(score);
        }
        sort(d.begin(), d.end());
        d.pop_back();
        d.pop_front();
        int sum = 0,avg = 0;
        for(deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
        {
            sum += (*dit);
            //cout << sum << " ";
        }
        avg = sum / d.size();
        (*it).m_Score = avg;
    }
}
int main()
{
    srand((unsigned int)time(NULL));
    vector<Person> v;
    CreatPerson(v);
    SetScore(v);
    for(vector<Person> :: iterator it = v.begin(); it != v.end();it++)
    {
        cout << (*it).m_Name << " " << (*it).m_Score << endl;
    }
}