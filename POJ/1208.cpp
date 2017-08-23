#include<cstdio>
#include<iostream>
#include<list>
#include<string>

using namespace std;
list<int> l[25],temp;
int point[25];

void remove_(int x)
{
    int i = point[x];
    while(l[i].back() != x)
    {
        int t = l[i].back();
        l[t].push_back(t);
        point[t] = t;
        l[i].pop_back();
    }
}

void move_(int x,int y)
{
    int i = point[x], j = point[y];
    while(l[i].back() != x)
    {
        temp.push_back(l[i].back());
        l[i].pop_back();
    }
    l[j].push_back(l[i].back());
    point[x] = j;
    l[i].pop_back();
    while(!temp.empty())
    {
        l[j].push_back(temp.back());
        point[temp.back()] = j;
        temp.pop_back();
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        l[i].push_back(i);
        point[i] = i;
    }
    string str1,str2;
    int a,b;
    while(cin >> str1 && str1 != "quit" )
    {
        cin >> a >> str2 >> b;
        if(str1 == "move" && str2 == "onto")
        {
            remove_(a);
            remove_(b);
            move_(a,b);
        }
        else if(str1 == "move" && str2 == "over")
        {
            remove_(a);
            move_(a,b);
        }
        else if(str1 == "pile" && str2 == "onto")
        {
            remove_(b);
            move_(a,b);
        }
        else
        {
            move_(a,b);
        }

    }
    for(int i = 0;i < n;i++)
    {
        cout << i << ':';
        while(!l[i].empty())
        {
            cout << " " << l[i].front();
            l[i].pop_front();
        }
        cout << endl;
    }
    return 0;
}