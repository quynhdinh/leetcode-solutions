int MatchingCharacters(string str) {
  vector<int> first(26, -1);
  vector<int> last(26, -1);
  int n = str.size();
  for(int i = 0; i < (int)str.size(); i++){
    if(first[str[i] - 'a'] == -1){
      first[str[i] - 'a'] = i;
      last[str[i] - 'a'] = i;
    } else {
      last[str[i] - 'a'] = i;
    }
  }
  debug(first);
  debug(last);
  map<char,char> cm;
  int res = 0;
  for(int i = 0; i < n; i++){
    int lastIndex = last[str[i] - 'a'];
    if(lastIndex == i || lastIndex == -1) continue;
    for(int j = i + 1; j < lastIndex; j++){
      if(cm.find(str[j]) == cm.end()){
        cm[str[j]] = str[j];
      }
    }
    if(res < (int)cm.size()){
      res = cm.size();
    }
  }
  return res;
}
