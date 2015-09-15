/*
功能：有一个能随机产生1到5整数的函数rand1to5，在此基础上实现产生1到8随机数的功能；
方法：用rand1to5产生两个1到5的随机整数，用5进制（10进制也是可以的）将它们整合成1个数，
这个数的范围应当是6到30，从中截取8到23这一段（即如果产生的数不在这个范围内就抛弃，再
1个数），对该数取对8的余数，我们需要的随机数（1到8）就是这个余数加1。

*/
#include <iostream>
#include <stdlib.h>
#include <time.h>

int rand1to5();

int main(){
	int item_num[8] = { };
	int loop_num = 10000;
	int i = 0, rand_int1 = 0, rand_int2 = 0;
	int temp = 0;
	srand((unsigned)time(NULL));//为rand()函数产生种子，保证每次rand()的结果时不同的
	while( i < loop_num )
	{
		rand_int1 = rand1to5();
		rand_int2 = rand1to5();
		temp = rand_int1*5+rand_int2;
		if( temp < 8 || temp > 23)
			continue;
		else
		{
			++item_num[temp%8];
			++i;
			//std::cout << temp%8+1 << std::endl;
		}
	}

	std::cout << "print rand int nums " << std::endl;
	for(int j = 0; j < 8;++j)
		std::cout << item_num[j] << std::endl;

	return 0;
}

int rand1to5(){
	int a = 1, b = 5;
	return rand()%(b-a+1)+a;//产生[a,b]的随机数
}