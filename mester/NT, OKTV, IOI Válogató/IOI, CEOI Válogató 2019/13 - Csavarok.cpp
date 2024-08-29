#include "csavarok.h"
#include <bits/stdc++.h>
using namespace std;

void idk(vector<int>& cids, vector<int>& aids) {
  assert(cids.size() == aids.size());
  if (cids.size() < 2) return;
  int tcid = cids[rand() % cids.size()];
  int taid = -1;
  vector<int> asmol, abig;
  for (int aid : aids) {
    int res = proba(tcid, aid);
    if (res == 1) asmol.push_back(aid);
    else if (res == -1) abig.push_back(aid);
    else taid = aid;
  }
  assert(taid != -1);
  vector<int> csmol, cbig;
  int tcid2 = -1;
  for (int cid : cids) {
    int res = proba(cid, taid);
    if (res == -1) csmol.push_back(cid);
    else if (res == 1) cbig.push_back(cid);
    else tcid2 = cid;
  }
  assert(tcid2 == tcid);

  idk(cbig, abig);
  idk(csmol, asmol);

  aids = {};
  for (int aid : asmol) aids.push_back(aid);
  aids.push_back(taid);
  for (int aid : abig) aids.push_back(aid);

  cids = {};
  for (int cid : csmol) cids.push_back(cid);
  cids.push_back(tcid);
  for (int cid : cbig) cids.push_back(cid);
}

int main() {
  int n = kezdet();
  vector<int> cids(n), aids(n);
  iota(cids.begin(), cids.end(), 1);
  iota(aids.begin(), aids.end(), 1);

  idk(cids, aids);

  int *res = new int[n];
  for (int i = 0; i < n; i++) res[cids[i] - 1] = aids[i];

  eredmeny(res);
}
