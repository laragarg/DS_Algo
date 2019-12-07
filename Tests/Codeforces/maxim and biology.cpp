#include<bits/stdc++.h>
using namespace std;
int main(){
	
	int n;
	cin>>n;
	
	string str1;
	cin>>str1;
	
	if(n<4){
		cout<<"0";
		return 0;
	}
	
	int ans=INT_MAX;
	
	string str2="ACTG";

	for(int i=0; i<n-3; i++){
		int temp=0;
		int k=0;
		for(int j=i; j<i+4; j++){
			
			if(str1[j]=='Z'&&str2[k]=='A'){
				temp+=1;
			}
			else{
				// cout<<"str1="<<int(str1[j])<<endl;
				// cout<<"str2="<<int(str2[k])<<endl;
				temp+=min( abs( int(str1[j]) - int(str2[k]) ), 26 - abs( int(str1[j]) - int(str2[k]) ));
			}
			//cout<<"temp="<<temp<<endl;
			k++;
		}
		ans=min(ans, temp);
	}

	cout<<ans;
	return 0;
}