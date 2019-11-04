//�������� 
//����Ϊ���鼰�䳤��
#include<iostream>
using namespace std;
void Quick_Sort(int arr[], int low, int high) 
{
	if (high <= low) return;
	int i = low;
	int j = high + 1;
	int key = arr[low];
	while (true)
	{
		/*���������ұ�key���ֵ*/
		while (arr[++i] < key)
		{
			if (i == high) {
				break;
			}
		}
		/*���������ұ�keyС��ֵ*/
		while (arr[--j] > key)
		{
			if (j == low) {
				break;
			}
		}
		if (i >= j) break;
		/*����i,j��Ӧ��ֵ*/
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	/*����ֵ��j��Ӧֵ����*/
	int temp = arr[low];
	arr[low] = arr[j];
	arr[j] = temp;
	Quick_Sort(arr, low, j - 1);
	Quick_Sort(arr, j + 1, high);
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
	Quick_Sort(arr,0,10);
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	system("pause");
}
