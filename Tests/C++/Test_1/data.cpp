#include "data.h"

CData::CData(int data)
    : m_data(data)
{
    std::cout << "Created : " << m_data << std::endl;
}

CData::~CData()
{
    std::cout << "Destoryed : " << m_data << std::endl;
}

int CData::data()
{
    return m_data;
}

