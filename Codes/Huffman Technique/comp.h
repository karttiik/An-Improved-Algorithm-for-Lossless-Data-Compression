static int iteration=0;
static int bitr=0;
static char dataarr[127]={};
static int bitarr[127]={};
static int bitsize[127]={};
static int temparr[127][127]={};

#define MAX_TREE_HT 127
// A Huffman tree node
typedef struct MinHeapNode {

	// input character
	char data;
	// Frequency of the character
	unsigned freq;
	// Left and right child of this node
	struct MinHeapNode *left, *right;
}MinHeapNode;

typedef struct MinHeap {
	// Current size of min heap
	unsigned size;
	// capacity of min heap
	unsigned capacity;
	// Array of minheap node pointers
	MinHeapNode** array;
}MinHeap;
// A function allocate a new min heap node with given character and frequency of the character
MinHeapNode* newNode(char data, unsigned freq) {
	MinHeapNode* temp = (MinHeapNode*)malloc(sizeof(MinHeapNode));
	temp->left = temp->right = NULL;
	temp->data = data;
	temp->freq = freq;
	return temp;
}
// A function to create
// a min heap of given capacity
MinHeap* createMinHeap(unsigned capacity) {

	MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
	minHeap->size = 0;
	minHeap->capacity = capacity;
	minHeap->array = (MinHeapNode**)malloc(minHeap->capacity * sizeof(MinHeapNode*));
	return minHeap;
}
// A function to swap two min heap nodes
void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b) {

	MinHeapNode* t = *a;
	*a = *b;
	*b = t;
}

void minHeapify(MinHeap* minHeap, int idx) {

	int smallest = idx;
	int left = 2 * idx + 1;
	int right = 2 * idx + 2;

	if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
		smallest = left;

	if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
		smallest = right;

	if (smallest != idx) {
		swapMinHeapNode(&minHeap->array[smallest],&minHeap->array[idx]);
		minHeapify(minHeap, smallest);
	}
}
// A function to check if size of heap is 1 or not
int isSizeOne(MinHeap* minHeap) {

	return (minHeap->size == 1);
}
// A function to extract minimum value node from heap
MinHeapNode* extractMin(MinHeap* minHeap) {

	MinHeapNode* temp = minHeap->array[0];
	minHeap->array[0]	= minHeap->array[minHeap->size - 1];
	--minHeap->size;
	minHeapify(minHeap, 0);
	return temp;
}
// A function to insert a new node to Min Heap
void insertMinHeap(MinHeap* minHeap,
				MinHeapNode* minHeapNode) {
				
	++minHeap->size;
	int i = minHeap->size - 1;
	while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
		minHeap->array[i] = minHeap->array[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	minHeap->array[i] = minHeapNode;
}

// A function to build min heap
void buildMinHeap(MinHeap* minHeap) {

	int n = minHeap->size - 1;
	int i;
	for (i = (n - 1) / 2; i >= 0; --i)
		minHeapify(minHeap, i);
}
// A function to print an array of size n
void printArr(int arr[], int n) {

	int i,j;
	int var=0;
	int intermed[127];
	int m=n-1;
	for (i = 0; i < n; ++i) {
	
		var=var+arr[i]*pow(10,m);
		intermed[i]=arr[i];
		m--;
	}
	for (j=0;j<n;++j)
	temparr[bitr][j]=intermed[j];
	bitsize[bitr]=n;
	bitarr[bitr]=var;
	bitr++;
}
// A function to check if this node is leaf
int isLeaf(MinHeapNode* root) {

	return !(root->left) && !(root->right);
}
// Creates a min heap of capacity equal to size and inserts all character of
// data[] in min heap. Initially size of min heap is equal to capacity
MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) {

	MinHeap* minHeap = createMinHeap(size);
	for (int i = 0; i < size; ++i)
		minHeap->array[i] = newNode(data[i], freq[i]);
	minHeap->size = size;
	buildMinHeap(minHeap);
	return minHeap;
}
// The main function that builds Huffman tree
MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {

	MinHeapNode *left, *right, *top;
	// Create a min heap of capacity equal to size. Initially, there are
	// modes equal to size.
	MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);
	// Iterate while size of heap doesn't become 1
	while (!isSizeOne(minHeap)) {
		// Extract the two minimum freq items from min heap
		left = extractMin(minHeap);
		right = extractMin(minHeap);
		// Create a new internal node with frequency equal to the sum of the two nodes frequencies.
		// Make the two extracted node as left and right children of this new node.
		// Add this node to the min heap '$' is a special value for internal nodes, not used
		top = newNode('$', left->freq + right->freq);
		top->left = left;
		top->right = right;
		insertMinHeap(minHeap, top);
	}
	// The remaining node is the root node and the tree is complete.
	return extractMin(minHeap);
}
// Prints huffman codes from the root of Huffman Tree.
// It uses arr[] to store codes
void printCodes(MinHeapNode* root, int arr[], int top) {
	// Assign 0 to left edge and recur
	if (root->left) {
		arr[top] = 0;
		printCodes(root->left, arr, top + 1);
	}
	// Assign 1 to right edge and recur
	if (root->right) {
		arr[top] = 1;
		printCodes(root->right, arr, top + 1);
	}
	// If this is a leaf node, then it contains one of the input
	// characters, print the character and its code from arr[]
	if (isLeaf(root)) {
		dataarr[iteration]=root->data;
		iteration++;
		printArr(arr, top);
	}
}
// The main function that builds a Huffman Tree and print codes by traversing
// the built Huffman Tree
void HuffmanCodes(char data[], int freq[], int size) {

	MinHeapNode* root = buildHuffmanTree(data, freq, size);
	// Print Huffman codes using the Huffman tree built above
	int arr[MAX_TREE_HT], top = 0;
	printCodes(root, arr, top);
}
