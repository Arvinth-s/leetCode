//OM NAMO NARAYANA
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int A, B;
        cin>>A>>B;
        //x=ABn1 y=An2 and n2%B!=0 
        if(B==1){
            cout<<"NO\n";
            continue;
        }
        int n2 = B+1;
        int x = A*B;
        int y = A*n2;
        int z = x+y;
        assert(x % (A * B) == 0);
        assert(y % (A * B) != 0);
        assert(z % (A * B) != 0);
        assert(z % (A ) == 0);
        assert(z % (A) == 0);
        printf("YES\n%d %d %d\n", x, y, z);
    }
    return 0;
}