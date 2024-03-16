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


    ~CVector() {
        free(m_pVect);
    }
};

int main() {
    CVector<int> vector1; 
    CVector<double> vector2; 

    vector1.Insert(42);
    vector1.Insert(17);

    vector2.Insert(3.14);
    vector2.Insert(2.718);

    return 0;
}
