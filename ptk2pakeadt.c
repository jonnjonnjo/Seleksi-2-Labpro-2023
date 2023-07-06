#include <stdio.h>
#include <stdlib.h>

const int maxn = 20005;
int n;

typedef struct{
    int key;
    int value;
} node;

typedef struct{
    node elements[20005]; // dunno why maxn doesn't work
} hashmap; 

int mod(int a,int b){
    return (a < 0 ? -1*(a%b) : (a%b));
}

void InitializeMap(hashmap *H){
    int i = 0;
    for( i = 0;i < maxn;i++){ // assign key and value as -1 as an empty row
        (H->elements[i].key) = -1;
        (H->elements[i].value) = -1;
    }
}

void insertIntoHashmap(hashmap *H, node ins){
    int i = mod(ins.key,maxn);
    int j = 0;
    for(j = 0;j < maxn;j++){
        if((H->elements[i].value) != -1) i = (i + 1)%maxn; // it means that the node are already filled
        else{
            (H->elements[i].key) = ins.key;
            (H->elements[i].value) = ins.value;
            break;
        }
    }

}

int findindex(hashmap H, int target){
    int i = mod(target,maxn);
    int j = 0;
    for(j = 0;j < maxn;j++){
        if(H.elements[i].value == -1 || H.elements[i].key != target) i = (i+1)%maxn;
        else{
            // H.elements[i].value != -1 and H.elements[i].key
            return H.elements[i].value;
        }
    }
    return -1;
}



/*
    Initial Ideaa
    1. First, find the minimum value of the all the array. the subtract the target and each elements in the array with the minimum value
    and placing them on the hashmap using this function : f(x) = (arr[x])/(maximum value of the new array +1);
    Why doing this? I'm doing this so that the finding operation could be done in O(1) instead of O(N) or iterating through all array. This will make the total complexityt is O(N^2)
    But, this actually doesn't work.
    eg : arr : [1,3,7,9,10] , then there will be no collision
    eg : arr : [1,10^8] . Since the array is only 1e4, then there will be no place for the second element

    another idea is to do some kind of sorting or binary search so the find operation could be done in O(log(N))
    I think this doesn't work since the problem suggest me to use Hashmap instead of Map (the implementation of map in C++ is with tree)

    so, we can just try the naive / obvious solution
    worst case : 
    n = 10^4
    arr = for i in range[1,1e4] arr[i] = 10^4*i

    then, there will be always collision
*/




int main(){
    // this is actually just a famous problem named 2 sum.
    // using map
    scanf("%d",&n);
    hashmap Hashmap;
    InitializeMap(&Hashmap);
    int i;
    int arr[maxn];
    for(i = 0;i < n;i++){
        scanf("%d",&arr[i]);
    }   


    int target;
    scanf("%d",&target);

    for(i = 0;i < n;i++){ 
        int remain = target - arr[i];
        int idx = findindex(Hashmap,remain);
        if(idx != -1){
            printf("%d\n%d\n",idx,i);
            break;
        }
        node temp;
        temp.key = arr[i];
        temp.value = i;
        insertIntoHashmap(&Hashmap,temp);
    }



    return 0;
}