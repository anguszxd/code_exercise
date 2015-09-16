#include <iostream>
#include <vector>
using namespace std;

void PrintSlash(int ind1[], int ind2[], bool direct, vector<vector <int> > nums);

int main(){
	vector<vector <int> > nums;
	int n = 0;
	cin >> n;

	nums.resize(n);
	for(int i = 0; i < n ; ++i)
	{
		nums[i].resize(n);
		for(int j = 0; j < n; ++j)
		{
			nums[i][j] = i*n+j+1;
		}
	}

	bool dir = 0;
	int ind1[] = { 0, 0 }, ind2[] = { 0, 0 };


	while( ind1[1] <= n)
	{
		PrintSlash( ind1, ind2, dir, nums );
		if ( ind1[0] < n-1 )
		{
			++ind1[0];
			++ind2[1];
		}
		else
		{
			++ind1[1];
			++ind2[0];
		}
		//change direction , controlled by bool type dir
		dir = dir ? false : true ;
		//cout << "bool: " << dir <<endl;
	}
/*
	PrintSlash(ind1,ind2,dir,nums);
	ind1[0]++;
	ind2[1]++;
	cout << ind1[0] << ind1[1] <<endl;
	cout << ind2[0] << ind2[1] <<endl;
	PrintSlash(ind1,ind2,~dir,nums);

*/	
	return 0;

}

void PrintSlash(int ind1[], int ind2[], bool direct, vector<vector <int> > nums)
{
	if(direct)
	{
		int move_ind[] = { ind1[0], ind1[1] };
		while( move_ind[1] <= ind2[1] )
		{
			cout << nums[ move_ind[0] ][ move_ind[1] ] << endl;
			move_ind[0]--;
			move_ind[1]++;
		}
	}
	else
	{
		int move_ind[] = { ind2[0], ind2[1] };
		while( move_ind[0] <= ind1[0] )
		{
			cout << nums[ move_ind[0] ][ move_ind[1] ] << endl;
			move_ind[0]++;
			move_ind[1]--;
		}
	}
}