/*
using state machine to evaluate string expression
if expression is illegal return -1
else return the calculate value

*/


#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

typedef pair <int,string> token;
static const int NUMBER = 0, OPERATOR =1, OTHERS = 3;

int get_char_type(char c) {
    if (c >= '0' && c <= '9') {
        return NUMBER;            
    }else if (c == '*' || c == '+'){
        return OPERATOR;
    } else {
        return OTHERS;
    }
}

vector<token> convert_exp(string input) {
    vector<token> token_list;
    token temp;
    
    for (int i = 0; i < input.size(); i++) {
        char c = input[i];
        int type = get_char_type(input[i]);
        switch(type){
            case NUMBER:
                temp = make_pair(NUMBER,input.substr(i,1));
                token_list.push_back(temp);
                break;
            case OPERATOR:
                temp = make_pair(OPERATOR,input.substr(i,1));
                token_list.push_back(temp);
                break;
            case OTHERS:
                break;
        }
    }
    return token_list;
        
}

long add(long a, long b) { return a + b; }

long multiply(long a, long b) { return a * b; }

long calc(vector<token> exp) {
  long result = -1;
  vector<token> buffer;
  token temp;
  token op1, op2;
  long op1_value, op2_value;
  long temp_answer_val;
  string temp_answer;
  int length = exp.size();
  for(int i=0; i<length; i++){
	temp = exp[i];
	if(temp.first == NUMBER){
		buffer.push_back(temp);
	} else if(temp.first == OPERATOR){
		if(buffer.size() <2){
			//error
			return -1;
		}else {
			op1 = buffer.back();
                        buffer.pop_back();
                        op2 = buffer.back();
                        buffer.pop_back();
                        op1_value = stol(op1.second);
                        op2_value = stol(op2.second);
                        if (temp.second.compare("*") == 0) {
				temp_answer_val = multiply(op1_value, op2_value);
				stringstream ss;
				ss << temp_answer_val;
                                temp_answer = ss.str();
                                temp.first = NUMBER;
                                temp.second = temp_answer;
                                buffer.push_back(temp);
                        } else if (temp.second.compare("+") == 0) {
				temp_answer_val = add(op1_value, op2_value);
				stringstream ss;
				ss << temp_answer_val;
                                temp_answer = ss.str();
                                temp.first = NUMBER;
                                temp.second = temp_answer;
                                buffer.push_back(temp);
                        } else {
				//error
				return -1;
                        }
                }
	} else {
		//error
		return -1;
	}
  }
  if(buffer.size() == 1){
	temp = buffer.back();
	buffer.pop_back();
	result = stol(temp.second);
  }
  return result;
}

long solution(string &S) {
  long answer = -1;
  //cout<<S<<endl;
  vector<token> tokens = convert_exp(S);
  /*
  for (int i = 0; i < tokens.size(); i++) {
        cout<<tokens[i].first<<" "<<tokens[i].second<<endl;
  }
  */
  answer = calc(tokens);
  return answer;
}

int main(){
  string str = "87*1+";
  long answer = solution(str);
  cout<<str<<"="<<answer<<endl;
  return 0;
}
