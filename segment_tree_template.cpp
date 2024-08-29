#define ll long long
template<typename T, typename R> struct segtree{
    vector<T> seg;
    vector<T> lazy;
    R rx = R();
    ll n = 0;
    segtree(){}
    segtree(ll n){
        resize(n);
    }
    segtree(vector<ll> &arr){
        n = arr.size();
        seg.resize(4*n);
        lazy.resize(4*n);
        build(0, 0, n-1, arr);
    }
    void make(vector<ll> &arr){
        n = arr.size();
        seg.resize(4*n);
        lazy.resize(4*n);
        build(0, 0, n-1, arr);
    }
    void resize(ll n){
        vector<ll> v(n+1);
        make(v);
    }
    void build(ll ind, ll low, ll high, vector<ll> &arr){
        if(low==high){
            seg[ind] = arr[low];
            return;
        }
        ll mid = (low+high)/2;
        build(ind*2+1, low, mid, arr);
        build(ind*2+2, mid+1, high, arr);
        seg[ind] = rx.comb(seg[ind*2+1], seg[ind*2+2]);
    }
    ll query(ll ind, ll low, ll high, ll l, ll r){
        if(lazy[ind]!=0){
            seg[ind] += (high-low+1)*lazy[ind];
            if(low!=high){
                lazy[2*ind+1] += lazy[ind];
                lazy[2*ind+2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        if(l<=low && high<=r){
            return seg[ind];
        }
        if(high<l || low>r || low>high){
            return rx.dval;
        }
        ll mid = (low+high)>>1;
        ll left = query(2*ind+1, low, mid, l, r);
        ll right = query(2*ind+2, mid+1, high, l, r);
        return rx.comb(left, right);
    }
    void rangeUpdate(ll ind, ll low, ll high, ll l, ll r, ll val){
        if(lazy[ind]!=0){
            seg[ind] += (high-low+1)*lazy[ind];
            if(low!=high){
                lazy[2*ind+1] += lazy[ind];
                lazy[2*ind+2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        if(l>high || r<low || low>high) return;
        if(low>=l && high<=r){
            seg[ind] += (high-low+1)*val; // for sum
            if(low!=high){
                lazy[2*ind+1] += val;
                lazy[2*ind+2] += val;
            }
            return;
        }
        ll mid = (low+high)/2;
        rangeUpdate(2*ind+1, low, mid, l, r, val);
        rangeUpdate(2*ind+2, mid+1, high, l, r, val);
        seg[ind] = rx.comb(seg[2*ind+1], seg[2*ind+2]);
    }
    void pointUpdate(ll ind, ll low, ll high, ll pos, ll val){
        if(low==high){
            seg[ind] += val;  // update the value to seg[ind]
            return;
        }
        ll mid = (low+high)/2;
        if(pos<=mid){
            pointUpdate(ind*2+1, low, mid, pos, val);
        }
        else{
            pointUpdate(ind*2+2, mid+1, high, pos, val);
        }
        seg[ind] = rx.comb(seg[2*ind+1], seg[2*ind+2]);
    }
    ll query(ll l, ll r) {return query(0, 0, n-1, l, r);}
    void pointUpdate(ll pos, ll val) {pointUpdate(0, 0, n-1, pos, val);}
    void rangeUpdate(ll l, ll r, ll val) {rangeUpdate(0, 0, n-1, l, r, val);}
};
struct ops{
    ll dval = 0;
    ops(){};
    ll comb(ll a, ll b) {return a+b;};
};