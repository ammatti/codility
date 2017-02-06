#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef pair <int,string> token;
static const int type_a_o =1, type_a_c =2, type_b_o=3, type_b_c=4,\
                 type_c_o =5, type_c_c =6, type_d_o=7, type_d_c=8, others=9;

int get_char_type(char c) {
    if (c == '{') {
        return type_a_o;
    }else if (c == '}'){
        return type_a_c;
    }else if (c == '('){
        return type_b_o;
    }else if (c == ')'){
        return type_b_c;
    }else if (c == '['){
        return type_c_o;
    }else if (c == ']'){
        return type_c_c;
    }else if (c == '<'){
        return type_d_o;
    }else if (c == '>'){
        return type_d_c;
    }else{
        return others;
    }  
}
void printBracketMatch(string a) {
    vector <token> buffer;
    token temp;
    bool answer = false;
    
    for(int i=0; i<a.size(); i++){
        char c = a[i];
        int type = get_char_type(c);
        cout<<"i="<<i<<" and "<<c<<endl;
        switch (type){
            case type_a_o:
            case type_b_o:
            case type_c_o:
            case type_d_o:
                temp = make_pair(type, a.substr(i,1));
                buffer.push_back(temp);
                break;
            case type_a_c:
                temp = buffer.back();
                buffer.pop_back();
                if (temp.first != type_a_o){
                    cout<<"NO MATCH 5";
                    return;
                }
                break;
            case type_b_c:
                temp = buffer.back();
                buffer.pop_back();
                if (temp.first != type_b_o){
                    cout<<"NO MATCH 4";
                    return;
                }
                break;
            case type_c_c:
                temp = buffer.back();
                buffer.pop_back();
                if (temp.first != type_c_o){
                    cout<<"NO MATCH 3";
                    return;
                }
                break;
            case type_d_c:
                temp = buffer.back();
                buffer.pop_back();
                if (temp.first != type_d_o){
                    cout<<"NO MATCH 2";
                    return;
                }
                break;
            case others:
                break;
        }
    }
    if (buffer.size()>0){
        answer = false;
    }else{
        answer = true;
    }
    
    if(answer){
        cout<<"MATCH";
    }else{
        cout<<"NO MATCH 1";
    }

}
int main(){
	string str = "(({<>}))";
	for(int i = 0; i < str.size(); ++i) {
		cout<<str[i]<<endl;
                if(str[i] == 'l')
			cout<<"AAAA"<<endl;
	}
	printBracketMatch(str);
}
