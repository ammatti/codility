#include <iostream>
#include <vector>
#include <numeric>
#include <string>

using namespace std;

vector<int> A;

int solution(vector<int> &A) {
    int previous_max_size = 0;
    int return_index = 0;
    int begin_maxslice_value = A.at(0);
    int begin_maxslice_index = 0;
    int max_size = 0;
    int current_value = begin_maxslice_value;
    int next_value = 0;
    
    for (int i=1; i< A.size(); i++){
        next_value = A.at(i);
        if (next_value <= current_value) {
            //asceding interrupt
            cout<<"asceding interrupt:"<<i<<endl;
            cout<<max_size<<endl;
            cout<<previous_max_size<<endl;
            if (max_size >= previous_max_size){
                    return_index = begin_maxslice_index;
                    previous_max_size = max_size;
                }
            begin_maxslice_value = A.at(i);
            begin_maxslice_index = i;
            max_size = 0;
            current_value = begin_maxslice_value;
        } else {
            max_size = max_size + 1;
            current_value = next_value;
        }
    }
    if (max_size >= previous_max_size) {
	return_index = begin_maxslice_index;
        previous_max_size = max_size;
	}
    cout<<"return_index="<<return_index<<endl;
    cout<<"previous_max_size="<<previous_max_size<<endl;
    return return_index;
}

int main() {
A.push_back(2);
  A.push_back(2);
  A.push_back(2);
  A.push_back(2);
  A.push_back(1);
  A.push_back(2);
  A.push_back(-1);
  A.push_back(2);
  A.push_back(1);
  A.push_back(3);
  //A.push_back(6);
  solution(A);
//cout<<"RESULT="<<solution(A)<<endl;
return 0;
}

