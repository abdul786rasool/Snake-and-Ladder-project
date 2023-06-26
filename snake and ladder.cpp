#include <bits/stdc++.h>
#include <iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;
vector<string> game_box(101,"*");// Game box array to store the attributes of each position

// Function to print the input attributes
void print_input(vector <pair<int,string>> &input)
{   cout << "No of attributes="<<input.size() << endl;
    cout << "Attributes:" <<  endl;
    for(auto p:input)
    {
        cout << p.first << " " << p.second << endl;

    }
    cout << "\n----------------------------------------------------------------\n";

}

//Function to return nodes with weights where we can go from current node .
vector<pair<int,int>> adjacent(int node)
{   vector<pair<int,int>> ans;
    if(game_box[node][0]=='L' || game_box[node][0]=='S')
    {
         int num=stoi(game_box[node].substr(1,game_box[node].length()-1));
         ans.push_back({num,0});
         return ans;
    }
    if(game_box[node][0]=='M')
    {
        int num=stoi(game_box[node].substr(1,game_box[node].length()-1));
       if(node+num<=100) ans.push_back({node+num,1});
        return ans;
    }
    if(game_box[node][0]=='R')
    {
       int num=stoi(game_box[node].substr(1,game_box[node].length()-1));
       for(int i=1;i<=6;i++)
       {
           if(i==num) continue;
         if(node+i<=100)  ans.push_back({node+i,1});
       }
       return ans;
    }
    for(int i=1;i<=6;i++)
       {
           if(node+i<=100) ans.push_back({node+i,1});
       }
       return ans;
}

 // Function to simulate the snake and ladder game
void snake_ladder()
{
    srand(time(0));
  // Generating random inputs of attributes.
    int n;
    n=20+rand()%80;
    string s1="LLLSSSRRMM";
    string s3="123456";
    vector<string> s2(101);
    for(int i=0;i<=100;i++) s2[i]=to_string(i);
    vector <pair<int,string>> input; //array to store inputs

    for(int i=0;i<n;i++)
    {
        int num=0;
        num=(rand()%97)+2;
        string attribute;
        attribute=s1[rand()%10];
        if(attribute=="R" || attribute=="M")
            {
                attribute+=s3[rand()%6];

            }

        else{

                if(attribute=="S")
                {
                    string temp = s2[(rand()%(num-1))+1];
                    attribute+=temp;

                }
                else
                {
                     string temp = s2[num+(rand()%(100-num))+1];
                     attribute+=temp;
                }

            }
        pair<int,string> temp={num,attribute};
        input.push_back(temp);

        game_box[num]=attribute;

    }


    cout << "\n" << "INPUT:" << endl;
    print_input(input);//printing inputs

    vector<int> distance(101,1e9);//Array to store moves to reach each node from node 0.
    distance[1]=0;
    vector<int> parent(101);
    for(int i=0;i<101;i++) parent[i]=i; //Array to store parentnode of each node in shortest path.
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,1});
    while(!pq.empty())
    {
        int node=pq.top().second;
        int dis=pq.top().first;
        pq.pop();
        for(auto it:adjacent(node))
        {
            int adjnode=it.first;
            int edgewt =it.second;
            if(dis+edgewt<distance[adjnode])
            {
                distance[adjnode]=dis+edgewt;
                pq.push({distance[adjnode],adjnode});
                parent[adjnode]=node;
            }
        }

    }
    if(distance[100]>=1e9)
        {
            cout << "NOT POSSIBLE" << endl;
        }
    else
        {   vector<int> path;//Array to store the path from node 0 to 100.
            cout << "Minimum no of moves = " << distance[100] << endl;
            cout << endl;
            int node=100;
            cout << "PATH : " ;
            while(parent[node]!=node)
            {
                path.push_back(node);
                node=parent[node];
            }
            path.push_back(1);
            reverse(path.begin(),path.end());
            for(auto x:path) cout<<x<<" ";
            cout << endl;
        }
    cout << "\n----------------------------------------------------------------\n";

    return ;
}

int main()
{

    snake_ladder();
    return 0;

}
