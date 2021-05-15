#include <iostream>
#include <vector>
#include <cmath> // for pow function

using namespace std;

typedef vector <double> Dvector;
typedef vector <Dvector> Dmatrix;

Dmatrix Minor(const Dmatrix &Amat, const int col){
	Dmatrix Minmat = Amat;
	int size = Amat.size();
	for (int i = 0; i < size; i++)
	{
		Minmat[i].erase(Minmat[i].begin() + col);
	}
	Minmat.erase(Minmat.begin());
	return Minmat;
}

Dmatrix Replace(Dmatrix Rmat, const int col, const Dvector &bvect){ //returns a Dmatrix
	for (unsigned int i = 0; i < Rmat.size(); i++)
	{
		Rmat[i][col] = bvect[i];
	}
	return Rmat;
}

double Det(const Dmatrix &Amat){
	int term;
	int total = 0; 
	if (Amat.size() == 2)
	{
		return ((Amat[0][0])*(Amat[1][1]) - (Amat[1][0])*(Amat[0][1]));
	}
	
	for (unsigned int i = 0; i < Amat.size(); i++)
	{
		term = i + 1;
		total = total + (pow((-1), (1 + term)) * Amat[0][i] * Det(Minor(Amat, i)));
	}
	return total;
}

Dmatrix GetA(){
	Dmatrix vect2D;
	int x, num;
	cin >> x;
	for (int i = 0; i < x; i++)
	{
		Dvector vect;
		for (int i2 = 0; i2 < x; i2++)
		{
			cin >> num;
			vect.push_back(num);
		}
		vect2D.push_back(vect);
	}
	return vect2D;
}

void Display(const Dmatrix &v){
	for (unsigned i = 0; i < v.size(); i++)
	{
		for (unsigned i2 = 0; i2 < v[i].size(); i2++)
		{
			cout << v[i][i2] << " ";
		}
		cout << endl;
	}
	cout << endl;	
}

void Display(const Dvector &v){
	for (unsigned i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
	cout << endl;
}

Dvector Getb(const int &size){
	int num;
	Dvector b;	
	for (int i = 0; i < size; i++)
	{
		cin >> num;
		b.push_back(num);
	}
	Display(b);
	return b;	
}

Dvector Solvex(const Dmatrix &Amat, const Dvector &bvect){  //returns a Dvector
	Dvector solution;
	double sol;
	for (unsigned int i = 0; i < Amat.size(); i++)
	{
		sol = Det(Replace(Amat, i, bvect)) / Det(Amat);
		solution.push_back(sol);
	}
	return solution;
}
/*
int main(){
	Dmatrix A;
	Dvector b, x;
	
	A = GetA();
	Display(A);
	b = Getb(A.size());
	x = Solvex(A,b);
	Display(x);

	return 0;
}*/
