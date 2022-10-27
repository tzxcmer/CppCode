#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;


int countStudents(vector<int>& students, vector<int>& sandwiches) {
    vector<int> cnt(2);
    for (auto s : students) cnt[s]++;
    auto stu = students.begin();
    auto san = sandwiches.begin();
    for (;san < sandwiches.end();)
    {
        if (*stu != *san)
        {
            if (cnt[*stu] == 0)
            {
                break;
            }
            int tmp = *stu;
            stu = students.erase(stu);
            students.push_back(tmp);
            
        }
        else
        {
            cnt[*stu]--;
            stu = students.erase(stu);
            san = sandwiches.erase(san);
            
        }

    }
    return students.size();
}


//int main()
//{
//    vector<int> stu = { 1,1,0,0 };
//    vector<int> san = { 0,1,0,1 };
//    countStudents(stu, san);
//}


#include<iostream>
#include<string>
using namespace std;

//int main()
//{
//    string str;
//    cin >> str;
//    int sumNum = 0;//Êý×Ö¸öÊý
//    int sumSmall = 0;//Ð¡Ð´×ÖÄ¸
//    int sumBig = 0;//´óÐ´×ÖÄ¸
//    int sumOther = 0;//·ûºÅ
//    int score = 0;
//    for (auto ch : str)
//    {
//        if (ch >= '0' && ch <= '9')
//        {
//            sumNum++;
//        }
//        else if (ch >= 'a' && ch <= 'z')
//        {
//            sumSmall++;
//        }
//        else if (ch >= 'A' && ch <= 'Z')
//        {
//            sumBig++;
//        }
//        else
//        {
//            sumOther++;
//        }
//
//    }
//    if (sumNum == 1)
//    {
//        score += 10;
//    }
//    else if (sumNum > 1)
//    {
//        score += 20;
//    }
//    if ((sumSmall == 0 && sumBig > 0) || (sumBig == 0 && sumSmall > 0))
//    {
//        score += 10;
//    }
//    else if (sumBig > 0 && sumSmall > 0)
//    {
//        score += 20;
//    }
//    if (sumOther == 1)
//    {
//        score += 10;
//    }
//    else if (sumOther > 1)
//    {
//        score += 25;
//    }
//    if ((sumBig || sumSmall) && sumNum)
//    {
//        score += 2;
//    }
//    else if ((sumBig || sumSmall) && sumNum && sumOther)
//    {
//        score += 3;
//    }
//    else if (sumBig && sumSmall && sumNum && sumOther)
//    {
//        score += 5;
//    }
//
//    string ans;
//    if (score >= 90)
//    {
//        ans = "VERY_SECURE";
//    }
//    else if (score < 90 && score >= 80)
//    {
//        ans = "SECURE";
//    }
//    else if (score < 80 && score >= 70)
//    {
//        ans = "VERY_STRONG";
//    }
//    else if (score < 70 && score >= 60)
//    {
//        ans = "STRONG";
//    }
//    else if (score < 60 && score >= 50)
//    {
//        ans = "AVERAGE";
//    }
//    else if (score < 50 && score >= 25)
//    {
//        ans = "WEAK";
//    }
//    else
//    {
//        ans = "VERY_WEAK";
//    }
//    cout << ans << endl;
//    return 0;
//}


//int main()
//{
//    const int a = 1;
//    int* p = (int*)(&a);
//    *p = 20;
//    cout << a << " " << *p << endl;
//}

#include<iostream>
#include<math.h>
using namespace std;

bool issushu(int n)
{

    int k = (int)sqrt(n);
    for (int i = 2;i < k;i++)
    {
        if (k % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n = 20;
    int sum = 0;
    int minsum = INT32_MAX;
    int res1 = 0;
    int res2 = 0;
    //cin >> n;

    for (int i = 1;i < n / 2;i++)
    {
        if (issushu(i))
        {
            if (issushu(n - i))
            {
                sum = n - i - i;
            }
        }
        if (minsum > sum)
        {
            minsum = sum;
            res1 = i;
            res2 = n - i;
        }
    }
    cout << res1 << endl << res2 << endl;
    return 0;
}