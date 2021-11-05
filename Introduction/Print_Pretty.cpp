#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;

		/* Enter your code here */
        cout<<hex<<left<<showbase<<nouppercase;
        cout<<(long long)A<<endl;
        cout<<dec<<fixed<<setprecision(2)<<right<<showpos<<setw(15)<<setfill('_');
        cout<<B<<endl;
        cout<<noshowpos<<uppercase<<scientific<<setprecision(9);
        cout<<C<<endl;
	}
	return 0;

}