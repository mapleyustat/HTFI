#ifndef LAWA_METHODS_HTUCKER_HTUCKERTREE_HTUCKERTREETESTS_H
#define LAWA_METHODS_HTUCKER_HTUCKERTREE_HTUCKERTREETESTS_H 1

#include <lawa/methods/htucker/htuckertree/htuckertree.h>
#include <lawa/methods/htucker/tensor/tensorfunctions.h>

namespace lawa{








void test_sparse_mult_ge(){
	flens::SparseGeMatrix<flens::extensions::CRS<double,flens::CRS_General> > s(3,4);
	s(1,2) = 1;
	s(2,3) = 2;
	s(3,4) = 3;
	s.finalize();
	flens::GeMatrix<flens::FullStorage<double,cxxblas::ColMajor> > g(4,4);
	g = 1,2,3,4,
		5,6,7,8,
		9,10,11,12,
		13,14,15,16;
	flens::GeMatrix<flens::FullStorage<double,cxxblas::ColMajor> > erg;
	erg = s*g;
	std::cout << erg << std::endl;
};

} // namespace lawa

#endif // LAWA_METHODS_HTUCKER_HTUCKERTREE_HTUCKERTREETESTS_H
