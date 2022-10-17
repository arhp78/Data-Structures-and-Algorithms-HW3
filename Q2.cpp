#include <iostream>
#include <cstdlib>


using namespace std;

int main( )
{
    int n ,x;
    int i,j,k;
    cin>>n>>x;
    int arr[n][2];
    for(i=0 ; i<n;i++){
        for(j=0;j<2;j++){
            cin >> arr[i][j];
        }}


        int coluom1[2*n];

        for(i=0 ; i<n;i++){
            for(j=0;j<2;j++){
                    coluom1[2*i+j]=arr[i][j];
            }
        }
         for (int j = 0; j < 2*n; j++)
        {
            for (int k = 0; k < 2*n - j - 1; k++)
                {
                if (coluom1[k] >= coluom1[k+1]){
                    swap(coluom1[k], coluom1[k+1]);}
                }
        }
        int count=0;
        int coluom[2*n];
         for (i=0;i<2*n;i++){
            coluom[i]=0;
        }
        coluom[0]=coluom1[0];
        for(i=1 ; i<2*n;i++){
                if(coluom1[i]==coluom1[i-1]){
                    count++;
                    continue;

                }
                coluom[i-count]=coluom1[i];

        }

        i=0;count=0;
        while(coluom[i]!=0){
            count++;
            i++;
        }



        long long int DP[2][count];

        for(i=0;i<3*(n-1)+1;i++){
                for(j=0;j<count;j++){
                    if(i==0){
                        if(coluom[j]>=arr[0][0] && coluom[j]<=arr[0][1]){
                            DP[i][j]=abs(coluom[j]-x);
                        }else{
                            DP[i][j]=abs(coluom[j]-x)+min(abs(coluom[j]-arr[0][0]),abs(coluom[j]-arr[0][1]));
                            }
                    }else{
                        if(j==0 && i%3==1){

                            DP[(i%2)][j]=DP[(i-1)%2][j];
                        }else if(j==0 && i%3==2){
                            DP[(i%2)][count-j-1]=DP[(i-1)%2][count-j-1];
                        }
                        if(j!=0 && i%3==1){
                            DP[(i%2)][j]=min(DP[(i-1)%2][j],DP[(i%2)][j-1]+coluom[j]-coluom[j-1]);
                        }else if(j!=0 && i%3==2){
                            DP[(i%2)][count-j-1]=min(DP[(i-1)%2][count-j-1],DP[(i%2)][count-j]+abs(coluom[count-j-1]-coluom[count-j]));
                        }else if(i%3==0){
                            if(coluom[j]>=arr[int((i-1)/3)+1][0] && coluom[j]<=arr[int((i-1)/3)+1][1]){
                                DP[(i%2)][j]=DP[(i-1)%2][j];
                            }else{
                            DP[(i%2)][j]=DP[(i-1)%2][j]+min(abs(coluom[j]-arr[int((i-1)/3)+1][0]),abs(coluom[j]-arr[int((i-1)/3)+1][1]));
                            }
                        }
                    }

            }

        }

       long long int m =DP[(n-1)%2][0];
        for(i=1;i<count;i++){
                if(DP[(n-1)%2][i]<m){
                    m=DP[(n-1)%2][i];
                }

        }


    cout<<m;


    return 0;

}


