#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {
  
    public:
        stack<int> stack_newest_on_top, stack_oldest_on_top;
        int deletions = 0;

        void push(int x) {
            stack_newest_on_top.push(x);

          
        }

        void pop() {
            if(stack_oldest_on_top.empty()) {
                stack<int> dummy = stack_newest_on_top;
                int n = dummy.size();
                while(!dummy.empty() && n > deletions) {
                    stack_oldest_on_top.push(dummy.top());
                    dummy.pop();
                    n--;
                }
            } 
            stack_oldest_on_top.pop();
            deletions++;
        }

        int front() {
            if(stack_oldest_on_top.empty()) {
                stack<int> dummy = stack_newest_on_top;
                int n = dummy.size();
                while(!dummy.empty() && n > deletions) {
                    stack_oldest_on_top.push(dummy.top());
                    dummy.pop();
                    n--;
                }
            } 
            return stack_oldest_on_top.top();
        }
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.push(x);
        }
        else if(type == 2) {
            q1.pop();
        }
        else cout << q1.front() << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
