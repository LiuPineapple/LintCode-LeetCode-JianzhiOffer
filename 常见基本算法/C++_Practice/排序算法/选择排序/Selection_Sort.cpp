//ѡ������ 
//����Ϊ���鼰�䳤��
#include<iostream>
using namespace std;
void Selection_Sort(int arr[], int size_arr)
{
	if (arr == NULL) return;
	if (size_arr <= 1) return;
	int index;
	for (int i = 0; i < size_arr - 1; i++)
	{
		index = i;
		for (int j = i+1; j < size_arr; j++)
		{
			if (arr[index] > arr[j])//��Ϊ�����򽫴��ںŸ�ΪС�ں�
			{
				index = j;
			}
		}
		swap(arr[index], arr[i]);
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
	Selection_Sort(arr, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	system("pause");
}
