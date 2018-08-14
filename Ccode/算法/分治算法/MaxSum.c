/*
求解n个整数组成序列的最大子序列和
*/

int MaxSum(int a[], int left, int right) //left和right参数是递归调用时方便
{
	int i, j;
	int s1, s2;
	int center;
	int left_sum, right_sum;
	int sum = 0;
	if (left == right)
	{
		if (a[left] > 0)
			sum = a[left];
		else
			sum = 0;
	}
	else
	{
		center = (left + right) / 2;
		left_sum = MaxSum(a, left, center);
		right_sum = MaxSum(a, center + 1, right);
		s1 = 0;
		for (i = left; i <= center; i++)
		{
			if (a[i] + s1 > s1)
				s1 += a[i];
		}
		s2 = 0;
		for (j = center + 1; j <= right; j++)
		{
			if (a[j] + s2 > s2)
				s2 += a[j];
		}
		sum = s1 + s2;
		if (sum < left_sum)
			sum = left_sum;
		if (sum < right_sum)
			sum = right_sum;
	}
	return sum;
}