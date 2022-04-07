int cmp(const void *a, const void *b) {
    /* a and b are pointers to the array of pointers. */
    int *aa = *(int * const *)a;
    int *bb = *(int * const *)b;
    return (aa[1] > bb[1]) - (aa[1] < bb[1]);
}

qsort(copy, n, sizeof(copy[0]), cmp);