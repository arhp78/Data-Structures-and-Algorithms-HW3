#include <iostream>
#include <math.h>


using namespace std;

int main( )
{
    int n ,m,q;
    int i,j;
    cin>>n>>m>>q;
     unsigned long long int arr[n][m];
    for(i=0 ; i<n;i++){
        for(j=0;j<m;j++){
            cin >> arr[i][j];
        }}




  for (int i = 0; i < n; i++)
  {

    for (int j = 0; j < m; j++)
    {

      for (int k = 0; k < m - j - 1; k++)
      {
        if (arr[i][k] <= arr[i][k + 1])
        {
          swap(arr[i][k], arr[i][k + 1]);
        }
      }
    }
  }

/*for(i=0;i<n;i++){
                    for(j=0;j<m;j++){
                            cout<<arr[i][j]<<"\t";
                    }
                    cout<<"\n";}
*/

        /*for(j=0;j<4;j++){
            cout<< arr[j];
        }*/
        int k=0;
        unsigned long long int DP[m+1][q];
        int counter[m+1][q];
        for(k=0;k<n;k++){


             for(i=0;i<m+1;i++){
                    for(j=0;j<q;j++){
                            counter[i][j]=0;
                    }
             }

            for(i=0;i<m+1;i++){
                    for(j=0;j<q;j++){
                        if(k==0 && i==0){
                            DP[i][j]=0;
                            continue;
                        }else if(k!=0 && i==0) {
                         DP[i][j]=DP[m][j];
                            continue;
                        }

                        int mode=arr[k][i-1]%q;
                        int factor=((q-mode)+j)%q ;
                        int count1=counter[i-1][factor];
                        int a=i-1;
                        int co=0;
                        while(count1>=floor(m/2)){
                                --a;
                                count1=counter[a][factor];
                                co++;
                        }
                        if(DP[i-1-co][factor]==0){
                                if(j==mode){
                                    DP[i][j]=max(arr[k][i-1],DP[i-1][j]);
                                        if(arr[k][i-1]>DP[i-1][j]){
                                        counter[i][j]=1;
                                        }else{
                                        counter[i][j]=counter[i-1][j];
                                        }
                                }else{
                                        DP[i][j]=DP[i-1][j];
                                        counter[i][j]=counter[i-1][j];
                                    }

                        }else{
                                DP[i][j]=max(arr[k][i-1]+DP[i-1-co][factor],DP[i-1][j]);
                                 if(arr[k][i-1]+DP[i-1-co][factor]>DP[i-1][j]){
                                    counter[i][j]=counter[i-1-co][factor]+1;
                                }else{
                                   counter[i][j]=counter[i-1][j];
                                   }
                                  }

                    }
                    }
                    /*
                for(i=0;i<m+1;i++){
                    for(j=0;j<q;j++){
                            cout<<DP[i][j]<<" ";
                            //cout<<counter[i][j]<<"\t";
                    }
                    cout<<"\n";
                    cout<<"\n";}
                    cout<<"\n";

*/


    }
    cout<<DP[m][0];
    return 0;

}


