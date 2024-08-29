#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define pll pair<ll, ll>
#define all(a) (a).begin(), (a).end()
#define F first
#define S second
#define oset ordered_set
#define rep(i, j, k) for (ll i = j; i < k; i++)
#define endl "\n"
template <typename T>
ostream &operator<<(ostream &os, vector<T> &v)
{
    if (v.size() == 0)
    {
        os << "empty vector\n";
        return os;
    }
    for (auto element : v)
        os << element << " ";
    return os;
}
template <typename T, typename S>
ostream &operator<<(ostream &os, pair<T, S> &p)
{
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, set<T> &v)
{
    if (v.size() == 0)
    {
        os << "empty set\n";
        return os;
    }
    auto endit = v.end();
    endit--;
    os << "[";
    for (auto it = v.begin(); it != v.end(); it++)
    {
        os << *it;
        if (it != endit)
            os << ", ";
    }
    os << "]";
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, multiset<T> &v)
{
    if (v.size() == 0)
    {
        os << "empty multiset\n";
        return os;
    }
    auto endit = v.end();
    endit--;
    os << "[";
    for (auto it = v.begin(); it != v.end(); it++)
    {
        os << *it;
        if (it != endit)
            os << ", ";
    }
    os << "]";
    return os;
}
template <typename T, typename S>
ostream &operator<<(ostream &os, map<T, S> &v)
{
    if (v.size() == 0)
    {
        os << "empty map\n";
        return os;
    }
    auto endit = v.end();
    endit--;
    os << "{";
    for (auto it = v.begin(); it != v.end(); it++)
    {
        os << "(" << (*it).first << " : " << (*it).second << ")";
        if (it != endit)
            os << ", ";
    }
    os << "}";
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, vector<vector<T>> &v)
{
    for (auto &subv : v)
    {
        for (auto &e : subv)
            os << e << " ";
        os << "\n";
    }
    return os;
}

bool do_debug = false;

#ifndef ONLINE_JUDGE
#define de(var) cout << (#var) << ": " << var << endl
#else
#define de(var)
#endif
vector<ll> adj[100010];

ll rnd(ll a, ll b)
{
    return a + rand() % (b - a + 1);
}
void tree(ll x)
{
    long long int n; // Number of nodes in the tree.
    // cin >> n;
    n = rnd(1,x);
    n = x;
    // cout << n << endl;
    long long int src[n];    // source array.
    long long int dst[n];    // destination array.
    long long int arr[n][n]; // adjacency matrix.
    for (long long int i = 0; i < n; i++)
    {
        dst[i] = i;
    }
    for (long long int i = 0; i < n; i++)
    {
        for (long long int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }
    long long int top = 0;
    src[0] = dst[0];
    top++;
    long long int i = 0;
    while (top != (n))
    {
        srand(time(NULL));
        long long int temp = rand() % (i + 1); // random integer generator between 0 and i.
        arr[src[temp]][dst[top]] = 1;
        arr[dst[top]][src[temp]] = 1;
        src[i + 1] = dst[top];
        top++;
        i++;
    }
    map<pair<ll, ll>, ll> m;
    for (long long int i = 0; i < n; i++)
    {
        // cout << "\n";
        for (long long int j = 0; j < n; j++)
        {
            // cout << arr[i][j] << " ";
            if (arr[i][j])
            {
                pair<ll, ll> tem = {min(i, j), max(i, j)};
                if (m[tem])
                    continue;
                else
                {
                    m[tem]++;
                    cout << i+1 << " " << j+1 << endl;
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
    }
}

vector<ll> par(200010);
void dfs(ll node, ll parent)
{
    par[node] = parent;
    for(auto x:adj[node])
    {
        if(x==parent) continue;
        dfs(x,node);
    }
    return;
}
void Logic_Overflow()
{
    // ll n=rnd(1,100);
    // rep(i,0,n)
    // {
    //     cout<<(char)('a'+rnd(1,25));
    // }
    // cout<<endl;
    // cout<<rnd(1,(n*(n+1))/2)<<endl;
    


}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("ans.txt", "w", stdout);
    srand(time(0));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    rep(i, 0, t) Logic_Overflow();
    return 0;
}

