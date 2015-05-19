#include "HugeInt.h"
using namespace std;
HugeInt::HugeInt(){
	num.clear();
	num.push_back(0);
}

HugeInt::HugeInt(string s){
	for(int i=s.size()-1;i>=0;i--){
		num.push_back(s[i]);
	}
}

HugeInt::HugeInt(int k){
	int digit=0,n_1=k;
	if(n_1==0){digit=1;}
	while(n_1!=0){
		digit++;
		n_1=n_1/10;
	}
	for(int i=0;i<digit;i++){
		num.push_back(k%10);
		k=k/10;
}}

vector<int> HugeInt::operator+(const HugeInt &b){
	vector<int> result;
	if(num.size()>=b.num.size()){
		for(int i=0;i<num.size();i++){
			if(i>=b.num.size()){
				result.push_back(num[i]);
			}
			else{
				result.push_back(num[i]+b.num[i]);
	}}}
	else{	
		for(int i=0;i<b.num.size();i++){
			if(i>=num.size()){
				result.push_back(b.num[i]);
			}
			else{
				result.push_back(num[i]+b.num[i]);
	}}}
	for(int i=0;i<result.size()-1;i++){
		if(result[i]>=10){
			result[i+1]=result[i+1]+result[i]/10;
			result[i]=result[i]%10;
	}}
	return result;
}

vector<int> HugeInt::operator-(const HugeInt&b){
	vector<int> result;
	for(int i=0;i<num.size();i++){
		if(i>=b.num.size()){
			result.push_back(num[i]);
		}
		else{
			result.push_back(num[i]-b.num[i]);
	}}
	for(int i=0;i<result.size()-1;i++){
		if(result[i]<0){
			result[i+1]--;
			result[i]+=10;
	}}
	return result;
}

void HugeInt::operator=(const vector<int> l){
	num.clear();
	for(int i=0;i<l.size();i++){
		num.push_back(l[i]);
}}

ostream &operator<<(ostream &out,const HugeInt &l){
	for(int i=l.num.size()-1;i>=0;i--){
		out<<l.num[i];
	}
	return out;
}
istream &operator>>(istream &in,HugeInt &l){
	l.num.clear();
	in >> l.input;
	for(int i=l.input.size()-1;i>=0;i--){
		l.num.push_back(l.input[i]-'0');
	}
	return in;
}
