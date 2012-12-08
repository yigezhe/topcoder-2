#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define x first
#define y second
#define LL long long
using namespace std;

typedef pair<int, int> per;
typedef vector<int>::iterator it;
typedef set<int>::iterator is;

int fr[26],fa[26],fol[5005],am[26];

struct FoxAndHandle {
	string lexSmallestName(string s) {
		string rez;
		for(int i=0; i<s.size(); ++i) ++fr[s[i]-'a'];
		for(int i=0; i<26; ++i) fr[i]/=2;
		int lm=s.size()/2,lst=0;
		for(;rez.size()<lm;) {
			memset(fa,0,sizeof(fa));
			char lmin='z'+1;int pmin=-1;
			for(int i=0; i<s.size(); ++i)
				if(!fol[i]) {
					if(i>=lst && s[i]<lmin && am[s[i]-'a']<fr[s[i]-'a']) {
						lmin=s[i];
						pmin=i;
					}
					if(fa[s[i]-'a']==fr[s[i]-'a']) break;
					else ++fa[s[i]-'a'];
				}
			rez+=lmin;
			++am[lmin-'a'];
			fol[pmin]=1;
			lst=pmin+1;
		}
		return rez;
	}
};


//Powered by [KawigiEdit] 2.0!



// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
	cout << "]" << endl;
	FoxAndHandle *obj;
	string answer;
	obj = new FoxAndHandle();
	clock_t startTime = clock();
	answer = obj->lexSmallestName(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p1 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p1;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	string p0;
	string p1;
	
	{
	// ----- test 0 -----
	p0 = "foxfox";
	p1 = "fox";
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "ccieliel";
	p1 = "ceil";
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "abaabbab";
	p1 = "aabb";
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = "bbbbaaaa";
	p1 = "bbaa";
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = "fedcbafedcba";
	p1 = "afedcb";
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = "nodevillivedon";
	p1 = "deilvon";
	all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
