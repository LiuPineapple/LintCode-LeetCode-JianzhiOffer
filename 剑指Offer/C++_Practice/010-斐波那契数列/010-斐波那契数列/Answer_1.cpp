//��C++��дԭ��

#include<iostream>
using namespace std;

//����1���ݹ飬������࣬��Ч��̫��
int Fibonacci_Solution1(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return Fibonacci_Solution1(n - 1) + Fibonacci_Solution1(n-2);
}
//��������ѭ����ʱ�临�Ӷ�ΪO(n)
int Fibonacci_Solution2(int n)
{
	int mini1 = 0;
	int mini2 = 1;
	int result = 0;
	if (n == 0)
		return mini1;
	if (n == 1)
		return mini2;
	for (int i = 2; i <= n; i++)
	{
		result = mini1 + mini2;
		mini1 = mini2;
		mini2 = result;
	}
	return result;
}
//�����ַ�������ʱ��д
int Fibonacci_Solution3(int n)
{
	return Fibonacci_Solution2(n);
}
// ====================���Դ���====================
void Test(int n, int expected)
{
	if (Fibonacci_Solution1(n) == expected)
		printf("Test for %d in solution1 passed.\n", n);
	else
		printf("Test for %d in solution1 failed.\n", n);

	if (Fibonacci_Solution2(n) == expected)
		printf("Test for %d in solution2 passed.\n", n);
	else
		printf("Test for %d in solution2 failed.\n", n);

	if (Fibonacci_Solution3(n) == expected)
		printf("Test for %d in solution3 passed.\n", n);
	else
		printf("Test for %d in solution3 failed.\n", n);
}

int main(int argc, char* argv[])
{
	Test(0, 0);
	Test(1, 1);
	Test(2, 1);
	Test(3, 2);
	Test(4, 3);
	Test(5, 5);
	Test(6, 8);
	Test(7, 13);
	Test(8, 21);
	Test(9, 34);
	Test(10, 55);

	Test(40, 102334155);
	system("pause");
	return 0;
}