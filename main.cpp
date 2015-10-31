#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

class matr_t
{
public:
    matr_t(int row_cnt, int col_cnt)
    {
        col_cnt_ = col_cnt;
        row_cnt_ = row_cnt;

        data_ = new int*[row_cnt];
        for (int m = 0; m < col_cnt; ++m)
            data_[m] = new int[col_cnt];
    }
    
    ~matr_t()
    {
        for (int i = 0; i < row_cnt_; ++i)
            delete[] data_[i];

        delete[] data_;
    }
    
    void fillrand_matr()
    {
        for (int i = 0; i < row_cnt_ ; i++)
            for (int j = 0; j < col_cnt_ ; j++)
                data_[i][j] = rand() % 10 + 1;
    }
    
    void print_matr() const
    {
        for (int i = 0; i < row_cnt_; i++)
        {
            for (int j = 0; j < col_cnt_; j++)
                cout << setw(4) << data_[i][j];
            cout << "\n";
        }
    }
    
    int get_col_cnt() const
    {
        return col_cnt_;
    }
    
    int get_row_cnt() const
    {
        return row_cnt_;
    }
    
    int get_data(int i, int j) const
    {
        return data_[i][j];
    }
    
    void set_data(int i, int j, int value) 
    {
        data_[i][j] = value;
    }
    
    matr_t & operator = ( matr_t const & a )
    {
        for (int i = 0; i < row_cnt_ ; i++)
            for (int j = 0; j < col_cnt_ ; j++)
                 set_data(i, j, a.get_data(i, j));
    }

private:
    int col_cnt_;
    int row_cnt_;
    
    int ** data_;
};

matr_t operator + ( matr_t const & a, matr_t const & b )
{
    matr_t c(a.get_row_cnt(), a.get_col_cnt());
    for (int i = 0; i < c.get_row_cnt() ; i++)
        for (int j = 0; j < c.get_col_cnt() ; j++)
            c.set_data(i, j, a.get_data(i, j) + b.get_data(i, j));
    return c;
}

matr_t operator * ( matr_t const & a, matr_t const & b )
{
    matr_t c(a.get_row_cnt(), b.get_col_cnt());
    int v;
    for (int i = 0; i < c.get_row_cnt() ; i++)
        for (int j = 0; j < c.get_col_cnt() ; j++)
        {
            v = 0;
            for (int m = 0; m < c.get_row_cnt(); m++)
                v += a.get_data(i, m) * b.get_data(m, j);
            c.set_data(i, j, v);
        }
    return c;
}

int main(int argc, char** argv)
{
    int col_cnt = 3, row_cnt = 3;    
    
    matr_t   a(row_cnt, col_cnt)
           , b(row_cnt, col_cnt)
           , c(row_cnt, col_cnt)
           , d(row_cnt, col_cnt);
    
    a.fillrand_matr();
    b.fillrand_matr();
    c = a + b;
    d = a * b;
   
    cout << " a:\n";
    a.print_matr();
    cout << "\n b:\n";
    b.print_matr();
    cout << "\n Sum:\n";
    c.print_matr();
    cout << "\n Mul:\n";
    d.print_matr();
    
    return 0;
}