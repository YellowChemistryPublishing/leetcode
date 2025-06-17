#include <iostream>
#include <set>
#include <vector>
using namespace std;
#define int long long
signed main(){
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    set<int> s;
    int left=0,right=0;

    int ret=0;
    while (left<n){
        while(right<n){
            if(s.count(a[right]))
                break;
            s.emplace(a[right++]);
        }

        ret+=right-left;

        s.erase(a[left]);
        ++left;
    }
    cout<<ret<<'\n';
}