//�������� 
//����Ϊ���鼰�䳤��
#include<iostream>
using namespace std;
void Insert_Sort(int arr[], int size_arr)
{
	if (arr == NULL) return;
	if (size_arr <= 1) return;
	for (int i = 1; i < size_arr; i++)
	{
		for (int j = i; j >0; j--)
		{
			if (arr[j - 1]>arr[j])//��Ϊ�����򽫴��ںŸ�ΪС�ں�
			{
				swap(arr[j], arr[j-1]);
			}
		}
		
	}
}
//����
int main()
{
	int arr[10] = { 1,4,6,8,0,2,5,7,9,3 };
	cout << "����ǰ" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "�����" << endl;
	Insert_Sort(arr, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	system("pause");
}
