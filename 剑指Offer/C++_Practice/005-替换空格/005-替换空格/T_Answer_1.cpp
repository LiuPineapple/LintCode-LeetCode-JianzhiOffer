//�ڴ𰸴���������޸�
//ʱ�临�Ӷ�ҲΪO(n)
//��while�ĵط�����һ������

#include<iostream>
using namespace std;

void replace_space(char str[], int length)
{
	//if (str == nullptr && length <= 0)
	//	return;

	int original_length = 0;
	int num_space=0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] != '\0')
		{
			original_length++;
		}
		if (str[i] == ' ')
		{
			num_space++;
		}
	}
	int new_length = original_length + 2 * num_space;
	int index_a = original_length;
	int index_b = new_length;
	while (index_a < index_b)
	{
		if (str[index_a] != ' ')
		{
			str[index_b--] = str[index_a];
		}
		else
		{
			str[index_b--] = '0';
			str[index_b--] = '2';
			str[index_b--] = '%';
		}
		index_a--;
	}
}
// ====================���Դ���====================
void Test(char* testName, char str[], int length, char expected[])
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	replace_space(str, length);

	if (expected == nullptr && str == nullptr)
		printf("passed.\n");
	else if (expected == nullptr && str != nullptr)
		printf("failed.\n");
	else if (strcmp(str, expected) == 0)
		printf("passed.\n");
	else
		printf("failed.\n");
}

// �ո��ھ����м�
void Test1()
{
	const int length = 100;

	char str[length] = "hello world";
	Test("Test1", str, length, "hello%20world");
}

// �ո��ھ��ӿ�ͷ
void Test2()
{
	const int length = 100;

	char str[length] = " helloworld";
	Test("Test2", str, length, "%20helloworld");
}

// �ո��ھ���ĩβ
void Test3()
{
	const int length = 100;

	char str[length] = "helloworld ";
	Test("Test3", str, length, "helloworld%20");
}

// �����������ո�
void Test4()
{
	const int length = 100;

	char str[length] = "hello  world";
	Test("Test4", str, length, "hello%20%20world");
}

// ����nullptr
void Test5()
{
	Test("Test5", nullptr, 0, nullptr);
}

// ��������Ϊ�յ��ַ���
void Test6()
{
	const int length = 100;

	char str[length] = "";
	Test("Test6", str, length, "");
}

//��������Ϊһ���ո���ַ���
void Test7()
{
	const int length = 100;

	char str[length] = " ";
	Test("Test7", str, length, "%20");
}

// ������ַ���û�пո�
void Test8()
{
	const int length = 100;

	char str[length] = "helloworld";
	Test("Test8", str, length, "helloworld");
}

// ������ַ���ȫ�ǿո�
void Test9()
{
	const int length = 100;

	char str[length] = "   ";
	Test("Test9", str, length, "%20%20%20");
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();
	Test8();
	Test9();
	system("pause");
	return 0;
}

