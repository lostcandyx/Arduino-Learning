/*
bool readMusic(char* filename)
{
  char str[20];
  int cnt = 0;
  FILE *in;
  in = fopen(filename,"r");
  if (in!=NULL)
  {
    while (!feof(in))
    {
      if(fgets(str,sizeof(str)-1,in)==NULL) continue;
      sscanf(str,"%d %d",&music[0][cnt],&music[1][cnt]);
      cnt++;
    }
    musicEnding = cnt;
    fclose(in);
    return true;
  }
  else 
  {
    fclose(in);
    return false;
  }
}*/
