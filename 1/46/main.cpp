#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

int main(int argc, char *argv[])
{         
    srand(time(NULL));
    
    int i, j, n, m, max, currentmax, temp;
    
    n = 5;
    m = 8;
    
    int **matrix = (int**) malloc(n* sizeof(int*));
    
    for(i=0; i < n; i++) {
        *(matrix+i) = (int*) malloc(m* sizeof(int*));
    }
        
    max = -9999;
    currentmax = 0;
        
    for(i=0; i<n; i++) {
        temp = 0;
        
        for(j=0; j<m; j++) {
            *(*(matrix+i)+j) = rand()%100-50;
            cout << *(*(matrix+i)+j) << " ";
            
            if ((j+1) % 2 != 0) {
               temp = abs(temp + *(*(matrix+i)+j));
            }
        }
        
        if (temp > max) {
           max = temp;   
           currentmax = i;     
        }
        
        cout << "= " << temp << endl;
    }
    
    cout << "Max abs in row a[" << currentmax << "] = " << max << endl;
    
    return EXIT_SUCCESS;
}
