#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

#include <cstddef>

namespace StructLib
{
    template <typename T>
    class SmartPointer
    {
    protected:
        T *m_pointer;

    public:
        SmartPointer(T *p = NULL)
        {
            m_pointer = p;
        }


        SmartPointer(const SmartPointer<T>& obj)
        {
            m_pointer = obj.m_pointer;
           // const_cast<SmartPointer<T>&>(obj.m_pointer) = NULL;
        }
        

       SmartPointer<T>& operator=(const SmartPointer<T>& obj)
        {
            if (NULL != obj)
            {
                delete m_pointer;
                m_pointer = obj.m_pointer;
                const_cast<SmartPointer<T>&>(obj.m_pointer) = NULL;
            }

            return *this;
        }


        T* operator->()
        {
            return m_pointer;
        }


        T& operator*()
        {
            return *m_pointer;
        }
        
        bool IsNull()
        {
            return (m_pointer == NULL);
        }


        ~SmartPointer()
        {
            delete m_pointer;
        }
    };
}


#endif // !SMARTPOINTER_H
