#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main(){
	int t,tr,ts,ds,dr,count1=0,count=0;
	scanf("%d",&t);
	while(t--){
		scanf("%d", &tr);
		int take_truth[tr];
		for (int i=0;i<tr;i++){
			scanf("%d",&take_truth[i]);
		}
		qsort(take_truth, tr, sizeof(int), cmpfunc);

		scanf("%d", &dr);
		int take_dare[dr];
		for (int i=0;i<dr;i++){
			scanf("%d",&take_dare[i]);
		}
		qsort(take_dare, dr, sizeof(int), cmpfunc);

		scanf("%d", &ts);
		int give_truth[ts];
		for (int i=0;i<ts;i++){
			scanf("%d",&give_truth[i]);
		}
//		qsort(c, ts, sizeof(int), cmpfunc);
		scanf("%d", &ds);
		int give_dare[ds];
		for (int i=0;i<ds;i++){
			scanf("%d",&give_dare[i]);
		}
//		qsort(d, ds, sizeof(int), cmpfunc);
        count1=0;
		for (int i=0;i<ts;i++){
			int ele=give_truth[i];
			
			int low=0,high=tr,mid;
			while(low<=high)
		    {
		        mid=(low+high)/2;
		        if(take_truth[mid]==ele)
		        {
		        	count1++;
                    // printf("1)ele found");
//		        	printf("yes\n");
//		            printf("%d found at %d position",ele,mid+1);
		            break;
		        }
		        else if(take_truth[mid]>ele)
		          high=mid-1;
		        else
		            low=mid+1;
		    } 	
		        
		}
		count=0;
		for (int i=0;i<ds;i++){
			int ele=give_dare[i];
            
			int low=0,high=dr,mid;
			while(low<=high)
		    {
		        mid=(low+high)/2;
		        if(take_dare[mid]==ele)
		        {
		        	count++;
                    
                    // printf("2)ele found");
//		        	printf("yes\n");
//		            printf("%d found at %d position",ele,mid+1);
		            break;
		        }
		        else if(take_dare[mid]>ele)
		          high=mid-1;
		        else
		            low=mid+1;
		    }
// 		    if(low>high){
// 		    	printf("2)no\n");
// 		    	break;
// 			}
// 			if(count==ds){
// 				printf("2)yes\n");
// 			}		
		}

        // printf("\ncount1=%d and ts=%d\n",count1,ts);
        //      printf("count=%d and ds=%d\n",count,ds);
        if(count1==ts && count==ds){
 			printf("yes\n");
             
 		}
        else{
            printf("no\n");
        }
			
	}
}