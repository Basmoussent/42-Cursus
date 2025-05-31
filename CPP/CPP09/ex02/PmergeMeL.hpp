

#ifndef PMERGEMEL_HPP
# define PMERGEMEL_HPP

# include "NbList.hpp"

class	PmergeMeL
{
	public:
		PmergeMeL();
		PmergeMeL(NbList const  & mm);
		PmergeMeL(PmergeMeL const & rhs);
		~PmergeMeL();

		PmergeMeL &	operator=(PmergeMeL const & rhs);

		void			fjSort();
		NbList &		getMergeMeL();

	private:
		void			pairSwap();
		void			splitMe();
		void			reload();
		void			reinsert();
		void			getOrder();
		unsigned int	nextGroupSize(unsigned int g, unsigned int group);
		void			binaryInsert(Number r, long int right);

		NbList					merge_me;
		NbList					halfbig;
		NbList					remain;
		NbList					pairing;
		std::list<unsigned int>	the_order;
};
#endif
