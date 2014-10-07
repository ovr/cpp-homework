#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

int main(int argc, char *argv[])
{         
    srand(time(NULL));
    
    int i, j, n, m, max, min, currentmax, currentmin, temp;
    
    n = 5;
    m = 8;
    
    int **matrix = (int**) malloc(n* sizeof(int*));
    
    for(i=0; i < n; i++) {
        *(matrix+i) = (int*) malloc(m* sizeof(int*));
    }
        
    max = -9999;
    min = 10000;
    
    currentmax = 0;
    currentmin = 0;
            
    for(i=0; i<n; i++) {
        temp = 0;
        
        for(j=0; j<m; j++) {
            temp += *(*(matrix+i)+j) = rand()%10-1;
            cout << *(*(matrix+i)+j) << " ";
        }
        
        if (temp > max) {
           max = temp;   
           currentmax = i+1;     
        }

        if (temp < min) {
           min = temp;   
           currentmin = i+1;     
        }
                
        cout << "= " << temp << endl;
    }
    
    cout << endl << endl;
    
    cout << "Max in row a[" << currentmax << "] = " << max << endl;
    cout << "Min in row a[" << currentmin << "] = " << min << endl;

    return EXIT_SUCCESS;
}
