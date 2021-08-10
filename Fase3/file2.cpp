using namespace std;


void countwww(istream& in, DocMap& www) {
    string s;
    while (in >> s) {
        ++www[s];
     }
  }


int Convert2(int x, int y)
{ return x*y;
}



float Q_mod(QueryMap q_obj)
{ float store=0;
  for (QueryMap::iterator l=q_obj.begin(); l != q_obj.end(); ++l)
	store+=(l->second*l->second);
  return sqrt(store);
}
