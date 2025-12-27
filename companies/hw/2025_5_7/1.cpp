#include<bits/stdc++.h>

using namespace std;
// we have defined the necessary header files here for this problem.
// If additional header files are needed in your program, please import here.

int  main()
{
    long long k,n;
    cin>>k>>n;
    if(k==0){
        return 0;
    }
    long long x,y;
    cin>>x>>y;
    vector<pair<long long,long long >> positions;
    vector<long long > distances;
    vector<long long > indices(n);
    for(long long  i=0;i<n;i++){
        long long  x1,y1;
        cin>>x1>>y1;
        positions.push_back({x1,y1});
        long long  d = abs(x1-x)+abs(y1-y);
        distances.push_back(d);
        indices[i]=i;
    }
    sort(indices.begin(),indices.end(),[&](long long  a,long long  b){
        return distances[a]<distances[b];
    });
    for(long long  i=0;i<k;i++){
        cout<<indices[i]+1<<" "<<positions[indices[i]].first<<" "<<positions[indices[i]].second<<" "<<distances[indices[i]];
        if(i+1!=k)cout<<endl;
    }    
    // please define the C++ input here. For example: long long  a,b; cin>>a>>b;;
    // please finish the function body here.
    // please define the C++ output here. For example:cout<<____<<endl;

    return 0;
}
