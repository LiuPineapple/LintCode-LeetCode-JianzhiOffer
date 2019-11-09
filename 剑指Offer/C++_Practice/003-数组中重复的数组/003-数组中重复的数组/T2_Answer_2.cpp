//��ͬ�ڴ𰸵ķ���
//����Ҳ�ᵽ�ˣ������ÿռ任ʱ��
//ʱ�临�Ӷ�ΪO(n)
//�ռ临�Ӷ�ΪO(n)

#include<iostream>
using namespace std;

int find_duplicate(const int *arr,int length)
{
	if (arr == nullptr || length <= 0)
	{
		return -1;
	}
	for (int i = 0; i < length; ++i)
	{
		if (arr[i] < 0 || arr[i] > length - 1)
			return -1;
	}
	int *arr2 = new int[length];
	for (int i = 0; i < length; i++)
	{
		if (arr2[arr[i]] == arr[i])
		{
			return arr[i];
		}
		//cout << arr2[arr[i]] << endl;
		arr2[arr[i]] = arr[i];
	}
	delete[] arr2;
	return -1;

}

// ====================���Դ���====================
void test(const char* testName, int* numbers, int length, int* duplications, int dupLength)
{
	int result = find_duplicate(numbers, length);
	for (int i = 0; i < dupLength; ++i)
	{
		if (result == duplications[i])
		{
			std::cout << testName << " passed." << std::endl;
			return;
		}
	}
	std::cout << testName << " FAILED." << std::endl;
}


// ����ظ�������
void test1()
{
	int numbers[] = { 2, 3, 5, 4, 3, 2, 6, 7 };
	int duplications[] = { 2, 3 };
	test("test1", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// һ���ظ�������
void test2()
{
	int numbers[] = { 3, 2, 1, 4, 4, 5, 6, 7 };
	int duplications[] = { 4 };
	test("test2", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// �ظ�����������������С������
void test3()
{
	int numbers[] = { 1, 2, 3, 4, 5, 6, 7, 1, 8 };
	int duplications[] = { 1 };
	test("test3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// �ظ�����������������������
void test4()
{
	int numbers[] = { 1, 7, 3, 4, 5, 6, 8, 2, 8 };
	int duplications[] = { 8 };
	test("test4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// ������ֻ����������
void test5()
{
	int numbers[] = { 1, 1 };
	int duplications[] = { 1 };
	test("test5", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// �ظ�������λ�����鵱��
void test6()
{
	int numbers[] = { 3, 2, 1, 3, 4, 5, 6, 7 };
	int duplications[] = { 3 };
	test("test6", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// ����ظ�������
void test7()
{
	int numbers[] = { 1, 2, 2, 6, 4, 5, 6 };
	int duplications[] = { 2, 6 };
	test("test7", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// һ�������ظ�����
void test8()
{
	int numbers[] = { 1, 2, 2, 6, 4, 5, 2 };
	int duplications[] = { 2 };
	test("test8", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// û���ظ�������
void test9()
{
	int numbers[] = { 1, 2, 6, 4, 5, 3 };
	int duplications[] = { -1 };
	test("test9", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// ��Ч������
void test10()
{
	int *numbers = nullptr;
	int duplications[] = { -1 };
	test("test10", numbers, 0, duplications, sizeof(duplications) / sizeof(int));
}

void main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
	test10();
	system("pause");
}