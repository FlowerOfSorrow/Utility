#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

void check_status(int status, const string &where){
	if(status < 0) cout << where << " -> error: " << strerror(errno) << "\n";
	else if(status >> 8) cout << where << " -> program exited abnormally\n";
	else return;
	exit(0);
}

int main(int argc, char *argv[]){
	cin.tie(0)->sync_with_stdio(0);
	const double TIME_LIMIT = 10.0;
	string sol = argv[1], checker = argv[2];
	cout << "Print the results? Type (y) or (n): ";
	cout.flush();
	char X;
	cin >> X;
	for(int i = 0; ; ++ i){
		check_status(system("./gen>./in"), "Generator");
		auto p1 = high_resolution_clock::now();
		check_status(system(("./" + sol + "<./in>./stress/out_bad").c_str()), "Bad Sol");
		auto p2 = high_resolution_clock::now();
		check_status(system(("printf \"\\n\" | cat ./in - ./stress/out_bad | ./" + checker + ">./stress/_res").c_str()), "Checker");
		ifstream _res("./stress/_res"), badin("./stress/out_bad");
		int res;
		_res >> res;
		vector<string> bad;
		string t;
		while(badin >> t) bad.push_back(t);
		cout << "Case #" << i << "\n";
		cout << sol << ": " << duration<double>(p2 - p1).count() << " seconds" << endl;
		if(!res || duration<double>(p2 - p1).count() > TIME_LIMIT){
			if(!res) cout << "WRONG ANSWER\n";
			else cout << "TIME LIMIT EXCEEDED\n";
			cout << sol << ": ";
			for(auto s: bad) cout << s << " ";
			cout << "\n";
			break;
		}
		cout << "Ok\n";
		if(X == 'y'){
			cout << sol << ": ";
			for(auto s: bad) cout << s << " ";
			cout << "\n";
		}
		cout << endl;
	}
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////