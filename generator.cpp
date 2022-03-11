#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc,char* argv[])
{
	registerGen(argc, argv, 1);

	int n = atoi(argv[1]);
	int m = atoi(argv[2]);
	int len = atoi(argv[3]);
	//int pre = atoi(argv[4]);
	//len=min(len,m-1);
	cout<<n<<" "<<m<<endl;
	for(int i=1;i<=n;i++){
		int l = rnd.next(1,max(m-len,1));
		//if(i == 1 && pre && l == 0) l = 1; 
		int r = rnd.next(min(m,l+len),m);
		cout<<l<<" "<<r<<endl;
	}
	return 0;
}
