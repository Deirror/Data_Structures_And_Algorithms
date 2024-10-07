template <class T>
int linearSearch(T* arr, int size, const T& searched) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == searched) {
            return i;
        }  
    } 
    
    return -1;
} 
