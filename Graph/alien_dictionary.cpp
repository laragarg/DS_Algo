//testing
vector<bool>vis;
void topsort(vector<vector<char> >&g, char par, stack<char> &st){
	int sz = g[par - 'a'].size();
	vis[par - 'a'] = true;
	for(int i=0; i<sz; i++){
		char child = g[par - 'a'][i];
		if(!vis[child - 'a']){
			topsort(g, child, st);
		}
	}
	st.push(par);
//	return;
}
string printOrder(string dict[], int n, int k){
    stack<char>st;
// 	st.clear();
	vis.clear();
	vis.resize(26);
	string ans;
	vector<vector<char> >g(26);
	char start = dict[0][0];
// 	cout<<"here"<<endl;
	for(int w=0; w<n-1; w++){
		string w1 = dict[w];
		string w2  = dict[w+1];
		int n1 = w1.size();
		int n2 = w2.size();
		int i = 0;
		int j = 0;
		while(i < n1 && j < n2){
			char x = w1[i];
			char y = w2[j];
			// if(x == y){
			// 	continue;
			// }
			if(x != y){
				g[x - 'a'].push_back(y);
				break;
			}
			i++;
			j++;
		}
	}
	for(int i=0; i<26; i++){
	    if(!vis[i]){
	        topsort(g, 'a' + i, st);
	    }
	}
	while(!st.empty()){
		char x = st.top();
		ans.push_back(x);
		st.pop();
	}
	return ans;
}