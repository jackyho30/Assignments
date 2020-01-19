#include <iostream>
#include "SafeMatrix.h"

// Methods
void SafeMatrix::transpose() {
	
	int position1 = 0;
	int position2 = 0;
	float* transp = new (std::nothrow) float[_dataSpaceAllocated]();
	
	for (int i = 0; i < _numRows; i++) {
		for (int x = 0; x < _numCols; x++) {
			//position in original matrix
			position1 = (i * _numCols + x);
			//position in transpose matrix
			position2 = (x * _numRows + i);
			
			transp[position2] = _data[position1];
		}
	}
	int temp = _numCols;
	_numCols = _numRows;
	_numRows = temp;
	delete[] _data;
	_data = transp;
	
}

bool SafeMatrix::appendRow(const int cols, const float data[]) {
	if (data == 0){
		return false;
	}
	if (cols == _numCols){
		int newAllocated = _dataSpaceAllocated + cols; 
		float* addRow = new (std::nothrow) float[newAllocated]();
		if (!addRow){
			return false;
		}
		if (!data){
			return false;
		}
		for (int i = 0; i < _dataSpaceAllocated; i++) {
			addRow[i] = _data[i];
		}
		for (int i = _dataSpaceAllocated; i < newAllocated; i++) {
			addRow[i] = data[i - _dataSpaceAllocated];
		}
		_numRows += 1;
		_dataSpaceAllocated = newAllocated;
		delete[] _data;
		_data = addRow;
		
		
		
		return true;
	}
	else{
		return false;
	}
	
}

bool SafeMatrix::appendColumn(const int rows, const float data[]) {
	if (rows < 0){
		return false;
	}
	if (rows == _numRows){
		int newAllocated = _dataSpaceAllocated + rows;
		float* addCol = new (std::nothrow) float[newAllocated]();
		if (!addCol){
			return false;
		}
		if (!data){
			return false;
		}
		int cols = _numRows/rows;
		for (int i = 0; i < newAllocated; i++) {
			if (_numCols % cols == 0){
				addCol[i] = data[i];
			}
			else{ 
				addCol[i] = _data[i];
			}
		}
		
		_numCols += 1;
		_dataSpaceAllocated = newAllocated;
		delete[] _data;
		_data = addCol;
	}
	else{
		return false;
	}
	return true;
}

Dimensions SafeMatrix::dimensions() const {
	Dimensions newDim;
	newDim.rows = _numRows;
	newDim.cols = _numCols;
	
	return newDim;
	
}

// Operators

float& SafeMatrix::operator()(int i, int j) {
	if (i >= _numRows || j >= _numCols || i < 0 || j < 0){
		return _nan;
	}
	return _data[i*_numCols + j];
}  

SafeMatrix SafeMatrix::operator+(const SafeMatrix& m) const {
	float* temp = new (std::nothrow) float[_dataSpaceAllocated]();
	if (_numCols == m._numCols && _numRows == m._numRows){
		for (int i = 0; i < _dataSpaceAllocated; i++) {
			temp[i] = _data[i] + m._data[i];
		}
	}
	else{
		SafeMatrix addition (-1, -1);
		return addition;
	}
	SafeMatrix addition(_numRows,_numCols);
	for (int i = 0; i < _numRows; i++) {
		for (int x = 0; x < _numCols; x++) {
			int position = (i * _numCols + x);
			MATRIX(addition, i, x) = temp[position];
		}
	}
	return addition;
}

SafeMatrix SafeMatrix::operator*(const SafeMatrix& m) const {
	if (_numRows < 0 || _numRows < 0 || m._numRows < 0 || m._numCols < 0){
		return SafeMatrix(-1,-1);
	}
	
	float* temp = new (std::nothrow) float[_numRows * m._numCols]();

	//stackoverflow matrix multiplication using 1d arrays
	if (_numCols == m._numRows){
		//Matrix A rows
		for (int i = 0; i < _numRows; i++) {
			//Matrix B columns
			for (int j = 0; j < m._numCols; j++) {
				float product = 0;
				//use k for both Acols and Brows
				for (int k = 0; k < m._numRows; k++) {
					product = product + _data[i * _numCols + k] * m._data[k * m._numCols + j];
				}
				//fill the temporary data
				temp[i * m._numCols + j] = product;
			}
		}	
	}
	else{
		SafeMatrix multiply (-1, -1);
		return multiply;
	}
	//create a new matrix using the dimensions of the multiplied and fill with the temp data
	SafeMatrix multiply(_numRows,m._numCols);
	for (int i = 0; i < _numRows; i++) {
		for (int x = 0; x < m._numCols; x++) {
			int position = (i * m._numCols + x);
			MATRIX(multiply, i, x) = temp[position];
		}
	}
	return multiply;
	
}
void SafeMatrix::operator=(const SafeMatrix& m) {
	float* newMatrix = new (std::nothrow) float[_dataSpaceAllocated]();
	if (!newMatrix) {
		_numRows = -1;
		_numCols = -1;
		_data = NULL;
	}
	for (int i = 0; i < m._dataSpaceAllocated; i++){
		newMatrix[i] = m._data[i];
	}
	delete[] _data;
	_data = newMatrix;
}

  // Constructors/Destructor
  ///////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////
SafeMatrix::SafeMatrix() {
	_numCols = 0;
	_numRows = 0;
	_dataSpaceAllocated = 0;
	_data = NULL;
	
}

SafeMatrix::SafeMatrix(const SafeMatrix& m) {
	_numRows = m._numRows;
	_numCols = m._numCols;
	if (_numCols >= 0 && _numRows >= 0){
		_dataSpaceAllocated = m._numRows * m._numCols;
	}
	float* data = new (std::nothrow) float[_dataSpaceAllocated]();
	if (!data) {
		_numRows = -1;
		_numCols = -1;
		_data = NULL;
	}
	
	else {
		for (int i = 0; i < _dataSpaceAllocated; i++) {
			data[i] = m._data[i];
		}
		_data = data;
	}
	
}

SafeMatrix::SafeMatrix(const int rows, const int cols) {
	_numRows = rows;
	_numCols = cols;
	
	if (_numCols >= 0 && _numRows >= 0){
		_dataSpaceAllocated = _numRows * _numCols;
	}
	float* data = new (std::nothrow) float[_dataSpaceAllocated]();

	if (!data) {
		_numRows = -1;
		_numCols = -1;
		_data = NULL;
	}
	else {
		for (int i = 0; i < _dataSpaceAllocated; i++) {
			data[i] = 0;
		}
		_data = data;
	}
}

SafeMatrix::SafeMatrix(const int rows, const int cols, const float initVal) {
	_numRows = rows;
	_numCols = cols;
	
	if (_numCols >= 0 && _numRows >= 0){
		_dataSpaceAllocated = _numRows * _numCols;
	}
	float* data = new (std::nothrow) float[_dataSpaceAllocated]();
	if (!data) {
		_numRows = -1;
		_numCols = -1;
		_data = NULL;
	}
	else {
		for (int i = 0; i < _dataSpaceAllocated; i++) {
			data[i] = initVal;
		}
		_data = data;
	}
	
}

SafeMatrix::~SafeMatrix() {
	delete[] _data;
}

std::ostream& operator<<(std::ostream& os, const SafeMatrix& m) {
	INVARIANT_TEST(m._numRows < NOT_A_MATRIX, "ostream::operator<<()");
	if (m._numRows < NOT_A_MATRIX) {
		m.errorMsg("Method ostream::operator<<: attempting to output deleted SafeMatrix");
		abort();
	}
	if (m._numRows == NOT_A_MATRIX) {
		os << "Not-a-Matrix";
		return os;
	}
	if (m._numRows == 0)
		os << "[]";
	for (int i = 0; i < m._numRows; ++i) {
		os << "[";
		for (int j = 0; j < m._numCols; ++j) {
			os << MATRIX(m,i,j);
			if (j < (m._numCols - 1))
				os << ", ";
			}
		os << "]";
		if (i < (m._numRows - 1))
			os << std::endl;
	}
	return os;
}

void SafeMatrix::errorMsg(const char msg[]) const {
	std::cerr << msg << std::endl;
}
