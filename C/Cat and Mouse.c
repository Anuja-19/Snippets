#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int mod(int x){
    if(x>0)
        return x;
    else
        return -1*x;
}
int main(){
    int q; 
    scanf("%d",&q);
    for(int a0 = 0; a0 < q; a0++){
        int x; 
        int y; 
        int z; 
        scanf("%d %d %d",&x,&y,&z);
        if(mod(z-x)<mod(z-y))
            printf("Cat A\n");
        else if(mod(z-y)<mod(z-x))
               printf("Cat B\n");
        else
              printf("Mouse C\n");
    }
    return 0;
}

