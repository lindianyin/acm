#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
class Solution {
public:
int* buildNext(char* P) { // ����ģʽ�� P �� next ��
    size_t m = strlen(P), j = 0; // ��������ָ��
    int* N = new int[m]; // next ��
    int  t = N[0] = -1; // ģʽ��ָ��
    while (j < m - 1)
        if ( 0 > t || P[j] == P[t]){ // ƥ��
            j++; t++;
            N[j] = t; // �˾�ɸĽ�Ϊ N[j] = (P[j] != P[t] ? t : N[t]);
        }else // ʧ��
            t = N[t];
    return N;
}
int match (char* P, char* S){ // KMP �㷨
    int* next = buildNext(P); // ���� next ��
    int m = (int) strlen (S), i = 0; // �ı���ָ��
    int n = (int) strlen(P), j = 0; //ģʽ��ָ��
    while (j < n && i < m) // ������������ȶ��ַ�
        if (0 > j || S[i] == P[j]) // ��ƥ�䣬�� P ���Ƴ������
            {i++; j++;} // ��ת����һ�ַ�
        else
            j = next[j]; // ģʽ�����ƣ�ע�⣺�ı������û��ˣ�
    delete [] next; // �ͷ� next ��
	if(j == n) return i-j;
    return -1;
}
int strStr(string haystack, string needle) {
	if(needle.empty()) 
		return 0;
	if(haystack.size() < needle.size())
		return -1;
	if(haystack.size() == needle.size())
		return haystack == needle ? 0 : -1;
	int ret = match((char*)needle.data(),(char*)haystack.data());	
	return ret;
}
};
int main(int argc,char* argv[]){
	Solution s;
	string haystack = "mississippi";
	string needle = "issipi";
	int ret = s.strStr(haystack,needle);
	cout << ret << endl;
	return 0;
}
