#include <stdio.h>
#include <string.h>
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        int sum=0;
        char origin[11];
        scanf("%d %s",&n,origin);
        while(n--){            
            char activity[100];
            scanf("%s",activity);
            if(strcmp(activity,"CONTEST_WON")==0){
                    int rank;
                    scanf("%d", &rank);
                    sum+=300;
                    if(rank<20){
                        sum+=20-rank;
                    }
            }
               else if(strcmp(activity,"TOP_CONTRIBUTOR")==0){
                // case('TOP_CONTRIBUTOR'):
                    sum+=300;
                    // break;
                }
                else if(strcmp(activity,"BUG_FOUND")==0){
                // case('BUG_FOUND'):
                    int severity;
                    scanf("%d", &severity);
                    sum+=severity;
                    // break;
                }
                else if(strcmp(activity,"CONTEST_HOSTED")==0){
                // case('CONTEST_HOSTED'):
                    sum+=50;
                    // break;
                }
                    
        }
        if(strcmp(origin,"INDIAN")==0){
            sum=sum/200;
        }
        else{
            sum=sum/400;
        }
        printf("%d",sum);
        }
        
     
    return 0;   
    }