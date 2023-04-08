#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    int box[5];
    cin >> T;
    while(T--) {
        int two=0,one=0;
        int ans;
        for(int i=0;i<5;i++)
            cin >> box[i];
        cin >> ans;
        ans += box[4];
        one += box[4] * 11;
        ans += box[3];
        two += box[3] * 5;
        ans += box[2]/4;
        box[2] = box[2]%4;
        if(box[2])
            ans++;
        two += 4-box[2];
        one += (4-box[2]) * 5;
        box[1] -= two;
        if(box[1] > 0) {
            ans += box[1] / 9 + 1;
            box[1] = box[1] % 9;
            one += (9-box[1]) * 2;
        }
        else
            one += (-1*box[1]) * 2;
        box[0] -= one;
        if(box[0] > 0)
            ans += box[1] / 36 + 1;
        cout << ans  << ":" << endl;
    }
}
