// HW0.cpp : 定義主控台應用程式的進入點。
//

#include "stdio.h"
#include "stdlib.h"
#include "iostream"

using namespace std;
#define MAX 10

int main()
{
	char op;
	int num[MAX] = { 0 }, inNum, length = 0, j, delNum, check = 0;;
	while (1)
	{
		cout << "Input or　Delete?";
		cin >> op;
		if (op == 'I' || op == 'i')
		{
			if (length < MAX)
			{
				cout << "Input an integer:";
				cin >> inNum;
				if (length == 0)
				{
					num[0] = inNum;
					length++;
				}
				else
				{
					for (int i = 0; i < length; i++)
					{
						if (num[i] >= inNum)
						{
							for (j = length; j >= i; j--)
							{
								num[j] = num[j - 1];
							}
							num[i] = inNum;
							length++;
							break;
						}
						else if (i == length - 1)
						{
							num[i + 1] = inNum;
							length++;
							break;
						}

					}

				}
				for (int k = 0; k < length; k++)
				{
					cout << num[k] << " ";
				}
				cout << endl;
			}
			else
			{
				cout << "full" << endl;
			}

		}
		else if (op == 'D' || op == 'd')
		{
			if (length == 0)
			{
				cout << "empty" << endl;
			}
			else
			{
				cout << "Delete which integer:";
				cin >> delNum;
				for (int i = 0; i < length; i++)
				{
					if (delNum == num[i])
					{
						if (i == length)
						{
							num[i] = 0;//若要刪除最後一個則直接將其令為0
							length--;

						}
						else
						{
							for (int k = i; k < length; k++)
							{
								num[k] = num[k + 1];
							}
							length--;
						}
						i--; //如果已經刪了一個發現還有重複的要刪，但數字已經往前移一位了
							 //所以要從前一位開始檢查
					}
				}

			}
			for (int k = 0; k < length; k++)
			{
				cout << num[k] << " ";
			}
			cout << endl;
		}

	}

}
