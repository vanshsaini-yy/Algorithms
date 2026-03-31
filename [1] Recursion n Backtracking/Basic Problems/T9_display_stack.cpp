#include <bits/stdc++.h>
using namespace std;

template <class T>
void display(stack<T> &st)
{
    if (st.size() == 0)
        return;
    T top = st.top();
    st.pop();
    cout << top << " ";
    display(st);
    st.push(top);
}

int main()
{
    stack<int> st;
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        st.push(x);
    }
    display<int>(st);
    return 0;
}
