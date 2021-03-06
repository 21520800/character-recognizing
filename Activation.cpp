#include <iostream>
#include <cmath>

#include "Activation.h"

const float EulerConstant = std::exp(1.0);

Activation::Activation() {
}

Activation::Activation(const Activation& orig) {
}

Activation::~Activation() {
}

float Activation::unitStep(float x)
{
	if ( x < 0 ) return 0;
	else return 1;	
}

Matrix Activation::unitStep(Matrix m)
{	
	int rows = m.getrows();
	int cols = m.getcols();
	
	int size = rows * cols;
	float* tmpdata;
	tmpdata = new float[size];

	int k = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			tmpdata[k] = unitStep(m.get(i,j)); 
			k++;
		}	
	}	

	Matrix m2;
	m2.allocateSize(rows,cols);
	m2.fillMatrix(tmpdata);
	return m2;
}

/************************ linear ****************************/

float Activation::linear(float m, float c, float x)
{
	return ((m*x)+c);
}

Matrix Activation::linear(float m, float c, Matrix m1)
{	
	int rows = m1.getrows();
	int cols = m1.getcols();
	
	int size = rows * cols;
	float* tmpdata;
	tmpdata = new float[size];

	int k = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			tmpdata[k] = ((m*(m1.get(i,j)))+c); k++;
		}	
	}	

	Matrix m2;
	m2.allocateSize(rows,cols);
	m2.fillMatrix(tmpdata);
	return m2;
}

/******************** sigmoid function **********************/

float Activation::sigmoid(float x)
{	
	return 1/(1 + std::pow (EulerConstant, -x));
}

Matrix Activation::sigmoid(Matrix m)
{	
	int rows = m.getrows();
	int cols = m.getcols();
	
	int size = rows * cols;
	float* tmpdata;
	tmpdata = new float[size];

	int k = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			tmpdata[k] = sigmoid(m.get(i,j)); 
			k++;
		}	
	}	

	Matrix m2;
	m2.allocateSize(rows,cols);
	m2.fillMatrix(tmpdata);
	return m2;
}

float Activation::SigmoidDerivative(float x)
{	
	return (sigmoid(x))*(1-sigmoid(x));
}

Matrix Activation::SigmoidDerivative(Matrix m)
{	
	int rows = m.getrows();
	int cols = m.getcols();
	
	int size = rows * cols;
	float* tmpdata;
	tmpdata = new float[size];

	int k = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			float x = m.get(i,j);
			tmpdata[k] = (sigmoid(x))*(1-sigmoid(x)); 
			k++;
		}	
	}	

	Matrix m2;
	m2.allocateSize(rows,cols);
	m2.fillMatrix(tmpdata);
	return m2;
}

/***************** Tan-Sigmoid Function ********************/

float Activation::tanSigmoid(float x)
{	
    /*
     *  (2 / (1 + e^(-2x)))-1
     */
    return ( 2 / ( 1 + ( std::pow (EulerConstant, (-2 * x) ) ) ) ) - 1;
}

Matrix Activation::tanSigmoid(Matrix m)
{	
	int rows = m.getrows();
	int cols = m.getcols();
	
	int size = rows * cols;
	float* tmpdata;
	tmpdata = new float[size];

	int k = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			tmpdata[k] = tanSigmoid(m.get(i,j)); 
			k++;
		}	
	}	

	Matrix m2;
	m2.allocateSize(rows,cols);
	m2.fillMatrix(tmpdata);
	return m2;
}

/***********************************************************/
