//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends


class twoStacks {
    int* arr; 
    int size; 
    int top1, top2; 
  
public: 
    // Constructor 
    twoStacks() 
    { 
        size = 100000; 
        int n = size;
        arr = new int[n]; 
        top1 = n / 2 + 1; 
        top2 = n / 2; 
    } 
  
    // Method to push an element x to stack1 
    void push1(int x) 
    { 
        // There is at least one empty 
        // space for new element 
        if (top1 > 0) { 
            top1--; 
            arr[top1] = x; 
        } 
        else { 
            cout << "Stack Overflow"
                 << " By element : " << x << endl; 
            return; 
        } 
    } 
  
    // Method to push an element 
    // x to stack2 
    void push2(int x) 
    { 
  
        // There is at least one empty 
        // space for new element 
        if (top2 < size - 1) { 
            top2++; 
            arr[top2] = x; 
        } 
    } 
  
    // Method to pop an element from first stack 
    int pop1() 
    { 
        if (top1 <= size / 2) { 
            int x = arr[top1]; 
            top1++; 
            return x; 
        } 
        else { 
            return -1;
        } 
    } 
  
    // Method to pop an element 
    // from second stack 
    int pop2() 
    { 
        if (top2 >= size / 2 + 1) { 
            int x = arr[top2]; 
            top2--; 
            return x; 
        } 
        else { 
            return -1;
        } 
    } 
}; 

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    while (T--) {
        twoStacks *sq = new twoStacks();

        int Q;
        cin >> Q;
        while (Q--) {
            int stack_no;
            cin >> stack_no;
            int QueryType = 0;
            cin >> QueryType;

            if (QueryType == 1) {
                int a;
                cin >> a;
                if (stack_no == 1)
                    sq->push1(a);
                else if (stack_no == 2)
                    sq->push2(a);
            } else if (QueryType == 2) {
                if (stack_no == 1)
                    cout << sq->pop1() << " ";
                else if (stack_no == 2)
                    cout << sq->pop2() << " ";
            }
        }
        cout << endl;
    }
}

// } Driver Code Ends
