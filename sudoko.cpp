#include<bits/stdc++.h>
using namespace std;	
#define pb push_back 
#define eb emplace_back
#define fn for(int i =0 ;i <n;i++)
#define fn1 for( int i =1;i<=n;	i++)
#define fm for(int j =0 ;j <m;j++)
#define fm1 for(int j =1;j<=m;j++)
#define fi first
#define se second
#define endl '\n'
const int N = 9;
vector<vector<int>>ar(N,vector<int>(N));
int n =9 , m = 9;
bool checkSquare(int row , int col ,int no){
	col/=3;
	col*=3;
	row/=3;
	row*=3;

	for(int i =row;i<row+3;i++){
		for(int j =col;j<col+3;j++){
			if(ar[i][j]==no)return 0;
		}
	}
	return 1;
}
bool checkRowCol(int row, int col ,int no){
	fn{
		if(ar[row][i]==no || ar[i][col]==no)return 0;
	}
	return 1;
}
void printBoard(){
	for(int j=0;j<=m;j++){
		if(j==0){
			cout<<" ";
		}else
			cout<<"----";
	}
	cout<<endl;
	fn{
		fm{
			if(j==0){
				cout <<" | ";
			}
			cout << ar[i][j];
			cout<<" | ";
		}
		cout<<endl;
		for(int j=0;j<=m;j++){
			if(j==0){
				cout<<" ";
			}else
			cout<<"----";
		}
		cout << endl;
	}
}
pair<int,int> done(){
	fn{
		fm{
			if(ar[i][j]==0){
				return make_pair(i,j);
			}
		}
	}
	return make_pair(-1,-1);
}

bool solve(){
	auto it = done();
	if(it.fi ==-1 && it.se==-1){
		return 1;
	}
	for(int i=1;i<=9;i++){
		if(checkSquare(it.fi,it.se,i)&&checkRowCol(it.fi,it.se,i)){
			ar[it.fi][it.se]=i;
			if(solve())
				return 1;
		}
		
		ar[it.fi][it.se]=0;
	}
	return 0;
}
signed main(){
		ar = {
		{7,8,0,4,0,0,1,2,0},
		{6,0,0,0,7,5,0,0,9},
		{0,0,0,6,0,1,0,7,8},
		{0,0,7,0,4,0,2,6,0},
		{0,0,1,0,5,0,9,3,0},
		{9,0,4,0,6,0,0,0,5},
		{0,7,0,3,0,0,0,1,2},
		{1,2,0,0,0,7,4,0,0},
		{0,4,9,2,0,6,0,0,7}
	};
	bool f = solve();
	if(f==0){
		cout <<"\n YOU WON !!!!!!\n";
	}else{
		cout<<"\n COMPUTER WON !!!!!! \n";
	}
	printBoard();

		
	return 0;
}