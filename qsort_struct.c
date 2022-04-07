struct combo{
    long long price;
    int sweet;
};

int cmp(void const *a, void const *b){
    // return *(struct combo*)b->sweet - *(struct combo*)a->sweet;
    
  struct combo *A = (struct combo *)a;
  struct combo *B = (struct combo *)b;

  return ( B->sweet - A->sweet );
}
 qsort(c,n,sizeof(struct combo),cmp);