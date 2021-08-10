using namespace std;


void countWords(istream& in, DocMap& words) {
    string s;
    while (in >> s) {
        ++words[s];
     }
  }


int dotprod(int x, int y)
{ return x*y;
}

int findTheDot(QueryMap q_obj, DocMap w)
{ int dot=0;
  for (QueryMap::iterator l=q_obj.begin(); l != q_obj.end(); ++l)
	for (DocMap::iterator p = w.begin(); p != w.end(); ++p)
		if (l->first == p->first)
			 dot+=dotprod(l->second, p->second);
  return dot;
}

float Q_mod(QueryMap q_obj)
{ float store=0;
  for (QueryMap::iterator l=q_obj.begin(); l != q_obj.end(); ++l)
	store+=(l->second*l->second);
  return sqrt(store);
}