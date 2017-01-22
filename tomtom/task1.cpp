#include <iostream>
#include <vector>

using namespace std;

/**
void swap(int *a, int *b) {
  if (*a != *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
//    *count = *count+1;
  }
}
**/

int partition(vector<int>& A, int p,int q, int* count)
{
    int x= A[p];
    int i=p;
    int j;

    for(j=p+1; j<q; j++)
    {
        if(A[j]<=x)
        {
          i = i + 1;
          if (A[i] != A[j]) {
            swap(A[i], A[j]);
            *count = *count+1;
          }
        }
    }
    if (A[i] != A[p]) {
      swap(A[i], A[p]);
      *count = *count+1;
    }
    cout<<"i="<<i<<endl;
    return i;
}

/*
int partition(vector<int>& A, int p,int q, int* count){
	int pivot = A[p];
        int left = p + 1;
	int right = q;
	bool done = false;
        while (!done){
            while ((A[left] <= pivot) && (left < q)){
                left = left + 1;
            }
            while ((A[right] >= pivot) && (right > p)){
                right = right -1;
            }
            if (left >= right){
                done = true;
            }else{
                //swap item
                *count = *count + 1;
                int temp = A[left];
                A[left] = A[right];
                A[right] = temp;
		}
        }
        //"""swap pivot """
        if (p != right){
            *count = *count + 1;
        }
        int temp2 = A[p];
        A[p] = A[right];
        A[right] = temp2;

        return right;
}
*/

void quickSort(vector<int>& A, int p, int q, int* count)
{
    int r;
    if(p<q)
    {
        r=partition(A, p,q, count);
        printf("47\n");
        quickSort(A,p,(r-1), count);
        printf("49\n");  
        quickSort(A,(r+1),q, count);
    }
}

bool solution(vector<int> &A) {
    bool result = false;
    int swap_count = 0;
    int start = 0;
    int end = A.size();
    quickSort(A, start, end, &swap_count);
    if (swap_count < 2) {
        result = true;
        }
    return result;
}

int main(){
 int a=3;
 int b=5;

 //swap(&a, &b);
 //cout<<a<<endl;
 //cout<<b<<endl;
 int count=0;
 vector<int> A = {1, 5, 3, 3, 7};
    int p=0;
    int q=5;
 cout<<"======Original======="<<endl;
    for(auto e: A)
        cout<< e <<" ";
    cout<< endl;    

//quickSort(A,p,q, &count);
bool ans = solution(A);
    cout<<"======Sorted======="<<endl;
    for(auto e: A)
        cout<< e <<" ";
    cout<< endl;
 cout<<ans<<endl;
 //vector<int>B;
 //cout<<B.size()<<endl;
}
