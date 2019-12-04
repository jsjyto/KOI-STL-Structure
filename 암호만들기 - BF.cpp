#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

const int MAX = 15;
int L, C;
char alphabet[MAX];

vector<char> vowel; //모음
vector<char> consonant; //자음
vector<string> result; //결과

map<string, bool> visited;

void password(int idx1, int idx2, int vCnt, int cCnt, string s)
{
	//조건 만족
	if (s.length() == L && vCnt >= 1 && cCnt >= 2)
	{
		sort(s.begin(), s.end());
		if (!visited.count(s))
		{
			visited[s] = true;
			result.push_back(s);
		}
		return;
	}

	//기저 사례
	if (s.length() == L)
		return;

	for (int i = idx1 + 1; i < vowel.size(); i++)
		password(i, idx2, vCnt + 1, cCnt, s + vowel[i]);

	for (int i = idx2 + 1; i < consonant.size(); i++)
		password(idx1, i, vCnt, cCnt + 1, s + consonant[i]);
}

int main(void)
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> L >> C;

	for (int i = 0; i < C; i++)
	{
		cin >> alphabet[i];
		if (alphabet[i] == 'a' || alphabet[i] == 'e' || alphabet[i] == 'i' || alphabet[i] == 'o' || alphabet[i] == 'u')
			vowel.push_back(alphabet[i]);

		else
			consonant.push_back(alphabet[i]);
	}

	sort(vowel.begin(), vowel.end());
	sort(consonant.begin(), consonant.end());

	password(-1, -1, 0, 0, "");

	sort(result.begin(), result.end());

	for (int i = 0; i < result.size(); i++)
		cout << result[i] << "\n";

	return 0;
}
