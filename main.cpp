//
//  main.cpp
//  commandLineProj
//
//  Created by maple on 10/30/18.
//  Copyright (c) 2018 maple. All rights reserved.
//

#include <iostream>
#include<string>
#include<vector>
#include <sstream>
using namespace::std;

//////////////////////////////////////////////////////
//check if the input string is a valid number
//input: string
//output: bool
//////////////////////////////////////////////////////
bool isNum(string& s)
{
    if(s.length()>1&&s[0]=='0')  //when s is a string start with 0 as 0989, then s is not valid number
        return false;
    
    for(int i=0;i<s.length();i++) //check every char in the string s is a digit. if not , then s is not a valid number.
    {
        if(isdigit(s[i])==false)
        {
            return false;
        }
    }
    return true;
}
//////////////////////////////////////////////////////
//check if the input string is a numberical sequence;
//input: string
//output: bool
//////////////////////////////////////////////////////
bool isNumSeq(string& input)
{
    if(input.length()==0)
        return false;
    stringstream ss(input);
    string elem;
    while(getline(ss,elem,' '))
    {
        if(isNum(elem)==false)
            return false;
    }
    return true;
}
///////////////////////////////////////////////////////////////////////////
//Check if the input string is a literal string which don't contains digit;
//input: string
//output: bool
///////////////////////////////////////////////////////////////////////////
bool isLiteralString(string& input)
{
    if(input.length()==0)
        return false;
    for(int i=0;i<input.length();i++)
    {
        if(isdigit(input[i]))
        {
            return false;
        }
    }
    return true;
}
///////////////////////////////////////////////////////////////////////////////
//Print the median of a number sequence
//input: vector<int>
//output: none;
///////////////////////////////////////////////////////////////////////////////
void findMedian(vector<int>& nums)
{
    if(nums.size()==0)
    {
        cout<<"median = none"<<endl;
        return;
    }
    int mid=(int)(0+(nums.size()-1))/2;
    cout<<"median = "<<nums[mid]<<endl;
}

///////////////////////////////////////////////////////////////////////////////
//Print the mean of a number sequence
//input: vector<int>
//output: none;
///////////////////////////////////////////////////////////////////////////////
void findMean(vector<int>& nums)
{
    int sum=0;
    float mean=0;
    for(auto n:nums)
    {
        sum+=n;
    }
    mean=sum/nums.size();
    cout<<"mean = "<<mean<<endl;
}

///////////////////////////////////////////////////////////////////////////////
//Print the Range of a number sequence
//input: vector<int>
//output: none;
///////////////////////////////////////////////////////////////////////////////
void findRange(vector<int>& nums)
{
    if(nums.size()==0)
    {
        cout<<"Range = none"<<endl;
    }
    int Range=nums[nums.size()-1]-nums[0];
    cout<<"Range = "<<Range<<endl;
}

///////////////////////////////////////////////////////////////////////////////
//Print the Mode of a number sequence
//input: vector<int>
//output: none;
///////////////////////////////////////////////////////////////////////////////
void findMode(vector<int>& nums)
{
    int occur=0;
    int mode=-1;
    int maxOccur=0;
    
    for(int i=0;i<nums.size();i++)
    {
        if(i==0)
        {
            occur=1;
        }
        else if(nums[i]==nums[i-1])
        {
            occur++;
        }
        else{
            occur=1;
        }
        
       if(maxOccur<occur)
       {
           maxOccur=occur;
           mode=nums[i];
       }
    }
    
    if(maxOccur==1)
    {
        cout<<"mode = none "<<endl;
    }
    else
        cout<<"mode = "<<mode<<endl;
}

////////////////////////////////////////////////////////////////////////////
//Process the number sequence : find median,mean,range,mode
//input: vector<int>
//output: none
////////////////////////////////////////////////////////////////////////////
void processNum(string& input)
{
    vector<int> nums;
    stringstream ss(input);
    string elem;
    while(getline(ss,elem,' '))
    {
        nums.push_back(stoi(elem));
    }
    sort(nums.begin(),nums.end());
    findMean(nums);
    findMedian(nums);
    findMode(nums);
    findRange(nums);
}


////////////////////////////////////////////////////////////////////////////////////////////////
//Count the occurence of each character and display it in alphabetical order , case sensitive.
//input : string
//output: none;
/////////////////////////////////////////////////////////////////////////////////////////////////
void processString(string& input)
{
    int cnts[256]={0};
    for(int i=0;i<input.length();i++)
    {
        char c=input[i];
        if((c>='a'&&c<='z')||(c>='A'&&c<='Z')) //only count the occurence of alphabet.
        {
            cnts[c]++;
        }
    }
    
    for(char c='a';c<='z';c++)
    {
        if(cnts[c]>0)
        {
            cout<<c<<" : "<<cnts[c]<<endl;
        }
    }
    
    for(char c='A';c<='Z';c++)
    {
        if(cnts[c]>0)
        {
            cout<<c<<" : "<<cnts[c]<<endl;
        }
    }
}



int main(int argc, const char * argv[])
{
    while(true)
    {
        string input;
        cout<<"Enter input: "<<endl;
        getline(cin,input);
        if(input=="quit")
        {
            cout<<"The program exit"<<endl;
            return 0;
        }
        
        if(isNumSeq(input))
        {
            processNum(input);
        }
        else if(isLiteralString(input))
            processString(input);
        else{
            cout<<"Wrong input! Please type in either a literal string or a number seqence!"<<endl;
        }
    }
    return 0;
}

