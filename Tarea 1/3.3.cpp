#include <iostream>
#include <cstdlib>

class CVector {
private:
    int* m_pVect;  
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
        m_pVect = (int*)realloc(m_pVect, sizeof(int) * (m_nMax + m_nDelta));
        m_nMax += m_nDelta;
    }

public:
    CVector(int delta = 10) {
        Init(delta);
    }

    void Insert(int elem) {
        if (m_nCount == m_nMax) {
            Resize();
        }
        m_pVect[m_nCount++] = elem;
    }

};

int main() {
    CVector vector1;
	
    vector1.Insert(10);
    vector1.Insert(20);
	
    free(vector1.m_pVect); 
    return 0;
}
