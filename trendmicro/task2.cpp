#include <iostream>
#include <vector>
#include <numeric>
#include <string>

using namespace std;

int getMaxMoviesWatched(vector<int> &movies, int K, int L){

    int maxK = 0;
    int indK = 0;
    int maxL = 0;
 
    int length = movies.size();
    cout<<"len="<<length<<endl;
    if ( length < (K+L) )
      return -1;

    for(int i = 0; i <= (length-K); i++){
      int value = 0;
      for(int j = i; j < K+i; j++)
        value += movies[j];

      if ( value > maxK ){
        maxK = value;
        indK = i;
      }
    }

    for(int i = 0; i <= (length-L); i++){
      int value = 0;
      if( i == indK )
        i += K;

      for(int j = i; j < (L+i); j++)
        value += movies[j];

      if ( value > maxL ){
        maxL = value;
      }
    }

    return maxK+maxL;
  }

int main() {

int solution;
int arr[] = {6, 1, 4, 6, 3, 2, 7, 4};
vector<int> mov(arr, arr+8);
int k=3;
int l=2;

solution = getMaxMoviesWatched(mov, k,l);
cout<<solution<<endl;

return 0;
}

