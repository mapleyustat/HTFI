#ifndef LAWA_METHODS_HTUCKER_MATRIXTENSORS_HTUCKERCLOSURE_TESTS_H
#define LAWA_METHODS_HTUCKER_MATRIXTENSORS_HTUCKERCLOSURE_TESTS_H 1

#include<lawa/methods/htucker/matrixtensors/matrixtensor.h>

namespace lawa{


void test_htuckerclosure(){
	MatrixTensor<flens::SparseGeMatrix<flens::extensions::CRS<double,flens::CRS_General> > > mt(2);

	flens::SparseGeMatrix<flens::extensions::CRS<double, flens::CRS_General> > A(3,3);
	A(1,1) = 1;
	A(2,2) = 2;
	A(3,3) = 3;
	A.finalize();
	mt.setMatrix(1,A);
	A.~flens::SparseGeMatrix<flens::extensions::CRS<double, flens::CRS_General> >();
	flens::SparseGeMatrix<flens::extensions::CRS<double,flens::CRS_General> > B(2,2);
	B(1,2) = 1.5;
	B(2,1) = 3;
	B.finalize();
	std::cout << B << std::endl;
	mt.setMatrix(2,B);
	
	emptytensor et;
	tensor<double> empty(et,2,1,2);
	HTuckerTree<double,SVD> testtree(2,empty);

	auto mat = mt + mt;
	mat*testtree;
	
};


};

#endif // LAWA_METHODS_HTUCKER_MATRIXTENSORS_HTUCKERCLOSURE_TESTS_H
