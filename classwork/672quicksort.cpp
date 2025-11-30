void quicksort(int ary[],int left,int right){
    if(left>=right){
        return;
    }
    int mid=partition(ary,left,right);
    quicksort(ary,left,mid-1);
    quicksort(ary,mid+1,right);
}