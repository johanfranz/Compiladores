  int point1 = 0, point2, auxx;
  cout<<"primS"<<endl;
  for(k = 0; k < contador; k++)
  {
    c = prod[k][0];
    point2 = 0;
    auxx = 0;
    
    for(kay = 0; kay <= ptr; kay++)
      if(c == done[kay])
        auxx = 1;
        
    if (auxx == 1)
      contadorinue;
    
    buscarprim(c, 0, 0);
    ptr += 1;
    
    done[ptr] = c;
    cout<<endl;
    cout<<c<<" = {";
    prims[point1][point2++] = c;
    
    for(i = 0 + jm; i < n; i++) {
      int lark = 0, chk = 0;
      
      for(lark = 0; lark < point2; lark++) {
        
        if (prim[i] == prims[point1][lark])
        {
          chk = 1;
          break;
        }
      }
      if(chk == 0)
      {
        printf("%c, ", prim[i]);
        prims[point1][point2++] = prim[i];
      }
    }
    cout<<"}"<<endl;
    jm = n;
    point1++;
  }