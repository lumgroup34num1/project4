#include <iostream>
#include <Windows.h>
#include "sm3.h"
using namespace std;

void printt_u8(u8* input);

int main()
{
	LARGE_INTEGER t1, t2, tc;
	double time;
	QueryPerformanceFrequency(&tc);

	u8 input[256] = "abc";
	//u8 input[256] = "abcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcd";//����
	u8 output[32];//256�Ӵ�ֵ���
	unsigned int len = 3;

	QueryPerformanceCounter(&t1);
	for (int i = 0; i < 100; i++)
	{
		SM3(input, len, output);
	}
	//SM3(input, len, output);
	QueryPerformanceCounter(&t2);
	time = 1000 * ((double)(t2.QuadPart - t1.QuadPart) / (double)tc.QuadPart);
	cout << "�����Ӵ�ֵʱ�䣺" << time / 100 << "ms" << endl;

	cout << "�Ӵ�ֵΪ��" << endl;
	printt_u8(output);
	return 0;
}

void printt_u8(u8* output) {
	for (int i = 0; i < 32; i++)//16�������
	{
		int a = output[i];
		if (a < 16)
			cout << "0x0" << hex << a << " ";
		else
			cout << "0x" << hex << a << " ";
		if ((i + 1) % 8 == 0)
			cout << endl;
	}
	cout << endl;
}