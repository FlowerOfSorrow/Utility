#include <bits/stdc++.h>
using namespace std;


int main(int argc, char *argv[]){
    string version = argv[1];
    assert(version == "11" || version == "14" || version == "17");
   	system(string("mkdir -p /aerenspch/bits").c_str());
    system(("g++-9 -std=c++" + version + " -Winvalid-pch -Wno-narrowing -DLOCAL -fconcepts -g -fsanitize=address,undefined /usr/include/x86_64-linux-gnu/c++/9/bits/stdc++.h -o /aerenspch/bits/stdc++.h.gch").c_str());
    system(string("mkdir -p /aerenspch/ext/pb_ds").c_str());
    system(("g++-9 -std=c++" + version + " -Winvalid-pch -Wno-narrowing -DLOCAL -fconcepts -g -fsanitize=address,undefined /usr/include/c++/9/ext/pb_ds/assoc_container.hpp -o /aerenspch/ext/pb_ds/assoc_container.hpp.gch").c_str());
    system(("g++-9 -std=c++" + version + " -Winvalid-pch -Wno-narrowing -DLOCAL -fconcepts -g -fsanitize=address,undefined /usr/include/c++/9/ext/pb_ds/tree_policy.hpp -o /aerenspch/ext/pb_ds/tree_policy.hpp.gch").c_str());
    return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////