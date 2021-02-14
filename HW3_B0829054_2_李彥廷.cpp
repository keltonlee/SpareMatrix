#include<iostream>
using namespace std;
struct SpareMatrix{
    int row,column,value;
};
void initialize(SpareMatrix a[],int n){
    for(int i=0;i<n;i++){
        a[i].row=0;
        a[i].column=0;
        a[i].value=0;
    }
}
int input(SpareMatrix a[],int row,int column){
    int terms=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            int num;
            cin>>num;
            if(num==0){
                continue;
            }
            a[terms].row=i;
            a[terms].column=j;
            a[terms].value=num;
            terms++;
        }
    }
    return terms;
}
void Transpose(SpareMatrix a[],SpareMatrix b[],int r,int c,int t){
    int **row=new int *[c];
    for(int i=0;i<c;i++){
        row[i]=new int[2];
        row[i][0]=0;//rowstart[0]設為0
    }
    row[0][1]=0;
    for(int i=0;i<t;i++){
        row[a[i].column][0]++;
    }
    for(int i=1;i<c;i++){
        row[i][1]=row[i-1][0]+row[i-1][1];
    }
    for(int i=0;i<t;i++){
        int j=row[a[i].column][1];
        b[j].row=a[i].column;
        b[j].column=a[i].row;
        b[j].value=a[i].value;
        row[a[i].column][1]++;
    }
    for(int i=0;i<c;i++){
        delete [] row[i];
    }
    delete [] row;
}
void output(SpareMatrix a[],int r,int c){
    int term=0;
    for(int i=0;i<c;i++){
        for(int j=0;j<r;j++){
            if((a[term].row==i)&&(a[term].column==j)){
                if(j==r-1){
                    cout<<a[term].value<<endl;
                }
                else{
                    cout<<a[term].value<<" ";
                }
                term++;
            }
            else{
                if(j==(r-1)){
                    cout<<"0"<<endl;
                }
                else{
                    cout<<"0"<<" ";
                }
            }
        }
    }
}
int main(){
    int r,c,term;
    cin>>r>>c;
    SpareMatrix one[r*c],two[r*c];
    initialize(one,r*c);
    initialize(two,r*c);
    term=input(one,r,c);
    cout<<"--------------------"<<endl;
    Transpose(one,two,r,c,term);
    for(int i=0;i<term;i++){
        cout << two[i].row<<"    "<<two[i].column<<"    "<<two[i].value<<endl;
    }
    cout<<"--------------------"<<endl;
    output(two,r,c);
}