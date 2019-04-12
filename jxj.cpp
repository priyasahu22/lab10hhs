include<iostream>
	using namespace std;
	
	/*
	
	2 Rules for Binary Heap
	- Its a complete tree. -> So you can use an array
	- Either a max-heap or min-heap. 
	
	Array Implementation 
	Root - A[0]
	
	Parent Node : Arr[(i-1)/2]
	Left Child  : Arr[(2*i)+1]
	Right Child : Arr[(2*i)+2]
	
	Functions:
	1. GetMin()
	2. ExtractMin()
	3. DecreaseKey()
	4. Insert()
	5. Delete()
	6. Display()
	
	*/
	
	
	class BinaryHeap{
	    public:
	    // Pointer to array of elements
	    int * hArr;
	    // Maximum possible size of array
	    int mSize;
	    // Current size of array 
	    int cSize;
	
	    BinaryHeap(int mSize){
	        // Constructor 
	        hArr = new int[mSize];
	        this->mSize = mSize;
	        cSize = 0;
	    }
	
	    void swap(int *a, int *b){
	        // Swap elements ... 
	        int temp = *a; 
	        *a = *b; 
	        *b = temp;
	    }
	
	    int parent(int i){ return (i-1)/2;}
	    int left(int i){ return (i*2)+1;}
	    int right(int i){ return (i*2)+2;}
	
	    int getMin(){ return hArr[0]; }
	
	    void insert(int value){
	        // Base case. for Heap Overflow
		if(cSize == mSize){
			cout<<"Can't insert more elements\n";
		}
	        // Insert the new key at the end.
	        else{
	        	hArr[cSize] = value;	
			//Check it for all hierarchy with loop
			int i = cSize;
				//Check if it breaks the heap property and fix it. 
			while (i != 0 && hArr[parent(i)]>hArr[i]){
				swap(&hArr[parent(i)],&hArr[i]);
				i = parent(i);
			}
			cSize++;
		}
	    }
	    void display(){
	        // Display the array
	        cout<<"The array you made is :\n";
	        for(int i = 0;i < cSize; i++){
	        	cout<<hArr[i]<<",";
	        }
	        cout<<endl;
	    }
	    int extractMin(){
	    	return extractMin(0);
	    }	
	    int extractMin(int index) 
	    { 
	        // Base case for Empty Heap
	        if(cSize == 0){
	        	cout<<"No sufficient elements\n";
	        	return 0;
	        }
	        // Base case for Heap with 1 value.
	        if(cSize == 1){
	        	cSize = 0;
	        }
		else{
	        // Copy the last element to the root. 
	        swap(&hArr[index],&hArr[cSize-1]);
	        cSize--;
	        
	        // Call MinHeapify on root. 
		MinHeapify(index);
	        // Return the min (Store it, before you replace the root with the last element)
	        return hArr[index];
	        }
	    }
	
	    void decreaseKey(int i, int new_val) 
	    { 
	        // Algorithm for what happens when I reduce the value of an element indexed at i to new_val. You can assume new_val to be less than the present value of the element. 
	        if(i<cSize){
	        	if(new_val<hArr[i]){
	        		hArr[i] = new_val;
	        		// Loop for correcting the Property 2.
	        		// Compare with parent and move up till i == 0 or there is no violation.
				while (i != 0 && hArr[i]<hArr[parent(i)]){
					swap(&hArr[i],&hArr[parent(i)]);
					i = parent(i);
				}	  
	        	}
