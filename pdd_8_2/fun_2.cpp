#include <bits/stdc++.h>
using namespace std;

/*
解析：关键是如何转换筛子

上下前后左右

1.基本操作：(注意到这里有六个，要写全)
right-> 右左前后上下
left-> 左右前后下上
front-> 前后下上左右
back-> 后前上下左右

2.
如果最小数在非上位置，转到上
下：left->left->left
前：back
后: front
左：right
右：left

其次找次小数位置，找除上下位置的次小数，移动到左
前：front->right
后：back->right

右：left->left->left

此时确定的就是唯一的位置

总结：一开始思考问题的时候就必须把问题都想全面，最好整体检查一下代码
*/
const int N = 1010, M = 6;

int w[N][M], n;

void left(int a[]) {
    swap(a[0], a[1]);
    swap(a[0], a[4]);
    swap(a[1], a[5]);
}

void right(int a[]) {
    swap(a[4], a[5]);
    swap(a[0], a[4]);
    swap(a[1], a[5]);
}

void front(int a[]) {
    swap(a[0], a[1]);
    swap(a[0], a[2]);
    swap(a[1], a[3]);
}

void back(int a[]) {
    swap(a[2], a[3]);
    swap(a[0], a[2]);
    swap(a[1], a[3]);
}


string convert(int a[]) {
    int min_val = INT_MAX, min_i = 0;
    cout << "begin" << endl;
    for (int i = 0; i < M; i ++) { // 上下左右前后
        cout << a[i] << ' ';
        if (min_val > a[i]) {
            min_val = a[i], min_i = i;
        }
    }
    cout << endl;

    cout << min_val << ' ' << min_i << endl;
    // 找到最小的数，放到上面
    if (min_i == 1) left(a), left(a), left(a); 
    else if (min_i == 2) back(a);
    else if (min_i == 3) front(a);
    else if (min_i == 4) right(a);
    else if (min_i == 5) left(a);

    // 找到次小的数，放到左面
    min_val = INT_MAX, min_i = 0;
    for (int i = 2; i < M; i ++) {
        if (min_val > a[i]) {
            min_val = a[i], min_i = i;
        }
    }

    for (int i = 0; i < M; i ++) cout << a[i] << ' ';
    cout << endl;
    cout << min_val << ' ' << min_i << endl;
    if (min_i == 2) front(a), right(a);
    else if (min_i == 3) back(a), right(a);
    else if (min_i == 5) left(a), left(a), left(a);

    for (int i = 0; i < M; i ++) cout << a[i] << ' ';
    cout << endl;
    string res;
    for (int i = 0; i < M; i ++) res += to_string(a[i]);
    cout << "end" << res << endl;
    return res;
}

int main() {
    freopen("pdd_8_2/data/in_2.txt", "r", stdin);
    freopen("pdd_8_2/data/out_2.txt", "w", stdout);
    cin >> n;
    unordered_map<string, int> hash;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < 6; j ++)
            cin >> w[i][j];
        hash[convert(w[i])] ++;
    }

    cout << hash.size() << endl;
    vector<int> res;
    for (auto x: hash) res.push_back(x.second), cout << x.first << endl;

    sort(res.begin(), res.end());
    for (int i = res.size() - 1; i >= 0; i --) cout << res[i] << ' ';
    cout << endl;
    // system("pause");
    return 0;
}