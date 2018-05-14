#include <iostream>
#include <vector>
#include <numeric>
#include <string>

using namespace std;

struct Node {
   char key;
   vector<Node *> child;
}

Node *newNode(int key)
{
   Node *temp = new Node;
   temp->key = key;
   return temp;
}

vector<int> solution(vector<int> &T) {
    // write your code in C++14 (g++ 6.2.0)
    //construct a tree
    vector<int> sol;
    Node* root = newNode(-1);
    //1. find root (capital)
    for (int i=0; i<T.size(); i++){
        if(T.at(i) == i){
            root.key = i;
        }else{
            
        }
    }   
    return sol;    
}

int main() {

int arr[] = {9, 1, 4, 9, 0, 4, 8, 9, 0, 1};
vector<int> input(arr, arr+10);
vector<int> sol = solution(input);

for(int i=0; i<sol.size(); i++){
    cout<<sol.at(i)<<endl;
}

return 0;
}

