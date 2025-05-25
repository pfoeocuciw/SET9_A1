#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

static int charAt(const std::string &s, int d) {
  return d < (int)s.size() ? (unsigned char)s[d] : -1;
}

static void msd(std::vector<std::string> &a,
                std::vector<std::string> &aux,
                int lo, int hi, int d) {
  if (hi - lo <= 1) return;
  const int R = 256;
  std::vector<int> count(R+2, 0);
  for (int i = lo; i < hi; ++i)
    count[charAt(a[i],d)+2]++;
  for (int r = 0; r < R+1; ++r)
    count[r+1] += count[r];
  for (int i = lo; i < hi; ++i) {
    int c = charAt(a[i],d);
    aux[lo + count[c+1]++] = std::move(a[i]);
  }
  for (int i = lo; i < hi; ++i)
    a[i] = std::move(aux[i]);
  for (int r = 0; r < R; ++r)
    msd(a, aux,
        lo + count[r],
        lo + count[r+1],
        d+1);
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  if (!(std::cin >> n)) return 0;
  std::vector<std::string> a(n), aux(n);
  std::string tmp;
  std::getline(std::cin, tmp);

  for (int i = 0; i < n; ++i)
    std::getline(std::cin, a[i]);

  msd(a, aux, 0, n, 0);

  for (auto &s : a)
    std::cout << s << "\n";
  return 0;
}

