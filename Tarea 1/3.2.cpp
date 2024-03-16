#include <iostream>
#include <cstdlib> 

struct Vector {
    int* m_pVect;     
    int m_nCount;     
    int m_nMax;       
    int m_nDelta;     
};

void InitVector(Vector* pThis) {
    pThis->m_pVect = nullptr;
    pThis->m_nCount = 0;
    pThis->m_nMax = 0;
    pThis->m_nDelta = 10;
}

void Insert(Vector* pThis, int elem) {
    if (pThis->m_nCount == pThis->m_nMax) {
        Resize(pThis);
    }
    pThis->m_pVect[pThis->m_nCount++] = elem;
}

void Resize(Vector* pThis) {
    pThis->m_pVect = (int*)realloc(pThis->m_pVect, sizeof(int) * (pThis->m_nMax + pThis->m_nDelta));
    pThis->m_nMax += pThis->m_nDelta;
}

int main() {
    Vector vector1;
    InitVector(&vector1);

    Insert(&vector1, 10);
    Insert(&vector1, 20);

    free(vector1.m_pVect); 
    return 0;
}
