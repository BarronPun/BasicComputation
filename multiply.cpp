#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

//Function multiply is a function used to calculate the multiplication of two
//integer number A and B, A and B can be very large
string multiply(string str1, string str2)
{
	int len1 = str1.length();
	int len2 = str2.length();

	int a[len1]={0}, b[len2]={0}, result[len1+len2] = {0};

	int count = 0, lsum = 0;

	for (int i=len1-1; i>=0; i--)
	{
		a[count++] = str1[i]-'0';
	}

	count = 0;

	for (int i=len2-1; i>=0; i--)
	{
		b[count++] = str2[i]-'0';
	}


	for (int i=0; i<len1; i++)
	{
		lsum = i;
		for (int j=0; j<len2; j++)
		{
			result[lsum++] += a[i]*b[j];
		}
	}

	for (int i=0; i<lsum; i++)
	{
		if (result[i]>=10)
		{
			if (result[lsum-1]>=10) lsum++;
			result[i+1] = result[i+1] + result[i]/10;
			result[i] = result[i] % 10;
		}
	}

	string ans;
	char ch;
	for (int i=0; i<lsum; i++)
	{
		ch = result[i] + '0';
		ans = ch + ans;
	}

	return ans;
} // end of function multiply


//test
int main()
{
	string NumberA, NumberB;

	cin >> NumberA;

	cin >> NumberB;

	cout << multiply(NumberA, NumberB) << endl;

}