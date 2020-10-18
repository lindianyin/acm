#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;
struct Card{
	char suit;
	char value;
};
std::ostream& operator<<(std::ostream& out, const Card& v) {
  out << v.suit << (int)v.value;
  return out;
}
class Solution{
public:
	int selection_sort(vector<Card>& A){
		int minj,sw=0;
		for(int i = 0;i<A.size();i++){
			minj = i;
			for(int j = i;j<A.size();j++){
				if(A[j].value<A[minj].value)
					minj = j;
			}
			swap(A[i],A[minj]);
			if(i != minj) sw++;
		}
		return sw;
	}	
	int bubble_sort(vector<Card>& A){
		int sw = 0;
		for(int i=0;i<A.size();i++){
			for(int j = A.size() -1;j>=i+1;j--){
				if(A[j].value < A[j-1].value){
					swap(A[i],A[j-1]);
					sw++;
				}
			}
		}
		return sw;
	}
	bool is_stable(vector<Card>& A,vector<Card>& B){
		for(int i = 0;i<A.size();i++){
			if(A[i].value != B[i].value)
				return false;
		}
		return true;
	}
};

int main(int argc,char* argv[]){
	Solution s;
	vector<Card> A = {{'H',4},{'C',9},{'S',4},{'D',2},{'C',3}};
	vector<Card> B = A;
	dbg(A);
	int sw = s.selection_sort(A);	
	dbg(A);
	//dbg(sw);
	int sw1 = s.bubble_sort(B);
	dbg(B);
	dbg(s.is_stable(A,B));
	return 0;
}
