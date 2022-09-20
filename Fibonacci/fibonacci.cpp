#include<iostream>  
#include<cstdlib>  
#include<ctime>   /* time function */
//#include<sys/time.h> /*gettimeofday*/
using namespace std;

unsigned int F0(int n){
	if(n==0){return 0;}
	else if(n==1){return 1;}
	else {return F0(n-1)+F0(n-2);}
}

unsigned int F1(int n){
	unsigned int *f = new unsigned int[n+1];
	//int *f = (int*)malloc(n*sizeof(int));
	//int f[n];
	f[0]=0;
	f[1]=1;
	for(int i = 2;i<=n;i++){
		f[i]=f[i-1]+f[i-2];
	}
	return f[n];
}

int main()
{
	int n;
    unsigned int ans;
	
	/*float timeuse;
	struct timeval time_start, time_end;*/
	
	clock_t starttime;
	clock_t endtime;
	double duration;
	cout << "input n:";
	cin >> n;
	starttime=clock();
	ans=F0(n);
	endtime=clock();
	duration=(double)(endtime-starttime)/CLOCKS_PER_SEC;
	cout << "==First case=="<<endl;
	cout << "fn="<< ans <<endl;
	cout <<"duration:" << duration <<endl;
	
	//gettimeofday(&time_start, NULL);
	starttime=clock();
	ans=F1(n);
	endtime=clock();
	//gettimeofday(&time_end, NULL);
	duration=(double)(endtime-starttime)/CLOCKS_PER_SEC;
	cout << "==Second case=="<<endl;
	cout << "fn="<< ans <<endl;
	cout <<"duration:" << duration <<endl;
}

