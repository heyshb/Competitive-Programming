#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

string ele[118] = {
				"H", 
				"He",
				"Li",
				"Be",
				"B", 
				"C", 
				"N", 
				"O", 
				"F", 
				"Ne",
				"Na",
				"Mg",
				"Al",
				"Si",
				"P", 
				"S", 
				"Cl",
				"Ar",
				"K", 
				"Ca",
				"Sc",
				"Ti",
				"V", 
				"Cr",
				"Mn",
				"Fe",
				"Co",
				"Ni",
				"Cu",
				"Zn",
				"Ga",
				"Ge",
				"As",
				"Se",
				"Br",
				"Kr",
				"Rb",
				"Sr",
				"Y", 
				"Zr",
				"Nb",
				"Mo",
				"Tc",
				"Ru",
				"Rh",
				"Pd",
				"Ag",
				"Cd",
				"In",
				"Sn",
				"Sb",
				"Te",
				"I", 
				"Xe",
				"Cs",
				"Ba",
				"La",
				"Ce",
				"Pr",
				"Nd",
				"Pm",
				"Sm",
				"Eu",
				"Gd",
				"Tb",
				"Dy",
				"Ho",
				"Er",
				"Tm",
				"Yb",
				"Lu",
				"Hf",
				"Ta",
				"W", 
				"Re",
				"Os",
				"Ir",
				"Pt",
				"Au",
				"Hg",
				"Tl",
				"Pb",
				"Bi",
				"Po",
				"At",
				"Rn",
				"Fr",
				"Ra",
				"Ac",
				"Th",
				"Pa",
				"U", 
				"Np",
				"Pu",
				"Am",
				"Cm",
				"Bk",
				"Cf",
				"Es",
				"Fm",
				"Md",
				"No",
				"Lr",
				"Rf",
				"Db",
				"Sg",
				"Bh",
				"Hs",
				"Mt",
				"Ds",
				"Rg",
				"Cn",
				"Nh",//"Uut",
				"Fl",
				"Mc",//"Uup",
				"Lv",
				"Ts",//"Uus",
				"Og"//"Uuo"
			};

char s[100];
bool f[110];
char upper(char x) {
    if (x >= 'a' && x <= 'z') {
        return x - 'a' + 'A';
    }
    return x;
}

bool check(int x,int l) {
    for (int i=0;i<118;i++) {
        if (ele[i].length() != l) {
            continue;
        }
        bool ok = true;
        for (int j=0;j<l;j++) {
            if (s[x - l + 1 + j] != upper(ele[i][j])) {
                ok = false;
            }
        }
        if (ok) return true;
    } 
    return false;
}

int main() {
    scanf("%s",s + 1);
    int N = strlen(s + 1);
    memset(f, false, sizeof(f));
    f[0] = true;
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=min(i, 3);j++) {
            if (check(i, j)) {
                f[i] |= f[i - j];
            }
        }
        //printf("f[%d]=%d\n",i,f[i]);
    }
    puts(f[N] ? "YES" : "NO");
}