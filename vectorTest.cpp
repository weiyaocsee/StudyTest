#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void MyPrint(int n)
{
    cout << n <<endl;
}

void test01()
{
    vector <int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    // for(vector<int>::iterator it = v.begin();it != v.end();it++)
    // {
    //     cout << *it << endl;
    // }

    for_each(v.begin(), v.end(), MyPrint);

}

int main()
{
    test01();
    cout << "test" << endl;

    return 0;
}