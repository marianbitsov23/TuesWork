#ifndef VECTOR_H
#define VECTOR_H

template<class T>
class Vector{
    public:
        int size;
        T* data;

        Vector();
        Vector(const Vector& vector);
        void push_back(T value);
        void sort();
        T pop();

    private:
        void resize();
};

#endif