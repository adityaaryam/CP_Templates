vector<ll> fact(N),ifact(N);
ll inverse(ll n)
{
    return binexp(fact[n],MOD-2,MOD)%MOD;
}
void pre_factorials()
{
    fact[0]=1;
    rep(i,1,N) fact[i]=(fact[i-1]*i)%MOD;
    rep(i,0,N) ifact[i]=inverse(i);
}

ll ncr(ll n,ll r)
{
    if(n<r) return 0;
    else if(n==r) return 1;
    else if(r==0) return 1;
    ll ans=fact[n];
    ans=(ans*ifact[r])%MOD;
    ans=(ans*ifact[n-r])%MOD;
    return ans;
}