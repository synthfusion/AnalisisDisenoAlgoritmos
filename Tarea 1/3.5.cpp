#include <iostream>
#include <cstdlib> 

template <typename Type>
class CVector {
private:
    Type* m_pVect;      
    int m_nCount;       
    int m_nMax;         
    int m_nDelta;       

    void Init(int delta) {
        m_pVect = nullptr;
        m_nCount = 0;
        m_nMax = 0;
        m_nDelta = delta;
    }

    void Resize() {
        m_pVect = (Type*)realloc(m_pVect, sizeof(Type) * (m_nMax + m_nDelta));
        m_nMax += m_nDelta;
    }

public:
    CVector(int delta = 10) {
        Init(delta);
    }

    void Insert(const Type& elem) { 
        if (m_nCount == m_nMax) {
            Resize();
        }

        m_pVect[m_nCount++] = elem;
    }

    class iterator {
    private:
        Type* m_pCurrent;
        CVector<Type>* m_pVector; 

    public:
        iterator(CVector<Type>* pVector) : m_pCurrent(pVector->m_pVect), m_pVector(pVector) {}

        Type& operator*() const { return *m_pCurrent; }

        iterator& operator++() {
            m_pCurrent++;
            return *this;
        }

        iterator operator++(int) {
            iterator temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const iterator& other) const {
            return m_pCurrent == other.m_pCurrent;
        }

        bool operator!=(const iterator& other) const {
            return !(*this == other);
        }
    };

    iterator begin() { return iterator(this); }

    iterator end() { return iterator(this, m_nMax); } // Consider using a sentinel value

    ~CVector() {
        free(m_pVect);
    }
};

int main() {
    CVector<int> vector1;

    vector1.Insert(42);
    vector1.Insert(17);
    vector1.Insert(31);

    for (CVector<int>::iterator it = vector1.begin(); it != vector1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
