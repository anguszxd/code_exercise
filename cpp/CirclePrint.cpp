/*
 *
 *
 *
*/

#include <iostream>
#include <vector>
using namespace std;

void PrintCircle(int left , int right , vector<vector<int> > nums );

int main(){
	vector<vector <int> > nums;
	int n = 0;
	cin >> n;
	nums.resize(n);

	for(int i = 0; i < n; ++i)
	{
		nums[i].resize(n);
		for(int j = 0; j < n; ++j)
		{
			nums[i][j] = i*n+j+1;
			//cout << nums[i][j] << endl;
		}

	}

	int left = 0, right = n-1;
	while( left <= right )
	{
		PrintCircle(left, right , nums);
		++left;
		--right;
	}


	return 0;
}

void PrintCircle(int left , int right, vector<vector<int> > nums)
{
	int LeftTop[2] = { left, left };
	int RightBut[2] = { right, right};
	int move_ind[ ] = { LeftTop[0], LeftTop[1] };

	for( ; move_ind[1] <= RightBut[1] ; ++move_ind[1] )
		cout << nums[ move_ind[0] ][ move_ind[1] ] << endl;

	++move_ind[0];--move_ind[1];
	for(; move_ind[0] <= RightBut[0] ; ++move_ind[0] )
		cout << nums[ move_ind[0] ][ move_ind[1] ] << endl;

	--move_ind[1];--move_ind[0];
	for(; move_ind[1] >= LeftTop[1] ; --move_ind[1])
		cout << nums[ move_ind[0] ][ move_ind[1] ] << endl;

	--move_ind[0];++move_ind[1];
	for(; move_ind[0] >LeftTop[0] ; --move_ind[0] )
		cout << nums[ move_ind[0] ][ move_ind[1] ] << endl;
}