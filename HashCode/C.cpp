#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAX_NUM_BOOK = 100000;
const int MAX_NUM_LIB = 100000;
int Score[MAX_NUM_BOOK + 10];
bool scanned[MAX_NUM_BOOK + 10];
class Library {
public:
    int N; // number of books
    int T; // days needed for sign up
    int M; // number of books shipped per day
    vector<int>Books;
}L[MAX_NUM_LIB + 10];

int N_Books;
int N_Libraries;
int Days;
vector<pair<int,vector<int> > > ans;
LL lib_score[MAX_NUM_LIB + 10];
int sz[MAX_NUM_LIB + 10];
vector<int>libs_store_book[MAX_NUM_BOOK + 10];
LL score_all_books = 0;

void check() {
    int now_day = 0;
    LL sum_score = 0;
    for (int i=0;i<N_Books;i++) {
        scanned[i] = false;
    }
    for (int i=0;i<ans.size();i++) {
        int lib_idx = ans[i].first;
        vector<int> books_order = ans[i].second;
        now_day += L[lib_idx].T;
        int day_remain = Days - now_day;
        if (day_remain <= 0) {
            break;
        }
        int up = min(LL(books_order.size()), 1LL * day_remain * L[i].M);
        for (int j=0;j<up;j++) {
            int book_idx = books_order[j];
            if (!scanned[book_idx]) {
                sum_score += Score[book_idx];
                scanned[book_idx] = true;
            }
        }
    }
    printf("%lld/%lld\n",sum_score,score_all_books);
}

void print() {
    printf("%d\n",ans.size());
    for (auto t:ans) {
        printf("%d %d\n",t.first,t.second.size());
        for (int i=0;i<t.second.size();i++) {
            printf("%d%c",t.second[i]," \n"[i==t.second.size() - 1]);
        }
    }
}

typedef pair<double,int> pdi;

int main() {
    //freopen("a_example.txt","r",stdin);
    //freopen("c_incunabula.txt","r",stdin);
    //freopen("f_libraries_of_the_world.txt","r",stdin);
    freopen("e_so_many_books.txt","r",stdin);
    //freopen("f_libraries_of_the_world.txt","r",stdin);
    //freopen("c1_out.txt","w",stdout);
    scanf("%d",&N_Books);
    scanf("%d",&N_Libraries);
    scanf("%d",&Days);
    for (int i=0;i<N_Books;i++) {
        scanf("%d",&Score[i]);
        score_all_books += Score[i];
    }
    for (int i=0;i<N_Libraries;i++) {
        scanf("%d%d%d",&L[i].N,&L[i].T,&L[i].M);
        L[i].Books.resize(L[i].N);
        lib_score[i] = 0;
        sz[i] = L[i].N;
        for (int j=0;j<L[i].N;j++) {
            scanf("%d",&L[i].Books[j]);
            lib_score[i] += Score[L[i].Books[j]];
            libs_store_book[L[i].Books[j]].push_back(i);
        }
    }
    set<pdi> st;
    for (int i=0;i<N_Libraries;i++) {
        st.insert(pdi(1.0 * lib_score[i] / L[i].T, i));
        //printf("%.5lf %d\n",1.0 * lib_score[i] / L[i].T, i);
    }
    int Days_remain = Days;
    for (int i=0;i<N_Books;i++) {
        scanned[i] = false;
    }
    for (int i=0;i<N_Libraries;i++) {
        if (st.empty()) {
            break;
        }
        auto it = (st.end());
        --it;
        auto pp = (*it);
        st.erase(it);
        int idx = pp.second;
        if (L[idx].T > Days_remain) {
            continue;
        }
        sort(L[idx].Books.begin(), L[idx].Books.end(), [&](int id1, int id2) {
            if (scanned[id1] != scanned[id2]) {
                return !scanned[id1];
            }
            return Score[id1] > Score[id2];
        });
        ans.push_back(make_pair(idx, L[idx].Books));
        Days_remain -= L[idx].T;
        for (auto book:L[idx].Books) {
            if (scanned[book]) {
                continue;
            }
            scanned[book] = true;
            for (auto t:libs_store_book[book]) {
                st.erase(pdi(1.0 * lib_score[t] / L[t].T, t));
                lib_score[t] -= Score[book];
                st.insert(pdi(1.0 * lib_score[t] / L[t].T, t));
            }
        }
    }
    check();
    //print();
}