#include <bits/stdc++.h>
using namespace std;

void setnow(int & num,int pos)
{
     num |= (1 << pos);
}

int main()
{
	int gd, cap;
	cin >> gd>> cap;
	int x=-1;
	unordered_map<int,pair<queue<int>,int>> mp;
	queue<int> empty;
	vector<int> order;
	order.push_back(0);
	mp[0]=make_pair(empty,gd);
	for(int i=1; i<pow(2,gd); i++){
		order.push_back(i);
		mp[i]=make_pair(empty,gd);
	}
	while(x!=6){
		cin >> x;
		int y;
		if(x==2){
			cin >> y;
			for(int i=gd; i>=0; i--){
				int rem = y%((int)pow(2,i));
				if(mp.find(rem)!=mp.end()){
					if(((mp[rem]).first).size()<cap){
						((mp[rem]).first).push(y);
					}
					else{
						int temp=rem;
						while(true){
							i++;
							if(gd<i) gd=i;
							setnow(rem,i-1);
							order.push_back(rem);
							((mp[temp]).second)++;
							(mp[rem])=make_pair(empty,((mp[temp]).second));
							queue<int> flag;
							int p;
							while(!((mp[temp]).first).empty()){
								p=((mp[temp]).first).front();
								((mp[temp]).first).pop();
								if(p%((int)pow(2,i))==rem) {
									((mp[rem]).first).push(p);
								}
								else{
									(flag).push(p);
								}
							}
							(mp[temp]).first=flag;
							if(y%((int)pow(2,i))==rem) {
								if(((mp[rem]).first).size()<cap){
									((mp[rem]).first).push(y);
									break;
								}
								else{
									temp=rem;
								}
							}
							else{
								if(((mp[temp]).first).size()<cap){
									((mp[temp]).first).push(y);
									break;
								}
								else{
									rem=temp;
								}
							}
						}
					}
					break;
				}
			}
		}
		else if(x==3){
			cin >> y;
			for(int i=gd; i>=0; i--){
				int rem = y%((int)pow(2,i));
				if(mp.find(rem)!=mp.end()){
					queue<int> flag;
					int p;
					while(!((mp[rem]).first).empty()){
						p=((mp[rem]).first).front();
						((mp[rem]).first).pop();
						flag.push(p);
						// if(p==y) {
						// 	cout << "yes"<< endl; // complete loop for correct flag
						// }
					}
					((mp[rem]).first)=flag;
					break;
				}
			}
		}
		else if(x==4){
			cin >> y;
			for(int i=gd; i>=0; i--){
				int rem = y%((int)pow(2,i));
				if(mp.find(rem)!=mp.end()){
					queue<int> flag;
					int p;
					while(!((mp[rem]).first).empty()){
						p=((mp[rem]).first).front();
						((mp[rem]).first).pop();
						if(p!=y) {
							flag.push(p);
						}
					}
					((mp[rem]).first)=flag;
					break;
				}
			}
		}
		else if(x==5){
			cout<< gd<< endl<< order.size()<<endl;
			for(int i=order.size()-1; i>=0; i--){
				cout << (mp[(order[i])].first).size()<<" "<< mp[(order[i])].second<<endl;
			}
		}
	}
	// cout << mp.size()<< endl;
	// for(auto x:mp){
	// 	cout << x.first<< endl;
	// 	int p;
	// 	while(!(x.second).empty()){
	// 		p=(x.second).front();
	// 		(x.second).pop();
	// 		cout << p<< " ";
	// 	}
	// 	cout << endl;
	// }
	// for(auto x: order) cout << x<< " ";
    return 0;
}