#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<vector>
using namespace std;

//int main()
//{
//    string str;
//    string ans;
//    cin >> str;
//    vector<int> count(10);
//
//    for (auto ch : str)
//    {
//        if (ch >= '1' && ch <= '9')
//        {
//            if (count[ch - '1'] == 0)
//            {
//                count[ch - '1' + 1]++;
//                ans.push_back(ch);
//            }
//
//        }
//    }
//    cout << ans;
//    return 0;
//}


bool areAlmostEqual(string s1, string s2) {
    if (s1 == s2)
        return true;
    int len = s1.size();
    if (len <= 2)
    {
        if (s1 != s2)
            return false;
    }
    int sum = 0;
    char ch;
    for (int i = 0;i < len;i++)
    {
        if (s1[i] != s2[i])
        {
            sum++;
            if(sum == 1)
            ch = s1[i];
        }
        if (sum > 2)
        {

            return false;
        }
        else if (sum == 2 && s1[i] != s2[i])
        {
            if (s2[i] != ch)
                return false;
        }
    }
    return true;
}


//int main()
//{
//    string s1 = "siyolsdcjthwsiplccjbuceoxmpjgrauocx";
//    string s2 = "siyolsdcjthwsiplccpbuceoxmjjgrauocx";
//    cout<<areAlmostEqual(s1, s2);
//    return 0;
//}


//int main()
//{
//    int a = 1;
//    int b = 2;
//    int c = 3;
//    printf("%d %d %d\n", a, b,c);
//}


#include<iostream>
#include<vector>
using namespace std;


//int main()
//{
//    int n = 8;
//    /*cin >> n;
//    vector<int> cnt(n);
//    for (int i = 0;i < n;i++)
//    {
//        cin >> cnt[i];
//    }*/
//
//    //-2 1 - 3 4 - 1 2 1 - 5
//    vector<int> cnt;
//    cnt.push_back(-2);
//    cnt.push_back(1);
//    cnt.push_back(-3);
//    cnt.push_back(4);
//    cnt.push_back(-1);
//    cnt.push_back(2);
//    cnt.push_back(1);
//    cnt.push_back(-5);
//
//
//    /*cnt.push_back(-1);
//    cnt.push_back(2);
//    cnt.push_back(1);*/
//
//    int ans = cnt[0];
//    int sum = INT32_MIN;
//    int fast = 0;
//    int slow = 0;
//    while (slow < n)
//    {
//        if (ans < 0)
//            ans = 0;
//        while (fast < n && cnt[fast]>0)
//        {
//            fast++;
//        }
//        while (slow < fast)
//        {
//            ans += cnt[slow++];
//        }
//        if (fast < n && cnt[fast] > 0)
//        {
//            ans += cnt[fast];
//        }
//        sum = max(ans, sum);
//        fast++;
//        slow++;
//        if(slow<n)
//        ans -= cnt[slow];
//    }
//    cout << sum << endl;
//    return 0;
//}



#include<iostream>
#include<string>
using namespace std;


bool ishuiwen(string str)
{
    int left = 0;
    int right = str.size() - 1;
    while (left < right)
    {
        if (str[left] != str[right])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

//int main()
//{
//    string s1, s2;
//   // cin >> s1 >> s2;
//    s1 = "aa";
//    s2 = "a";
//
//    int sum = 0;
//
//    for (int i = 0;i < s1.size();i++)
//    {
//        string stmp = s1;
//        stmp.insert(i, s2);
//        if (ishuiwen(stmp))
//        {
//            sum++;
//        }
//    }
//    cout << sum << endl;
//    return 0;
//}


#include<iostream>
#include<vector>
using namespace std;


//int main()
//{
//    int w = 3;
//    int h = 2;
//    int sum = 0;
//    //cin >> w >> h;
//    vector<vector<int>> cnt(h, vector<int>(w));
//    for (int i = 0;i < cnt.size();i++)
//        for (int j = 0;j < cnt[0].size();j++)
//        {
//            if ((i == 0 && j <= 1) || (j == 0 && i <= 1))
//            {
//                cnt[i][j] = 1;
//                sum++;
//            }
//            else if ((j == 2 && i <= 1) || (i == 2 && j <= 1))
//            {
//                cnt[i][j] = 0;
//            }
//            else if ((i >= 2 && i < cnt.size() - 1) && (cnt[i + 2][j] == 1 || cnt[i - 2][j] == 1))
//            {
//                cnt[i][j] = 0;
//            }
//            else if ((j >= 2 && j < cnt.size() - 1) && (cnt[i][j + 2] == 1 || cnt[i][j - 2] == 1))
//            {
//                cnt[i][j] = 0;
//            }
//            else {
//                cnt[i][j] = 1;
//                sum++;
//            }
//        }
//    cout << sum << endl;
//    return 0;
//}



#include<iostream>
#include<vector>
using namespace std;


const int MAXN = 1005;
int v[MAXN];    // 体积
int w[MAXN];    // 价值 
int f[MAXN][MAXN];  // f[i][j], j体积下前i个物品的最大价值 

//int main()
//{
//    int n, m;
//    cin >> n >> m;
//    for (int i = 1; i <= n; i++)
//        cin >> v[i] >> w[i];
//
//    for (int i = 1; i <= n; i++)
//        for (int j = 1; j <= m; j++)
//        {
//            //  当前背包容量装不进第i个物品，则价值等于前i-1个物品
//            if (j < v[i])
//                f[i][j] = f[i - 1][j];
//            // 能装，需进行决策是否选择第i个物品
//            else
//                f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]);
//        }
//
//    cout << f[n][m] << endl;
//
//    return 0;
//}



#include<iostream>
using namespace std;


bool fibo(int n)
{
    int p = 0;
    int b = 1;
    int r = 0;
    while (r < n)
    {
        r = p + b;
        p = b;
        b = r;
    }
    if (r == n)
    {
        return true;
    }
    return false;
}

//int main()
//{
//    int num = 0;
//    cin >> num;
//
//    int subsum = 0;
//    int addsum = 0;
//    int sum = 0;
//
//
//    /*int tmp = num;
//    while (tmp--)
//    {
//        subsum++;
//        if (fibo(tmp))
//            break;
//     
//    }
//
//    tmp = num;
//
//    while (tmp++)
//    {
//        addsum++;
//        if (fibo(tmp))
//            break;
//        
//    }*/
//
//
//    int p = 0;
//    int b = 1;
//    int r = 0;
//
//    while (r < num)
//    {
//        r = p + b;
//        p = b;
//        b = r;
//    }
//    addsum = r - num;
//    subsum = num - b;
//
//    sum = min(addsum, subsum);
//    cout << sum << endl;
//    return 0;
//}




#include<stack>

bool chkParenthesis(string A, int n) {
    // write code here

    stack<char> s;
    if (A[0] == '(')
    {
        s.push(A[0]);
    }
    else
    {
        return false;
    }

    int i = 1;

    while (!s.empty() && i < n)
    {
        if (A[i] == '(')
        {
            s.push(A[i]);
            i++;
        }
        else if (A[i] == ')')
        {
            if (!s.empty())
            {
                s.pop();
                i++;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }

    if (i == n)
        return true;

    else
        return false;

}


//int main()
//{
//    string A = "()()(((())))";
//    chkParenthesis(A, 12);
//}


class A

{

public:

    A() :m_iVal(0) { test(); }

    virtual void func() { std::cout << m_iVal << ' '; }

    void test() { func(); }

public:

    int m_iVal;

};



class B : public A

{

public:

    B() { test(); }

    virtual void func()

    {

        ++m_iVal;

        std::cout << m_iVal << ' ';

    }

};



//int main(int argc, char* argv[])
//
//{
//
//    A* p = new B;
//
//    p->test();
//
//    return 0;
//
//}



int totalFruit(vector<int>& fruits) {
    int numbers = 2;
    vector<int> cnt(2);
    int sum = 0;
    int tmp = 0;
    int count = 0;
    for (int i = 0;i < fruits.size();i++)
    {
        if (numbers == 2)
        {
            cnt[0] = fruits[i];
            numbers--;
            tmp = i;
            count++;
        }
        else if (numbers == 1 && fruits[i] != cnt[0])
        {
            cnt[1] = fruits[i];
            numbers--;
            count++;
        }
        else if (fruits[i] == cnt[1])
        {
            count++;
        }
        else if (fruits[i] == cnt[0])
        {
            count++;
            tmp = i;
        }
        else if (numbers == 0 && fruits[i] != cnt[0] && fruits[i] != cnt[1])
        {
            i = tmp;
            cnt[0] = 0;
            cnt[1] = 0;
            numbers = 2;
            sum = max(sum, count);
            count = 0;
        }
    }
    return sum;
}



//int main()
//{
//    //[3,3,3,1,2,1,1,2,3,3,4]
//    vector<int> f;
//    f.push_back(3);
//    f.push_back(3);
//    f.push_back(3);
//    f.push_back(1);
//    f.push_back(2);
//    f.push_back(1);
//    f.push_back(1);
//    f.push_back(2);
//    f.push_back(3);
//    f.push_back(3);
//    f.push_back(4);
//    totalFruit(f);
//}


class s
{
public:
    s(int x)
    {
        p = new int(x);
    }
    int show()
    {
        return *p;
    }
private:
    int* p;
};

//int main()
//{
//    s s1(5);
//    cout << s1.show();
//}


int countStudents(vector<int>& students, vector<int>& sandwiches) {
    vector<int> cnt(2);
    for (auto s : students) cnt[s]++;
    auto stu = students.begin();
    auto san = sandwiches.begin();
    for (;san < sandwiches.end();)
    {
        if (*stu != *san)
        {

            int tmp = *stu;
            stu = students.erase(stu);
            students.push_back(tmp);
            san++;
        }
        else
        {
            stu = students.erase(stu);
            san = sandwiches.erase(san);
        }

    }
    return students.size();
}


int main()
{
    vector<int> stu = { 1,1,0,0 };
    vector<int> san = { 0,1,0,1 };
    countStudents(stu, san);
}