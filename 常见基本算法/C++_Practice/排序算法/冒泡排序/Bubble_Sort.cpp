 //ð������ 
//����Ϊ���鼰�䳤��
#include<iostream>
using namespace std;
 void Bubble_Sort(int arr[], int size_arr)
 {
	if (arr == NULL) return;
    if (size_arr <= 1) return;
	for (int i = 0; i < size_arr - 1; i++)
	{
		for (int j = 0; j < size_arr - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])//��Ϊ�����򽫴��ںŸ�ΪС�ں�
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				//����ֱ��ʹ��swap(arr[j],arr[j+1])
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
	 Bubble_Sort(arr,10);
	 for (int i = 0; i < 10; i++)
	 {
		 cout << arr[i] << " ";
	 }
	 cout << endl;
	 system("pause");
 }
