#include <iostream>
#include <string>

using namespace std;

int getFinalAmount(int initialAmount , string betResults) {
    int answer = initialAmount;
    int scale = 2;
    int nextBet = 1;
    bool lose = false;
    //for each round
    for (int i=0; i<betResults.size(); i++){
        if ((answer - nextBet) < 0){
                return answer;
        }
        if(betResults[i] == 'W'){
            answer = answer+nextBet;
            if(lose){
		nextBet =1;
		}
            lose = false;
        }else if(betResults[i] == 'L'){
            answer = answer-nextBet;
            nextBet = nextBet*scale;
            lose = true;
        }else{
            //error
            return answer;
        }
    }
    return answer;
}

int main(){
	string str = "LLLWLLLL";
	for(int i = 0; i < str.size(); ++i) {
		cout<<str[i]<<endl;
                if(str[i] == 'l')
			cout<<"AAAA"<<endl;
	}

        int ans = getFinalAmount(15, str);
        cout<<ans<<endl;
}
