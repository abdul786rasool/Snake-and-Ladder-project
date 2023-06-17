#include <bits/stdc++.h>
#include <iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;
vector<int> dp(101,-1);  // DP array to store the minimum moves to reach each position
vector<bool> visited(101,false);// Visited array to track visited positions
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


// Function to check if the move is valid based on the given rules and attributes
bool is_valid(int i,int m)
{
    if(game_box[i][0]=='R')
        {
        string num=game_box[i].substr(1,game_box[i].length()-1);
        if(m==stoi(num)) return false;
        return true;
        }
     if(game_box[i][0]=='M')
        {
        string num=game_box[i].substr(1,game_box[i].length()-1);
        if(m==stoi(num)) return true;
        return false;
        }
    return true;

}


// Function to solve the game using dynamic programming approach and return the minimum moves to reach position i
int solve(int i)
{
   
    if(i>100) return 1e8;
    if(i==100) return dp[i]= 0;
    if(dp[i]!=-1) return dp[i];
    if(visited[i]==true)
        {
        return 1e8; 
        }
    visited[i]=true;


    if((game_box[i][0]=='L') || (game_box[i][0]=='S') )
    {
        string num=game_box[i].substr(1,game_box[i].length()-1);
        dp[i]=solve(stoi(num));
         visited[i]=false;
         return dp[i];
    }

    int ans=1e8;
    for(int m=1;m<=6;m++)
    {
        if(is_valid(i,m))
        {
            ans=min(ans,1+solve(i+m));
        }
    }

    dp[i]=ans;
    visited[i]=false;
    return dp[i];

}


 // Function to simulate the snake and ladder game
int snake_ladder(int t)
{   
    srand(time(0)+100*t);


// Generating random inputs of attributes.
    int n;
    n=rand()%100;
    string s1="LSRM";
    string s3="123456";
    vector<string> s2(101);
    for(int i=0;i<=100;i++) s2[i]=to_string(i);
    vector <pair<int,string>> input;
    //cout << n << endl;
    for(int i=0;i<n;i++)
    {
        int num=0;
        num=(rand()%97)+2;
        string attribute;
        attribute=s1[rand()%4];
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
        if(game_box[num] != "*")
        {
            for(int k=0;k<101;k++) game_box[k]="*"; // If same number get more than 1 attribute funtction will be terminated.
            return -1;
        }

        game_box[num]=attribute;

    }


    cout << "\n" << "INPUT:" << endl;
    print_input(input);

    int ans=solve(1);

    if(ans>=1e8) 
        {
            cout << "NOT POSSIBLE" << endl;
        }
    else
        {
            cout << "Minimum no of moves = " << ans << endl;
            cout << endl;
            int i=1;
            cout << "PATH : " ;
            while(i<=100)
            {
                cout << i << " ";
                if(i==100) break;
                if((game_box[i][0]=='L') || (game_box[i][0]=='S') )
                    {
                        string num=game_box[i].substr(1,game_box[i].length()-1);
                        i=stoi(num);
                    }
                else
                    {
                        int ans=i;
                        for(int m=1;m<=6;m++)
                           {
                                if(is_valid(i,m))
                                {
                                    if(dp[i+m]<dp[ans])
                                    {ans=i+m;}
                                }
                           }
                        i=ans;
                    }
            }
        }
    cout << "\n----------------------------------------------------------------\n";

    return 0;
}

int main()
{
    int t=0;
    while(snake_ladder(t++)==-1); //solve until valid inputs are generated.
    return 0;

}
