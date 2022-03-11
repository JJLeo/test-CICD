#include "testlib.h"
using namespace std;
int main(int argc,char* argv[])
{
	registerValidation(argc,argv);
	int n=inf.readInt(2,50,"n");
	inf.readSpace();
	int m=inf.readInt(1,100000,"m");
	inf.readEoln();
	for (int i=1;i<=n;i++)
	{
		int x,y;
		x=inf.readInt(1,m,"l");
		inf.readSpace();
		y=inf.readInt(x,m,"r");
		inf.readEoln();
	}
	inf.readEof();
	return 0;
}

