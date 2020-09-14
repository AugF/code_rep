#include <bits/stdc++.h>
using namespace std;

struct Vec2 {
    float x, y;
};

Vec2 f1(Vec2 v0, Vec2 v1) {
    return {v0.x - v1.x, v0.y - v1.y};
}

float f2(Vec2 v0, Vec2 v1) {
    return v0.x * v1.x + v0.y * v1.y;
}

Vec2 f3(Vec2 p1, Vec2 p2, Vec2 p) {
    Vec2 v1 = f1(p2, p1), v2 = f1(p, v1);
    float d = f2(v1, v2) / f2(v1, v1);
    if (d <= 0) return p1;
    if (d >= 1) return p2;
    return {p1.x + v1.x * d, p1.y + v1.y * d};
}

float calc(Vec2 *v, int n, Vec2 p) {
    bool f = true;
    float d = 10000000.0f;
    for (int i = 0; i < n; i ++) {
        int j = (i + 1) % n;
        Vec2 v1 = f1(v[i], v[j]);
        Vec2 v2 = f1(p, v[j]);
        if (v1.x * v2.y - v1.y * v2.x <= 0) {
            f = false;
            Vec2 p1 = f3(v[i], v[j], p);
            float tmpD = (p1.x - p.x) * (p1.x - p.x) + (p1.y - p.y) * (p1.y - p.y);
            if (tmpD < d) d = tmpD;
        }
    }
    return f?-1: d;
}

int main() {
    Vec2 v[] = {{107, 101}, {107, -53}, {47, -61}, {-113, -13}, {-97, 71}, {23, 123}};
    Vec2 p = {47, -64};
    printf("%.2f", calc(v, sizeof(v) / sizeof(Vec2), p));
    system("pause");
    return 0;
}

