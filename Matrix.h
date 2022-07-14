#include<iostream>
using namespace std;

class Matrix{
	private:
		int cols;
		int rows;
		int **matrix; //aqui se alamacenaran los datos de la matriz
		
	public:
		Matrix(int r, int c){
			rows = r;
			cols = c;
			
			matrix = new int *[rows];
			for(int i=0; i<cols; i++){
				matrix[i] = new int[cols]; //creamos memoria para la matriz
			}
		}
		
		friend istream& operator>>(istream &in, Matrix &m){
			for(int i=0; i<m.rows; i++){
				for(int j=0; j<m.cols; j++){
					cout<< "Elemento ["<<i+1<<", "<< j+1<<"]: ";
					in>> m.matrix[i][j];
				}
			}
			return in;
		}
		
		friend ostream& operator<<(ostream &out, Matrix m){
			for(int i=0; i<m.rows; i++){
				for(int j=0; j<m.cols; j++){
					out<< " "<< m.matrix[i][j]<<" ";
				}
				out<< endl;
			}
			return out;
		}
		
		bool dim(Matrix m){
			return ((rows==m.rows)&&(cols==m.cols));
		}
		
		Matrix operator+(Matrix m){
			Matrix aux(rows, cols);
			for(int i=0; i<m.rows; i++){
				for(int j=0; j<m.cols; j++){
					aux.matrix[i][j] = matrix[i][j]+m.matrix[i][j];
				}
			}
			return aux;
		}
		
		Matrix operator-(Matrix m){
			Matrix aux(rows, cols);
			for(int i=0; i<m.rows; i++){
				for(int j=0; j<m.cols; j++){
					aux.matrix[i][j] = matrix[i][j]-m.matrix[i][j];
				}
			}
			return aux;
		}
		
		Matrix operator*(Matrix m){
			Matrix aux(rows, cols);
			for(int i=0; i<m.rows; i++){
				for(int j=0; j<m.cols; j++){
					aux.matrix[i][j] = 0;
					for(int k=0; k<rows; k++){		//k<rows sirve solo porque use matrices cuadradas
						aux.matrix[i][j] += matrix[i][k]*m.matrix[k][j];
					}
				}
			}
			return aux;
		}
		
		Matrix transpuesta(){
			Matrix aux(rows, cols);
			for(int i=0; i<rows; i++){
				for(int j=0; j<cols; j++){
					aux.matrix[i][j] = matrix[j][i];
				}
			}
			return aux;
		}
	
	
};
