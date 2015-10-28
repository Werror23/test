#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

struct matr_t
{
    int col_cnt_;
    int row_cnt_;
    
    int ** data_;
};

void allocate_matr( matr_t * matr, int row_cnt, int col_cnt )
{
    matr->col_cnt_ = col_cnt;
    matr->row_cnt_ = row_cnt;
    
    matr->data_ = new int*[row_cnt];
    for (int m = 0; m < col_cnt; ++m)
        matr->data_[m] = new int[col_cnt];
}

void fillrand_matr( matr_t *matr )
{
    for (int i = 0; i < matr->row_cnt_ ; i++)
        for (int j = 0; j < matr->col_cnt_ ; j++)
            matr->data_[i][j] = rand() % 10 + 1;
       
}

void sum_matr( matr_t *a, matr_t *b, matr_t *c )
{
    for (int i = 0; i < c->row_cnt_ ; i++)
        for (int j = 0; j < c->col_cnt_ ; j++)
            c->data_[i][j] = a->data_[i][j] + b->data_[i][j];
        
}

void print_matr( matr_t matr )
{
    for (int i = 0; i < matr.row_cnt_; i++)
    {
        for (int j = 0; j < matr.col_cnt_; j++)
            cout << setw(3) << matr.data_[i][j];
        cout << "\n";
    }
    
}

int main(int argc, char** argv)
{
    int col_cnt = 3, row_cnt = 3;    
    
    matr_t a, b, c;
    
    a.data_ = b.data_ = c.data_ = NULL;
    
    allocate_matr(&a, row_cnt, col_cnt);
    allocate_matr(&b, row_cnt, col_cnt);
    allocate_matr(&c, row_cnt, col_cnt);

    fillrand_matr(&a);
    fillrand_matr(&b);
    sum_matr(&a, &b, &c);
    
    cout << " a:\n";
    print_matr(a);
    cout << "\n b:\n";
    print_matr(b);
    cout << "\n c:\n";
    print_matr(c);
    
    return 0;
}