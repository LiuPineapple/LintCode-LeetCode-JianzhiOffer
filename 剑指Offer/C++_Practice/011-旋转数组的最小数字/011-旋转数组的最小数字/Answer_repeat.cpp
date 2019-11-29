//���ֲ����������������飬ʱ�临�Ӷ�ΪO(log(n))
//Ҫ���������������:
//-���鳤��Ϊ0
//- ���鳤��Ϊ1
//- ����û����ת
//- ���ֲ��ҵ����ߺ��м����

#include<exception>
#include<iostream>
#include<cstdio>
using namespace std;

//˳�����
int MinInorder(int * number, int index1, int index2)
{
	int result = number[index1];
	for (int i = index1+1; i <= index2; i++)
	{
		if (result > number[i])
			result = number[i];
	}
	return result;
}


//���ֲ���
int Min(int * number, int length)
{
	if (number == nullptr || length <= 0)
		throw new exception("Invalide Input");
	int index1 = 0;
	int index2 = length - 1;
	int indexM = index1;
	while (number[index1] >= number[index2])
	{
		if (index2 - index1 == 1)
		{
			indexM = index2;
			break;
		}
		indexM = (index1 + index2) / 2;
		if (number[index2] == number[index1] && number[index1] == number[indexM])
			return MinInorder(number, index1, index2);
			return 1;
		if (number[indexM] >= number[index1])
			index1 = indexM;
		if (number[indexM] <= number[index2])
			index2 = indexM;
	}
	return number[indexM];
}

	// ====================���Դ���====================
	void Test(int* numbers, int length, int expected)
	{
		int result = 0;
		try
		{
			result = Min(numbers, length);

			for (int i = 0; i < length; ++i)
				printf("%d ", numbers[i]);

			if (result == expected)
				printf("\tpassed\n");
			else
				printf("\tfailed\n");
		}
		catch (...)
		{
			if (numbers == nullptr)
				printf("Test passed.\n");
			else
				printf("Test failed.\n");
		}
	}

	int main(int argc, char* argv[])
	{
		// �������룬��������������һ����ת
		int array1[] = { 3, 4, 5, 1, 2 };
		Test(array1, sizeof(array1) / sizeof(int), 1);

		// ���ظ����֣������ظ������ָպõ���С������
		int array2[] = { 3, 4, 5, 1, 1, 2 };
		Test(array2, sizeof(array2) / sizeof(int), 1);

		// ���ظ����֣����ظ������ֲ��ǵ�һ�����ֺ����һ������
		int array3[] = { 3, 4, 5, 1, 2, 2 };
		Test(array3, sizeof(array3) / sizeof(int), 1);

		// ���ظ������֣������ظ������ָպ��ǵ�һ�����ֺ����һ������
		int array4[] = { 1, 0, 1, 1, 1 };
		Test(array4, sizeof(array4) / sizeof(int), 0);

		// �����������飬��ת0��Ԫ�أ�Ҳ���ǵ����������鱾��
		int array5[] = { 1, 2, 3, 4, 5 };
		Test(array5, sizeof(array5) / sizeof(int), 1);

		// ������ֻ��һ������
		int array6[] = { 2 };
		Test(array6, sizeof(array6) / sizeof(int), 2);

		// ����nullptr
		Test(nullptr, 0, 0);
		system("pause");
		return 0;
	}

