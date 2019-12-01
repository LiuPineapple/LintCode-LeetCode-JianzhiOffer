// �����˴��еĵ�һ�ֽⷨ��ʹ�����з񶨵Ļ�������ѭ���Ľⷨ�������޸ģ��õ���ȷ�ⷨ
#include<iostream>
using namespace std;

//int NumberOf1_Solution1(int n)
//{
//	int a = 1;
//	int count = 0;
//	while (a)
//	{
//		if (a&n)
//			count++;
//		a = a << 1;
//	}
//	return count;
//}
int NumberOf1_Solution1(int n)
{
	int count = 0;
	for (int i = 0; i < 32; i++)
	{
		if ((n >> i) & 1)
			count++;
	}
	return count;
}

int NumberOf1_Solution2(int n)
{
	int count = 0;
	while (n)
	{
		count++;
		n = n&(n - 1);
	}
	return count;
}

// ====================���Դ���====================
void Test(int number, unsigned int expected)
{
	int actual = NumberOf1_Solution1(number);
	if (actual == expected)
		printf("Solution1: Test for %p passed.\n", number);
	else
		printf("Solution1: Test for %p failed.\n", number);

	actual = NumberOf1_Solution2(number);
	if (actual == expected)
		printf("Solution2: Test for %p passed.\n", number);
	else
		printf("Solution2: Test for %p failed.\n", number);

	printf("\n");
}

int main(int argc, char* argv[])
{
	// ����0���ڴ��������0
	Test(0, 0);

	// ����1���ڴ��������1
	Test(1, 1);

	// ����10���ڴ��������2
	Test(10, 2);

	// ����0x7FFFFFFF���ڴ��������31
	Test(0x7FFFFFFF, 31);

	// ����0xFFFFFFFF�����������ڴ��������32
	Test(0xFFFFFFFF, 32);

	// ����0x80000000�����������ڴ��������1
	Test(0x80000000, 1);
	system("pause");
	return 0;
}

