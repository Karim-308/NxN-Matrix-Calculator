#include <iostream>
#include<math.h>

using namespace std;



const int M = 10;
const int N = 10;


int copy_a [10][10]={0};
int copy_b [10][10]={0};

void print(int arr[N][M], int r, int c)
{
    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}


void print_inv(double arr[N][M], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}



void if_zero ( double &det)
{
    if( det== -0 )
         det=0;
}


void array_display (int * arr, int row ,int column)

{

    for (int i = 0; i<row ; i++)
    {
        for (int j = 0; j<column ; j++)
        {
            cout << *((arr+i*column) + j)<<" ";
        }
    cout <<endl;
}
}
/*

void array_display_inv (double * arr, double row ,double column)

{

    for (int i = 0; i<row ; i++)
    {
        for (int j = 0; j<column ; j++)
        {
            cout << *((arr+i*column) + (double)j)<<" ";
        }
    cout <<endl;
}
}
*/

void copier_a  (int arr_A[M][N] , int r ,int c , int copy_a[10][10] )
{
    // copying the array

    for (int j =0 ; j<r ; j++ )
    {
        for(int k =0 ; k<c ; k++)
        {
           copy_a[j][k] = arr_A[j][k];
        }
    }
}




void copier_b  (int arr[M][N] , int r ,int c , int copy_b[M][N] )
{
    // copying the array

    for (int j =0 ; j<r ; j++ )
    {
        for(int k =0 ; k<c ; k++)
        {
           copy_b[j][k] = arr[j][k];
        }
    }
}


bool approx_equal( double x, double y)
{
const double EPSL = 1E-4;
if (x == 0) return fabs(y) <= EPSL;
if (y == 0) return fabs(x) <= EPSL;
return fabs(x - y) / max(fabs(x), fabs(y)) <= EPSL;
}



bool approx_equal_long_long ( long long x,long long y)
{
const double EPSL = 1E-10;
if (x == 0) return fabs(y) <= EPSL;
if (y == 0) return fabs(x) <= EPSL;
return fabs(x - y) / max(fabs(x), fabs(y)) <= EPSL;
}



void array_increment (int * arr, int row ,int column)
{

    for (int i = 0; i<row ; i++)
    {
        for (int j = 0; j<column ; j++)
        {
            *((arr+i*column) + j)+=1 ;
        }
    }
}



void array_Addition (int  arr1 [M][N] , int row1 ,int column1, int  arr2 [M][N] , int row2 ,int  column2 , int res  [M][N],int res_row ,int res_column  )
{



    for (int i = 0; i<res_row ; i++)
    {
        for (int j = 0; j<res_column ; j++)
       res[i][j] =  arr1[i][j] + arr2[i][j] ;

    }

    }









void array_Subtraction (int  arr1 [M][N] , int row1 ,int column1, int  arr2 [M][N] , int row2 ,int  column2 , int res  [M][N],int res_row ,int res_column  )
{


    for (int i = 0; i<res_row ; i++)
    {
        for (int j = 0; j<res_column ; j++)
       res[i][j] =  arr1[i][j] - arr2[i][j] ;

    }

    }




void array_Multiplication (int * arr1, int row1 ,int column1, int * arr2 , int row2 ,int  column2 , int res [M] [N] ,int res_row ,int res_column  )
{



    for (int i = 0; i<res_row ; i++)
    {
        for (int j = 0; j<res_column ; j++)     //// R [i][j]
       {

        long long sum=0;

               for (int f =0 ; f<row2 ;f++)
                                                                                    /*Arr_[m][n] */
         res[i][j] = res [i] [j] + *((arr1 +i*res_column) +f ) * * ((arr2 +f*res_column) + j);
        }       //*((arr1+i*res_column ) + j) - *((arr2+i*res_column ) + j)
    }

    }



long long  determinant (int det_arr[M][M],int n) {
  long long det=0, p, h, k, i, j;
  int  temp[M][M];
  if(n==1) {
    return det_arr[0][0];
  } else if(n==2) {



      int   a = det_arr[0][0] ;
      int   b =  det_arr[0][1] ;
      int   c = det_arr[1][0];
      int   d =  det_arr[1][1];
        det = (a * d) -(b * c);
        return det;

  }

  else {
         int  sign = 1;
    for(p=0;p<n;p++) {
      h = 0;
      k = 0;
      for(i=1;i<n;i++) {
        for( j=0;j<n;j++) {
          if(j==p) {
            continue;
          }
          temp[h][k] = det_arr[i][j];
          k++;
          if(k==n-1) {
            h++;
            k = 0;
          }
        }
      }
      det=det+det_arr[0][p]*sign*determinant(temp,n-1);
    sign = -1*sign;
    }
    return det;
  }
}




long long double_approximation (long double ans)
{
    if (ans >= 0)
    {
        long long x = ans *10 ;
        if((x%10)>= 5 )
            return (x/10) +1;
        else
            return  x/10;
    }

    else
    {
        long long x = (-ans) *10 ;
        if((x%10)>= 5 )
            return -(x/10) -1;
        else
            return  -(x/10);
    }


}



////////////////////


  double det_method_2  (int copy_arr[M][N] , int r ,int c)
{
    // copying the array
     double arr[M][N];

    for (int j =0 ; j<r ; j++ )
    {
        for(int k =0 ; k<c ; k++)
        {
           arr[j][k] = ( double)copy_arr[j][k];
        }
    }





    double det;


if (arr[r-1][0] == 0)
{
    int detector=0;
    int t=1;
    for( ; t<=c-1 ; t++ )
       { detector+= arr[c-1][t];
        if (detector != 0)
        break;}
         if (detector == 0) {det =0;/* cout <<"det="<<det*/ return det ;}

//cout<<endl <<"/////////////  det:"<<det<<"   "<<t<<"////////////"<<endl;
        for (int j = 0 ; j <=r-1 ; j++)
            {
            double temp =  arr[j] [0];
            arr[j] [0] =  arr[j] [t];
             arr[j] [t] = temp;

            }

det = -1*arr [r-1][0];

        }


        else {det = arr [r-1][0];}




//cout <<"//////////////Afer keep or switching first colomn////////////////"<<endl;

//print (*arr,r,c);




//det = arr [r-1][0];

    for (int i=0 ; i<r ;i++)
    {arr[i][0] /= arr[r-1][0];}









for (int j = 0 ; j < (r-1) ; j++)

{
    for (int k = c-1 ; k >=0 ; k--)
    {


        /////////////////////////////////////////////
        if(arr[j][0]!=0)
        arr[j][k] = arr[j][k]  + (-1*( arr[j][0]) / arr[r-1][0])* arr[r-1][k] ;
        ///////////////////////////////////////////////
    }


}



    for (int i=1 ; i<c ;i++)
        arr[r-1][i] = {0};





for (int i = 0 ; i<r-1 ; i++  ){
    for (int j= i+1 ; j<r ; j++  ){
        for (int k=1 ; k<(c); k++ )

        {
            if (arr[i][c-(i+1)]==0)

            {
                 int detector=0;
                int t=c-(i+2);
                for( ; t>0 ; t-- )
                { detector+= arr[i][t];
                    if (detector != 0)

                    break;}
                    if (detector == 0) {det =0; /*cout <<"det="<<det ;*/ return det ;}



               // cout<<endl <<t<<endl;

                  for (int j = 0 ; j <=r-1 ; j++)
            {
            double temp =  arr[j] [c-(i+1)];
            arr[j] [c-(i+1)] =  arr[j] [t];
             arr[j] [t] = temp;

            }

det = -1*det;

//cout <<"////// after switching ////////////////////////"<<endl;
//print (*arr,r,c);

            }




 ////////////////////////////////////////////////////
                    if(arr[j][c-j]!=0)

        arr[j][k]= arr [j][k] + -1* ( arr[j][c-(i+1)]) *( arr [i][k] )/ arr[i][c-(i+1)] ;
      
        }
    }

}


for (int i = 0 ; i<c ; i++  )

det = det * arr[(c-1)-i][i];

double_approximation(det);
if_zero(det);

if (approx_equal(det,0)) {/*cout <<"det="<<det;
	    cout.setf(ios_base::fixed);
	cout <<setprecision(0)<< "Fixed: " << 0 << endl;*/ return 0;}


if(r==9 || r==8 || r==1 || r==4 || r==5 )
	{/*cout <<"det="<<det;
	    cout.setf(ios_base::fixed);
	cout <<setprecision(0)<< "Fixed: " << det << endl;*/ return det;}

else

	{/*cout <<"det="<<det;
	    cout.setf(ios_base::fixed);
	cout <<setprecision(0)<< "Fixed: " << -1*det << endl;*/  return  -1*det ;}







    }
////////////////////

void inverse (int  arr [M][N] , int n , double res_arr [M][N] )
{
    int h ,k,i,j;
     double cofactor= 1.0/(double) determinant(arr,n); ////////////////////////////////////double)
   int inner_det [M][N];
   int x,p;
//calculate determinat of each position
if(n==1) {/*cout<<"cofactr"<<cofactor<<endl;*/res_arr[0][0] = cofactor;  }
else if(n==2)
 {

      res_arr[0][0] = arr[1][1] * cofactor ;
      res_arr[1][1] = arr[0][0] * cofactor ;
      res_arr[0][1] = -1*arr[0][1] * cofactor ;
      res_arr[1][0] = -1* arr[1][0] * cofactor ;
 }
 else{

       int  sign = +1;
    for (x=0 ; x<n ; x++) {
    for(p=0;p<n;p++) {
      h = 0;
      k = 0;
      for(i=0;i<n;i++) {
            if (i==x) continue;
        for( j=0;j<n;j++) {
          if(j==p) {
            continue;
          }
          inner_det[h][k] = arr[i][j];
          k++;
          if(k==n-1) {
            h++;
            k = 0;
          }
        }
      }
      res_arr[x][p]=pow(-1,(x+p))*determinant(inner_det,n-1);
   // sign = -1*sign;
    }
  }

//print_inv (res_arr,n,n);

  //// tranpose result array


      for (int w = 0 ; w<n-1 ; w++ )
      {
          for (int v = w+1 ; v< n ; v++ )
          {
              if(w==v) continue;
          double  temp =  res_arr [w] [v] ;
         res_arr [w] [v] = res_arr [v] [w] ;
          res_arr [v] [w] = temp;
      

          }
       
      }



        for (int w = 0 ; w<n ; w++ )
      {
          for (int v = 0 ; v< n ; v++ )
          {
              res_arr[w][v] = res_arr[w][v] * cofactor ;

          }
      }
 }



}









int main()
{
    cout<<"Please enter dimensions of Matrix A:"<<endl;

    int m,n;

    cin>> m>>n; // m is the number of rows in arr_A /// n is the number of columns is arr_A

    int arr_A[M][N] ={0} ;

    cout <<"Please enter dimensions of Matrix B:"<<endl;

    int a,b ;
    cin >>a>>b;

    int arr_B[M][N]={0};
                                                              // a is the number of rows in arr_B /// b is the number of columns is arr_B
    cout <<"Please enter values of Matrix A:"<<endl;

    for (int i = 0; i<m ; i++)
    {
        for (int j = 0; j<n ; j++)                                   // values for arr_A
        {
            cin>>arr_A [i][j];

        }

}

cout <<"Please enter values of Matrix B:"<<endl;


    for (int i = 0; i<a ; i++)
    {
        for (int j = 0; j<b ; j++)
        {
            cin>>arr_B [i][j];

        }

}

int operation=0  ;  // operation is a variable for choosing the operation required


cout <<"Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):"<<endl;  //asking the user to enter the operation
cin >> operation;



while (operation !=7 )


{

switch (operation)
{







case 1 :


        if (m==a && n==b && m > 0 && n >0 && a>0 && b>0)
       {
        int result [M][N]= {0};

        array_Addition(arr_A,m,n,arr_B,a,b ,result,m,n);


        print(result,a,b);
        break;


       }
        else
            cout <<"The operation you chose is invalid for the given matrices."<<endl;
            break;

case 2 :


        if (m==a&&n==b && m > 0 && n >0 && a>0 && b>0)
       {
        int result [M][N]={0};

        array_Subtraction(arr_A,m,n,arr_B,a,b ,result,m,n);

        print(result,a,b);
        break;


       }
        else
            cout <<"The operation you chose is invalid for the given matrices."<<endl;
            break;




case 3 :


        if (n==a && m > 0 && n >0 && a>0 && b>0)
       {
        int result [m][b]={0};


    for (int i = 0; i<m ; i++)
    {
        for (int j = 0; j<b ; j++)     //// R [i][j]
       {

        long long sum=0;

               for (int f =0 ; f<a ;f++)
                                                                                    /*Arr_[m][n] */
           { sum   = sum + arr_A[i][f] * arr_B [f] [j] ; }

            result[i][j] = sum;
        }
    }

      // array_Multiplication((int *)arr_A,m,n,(int *)arr_B,a,b ,(int *)result,m,b);

        array_display((int *)result,m,b);
        break;


       }
        else
            cout <<"The operation you chose is invalid for the given matrices."<<endl;
            break;



case 5:

    if (m!=n) {
        cout <<"The operation you chose is invalid for the given matrices."<<endl;
        break;}
    else if (m==0 && n==0) {cout <<1<<endl; break;}
    else
    {
        copier_a(arr_A , m ,n ,copy_a);
      //  double answer=determinant(arr_A,m);
   //  cout<<double_approximation(answer)<<endl;
   //   cout <<determinant(m,(int*) arr_A)<<endl;
       //copier_a(copy_a, m ,n ,arr_A );

    //cout<<determinant(m,*arr_A)<<endl;

//       copier_a(arr_A,m,n,copy_a);
      // cout<<det_method_2(copy_a,m,n)<<endl;
       long long ans_1= det_method_2(copy_a,m,n);
    long long ans_2= determinant(arr_A,m);
       if(approx_equal_long_long(ans_1,ans_2))
      cout/*<<"Methodold"*/<<ans_1<<endl;
       else
       cout/*<<"Methodnew"*/<<ans_2<<endl;


        break;
   }

case 6 :

    if (a!=b)
     {

        cout <<"The operation you chose is invalid for the given matrices."<<endl;
        break; }
    else if (a==0 && b==0) {cout <<1<<endl; break;}
    else
    {
       copier_b(arr_B,a,b,copy_b);

//        double answer=determinant(a,*arr_B);
      //  cout<<double_approximation(answer)<<endl;
       //  copier_b(copy_b,a,b,arr_B);


   //    copier_b(arr_B,a,b,copy_b);
      // cout<<det_method_2(copy_b,a,b)<<endl;
     long long ans_1= det_method_2(copy_b,a,b);
      long long ans_2= determinant(arr_B,a);

      if(approx_equal_long_long(ans_1,ans_2))
     cout/*"Method old"*/<<ans_2<<endl;
    else
    cout/*<<"Method new"*/<<ans_2<<endl;







        break;
    }
// A m  n   B  a b

case 4:

    if (a==b && a==n && (determinant(arr_B,a)!=0) && m > 0 && n >0 && a>0 && b>0)
    {
    double result_inv [M][N];
    inverse(arr_B,a,result_inv);

      //  print_inv(result,a,b);
  double result [M][N]={0};


    //    print_inv(result_inv,a,b);


    for (int i = 0; i<m ; i++)
    {
        for (int j = 0; j<b ; j++)     //// R [i][j]
       {

       long  double sum=0;

               for (int f =0 ; f<m ;f++)
                                                                                    /*Arr_[m][n] */
           { sum   = sum + arr_A[i][f] * result_inv [f] [j] ; }

            result[i][j] = double_approximation(sum);
        }
    }

        print_inv(result,m,b);


        break;
    }
    else {
        cout <<"The operation you chose is invalid for the given matrices."<<endl;
        break;}
}


cout <<"Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):"<<endl;  //asking the user to enter the operation
cin >> operation;


}

cout <<"Thank you!"<<endl ;







    return 0;
}
