import java.util.*;
class a {
    int[][] mat;
    int m;
    void input(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the matrix size:");
        m = sc.nextInt();
        System.out.println("Enter the matrix elements:");
        mat = new int[m][m];
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++)
                mat[i][j] = sc.nextInt();
        }
    }
    void output(){
        System.out.println("The array is:");
        for(int i=0;i<mat.length;i++){
            for(int j=0;j<mat[i].length;j++)
                System.out.print(mat[i][j]+' ');
        }
    }
}

class Calculation extends Matrix {
    int sumR = 0,sumC = 0,sumleft = 0,sumr8 = 0;
    void diagonalSum(int[][] mat, int m){
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (i == j)
                    sumleft += mat[i][j];
                if ((i + j) == (m - 1))
                    sumr8 += mat[i][j];
            }
        }
        System.out.println("Sum of left diagonal:" + sumleft);          
        System.out.println("Sum of right diagonal:" + sumr8);
    }
    void Row_col(int[][] mat, int m){
        System.out.println("Sum of Rows:");
        for(int i = 0; i < m; i++){    
            sumR = 0;    
            for(int j = 0; j < m; j++){    
              sumR = sumR + mat[i][j];    
            }    
            System.out.println("Sum of " + (i+1) +" row: " + sumR);    
        }  
        System.out.println("Sum of Colums:");
         for(int i = 0; i < m; i++){    
            sumC = 0;    
            for(int j = 0; j < m; j++){    
              sumC = sumC + mat[j][i];    
            }    
            System.out.println("Sum of " + (i+1) +" column: " + sumC);    
        }
    }
    public static void main(String[] args) {
        Calculation calc = new Calculation();
        calc.input();
        calc.diagonalSum(calc.mat, calc.m);
        calc.Row_col(calc.mat, calc.m);
    }
}