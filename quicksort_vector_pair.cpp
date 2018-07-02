int particion(vector<pair<string,int>> A,int p,int r){
    int pivot=stoi(A[r].first);
    int i=(p-1);
    for(int j=p;j<=r-1;j++){
        if(stoi(A[j].first)<=pivot){
            i++;
            swap(A[i].first,A[j].first);
            swap(A[i].second,A[j].second);
        }
    }
    swap(A[i+1].first,A[r].first);
    swap(A[i+1].second,A[r].second);
    return (i+1);
}
void quicksort(vector<pair<string,int>> &A,int p,int r){
    int q;
    if(p<r){
        q=particion(A,p,r);
        quicksort(A,p,q-1);
        quicksort(A,q+1,r);
    }
}
