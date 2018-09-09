/*************************************************************************
    > File Name: a.cpp
    > Author: Lee
    > Mail: 825526448@qq.com
    > Created Time: Thu 06 Sep 2018 10:47:31 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a[5] = {2,5,1,3,7};
	int i = 0, j = 0,m = 0,sum = 0;
    for(i = 0; i < 5;i++)
		printf("%d ",a[i]);
	printf("\n");

	for(i=0;i<4;i++)
		for(j = i+1;j<5;j++)
		{
			if(a[i] > a[j])
			{
				m    = a[i];
				a[i] = a[j];
				a[j] = m;
			}
		}
	for(i = 0;i<5;i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}

