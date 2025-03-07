#include <bits/stdc++.h>
using namespace std;
int a[] = {1, 5, 8, 10, 13, 16, 19, 22, 25, 28, 29, 32, 45, 77}; // 下标0——13
int find_1(int g)                                                // 功能：查找g的下标 若a[mid]存在 L一定在mid前面 R在mid或mid后面 L和R永远不会重合    若没g返回-1
{
    int L = 0, R = 13;
    int mid;
    while (L < R)
    {
        mid = (L + R + 1) / 2;
        if (a[mid] < g)
        {
            L=mid;
        }
        else if (a[mid] == g)
        {
            return mid;
        }
        else if (a[mid] > g)
        {
            R=mid-1;
        }
    }
    return -1;
}
int find_2(int g) // 查找大于等于g的下标
{
    int L = 0, R = 13;
    int mid;
    while (L < R)
    {
        mid = (L + R + 1) / 2;
        if (a[mid] < g)
        {
            L=mid;
        }
        else if (a[mid] == g)
        {
            return mid;
        }
        else if (a[mid] > g)
        {
            R=mid-1;
        }
    }
    return -1;
}

int find_3(int g) // 查找大于g的下标
{
    int L = 0, R = 13;
    int mid;
    while (L < R)
    {
        mid = (L + R) / 2;
        if (a[mid] < g)
        {
            L=mid+1;
        }
        else if (a[mid] == g)
        {
            return mid+1;
        }
        else if (a[mid] > g)
        {
            R=mid;
        }
    }
    return L;
}

int find_4(int g) // 查找小于等于g的下标
{
    int L = 0, R = 13;
}

int find_5(int g) // 查找小于g的下标
{
    int L = 0, R = 13;
}
int main()
{
    cout<<find_3(16);
}
/*





*/