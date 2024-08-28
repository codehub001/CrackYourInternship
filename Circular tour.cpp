//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here[
        int gasSum=0;
        int costSum=0;
        for(int i=0;i<n;i++){
            gasSum+=p[i].petrol;
        }
        for(int i=0;i<n;i++){
            costSum+=p[i].distance;
        }
        if(gasSum<costSum){
            return -1;
        }
        int total=0;
        int resultIndex=0;
        for(int i=0;i<n;i++){
            total+=p[i].petrol-p[i].distance;
            if(total<0){
                total=0;
                resultIndex=i+1;
            }
        }
        return resultIndex;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends
