

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include "NbVector.hpp"

class	PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(NbVector const  & mm);
		PmergeMe(PmergeMe const & rhs);
		~PmergeMe();

		PmergeMe &	operator=(PmergeMe const & rhs);

		void				fjSort();
		NbVector &	getMergeMe();

	private:
		void			pairSwap();
		void			splitMe();
		void			reload();
		void			reinsert();
		void			getOrder();
		unsigned int	nextGroupSize(unsigned int g, unsigned int group);
		void			binaryInsert(Number r, long int right);

		NbVector					merge_me;
		NbVector					halfbig;
		NbVector					remain;
		NbVector					pairing;
		std::vector<unsigned int>	the_order;
};
#endif
