#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>


typedef std::vector<int> vi;\
typedef std::vector<std::vector<int> > matrix;

void printMatrix(const matrix& M)
{
    int m = M.size();
    int n = M[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            std::cout << M[i][j] << " ";
        std::cout << std::endl;
    }
}

void printVector(const vi& V, char* msg)
{

    std::cout << msg << "[ ";
    for_each(V.begin(), V.end(), [](int a) {
        std::cout << a << " ";
    });
    std::cout << "]" << std::   endl;
}

void sparesify(const matrix& M)
{
    int m = M.size();
    int n = M[0].size(), i, j;
    vi A;
    vi IA = { 0 }; // IA matrix has N+1 rows
    vi JA;
    int NNZ = 0;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (M[i][j] != 0) {
                A.push_back(M[i][j]);
                JA.push_back(j);

                // Count Number of Non Zero
                // Elements in row i
                NNZ++;
            }
        }
        IA.push_back(NNZ);
    }

    printMatrix(M);
    printVector(A, (char*)"A = ");
    printVector(IA, (char*)"IA = ");
    printVector(JA, (char*)"JA = ");
}
//******************


void create_Matrix(int **sparseMatrix, int rows, int cols)
{
    /*sparseMatrix = new int* [rows];*/
    for (int i=0; i<rows; i++)
    {
        sparseMatrix[i] = new int [cols];
    }

    for (int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            std::cin>>sparseMatrix[i][j];
        }
    }

}

void array_representation(int **sparseMatrix, int rrows, int ccols)
{
    int size =0;
    for (int i=0; i<rrows; i++)
    {
        for(int j=0; j<ccols; j++)
        {
            if (sparseMatrix[i][j]!=0)
            {
                size++;
            }
        }
    }
    int compactMatrix[3][size];

    int k=0;
    for (int i=0; i<rrows; i++)
    {
        for (int j=0; j<ccols; j++)
        {
            if (sparseMatrix[i][j]!=0)
            {
                compactMatrix[0][k]=i;
                compactMatrix[1][k]=j;
                compactMatrix[2][k]=sparseMatrix[i][j];
                k++;
            }
        }
    }
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<size; j++)
            std::cout<<" "<<compactMatrix[i][j];

        std::cout<<"\n";
    }
}

void print_matrix(int **matrixA, int rrows, int ccols)
{
    for (int i=0; i<rrows; i++)
    {
        for (int j=0; j<ccols; j++)
        {
            std::cout<<matrixA[i][j]<<std::endl;
        }
    }
}

//********************

class Node
{
public:
    int row;
    int col;
    int data;
    Node *next;
};


void create_new_node(Node **p, int row_index, int col_index, int x)
{
    Node *tmp=*p;
    Node *r;

    if(tmp== nullptr)
    {
        tmp=new Node();
        tmp->row=row_index;
        tmp->col=col_index;
        tmp->data=x;
        tmp->next= nullptr;
        *p=tmp;
    }

    else
    {
        while(tmp->next!= nullptr)
            tmp=tmp->next;
        r=new Node();
        r->row=row_index;
        r->col=col_index;
        r->data=x;
        r->next= nullptr;
        tmp->next=r;

    }
}

void print_list(Node *start)
{
    Node *ptr=start;
    std::cout<<"row position: ";
    while(ptr!= nullptr)
    {
        std::cout<<ptr->row<<" ";
        ptr=ptr->next;
    }
    std::cout<<std::endl;
    std::cout<<"column position: ";
    ptr=start;
    while(ptr!= nullptr)
    {
        std::cout<<ptr->col<<" ";
        ptr=ptr->next;
    }
    std::cout<<std::endl;
    std::cout<<"Value: ";
    ptr=start;

    while (ptr!=nullptr)
    {
        std::cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}

Node *list_representation(int **sparseMatrix, int rows, int cols)
{
    create_Matrix(sparseMatrix, rows, cols);
    Node *first=nullptr;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            if (sparseMatrix[i][j]!=0)
                create_new_node(&first, i, j, sparseMatrix[i][j]);
        }
    }
    std::cout<<std::endl;
    /*print_list(first);*/
    return first;

}

//**************************

//ADDITION
/*Node *add_matrices(Node *matrixA, Node *matrixB)
{
    Node *matrixC= nullptr;
    while(matrixA!= nullptr && matrixB!= nullptr)
    {
        if(matrixA->row==matrixB->row)
        {
            if(matrixA->col==matrixB->col)
            {
                create_new_node(&matrixC, matrixA->row, matrixA->col, matrixA->data+matrixB->data);
                matrixA = matrixA->next;
                matrixB = matrixB->next;
            }
            else {
                if (matrixA->col < matrixB->col)
                {
                    create_new_node(&matrixC, matrixA->row, matrixA->col, matrixA->data);
                    matrixA = matrixA->next;
                } else
                {
                    create_new_node(&matrixC, matrixB->row, matrixB->col, matrixB->data);
                    matrixB = matrixB->next;
                }
            }

        } else{
            if (matrixA->row < matrixB->row)
            {
                create_new_node(&matrixC, matrixA->row, matrixA->col, matrixA->data);
                matrixA = matrixA->next;
            } else
            {
                create_new_node(&matrixC, matrixB->row, matrixB->col, matrixB->data);
                matrixB = matrixB->next;
            }
        }
    }
    return matrixC;

}*/


/*void print_matrix(int **matrixA, int rrows, int ccols)
{
    for (int i=0; i<rrows; i++)
    {
        for (int j=0; j<ccols; j++)
        {
            std::cout<<matrixA[i][j]<<std::endl;
        }
    }
}*/
//MULTIPLICATION
/*void multiplication_of_matrices( int **matrixA, int **matrixB, int rowsA, int colsA, int colsB)
{
    std::cout<<"I'm in";
    int **matrixC;
    matrixC = new int *[rowsA];
    for (int i = 0; i < rowsA; i++) {
        matrixC[i] = new int[colsB];
    }

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            matrixC[i][j] = 0;
            for (int t = 0; t < colsA; t++) {
if ((matrixA[i][t] != 0) && (matrixB[t][j] != 0))

                    matrixC[i][j] += matrixA[i][t] * matrixB[t][j];


            }
        }
    }
    print_matrix(matrixC, rowsA, colsB);

}*/

//***********OPERATIONS WITH MATRIX**************

class sparse_matrix
{
    const static int MAX = 100;
    int **data;
    int row, col, len;
public:
    //constructor
    sparse_matrix(int r, int c)
    {
        row=r;
        col=c;
        len=0;
        data=new int*[MAX];

        for(int i=0; i< MAX; i++)
        {
            data[i]=new int[3];
        }
    }
    //insertion elements into sparse matrix
    void insert(int r, int c, int val)
    {
        //invalid entry
        if(r>row||c>col)
        {
            std::cout<<"Invalid entry";
        }
        else
        {
            data[len][0]=r;//row value
            data[len][1]=c;//column value
            data[len][2]=val;//element's value
            len++;
        }
    }
    void add(sparse_matrix b)
    {
        //if matrices don't have same dimensions
        if(row!=b.row||col!=b.col)
        {
            std::cout<<"matrices can't be added";
        }
        else
        {
            int apos=0, bpos=0;
            sparse_matrix result(row, col);

            while(apos<len && bpos<b.len)
            {

                // if b's row and col is smaller
                if (data[apos][0] > b.data[bpos][0] ||
                    (data[apos][0] == b.data[bpos][0] &&
                     data[apos][1] > b.data[bpos][1]))

                {

                    // insert smaller value into result
                    result.insert(b.data[bpos][0],
                                  b.data[bpos][1],
                                  b.data[bpos][2]);

                    bpos++;
                }

                    // if a's row and col is smaller
                else if (data[apos][0] < b.data[bpos][0] ||
                         (data[apos][0] == b.data[bpos][0] &&
                          data[apos][1] < b.data[bpos][1]))

                {

                    // insert smaller value into result
                    result.insert(data[apos][0],
                                  data[apos][1],
                                  data[apos][2]);

                    apos++;
                }

                else
                {

                    // add the values as row and col is same
                    int addedval = data[apos][2] +
                                   b.data[bpos][2];

                    if (addedval != 0)
                        result.insert(data[apos][0],
                                      data[apos][1],
                                      addedval);
                    // then insert
                    apos++;
                    bpos++;
                }
            }

            // insert remaining elements
            while (apos < len)
                result.insert(data[apos][0],
                              data[apos][1],
                              data[apos++][2]);

            while (bpos < b.len)
                result.insert(b.data[bpos][0],
                              b.data[bpos][1],
                              b.data[bpos++][2]);

            // print result
            result.print();
        }
    }

    sparse_matrix transpose()
    {

        // new matrix with inversed row X col
        sparse_matrix result(col, row);

        // same number of elements
        result.len = len;

        // to count number of elements in each column
        int *count = new int[col + 1];

        // initialize all to 0
        for (int i = 1; i <= col; i++)
            count[i] = 0;

        for (int i = 0; i < len; i++)
            count[data[i][1]]++;

        int *index = new int[col + 1];

        // to count number of elements having
        // col smaller than particular i

        // as there is no col with value < 0
        index[0] = 0;

        // initialize rest of the indices
        for (int i = 1; i <= col; i++)

            index[i] = index[i - 1] + count[i - 1];

        for (int i = 0; i < len; i++)
        {

            // insert a data at rpos and
            // increment its value
            int rpos = index[data[i][1]]++;

            // transpose row=col
            result.data[rpos][0] = data[i][1];

            // transpose col=row
            result.data[rpos][1] = data[i][0];

            // same value
            result.data[rpos][2] = data[i][2];
        }

        // the above method ensures
        // sorting of transpose matrix
        // according to row-col value
        return result;
    }

    void multiply(sparse_matrix b)
    {
        if (col != b.row)
        {

            // Invalid multiplication
            std::cout << "Can't multiply, Invalid dimensions";
            return;
        }

        // transpose b to compare row
        // and col values and to add them at the end
        b = b.transpose();
        int apos, bpos;

        // result matrix of dimension row X b.col
        // however b has been transposed,
        // hence row X b.row
        sparse_matrix result(row, b.row);

        // iterate over all elements of A
        for (apos = 0; apos < len;)
        {

            // current row of result matrix
            int r = data[apos][0];

            // iterate over all elements of B
            for (bpos = 0; bpos < b.len;)
            {

                // current column of result matrix
                // data[,0] used as b is transposed
                int c = b.data[bpos][0];

                // temporary pointers created to add all
                // multiplied values to obtain current
                // element of result matrix
                int tempa = apos;
                int tempb = bpos;

                int sum = 0;

                // iterate over all elements with
                // same row and col value
                // to calculate result[r]
                while (tempa < len && data[tempa][0] == r &&
                       tempb < b.len && b.data[tempb][0] == c)
                {
                    if (data[tempa][1] < b.data[tempb][1])

                        // skip a
                        tempa++;

                    else if (data[tempa][1] > b.data[tempb][1])

                        // skip b
                        tempb++;
                    else

                        // same col, so multiply and increment
                        sum += data[tempa++][2] *
                               b.data[tempb++][2];
                }

                // insert sum obtained in result[r]
                // if its not equal to 0
                if (sum != 0)
                    result.insert(r, c, sum);

                while (bpos < b.len &&
                       b.data[bpos][0] == c)

                    // jump to next column
                    bpos++;
            }
            while (apos < len && data[apos][0] == r)

                // jump to next row
                apos++;
        }
        result.print();
    }

    // printing matrix
    void print()
    {
        std::cout << "\nDimension: " << row << "x" << col;
        std::cout << "\nSparse Matrix: \nRow\tColumn\tValue\n";

        for (int i = 0; i < len; i++)
        {
            std::cout << data[i][0] << "\t " << data[i][1]
                 << "\t " << data[i][2] << std::endl;
        }
    }
};



//***********************************************
class triangular
{
private:
    double x1, y1, x2, y2, x3, y3;
public:
    triangular(double a1, double b1, double a2, double b2, double a3, double b3)
    {
        x1=a1;
        y1=b1;
        x2=a2;
        y2=b2;
        x3=a3;
        y3=b3;
    }

    double len(double x, double y, double a, double b)
    {
        double length = sqrt(pow((a-x),2)+pow((b-y),2));
        return length;
    }

    double S()
    {
        double a = len(x1, y1, x2, y2);
        double b = len(x2, y2, x3, y3);
        double c = len(x3, y3, x1, y1);
        double p = (a+b+c)/2;
        double S = sqrt(p*(p-a)*(p-b)*(p-c));
        return S;
    }
    double P()
    {
        double a = len(x1, y1, x2, y2);
        double b = len(x2, y2, x3, y3);
        double c = len(x3, y3, x1, y1);
        double P = a+b+c;
        return P;
    }
    void print()
    {
        double func1, func2;
        func1=S();
        func2=P();
        std::cout<<func1<<std::endl;
        std::cout<<func2;
    }

    bool isRiv()
    {
        double a = len(x1, y1, x2, y2);
        double b = len(x2, y2, x3, y3);
        double c = len(x3, y3, x1, y1);
        if((a==b)||(a==c)||(b==c))
        {
            return true;
        }
        else
            return false;

    }
    bool isRiv2()
    {
        double a = len(x1, y1, x2, y2);
        double b = len(x2, y2, x3, y3);
        double c = len(x3, y3, x1, y1);
        if(a==b==c)
        {
            return true;
        }
        else
            return false;

    }
    double vec(double a1, double b1, double a2, double b2)
    {
        double a = a2-a1;
        double b = b2-b1;
    }
};




int main() {

    int rows;
    int cols;
    std::cout<<"rows - ";
    std::cin>>rows;
    std::cout<<"cols - ";
    std::cin>>cols;
    int **sparseMatrix1 = new int* [rows];
    //ARRAY REPRESENTATION
    /* sparseMatrix1 = new int* [rows];
     create_Matrix(sparseMatrix1, rows, cols);
     std::cout<<"*******ARRAY REPRESENTATION***********"<<std::endl;
     array_representation(sparseMatrix1, rows, cols);
     std::cout<<std::endl;*/



    //LIST REPRESENTATION
    //Node *matrix1;
    //Node *matrix2;
    //Node *matrix3;
    //matrix1=list_representation(sparseMatrix1, rows, cols);
    //matrix2=list_representation(sparseMatrix2, rows, cols);
    //std::cout<<"**********LIST REPRESENTATION***********"<<std::endl;
    //print_list(matrix1);
    //std::cout<<std::endl;
    //print_list(matrix2);
    //std::cout<<std::endl;
    //matrix3=add_matrices(matrix1,matrix2);
    //print_list(matrix3)


    //VECTOR REPRESENTATION
    /*matrix M;
    int ch;
    for(int i=0; i<rows; i++)
    {
        M.push_back({});
        for(int j=0; j<cols; j++)
        {
            std::cin>>ch;
            M[i].push_back(ch);
        }
    }
    std::cout<<"***********VECTOR REPRESENTATION************"<<std::endl;
    sparesify(M);*/

    triangular a(5,6, 7, 8, 11, 15);
    a.print();




    //MEMORY FREE
    /*  for (int i=0; i<rows; i++)
      {
          delete  [] sparseMatrix1[i];
      }
      delete[] sparseMatrix1;
  */

    return 0;
}
