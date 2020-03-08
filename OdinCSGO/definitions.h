namespace SDK
{
	template< class T, class I = int >
	class CUtlMemory
	{
	protected:
		int calculateNewAllocationCount(int nAllocationCount, int nGrowSize, int nNewSize, int nBytesItem)
		{
			if (nGrowSize)
			{
				nAllocationCount = ((1 + ((nNewSize - 1) / nGrowSize)) * nGrowSize);
			}
			else
			{
				if (!nAllocationCount)
					nAllocationCount = (31 + nBytesItem) / nBytesItem;

				while (nAllocationCount < nNewSize)
					nAllocationCount *= 2;
			}

			return nAllocationCount;
		}

	public:
		T& operator[](I i)
		{
			return m_pMemory[i];
		}

		T* base()
		{
			return m_pMemory;
		}

		int allocationCount() const
		{
			return m_nAllocationCount;
		}

		void grow(int increaseBy = 1)
		{
			if (isExternallyAllocated())
				return;

			auto nOldAllocationCount = m_nAllocationCount;
			int nAllocationRequested = m_nAllocationCount + increaseBy;
			int nNewAllocationCount = calculateNewAllocationCount(m_nAllocationCount, m_nGrowSize, nAllocationRequested,
				sizeof(T));

			if ((int)(I)nNewAllocationCount < nAllocationRequested)
			{
				if ((int)(I)nNewAllocationCount == 0
					&& (int)(I)(nNewAllocationCount - 1) >= nAllocationRequested)
					--nNewAllocationCount;
				else
				{
					if ((int)(I)nAllocationRequested != nAllocationRequested)
						return;

					while ((int)(I)nNewAllocationCount < nAllocationRequested)
						nNewAllocationCount = (nNewAllocationCount + nAllocationRequested) / 2;
				}
			}

			m_nAllocationCount = nNewAllocationCount;

			if (m_pMemory)
			{
				auto ptr = new unsigned char[m_nAllocationCount * sizeof(T)];
				memcpy(ptr, m_pMemory, nOldAllocationCount * sizeof(T));
				m_pMemory = (T*)ptr;
			}
			else
			{
				m_pMemory = (T*) new unsigned char[m_nAllocationCount * sizeof(T)];
			}
		}

		bool isExternallyAllocated() const
		{
			return m_nGrowSize < 0;
		}

	protected:
		T* m_pMemory;
		int m_nAllocationCount;
		int m_nGrowSize;
	};

	template< class T >
	T* construct(T* pMemory)
	{
		return ::new(pMemory) T;
	}

	template< class T >
	void destruct(T* pMemory)
	{
		pMemory->~T();
	}

	template< class T, class A = CUtlMemory< T > >
	class CUtlVector
	{
		typedef A CAllocator;
	public:
		T& operator[](int i)
		{
			return m_Memory[i];
		}

		T& at(int i) 
		{
			return m_Memory[i];
		}

		T* base()
		{
			return m_Memory.base();
		}

		int count() const
		{
			return m_nSize;
		}

		void removeAll()
		{
			for (int i = m_nSize; --i >= 0; )
				destruct(&at(i));

			m_nSize = 0;
		}

		int addToTail()
		{
			return insertBefore(m_nSize);
		}

		int insertBefore(int elem)
		{
			grow();
			shiftElementsRight(elem);
			construct(&at(elem));

			return elem;
		}

	protected:
		void grow(int num = 1)
		{
			if (m_nSize + num > m_Memory.allocationCount())
				m_Memory.grow(m_nSize + num - m_Memory.allocationCount());

			m_nSize += num;
			m_pElements = base();
		}

		void shiftElementsRight(int elem, int num = 1)
		{
			int numToMove = m_nSize - elem - num;
			if ((numToMove > 0) && (num > 0))
				memmove(&at(elem + num), &at(elem), numToMove * sizeof(T));
		}

		CAllocator m_Memory;
		int m_nSize;
		T* m_pElements;
	};
}