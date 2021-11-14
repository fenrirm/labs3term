#include <iostream>
#include <algorithm>
#include <vector>


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

/*
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
};
*/

//insert element into sparse matrix





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
    Node *matrix1;
    //Node *matrix2;
    //Node *matrix3;
    matrix1=list_representation(sparseMatrix1, rows, cols);
    //matrix2=list_representation(sparseMatrix2, rows, cols);
    std::cout<<"**********LIST REPRESENTATION***********"<<std::endl;
    print_list(matrix1);
    //std::cout<<std::endl;
    //print_list(matrix2);
    //std::cout<<std::endl;
    //matrix3=add_matrices(matrix1,matrix2);
    //print_list(matrix3)


    //VECTOR REPRESENTATION
    matrix M;
    int ch;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            std::cin>>ch;
        }
    }
    std::cout<<"***********VECTOR REPRESENTATION************"<<std::endl;
    sparesify(M);




    //MEMORY FREE
    /*  for (int i=0; i<rows; i++)
      {
          delete  [] sparseMatrix1[i];
      }
      delete[] sparseMatrix1;
  */

    return 0;
}
